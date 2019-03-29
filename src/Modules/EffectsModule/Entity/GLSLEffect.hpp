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
            ofParameterGroup parameters;
            ofJson config;
            bool isLoaded = false;
            
            /*!
             Checks for the mandatory fields on the configuration json
             Can be improve to also check for types
             \param config
             */
            static void checkMandatoryConfigurationFields(ofJson config);
            
            /*!
             
             */
            static void checkMandatoryUniformConfigurationFields(ofJson config);
            
            /*!
             Loads the configuration of a GLSL shader stored in a json file
             */
            static ofJson loadConfiguration(std::string shaderName);

            /*!
             Sets the glsl shader effect parameters data using the uniforms configuration.
             
             Important: all parameters with wrong types will be ignored
             
             \param uniforms the configuration
             \param parameters the parameters
             */
            static void setParameters(ofJson uniforms, ofParameterGroup &_parameters);
       
            /*!
             Sets an integer parameter of the shader effect
             
             Important: will ignore all non integer parameters
             
             \param uniformConfig the configuration of the paramenter/uniform
             \param parameters the parameters
             */
            static void setIntegerParameter(ofJson uniformConfig, ofParameterGroup &_parameters);
            
            /*!
             Sets a floar parameter of the shader effect
             
             Important: will ignore all non float parameters
             
            \param uniformConfig the configuration of the paramenter/uniform
             \param parameters the parameters
             */
            static void setFloatParameter(ofJson uniformConfig, ofParameterGroup &_parameters);
            
            
            static void setVec2Parameter(ofJson uniformConfig, ofParameterGroup &_parameters);
            
            /*!
             Load a shader
             \param shaderName
             */
            void load(std::string shaderName);
 
            /*!
             Proccess an fbo using the current parameters of the effect
             \param fbo
             */
            void process(ofFbo &fbo);
            
        };
    }
}


#endif /* GLSLEffect_hpp */
