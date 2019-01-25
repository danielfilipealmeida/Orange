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

void ofxGuiFacade::createSlider(ofParameter<float> parameter)
{
    ofxFloatSlider* slider;
    slider = new ofxFloatSlider();
    slider->setup(parameter);
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
    slider->setup(parameter.set(title, parameter, minValue, maxValue), PANEL_WIDTH, PANEL_HEIGHT);
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
    slider->setup(parameter.set(title, parameter, minValue, maxValue), PANEL_WIDTH, PANEL_HEIGHT);
    currentPanel->add(slider);
}

void ofxGuiFacade::createLabel(ofParameter<string> parameter, string name)
{
    ofxLabel* label;
    label = new ofxLabel();
    label->setup(parameter, PANEL_WIDTH, PANEL_HEIGHT);
    if (!name.empty()) {
        label->setName(name);
    }
    
    currentPanel->add(label);
}

void ofxGuiFacade::createLabel(string text)
{
    ofxLabel* label;
    label = new ofxLabel();
    label->setup(text, PANEL_WIDTH, PANEL_HEIGHT);
    currentPanel->add(label);
}



ofxMatrix<ofTexture *>* ofxGuiFacade::createImageMatrix(ofParameter<vector<ofTexture *>> value)
{
    ofxMatrix<ofTexture *> *matrix;
    
    matrix = new ofxMatrix<ofTexture *>();
    matrix->setup(value, PANEL_WIDTH, PANEL_WIDTH * 3.0 / 4.0);
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

void ofxGuiFacade::createNavigator(ofParameter<ofxPaginatedInterface *> element)
{
    ofxNavigator* navigator;
    
    navigator = new ofxNavigator();
    navigator->setup(element);
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
