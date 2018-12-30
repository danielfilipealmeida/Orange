//
//  GUIController.cpp
//  orange
//
//  Created by Daniel Almeida on 04/12/2018.
//

#include "GUIController.hpp"
#include "ofMain.h"


using namespace Orange::GUI;

GUIController::GUIController(GUIFacadeInterface *_facade, OSFacadeInterface *_os)
{
    facade = _facade;
    os = _os;
    facade->setupPanel();
    setupMenu();
}


void GUIController::setup()
{
    // Previews Panel setup. move to method. Also, this doesn't need to be recreated everytime!
    facade->setCurrentPanel(PreviewsPanel);
    facade->clear();
    //facade->setName("Previews");
    facade->createLabel(std::string("Output"));
    facade->createPreview(&(engineController->fbo));
    engineController->forEachLayer([&](shared_ptr<Orange::Layers::Layer> layer) {
         facade->createLabel(layer->name);
        facade->createPreview(&(layer->fbo));
    });
    
    // Layer Panel setup. move to method
    facade->setCurrentPanel(LayerPanel);
    facade->clear();
    facade->setName(layer->name);
    facade->createPreview(&(layer->fbo));
    facade->createSlider(layer->alpha, "Layer Alpha", 0, 1);
    facade->createSlider(layer->blendMode, "Blend Mode", 0, 4);
    
    
    // Visual Panel setup. move to method
    facade->setCurrentPanel(VisualPanel);
    facade->clear();

    shared_ptr<Visuals::BaseVisual> currentVisual = layer->getCurrentVisual();
    if (dynamic_cast<Visuals::Video*>(currentVisual.get())) {
        shared_ptr<Visuals::Video> currentVideo = std::dynamic_pointer_cast<Visuals::Video>(currentVisual);
        facade->createSlider(currentVideo->currentFrame, "Current Frame", 0, currentVideo->getNumberOfFrames());
    }
    
    
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
