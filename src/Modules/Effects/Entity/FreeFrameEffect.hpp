//
//  FreeFrameEffect.hpp
//  orange
//
//  Created by Daniel Almeida on 13/01/2019.
//

#ifndef FreeFrameEffect_hpp
#define FreeFrameEffect_hpp

#include <stdio.h>

#include "EffectBase.hpp"
#include "ofxFFPlugin.h"
#include "ofxFFHost.h"

namespace Orange {
    namespace Effects {
        class FreeFrameEffect : public  EffectBase {
            ofxFFGLInstance *instance;
            
        public:
            
            void setInstance(ofxFFGLInstance *_instance);
            
            void draw(float x, float y, float w, float h);
            
            /*!
             renders current frame of the drawable
             */
            void render();
            
            /*!
             Process
             \param ofFbo& fbo
             */
            void process(ofTexture &tex);
        };
    }
}



#endif /* FreeFrameEffect_hpp */
