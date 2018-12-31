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
    setCurrentPanel(PreviewsPanel);
}

void ofxGuiFacade::setupPanel()
{
    previewsPanel.setWidthElements(PANEL_WIDTH);
    previewsPanel.setup("Previews");
    previewsPanel.setPosition(0, 0);
    previewsPanel.setUseTTF(true);
    
    layerPanel.setWidthElements(PANEL_WIDTH);
    layerPanel.setup("Layer");
    layerPanel.setPosition(PANEL_WIDTH, 0);
    layerPanel.setUseTTF(true);
    
    visualPanel.setWidthElements(PANEL_WIDTH);
    visualPanel.setup("Visual");
    visualPanel.setPosition(PANEL_WIDTH * 2, 0);
    visualPanel.setUseTTF(true);
}

void ofxGuiFacade::setName(ofParameter<string> name)
{
    currentPanel->setName(name);
}

void ofxGuiFacade::createSlider(ofParameter<float> parameter,
                                std::string title,
                                float minValue,
                                float maxValue,
                                string name)
{
    ofxFloatSlider* slider;
    slider = new ofxFloatSlider();
    slider->setup(parameter.set(title, parameter, minValue, maxValue), PANEL_WIDTH, PANEL_HEIGHT);
    currentPanel->add(slider);
}

void ofxGuiFacade::createSlider(ofParameter<int> parameter,
                                std::string title,
                                int minValue,
                                int maxValue,
                                string name)
{
    ofxIntSlider* slider;
    slider = new ofxIntSlider();
    slider->setup(parameter.set(title, parameter, minValue, maxValue), PANEL_WIDTH, PANEL_HEIGHT);
    currentPanel->add(slider);
}

void ofxGuiFacade::createLabel(ofParameter<string> parameter, string name)
{
    ofxLabel* label;
    label = new ofxLabel();
    label->setup(parameter, PANEL_WIDTH, PANEL_HEIGHT);
    currentPanel->add(label);
}

void ofxGuiFacade::createLabel(string text, string name)
{
    ofxLabel* label;
    label = new ofxLabel();
    label->setup(text, PANEL_WIDTH, PANEL_HEIGHT);
    currentPanel->add(label);
}

ofxPreview* ofxGuiFacade::createPreview(ofFbo *fbo, string name)
{
    ofxPreview* preview;
    
    preview = new ofxPreview();
    preview->setup(fbo);
    preview->setName(name);
    currentPanel->add(preview);
    
    return preview;
}

void ofxGuiFacade::draw()
{
    previewsPanel.draw();
    layerPanel.draw();
    visualPanel.draw();
}


void ofxGuiFacade::clear()
{
    currentPanel->clear();
}

void ofxGuiFacade::setCurrentPanel(PanelNames panelName)
{
    switch (panelName) {
        case PreviewsPanel:
            currentPanel = &previewsPanel;
            break;
            
        case LayerPanel:
            currentPanel = &layerPanel;
            break;
            
        case VisualPanel:
            currentPanel = &visualPanel;
            break;
    }
}
