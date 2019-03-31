//
//  GUIController.cpp
//  orange
//
//  Created by Daniel Almeida on 04/12/2018.
//

#include "GUIController.hpp"
#include "ofMain.h"
#include "ofxGui.h"


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
}

void GUIController::setupEffectsInTarget(Orange::Effects::Target target) {
    engineController->effectsController->forEachEffect(target, [&](shared_ptr<Orange::Effects::EffectBase> effect) {
        shared_ptr<Orange::Effects::GLSLEffect> glslEffect = dynamic_pointer_cast<Orange::Effects::GLSLEffect>(effect);
        
        if (glslEffect) {
            facade->createParameterGroup(glslEffect->parameters);
        }
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
}

void GUIController::setup()
{
    setupPreviewsPanel();
    setupLayerPanel();
    setupVisualPanel();
    setupEffectPanel();
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
    
    ofxMatrix<ofImage *> *matrix = facade->createImageMatrix(parameter, std::string(layer->name) + " Visual Matrix");
    facade->createNavigator(matrix, std::string(layer->name) + " Visual Matrix Navigator");
    
}
