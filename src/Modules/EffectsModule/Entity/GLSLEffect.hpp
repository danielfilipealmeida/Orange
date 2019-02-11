//
//  GLSLEffect.hpp
//  orange
//
//  Created by Daniel Almeida on 03/02/2019.
//

#ifndef GLSLEffect_hpp
#define GLSLEffect_hpp

#include <stdio.h>
#include "EffectBase.hpp"

namespace Orange {
    namespace Effects {
        class GLSLEffect : public  EffectBase {
            ofShader shader;
            ofFbo internalFbo;
            
        public:
            void load(std::string shaderName);
            void process(ofFbo &fbo);
        };
    }
}


#endif /* GLSLEffect_hpp */
