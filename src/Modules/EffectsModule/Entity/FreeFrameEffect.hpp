//
//  FreeFrameEffect.hpp
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

#ifndef FreeFrameEffect_hpp
#define FreeFrameEffect_hpp

#include <stdio.h>

#include "EffectBase.hpp"
#include "ofxFFPlugin.h"
#include "ofxFFHost.h"

namespace Orange {
    namespace Effects {
        
        /*!
         Class that implement the listener of each parameter
         */
        class FreeFrameEffectListener  {
            unsigned int parameterNumber;
            ofxFFGLInstance *instance;
        public:
            FreeFrameEffectListener(ofxFFGLInstance *_instance, unsigned int _parameterNumber) {
                instance = _instance;
                parameterNumber = _parameterNumber;
            };
            void update(float &value) {
                instance->setParameter(parameterNumber, value);
            };
        };
        
        
        class FreeFrameEffect : public  EffectBase {
            ofxFFGLInstance *instance;
            ofxFFPlugin *plugin;
            
            vector<FreeFrameEffectListener *>listeners;
            
            /*!
             Cleans all the currently set listeners
             */
            void clearListeners();
            
            /*!
             Update all parameters and their listeners
             */
            void updateParameters();
            
        public:
            
            ofParameter<string> name;
            vector<ofParameter<float>> parameters;
            
            
            /*!
             Configures this FreeFrameEffect
             \param ofxFFPlugin *_plugin
             \param ofxFFGLInstance *_instance
             */
            void setPluginAndInstance(ofxFFPlugin *_plugin, ofxFFGLInstance *_instance);
            
            /*!
             Process
             \param ofFbo& fbo
             */
            void process(ofTexture &tex);
            
            void process(ofFbo &fbo) {};
            
            /*!
             Apply a lambda to each parameter
             \param
             */
            void forEachParameter(std::function<void (ofParameter<float>)> lambda);
        };
    }
}



#endif /* FreeFrameEffect_hpp */
