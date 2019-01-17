//
//  FreeFrameHostAdapter.hpp
//  orange
//
//  Created by Daniel Almeida on 13/01/2019.
//

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
