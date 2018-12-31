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


void GUIController::setupPreviewsPanel() {
    facade->setCurrentPanel(PreviewsPanel);
    facade->clear();
    facade->createPreview(&(engineController->fbo))->setTitle(std::string("Output"));
    engineController->forEachLayer([&](shared_ptr<Orange::Layers::Layer> layer) {
        facade->createPreview(&(layer->fbo))->setTitle(std::string(layer->name));
    });
}

void GUIController::setupLayerPanel() {
    facade->setCurrentPanel(LayerPanel);
    facade->clear();
    facade->setName(layer->name);
    facade->createPreview(&(layer->fbo));
    facade->createSlider(layer->alpha, "Layer Alpha", 0, 1);
    facade->createSlider(layer->blendMode, "Blend Mode", 0, 4);
}

void GUIController::setupVisualPanel() {
    facade->setCurrentPanel(VisualPanel);
    facade->clear();
    
    shared_ptr<Visuals::BaseVisual> currentVisual = layer->getCurrentVisual();
    if (dynamic_cast<Visuals::Video*>(currentVisual.get())) {
        shared_ptr<Visuals::Video> currentVideo = std::dynamic_pointer_cast<Visuals::Video>(currentVisual);
        facade->createSlider(currentVideo->currentFrame, "Current Frame", 0, currentVideo->getNumberOfFrames());
    }
}

void GUIController::setup()
{
    setupPreviewsPanel();
    setupLayerPanel();
    setupVisualPanel();
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
