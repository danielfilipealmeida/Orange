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
    facade->createSlider("Alpha", 0, 0, 1);
}

void GUIController::draw()
{
    ofDisableAlphaBlending();
    
    ofSetColor(255,255,255,0);
    facade->draw();
}

