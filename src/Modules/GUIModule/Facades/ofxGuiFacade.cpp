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

#define USE_DEFINED_STRING(str1, str2) !str1.empty() ? str1 : str2

#define NAME_OR_RANDOM(name) !name.empty() ? name : "element_" + ofToString(time(NULL))

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
                                string name)
{
    ofxFloatSlider* slider;
    slider = new ofxFloatSlider();
    slider->setup(parameter);
    slider->setName(NAME_OR_RANDOM(name));
    currentPanel->add(slider);
}

void ofxGuiFacade::createSlider(ofParameter<float> parameter,
                                std::string title,
                                float minValue,
                                float maxValue)
{
    if (currentPanel->getControl(title)) {
        return;
    }
    
    ofxFloatSlider* slider;
    slider = new ofxFloatSlider();
    slider->setup(parameter.set(NAME_OR_RANDOM(title), parameter, minValue, maxValue), PANEL_WIDTH, PANEL_HEIGHT);
    
    currentPanel->add(slider);
}

void ofxGuiFacade::createSlider(ofParameter<int> parameter,
                                std::string title,
                                int minValue,
                                int maxValue)
{
    if (currentPanel->getControl(title)) {
        return;
    }
    
    ofxIntSlider* slider;
    slider = new ofxIntSlider();
    slider->setup(parameter.set(NAME_OR_RANDOM(title), parameter, minValue, maxValue), PANEL_WIDTH, PANEL_HEIGHT);
    
    currentPanel->add(slider);
}

void ofxGuiFacade::createLabel(ofParameter<string> parameter)
{
    ofxLabel* label;
   
    label = new ofxLabel();
    label->setup(parameter, PANEL_WIDTH, PANEL_HEIGHT);
    label->setName(parameter.get());
    
    currentPanel->add(label);
}

void ofxGuiFacade::createLabel(string text)
{
    ofxLabel* label;
    label = new ofxLabel();
    label->setup(text, PANEL_WIDTH, PANEL_HEIGHT);
    label->setName(text);
    
    currentPanel->add(label);
}



ofxMatrix<ofImage *>* ofxGuiFacade::createImageMatrix(ofParameter<vector<ofImage *>> value, string name)
{
    ofxMatrix<ofImage *> *matrix;
    
    matrix = new ofxMatrix<ofImage *>();
    matrix->setup(value, PANEL_WIDTH, PANEL_WIDTH * 3.0 / 4.0);
    matrix->setName(NAME_OR_RANDOM(name));
    currentPanel->add(matrix);
    
    return matrix;
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

void ofxGuiFacade::createNavigator(ofParameter<ofxPaginatedInterface *> element, string name)
{
    ofxNavigator* navigator;
    
    navigator = new ofxNavigator();
    navigator->setup(element);
    navigator->setName(NAME_OR_RANDOM(name));
    currentPanel->add(navigator);
    
}
void ofxGuiFacade::draw()
{
    previewsPanel.draw();
    layerPanel.draw();
    visualPanel.draw();
}


void ofxGuiFacade::clear()
{
    for (auto controlName : currentPanel->getControlNames())
    {
        ofxBaseGui *control = currentPanel->getControl(controlName);
        //control->getParameter().
    }
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
