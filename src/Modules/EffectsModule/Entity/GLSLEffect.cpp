//
//  GLSLEffect.cpp
//  orange
//
//  Created by Daniel Almeida on 03/02/2019.
//

#include "GLSLEffect.hpp"

using namespace Orange::Effects;



void GLSLEffect::checkMandatoryConfigurationFields(ofJson config)
{
    const std::vector<string> mandatoryConfigurationFields = {"name", "uniforms"};
    
    for(auto field:mandatoryConfigurationFields) {
        auto value = config[field];
        
        if (value.is_null()) throw new std::runtime_error("Mandatory field " + field + " not found.");
    }
}

void GLSLEffect::checkMandatoryUniformConfigurationFields(ofJson config) {
    const std::vector<string> mandatoryUniformConfigurationFields = {"name", "type", "minimum", "maximum", "value"};
    
    for(auto field:mandatoryUniformConfigurationFields) {
        auto value = config[field];
        
        if (value.is_null()) throw new std::runtime_error("Mandatory uniform field " + field + " not found.");
    }
}


void GLSLEffect::setIntegerParameter(ofJson uniformConfig, ofParameterGroup &_parameters)
{
    if (uniformConfig["type"] != "integer") return;
    
    ofParameter<int> parameter;
    parameter.set(
                  uniformConfig["name"],
                  uniformConfig["value"],
                  uniformConfig["minimum"],
                  uniformConfig["maximum"]);
    _parameters.add(parameter);
}

void GLSLEffect::setFloatParameter(ofJson uniformConfig, ofParameterGroup &_parameters)
{
    if (uniformConfig["type"] != "float") return;
    
    ofParameter<float> parameter;
    parameter.set(
                  uniformConfig["name"],
                  uniformConfig["value"],
                  uniformConfig["minimum"],
                  uniformConfig["maximum"]);
    _parameters.add(parameter);
}

void GLSLEffect::setVec2Parameter(ofJson uniformConfig, ofParameterGroup &_parameters)
{
    if (uniformConfig["type"] != "vec2") return;
    
    ofParameter<glm::vec2> parameter;
    parameter.set(
                  uniformConfig["name"],
                  glm::vec2(uniformConfig["value"][0], uniformConfig["value"][1]),
                  glm::vec2(uniformConfig["minimum"][0], uniformConfig["minimum"][1]),
                  glm::vec2(uniformConfig["maximum"][0], uniformConfig["maximum"][1]));
    _parameters.add(parameter);
    //glm::vec2
}

void GLSLEffect::setParameters(ofJson uniforms, ofParameterGroup &_parameters) {
    for(auto uniformConfig:uniforms)
    {
        checkMandatoryUniformConfigurationFields(uniformConfig);
        
        try {
            GLSLEffect::setIntegerParameter(uniformConfig, _parameters);
            GLSLEffect::setFloatParameter(uniformConfig, _parameters);
            GLSLEffect::setVec2Parameter(uniformConfig, _parameters);
            
        }
        catch(std::runtime_error *exception) {
            ofLogError(exception->what());
        }
    }
}

void GLSLEffect::load(std::string shaderName)
{
    config = loadConfiguration(shaderName);
    isLoaded = shader.load("effects/glsl/" + shaderName);

    GLSLEffect::setParameters(config["uniforms"], parameters);
    
    shader.setUniforms(parameters);
    parameters.setName(config["name"]);
}

ofJson GLSLEffect::loadConfiguration(std::string shaderName)
{
    std::string path = "effects/glsl/" + shaderName + ".json";
    ofJson config = ofLoadJson(path);
    
    checkMandatoryConfigurationFields(config);
    
    return config;
}

void GLSLEffect::process(ofFbo &fbo)
{
    if (!internalFbo.isAllocated()) {
        internalFbo.allocate(fbo.getWidth(), fbo.getHeight());
    }
    
    internalFbo.begin();
    shader.begin();
    shader.setUniforms(parameters);
    fbo.draw(0,0);
    shader.end();
    internalFbo.end();
    std::swap(fbo, internalFbo);
}

