//
//  FreeFrameHostAdapter.cpp
//  orange
//
//  Created by Daniel Almeida on 13/01/2019.
//

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
