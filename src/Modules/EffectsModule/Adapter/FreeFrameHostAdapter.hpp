//
//  FreeFrameHostAdapter.hpp
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

#ifndef FreeFrameHostAdapter_hpp
#define FreeFrameHostAdapter_hpp

#include <stdio.h>

#include "ofxFFHost.h"
#include "FreeFrameEffect.hpp"
#include "FreeFrameEffect.hpp"

namespace Orange {
    namespace Effects {
        class FreeFrameHostAdapter {
            ofxFFHost host;
            
        public:
            FreeFrameHostAdapter();
            
            /*! THIS SHOULD NOT BE NEEDED!!! WORK TO HAVE THIS ELIMINATED*/
            ofxFFHost* getHost();
            
            shared_ptr<FreeFrameEffect>newFreeFrameEffectByName(string name,
                                                      float width,
                                                      float height);
            
        private:
            
            
            FreeFrameEffect getFreeFameEffectByName(string name);
            ofxFFPlugin* getFreeFramePluginByName(string name);
            
            /*!
             Loads all Plugins and get them into the app
             */
            //void loadAllPlugins();
        };
    }
}

#endif /* FreeFrameHostAdapter_hpp */
