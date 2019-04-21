//
//  GUIController.cpp
//  orange
//
//  Created by Daniel Almeida on 04/12/2018.
//

#include "GUIController.hpp"
#include "ofMain.h"
#include "ofxGui.h"
#include "EffectsController.hpp"
#include "VisualsHelpers.hpp"


using namespace Orange::GUI;

GUIController::GUIController(GUIFacadeInterface *_facade, OSFacadeInterface *_os)
{
    facade = _facade;
    os = _os;
    facade->setupPanels();
    setupMenu();
    
    currentFrame.addListener(this, &GUIController::currentFrameChanged);
}


void GUIController::setupPreviewsPanel() {
    facade->setCurrentPanel(PreviewsPanel);
    facade->clear();
    facade->createPreview(&(engineController->fbo))->setTitle(std::string("Output"));
    engineController->forEachLayer([&](shared_ptr<Orange::Layers::Layer> layer) {
        facade->createPreview(&(layer->fbo),std::string(layer->name))->setTitle(std::string(layer->name));
    });

    // this needs to go to another panel
    vector<ofImage *> thumbnails = Orange::Visuals::VisualsHelpers::getVisualsThumbs(this->engineController->loadedVisuals);
    ofParameter<vector<ofImage *>> parameter = thumbnails;
    
    ofxMatrix<ofImage *> *matrix = facade->createImageMatrix(parameter, "Loaded Visuals", 4,3);
    facade->createNavigator(matrix, std::string(layer->name) + " Visual Matrix Navigator");
    
    facade->createButton("Add to Output", [&]() {
    });
    
    unsigned int counter = 1;
    this->engineController->forEachLayer([&](shared_ptr<Orange::Layers::Layer> layer) {
        std::string title = ofToString("Add to ") + layer->name.get();
        
        facade->createButton(title, [&, counter]() {
        });
        counter++;
    });
}

void GUIController::setupEffectsInTarget(Orange::Effects::Target target) {
    unsigned int effectCounter = 0;
    engineController->effectsController->forEachEffect(target, [&](shared_ptr<Orange::Effects::EffectBase> effect) {
        shared_ptr<Orange::Effects::GLSLEffect> glslEffect = dynamic_pointer_cast<Orange::Effects::GLSLEffect>(effect);
        if (glslEffect) {
            facade->createParameterGroup(glslEffect->parameters);
             facade->createButton("Remove", [&, target, effectCounter]() {
                 this->engineController->effectsController->removeEffect(effectCounter, target);
                 setupEffectPanel();
             });
        }
        ++effectCounter;
    });
}

void GUIController::setupEffectPanel() {
    facade->setCurrentPanel(EffectsPanel);
    facade->clear();
    
    facade->setName(std::string("Effects"));
    
    facade->createLabel(std::string("Output"));
    setupEffectsInTarget(Orange::Effects::Target::Output);
    
    unsigned int layerCount = 1;
    engineController->forEachLayer([&](shared_ptr<Layers::Layer> layer) {
        facade->createLabel(std::string("Layer ") + ofToString(layerCount));
        setupEffectsInTarget((Effects::Target) layerCount);
        layerCount++;
    });
}

void GUIController::setupLayerPanel() {
    facade->setCurrentPanel(LayerPanel);
    facade->clear();
    
    facade->setName(std::string("Layers"));
    engineController->forEachLayer([&](shared_ptr<Orange::Layers::Layer> layer) {
        facade->createLabel(std::string(layer->name));
        facade->createSlider(layer->alpha, std::string(layer->name) + " Alpha", 0, 1);
        facade->createSlider(layer->blendMode, std::string(layer->name) + "Blend Mode", 0, 4);
        
        setupVisualsMatrixForLayer(layer);
    });
}

void GUIController::setupVisualPanel() {
    facade->setCurrentPanel(VisualPanel);
    facade->clear();
    currentVisual = layer->getCurrentVisual();
    if (dynamic_cast<Visuals::Video*>(currentVisual.get())) {
        shared_ptr<Visuals::Video> currentVideo = std::dynamic_pointer_cast<Visuals::Video>(currentVisual);
        facade->createSlider(currentFrame, "Current Frame", 0, currentVideo->getNumberOfFrames());
    }
    
    /*
    facade->createButton("Remove Selected", [&]() {
        layer->visuals.remove(layer->currentVisualIndex);
        layer->currentVisualIndex = -1;
        this->setupLayerPanel();
        this->setupVisualPanel();
    });
     */
}

