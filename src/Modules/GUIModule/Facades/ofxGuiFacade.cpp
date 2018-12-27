//
//  ofxGuiFacade.cpp
//  orange
//
//  Created by Daniel Almeida on 04/12/2018.
//

#include "ofxGuiFacade.hpp"
#include <string>

using namespace Orange::GUI;

#include "ofxPreview.hpp"

ofxGuiFacade::ofxGuiFacade()
{
    width = 320;
    height = 32;
    x = 10;
    y = 10;
    title = "gui";
}

void ofxGuiFacade::createPanel()
{
    gui.setup(title);
    gui.setPosition(x, y);
    gui.setWidthElements((float) width);
    gui.setUseTTF(true);
}

void ofxGuiFacade::setName(ofParameter<string> name)
{
    gui.setName(name);
}

void ofxGuiFacade::createSlider(ofParameter<float> parameter,
                                std::string title,
                                float minValue,
                                float maxValue)
{
    ofxFloatSlider* slider;
    slider = new ofxFloatSlider();
    slider->setup(parameter.set(title, parameter, minValue, maxValue), width, height);
    gui.add(slider);
}

void ofxGuiFacade::createSlider(ofParameter<int> parameter,
                                std::string title,
                                int minValue,
                                int maxValue)
{
    ofxIntSlider* slider;
    slider = new ofxIntSlider();
    slider->setup(parameter.set(title, parameter, minValue, maxValue), width, height);
    gui.add(slider);
}

void ofxGuiFacade::createLabel(ofParameter<string> parameter)
{
    ofxLabel* label;
    label = new ofxLabel();
    label->setup(parameter, width, height);
    gui.add(label);
}

void ofxGuiFacade::createPreview(ofFbo *fbo)
{
    ofxPreview* preview;
    
    preview = new ofxPreview();
    preview->setup(fbo, width);
    gui.add(preview);
}

void ofxGuiFacade::draw()
{
    gui.draw();
}


void ofxGuiFacade::clear()
{
    gui.clear();
}
