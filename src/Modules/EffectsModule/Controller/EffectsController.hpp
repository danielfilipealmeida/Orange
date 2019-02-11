//
//  EffectsController.hpp
//  orange
//
//  Created by Daniel Almeida on 13/01/2019.
//

#ifndef EffectsController_hpp
#define EffectsController_hpp

#include <stdio.h>

#include "GLSLEffect.hpp"
#include "EffectBase.hpp"
#include "Repository.hpp"

namespace Orange {
    namespace Effects {
        class EffectsController {
            Orange::Base::Repository<shared_ptr<Orange::Effects::EffectBase>> effects;
          
        public:
            float width, height;
            
            /*!
             Constructor.
             Sets the FreeFrame host adapter to be used for applying free frame filters and generators
             */
            EffectsController();
            
            /*!
             Adds a new GLSL effect
             \param string the vert shader
             \param string the frag shader
             */
            void newGLSLEffect(std::string shaderName);
            
            /*!
             Proccess all the fbo using all the effects
             \param ofFbo &fbo
             */
            void process(ofFbo &fbo);
            
            /*!
             Apply a lambda to all effects
             \param std::function<void (Orange::Effects::EffectBase)> lambda
             */
            void forEachEffect(std::function<void (shared_ptr<Orange::Effects::EffectBase>)> lambda);
        };
    }
}

#endif /* EffectsController_hpp */