void GUIController::setupEffectListPanel() {
    static std::string controlName = ofToString("effectsList");
    facade->setCurrentPanel(EffectsListPanel);
    facade->clear();
    
    vector<std::string> values = engineController->effectsController->getEffectsNames();
    ofParameter<vector<std::string>> parameter = values;
    
    ofxList<std::string>* stringList = facade->createStringList(parameter, controlName);
    
    facade->createNavigator(stringList, ofToString("Effects List Navigator"));
    facade->createButton("Add to Output", [&]() {
        this->facade->setCurrentPanel(EffectsListPanel);
        ofxList<std::string>* control = (ofxList<std::string>*) this->facade->getControl(controlName);
        std::string shaderName = control->getSelectedValue();
        if (shaderName.empty()) return;
        engineController->effectsController->newGLSLEffect(shaderName, Orange::Effects::Target::Output);
        this->setupEffectPanel();
    });
    
    unsigned int counter = 1;
    this->engineController->forEachLayer([&](shared_ptr<Orange::Layers::Layer> layer) {
        std::string title = ofToString("Add to") + layer->name.get();
       
        
        facade->createButton(title, [&, counter]() {
             this->facade->setCurrentPanel(EffectsListPanel);
             ofxList<std::string>* control = (ofxList<std::string>*) this->facade->getControl(controlName);
             std::string shaderName = control->getSelectedValue();
             if (shaderName.empty()) return;
             engineController->effectsController->newGLSLEffect(shaderName, (Orange::Effects::Target) counter);
             this->setupEffectPanel();
         });
        counter++;
    });
}

void GUIController::setup()
{
    setupPreviewsPanel();
    setupLayerPanel();
    setupVisualPanel();
    setupEffectPanel();
    setupEffectListPanel();
}

void GUIController::update()
{
    shared_ptr<Visuals::Video> currentVideo = getCurrentVideo();
    
    if(currentVideo == NULL) {
        return;
    }
    if (currentVideo->isLoaded() == false) {
        return;
    }
    
    currentFrame.removeListener(this, &GUIController::currentFrameChanged);
    currentFrame.set(currentVideo->getCurrentFrame());
    currentFrame.addListener(this, &GUIController::currentFrameChanged);
}

void GUIController::draw()
{
    ofDisableAlphaBlending();
    ofSetColor(255,255,255,0);
    facade->draw();
}

void GUIController::setLayer(shared_ptr<Orange::Layers::Layer> _layer)
{
    layer = _layer;
    setup();
}

void GUIController::setEngineController(shared_ptr<Engine::EngineController> _engineController)
{
    engineController = _engineController;
}


void GUIController::setupMenu()
{
    os->setupMenuBar();
}


shared_ptr<Orange::Visuals::Video> GUIController::getCurrentVideo()
{
    if (!dynamic_cast<Visuals::Video*>(currentVisual.get())) {
        return NULL;
    }
    
    shared_ptr<Visuals::Video> currentVideo = std::dynamic_pointer_cast<Visuals::Video>(currentVisual);
    
    return currentVideo;
}

void GUIController::currentFrameChanged(int & currentFrame)
{
    shared_ptr<Visuals::Video> currentVideo = getCurrentVideo();
    
    if(currentVideo == NULL) {
        return;
    }
    
    if (currentVideo->isLoaded() == false) {
        return;
    }
    
    currentVideo->setFrame(currentFrame);
}


void GUIController::setupVisualsMatrixForLayer(shared_ptr<Orange::Layers::Layer> layer)
{
    if (layer == NULL) {
        return;
    }
    vector<ofImage *> thumbnails = layer->getVisualsThumbs();
    ofParameter<vector<ofImage *>> parameter = thumbnails;
    
    std::string matrixName = std::string(layer->name) + " Visual Matrix";
    
    ofxMatrix<ofImage *> *matrix = facade->createImageMatrix(parameter, matrixName);
    matrix->labels = layer->labels;
    facade->createNavigator(matrix, std::string(layer->name) + " Visual Matrix Navigator");
    
    shared_ptr<Orange::Layers::Layer> localLayer = layer;
    facade->createButton("Remove Selected", [&, matrixName, localLayer]() {
        facade->setCurrentPanel(PanelNames::LayerPanel);
        ofxMatrix<ofImage *> *matrix = (ofxMatrix<ofImage *>*) facade->getControl(matrixName);
        
        if (matrix == NULL) return;
        
        unsigned int selectedVisual = matrix->getSelectedCell();
        
        if (selectedVisual < 0 ) return;
        
        localLayer->removeByIndex(selectedVisual);
        this->setupVisualPanel();
        this->setupLayerPanel();
    });
}
