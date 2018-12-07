//
//  GUIController.cpp
//  orange
//
//  Created by Daniel Almeida on 04/12/2018.
//

#include "GUIController.hpp"
#include "ofMain.h"


using namespace Orange::GUI;

GUIController::GUIController(GUIFacadeInterface *_facade)
{
    facade = _facade;
}


void GUIController::setup()
{
    facade->clear();
    facade->setName(layer->name);
    facade->createSlider(layer->alpha, "Layer Alpha", 0, 1);
}

void GUIController::draw()
{
    ofDisableAlphaBlending();
    
    ofSetColor(255,255,255,0);
    facade->draw();
}


void GUIController::setLayer(Orange::Layers::Layer *_layer)
{
    layer = _layer;
 
    setup();
}
