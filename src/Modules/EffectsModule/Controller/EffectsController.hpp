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
        
        typedef enum {
            Output = 0,
            Layer1,
            Layer2,
            Layer3,
            Layer4
        } Target;
        
        class EffectsController {
        private:
            std::map<Target, Orange::Base::Repository<shared_ptr<Orange::Effects::EffectBase>>> effects;
            std::vector<std::filesystem::path> searchPaths;
            std::map<string,std::filesystem::path> foundFilters;
            
        public:
            float width, height;
            
            /*!
             Constructor.
             Sets the FreeFrame host adapter to be used for applying free frame filters and generators
             */
            EffectsController();
            
            /*!
             
             */
            Base::Repository<shared_ptr<Orange::Effects::EffectBase>> *getEffectsRepositoryFromTarget(Target target);
            
            /*!
             Adds a new GLSL effect
             \param string the vert shader
             \param string the frag shader
             */
            void newGLSLEffect(std::string shaderName, Target target);
            
            /*!
             Proccess all the fbo using all the effects
             \param ofFbo &fbo
             */
            void process(ofFbo &fbo, Target target);
            
            /*!
             Apply a lambda to all effects
             \param std::function<void (Orange::Effects::EffectBase)> lambda
             */
            void forEachEffect(Target target, std::function<void (shared_ptr<Orange::Effects::EffectBase>)> lambda);
            
            /*!
             */
            void addSearchPath(string path);
            
            /*!
            */
            void scanEffects();
            
            /*!
             */
            std::vector<string> getEffectsNames();
            
        private:
            std::vector<ofFile> filterJsonFiles(std::vector<ofFile> inputFiles);
        };
    }
}

#endif /* EffectsController_hpp */
