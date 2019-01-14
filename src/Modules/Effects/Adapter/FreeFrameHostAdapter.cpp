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
}

ofxFFHost* FreeFrameHostAdapter::getHost() {
    return &host;
}

/*
FreeFramePlugin *FreeFrameHostAdapter::createFreeFramePluginByName(string name) {
    FreeFramePlugin *ffPlugin;
    
    ffPlugin = new FreeFramePlugin(&host, name);
    
    return ffPlugin;
}
 */


FreeFrameEffect FreeFrameHostAdapter::getFreeFameEffectByName(string name)
{
    ofxFFPlugin *plugin = getFreeFramePluginByName(name);
    
    FreeFrameEffect effect;
    
    return effect;
}

ofxFFPlugin *FreeFrameHostAdapter::getFreeFramePluginByName(string name) {
    for(auto plugin : host.loadedPlugins) {
        if (plugin->getName().compare(name) != 0) {
            continue;
        }
        
        return plugin;
    }
    
    return NULL;
}
