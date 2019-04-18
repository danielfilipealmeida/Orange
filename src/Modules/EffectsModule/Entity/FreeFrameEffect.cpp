//
//  FreeFrameEffect.cpp
//  orange
//
//  Created by Daniel Almeida on 13/01/2019.
//
// IMPORTANT:
// FreeFrame filters are currently considered incompatible with GLSL filters.
// This is because FreeFrame filters require ArbTex to be disabled while
// GLSL requires the oposite.
// Also, the used ofxFreeFrame is tweaked to compile on OSX 10.14 and isn't
// available, making this code not portable.
// Because of this, FreeFrame filters have been removed from the Application.
// The code maintains for reference

#include "FreeFrameEffect.hpp"
#include "ofMain.h"

using namespace Orange::Effects;




void FreeFrameEffect::setPluginAndInstance(ofxFFPlugin *_plugin, ofxFFGLInstance *_instance) {
    instance = _instance;
    plugin = _plugin;
    name.set(plugin->getName());
    updateParameters();
}

void FreeFrameEffect::clearListeners() {
    for(auto listener : listeners) {
        delete listener;
    }
    listeners.clear();
}

void FreeFrameEffect::updateParameters()
{
    parameters.clear();
    clearListeners();
    for(auto f = 0; f < plugin->getParameterCount(); f++) {
        ofParameter<float> parameter;
        parameter.set(plugin->getParameterName(f), instance->getParameter(f));
        parameter.setMax(1);
        parameter.setMin(0);
        parameters.push_back(parameter);
        
        FreeFrameEffectListener *listener = new FreeFrameEffectListener(instance, f);
        parameter.addListener(listener, &FreeFrameEffectListener::update);
        listeners.push_back(listener);
    }
}

void FreeFrameEffect::process(ofTexture &tex)
{
    instance->processFrame(tex);
}

void FreeFrameEffect::forEachParameter(std::function<void (ofParameter<float>)> lambda)
{
    for(auto parameter : parameters) {
        lambda(parameter);
    }
}
