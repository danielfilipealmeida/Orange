//
//  GUIController.cpp
//  orange
//
//  Created by Daniel Almeida on 04/12/2018.
//

#include "GUIController.hpp"
#include "ofMain.h"


using namespace Orange::GUI;

GUIController::GUIController(GUIFacadeInterface *_facade, OSInterface *_os)
{
    facade = _facade;
    os = _os;
}


void GUIController::setup()
{
    facade->clear();
    facade->setName(layer->name);
    facade->createPreview(&(layer->fbo));
    facade->createSlider(layer->alpha, "Layer Alpha", 0, 1);
    facade->createSlider(layer->blendMode, "Blend Mode", 0, 4);
    
    setupMenu();
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


void GUIController::setupMenu()
{
    os->setupMenuBar();
}
