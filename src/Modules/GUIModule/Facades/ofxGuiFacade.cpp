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
    currentPanel = &layerPanel;
}

void ofxGuiFacade::setupPanel()
{
    layerPanel.setWidthElements(PANEL_WIDTH);
    layerPanel.setup("Layer");
    layerPanel.setPosition(0, 0);
    layerPanel.setUseTTF(true);
    
    visualPanel.setWidthElements(PANEL_WIDTH);
    visualPanel.setup("Visual");
    visualPanel.setPosition(PANEL_WIDTH, 0);
    visualPanel.setUseTTF(true);
}

void ofxGuiFacade::setName(ofParameter<string> name)
{
    currentPanel->setName(name);
}

void ofxGuiFacade::createSlider(ofParameter<float> parameter,
                                std::string title,
                                float minValue,
                                float maxValue)
{
    ofxFloatSlider* slider;
    slider = new ofxFloatSlider();
    slider->setup(parameter.set(title, parameter, minValue, maxValue));
    currentPanel->add(slider);
}

void ofxGuiFacade::createSlider(ofParameter<int> parameter,
                                std::string title,
                                int minValue,
                                int maxValue)
{
    ofxIntSlider* slider;
    slider = new ofxIntSlider();
    slider->setup(parameter.set(title, parameter, minValue, maxValue));
    currentPanel->add(slider);
}

void ofxGuiFacade::createLabel(ofParameter<string> parameter)
{
    ofxLabel* label;
    label = new ofxLabel();
    label->setup(parameter);
    currentPanel->add(label);
}

void ofxGuiFacade::createPreview(ofFbo *fbo)
{
    ofxPreview* preview;
    
    preview = new ofxPreview();
    preview->setup(fbo);
    currentPanel->add(preview);
}

void ofxGuiFacade::draw()
{
    layerPanel.draw();
    visualPanel.draw();
}


void ofxGuiFacade::clear()
{
    currentPanel->clear();
}

