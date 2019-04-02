//
//  ofxGuiFacade.cpp
//  orange
//
//  Created by Daniel Almeida on 04/12/2018.
//

#include "ofxGuiFacade.hpp"
#include <string>
#include "ofxButton.h"
#include "functional"
#include "ofxPreview.hpp"

using namespace Orange::GUI;


class CallbackClass {
    std::function<void()> callback;
public:
    CallbackClass(std::function<void()> _callback) : callback(_callback){};
    
    void callbackMethod(){
        callback();
    };
};



#define USE_DEFINED_STRING(str1, str2) !str1.empty() ? str1 : str2

#define NAME_OR_RANDOM(name) !name.empty() ? name : "element_" + ofToString(time(NULL))

ofxGuiFacade::ofxGuiFacade()
{
    panelsMap[PreviewsPanel] = &previewsPanel;
    panelsMap[LayerPanel] = &layerPanel;
    panelsMap[VisualPanel] = &visualPanel;
    panelsMap[EffectsPanel] = &effectsPanel;
    panelsMap[EffectsListPanel] = &effectsListPanel;
    
    setCurrentPanel(PreviewsPanel);
}

void ofxGuiFacade::setupPreviewPanel() {
    previewsPanel.setWidthElements(PANEL_WIDTH);
    previewsPanel.setup("Previews");
    previewsPanel.setPosition(0, 0);
    previewsPanel.setUseTTF(true);
}

void ofxGuiFacade::setupLayersPanel() {
    layerPanel.setWidthElements(PANEL_WIDTH);
    layerPanel.setup("Layer");
    layerPanel.setPosition(PANEL_WIDTH, 0);
    layerPanel.setUseTTF(true);
}

void ofxGuiFacade::setupVisualPanel() {
    visualPanel.setWidthElements(PANEL_WIDTH);
    visualPanel.setup("Visual");
    visualPanel.setPosition(PANEL_WIDTH * 2, 0);
    visualPanel.setUseTTF(true);
}

void ofxGuiFacade::setupEffectsPanel() {
    effectsPanel.setWidthElements(PANEL_WIDTH);
    effectsPanel.setup("Effects");
    effectsPanel.setPosition(PANEL_WIDTH * 3, 0);
    effectsPanel.setUseTTF(true);
}

void ofxGuiFacade::setupEffectsListPanel()
{
    effectsListPanel.setWidthElements(PANEL_WIDTH);
    effectsListPanel.setup("Effects List");
    effectsListPanel.setPosition(0,0);
    effectsListPanel.setUseTTF(true);
}

void ofxGuiFacade::setupPanels()
{
    setupPreviewPanel();
    setupLayersPanel();
    setupVisualPanel();
    setupEffectsPanel();
    setupEffectsListPanel();
}

void ofxGuiFacade::setName(ofParameter<string> name)
{
    currentPanel->setName(name);
}


void ofxGuiFacade::createButton(std::string caption, std::function<void()> callback)
{
    ofxButton *button;
    
    button = new ofxButton();
    button->setup(caption);
    button->setName(caption);
    
    if (callback!=NULL) {
        CallbackClass *callbackObj = new CallbackClass(callback);
        button->addListener(callbackObj, &CallbackClass::callbackMethod);
    }
    
    currentPanel->add(button);
}


void ofxGuiFacade::createParameterGroup(ofParameterGroup parameters)
{
    currentPanel->add(parameters);
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
    label->setup(ofToString(""), PANEL_WIDTH, PANEL_HEIGHT);
    label->setName(parameter.get());
    label->setBackgroundColor(ofColor::orangeRed);
    label->setFillColor(ofColor::black);
    label->setTextColor(ofColor::black);
    
    currentPanel->add(label);
}

void ofxGuiFacade::createLabel(string text)
{
    ofxLabel* label;
    label = new ofxLabel();
    label->setup(NULL, NULL, PANEL_WIDTH, PANEL_HEIGHT);

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

ofxList<std::string>* ofxGuiFacade::createStringList(ofParameter<vector<std::string>> value, string name)
{
    ofxList<std::string>* list;
    
    list = new ofxList<std::string>();
    list->setup(value, PANEL_WIDTH, PANEL_WIDTH * 3.0 / 4.0);
    list->setName(NAME_OR_RANDOM(name));
    currentPanel->add(list);
    
    return list;
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
    effectsPanel.draw();
}

void ofxGuiFacade::drawPanel(PanelNames panel) {
    panelsMap[panel]->draw();
}


void ofxGuiFacade::clear()
{
    for (auto controlName : currentPanel->getControlNames())
    {
        ofxBaseGui *control = currentPanel->getControl(controlName);
    }
    currentPanel->clear();
}

void ofxGuiFacade::setCurrentPanel(PanelNames panelName)
{
    currentPanel = panelsMap.at(panelName);
}


void ofxGuiFacade::mouseEventOnPanel(PanelNames panelName, ofMouseEventArgs & args)
{
    ofxPanel* panel = panelsMap.at(panelName);
    
    switch (args.type) {
        case ofMouseEventArgs::Pressed:
            panel->mousePressed(args);
            break;
            
        default:
            break;
    }

}
