//
//  FreeFrameHostAdapter.cpp
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

#include "FreeFrameHostAdapter.hpp"


using namespace Orange::Effects;

FreeFrameHostAdapter::FreeFrameHostAdapter() {
    host.addPluginFolder("effects/freeframe");
    host.listPluginFiles();
    host.loadAllPlugins();
    ofDisableArbTex();
}

ofxFFHost* FreeFrameHostAdapter::getHost() {
    return &host;
}

FreeFrameEffect FreeFrameHostAdapter::getFreeFameEffectByName(string name)
{
    ofxFFPlugin *plugin = getFreeFramePluginByName(name);
    
    FreeFrameEffect effect;
    
    return effect;
}

ofxFFPlugin *FreeFrameHostAdapter::getFreeFramePluginByName(string name) {
    return host.getPlugin(name);
}

shared_ptr<FreeFrameEffect>FreeFrameHostAdapter::newFreeFrameEffectByName(string name,
                                                                float width,
                                                                float height)
{
    shared_ptr<FreeFrameEffect> ffFx = make_shared<FreeFrameEffect>();
    
    ofxFFPlugin *plugin = getFreeFramePluginByName(name);
    plugin->init();
    
    if (plugin->getCaps(FF_CAP_PROCESSOPENGL)) {
        ofxFFGLInstance *instance = plugin->createGLInstance(width, height);
        instance->setParameter(0, 1);
        ffFx->setPluginAndInstance(plugin, instance);
    }
    
    cout << "parameter count: " << plugin->getParameterCount() << endl;
    return ffFx;
}

/*
void FreeFrameHostAdapter::loadAllPlugins() {
    host->loadAllPlugins();
}
 */
