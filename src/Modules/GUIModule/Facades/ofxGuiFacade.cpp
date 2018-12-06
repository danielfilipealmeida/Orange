//
//  ofxGuiFacade.cpp
//  orange
//
//  Created by Daniel Almeida on 04/12/2018.
//

#include "ofxGuiFacade.hpp"
#include <string>

using namespace Orange::GUI;


ofxGuiFacade::ofxGuiFacade()
{
    gui.setup();
}

void ofxGuiFacade::createSlider(std::string title, float value, float minValue, float maxValue)
{
    ofxFloatSlider* slider;
    slider = new ofxFloatSlider();
    slider->setup(title, value, minValue, maxValue);
    gui.add(slider);
}

void ofxGuiFacade::draw()
{
    gui.draw();
}
