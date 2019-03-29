//
//  GLSLEffectTest.cpp
//  UnitTests
//
//  Created by Daniel Almeida on 22/03/2019.
//

#include <stdio.h>
#include "catch.hpp"

#define private public

#include "GLSLEffect.hpp"

using namespace Orange::Effects;

TEST_CASE("Configuration is loaded on init", "loadConfiguration" ) {
    GLSLEffect effect;
    
    ofSetDataPathRoot("data");
    
    REQUIRE(effect.config.empty() == true);
    
    ofJson config = GLSLEffect::loadConfiguration("BlurX");
    
    REQUIRE(config["name"] == "Blur X");
    REQUIRE(config["uniforms"].is_array() == true);
    REQUIRE(config["uniforms"].size() == 1);
    REQUIRE(config["uniforms"][0]["value"] == 0.0);
    REQUIRE(config["uniforms"][0]["maximum"] == 20.0);
    REQUIRE(config["uniforms"][0]["minimum"] == 0.0);
    REQUIRE(config["uniforms"][0]["name"] == "blurAmnt");
    REQUIRE(config["uniforms"][0]["type"] == "float");
    
    /*
    ofParameter<float> parameter = effect.parameters.getFloat("value");

    REQUIRE(parameter.getName() == "Blur X");
    REQUIRE(parameter.get() == 0.0);
    REQUIRE(parameter.getMin() == 0.0);
    REQUIRE(parameter.getMax() == 20.0);
     */
}


TEST_CASE("Can set an integer parameter","setIntegerParameter") {
    ofParameterGroup parameters;
    ofJson intUniformConfig = {
        {"name", "int parameter"},
        {"type", "integer"},
        {"minimum", 0},
        {"maximum", 20},
        {"value", 10}
    };
    
    GLSLEffect::setIntegerParameter(intUniformConfig, parameters);
    
    ofParameter<int> parameter = parameters.getInt("int parameter");
    
    REQUIRE(parameter.getName() == "int parameter");
    REQUIRE(parameter.getMax() == 20);
    REQUIRE(parameter.getMin() == 0);
    REQUIRE(parameter.get() == 10);
}


TEST_CASE("Can set a float parameter","setFloatParameter") {
    ofParameterGroup parameters;
    ofJson floatUniformConfig = {
        {"name", "float parameter"},
        {"type", "float"},
        {"minimum", 0.0},
        {"maximum", 20.0},
        {"value", 10.0}
    };
    
    GLSLEffect::setFloatParameter(floatUniformConfig, parameters);
    
    ofParameter<float> parameter = parameters.getFloat("float parameter");
    
    REQUIRE(parameter.getName() == "float parameter");
    REQUIRE(parameter.getMax() == 20.0);
    REQUIRE(parameter.getMin() == 0.0);
    REQUIRE(parameter.get() == 10.0);
}

TEST_CASE("fails when using setFloatParameter to set parameters with wrong types", "setFloatParameter") {
    ofParameterGroup parameters;
    std::vector<string> types = {"", "int", "integer", "f", "floater"};
    
    for(auto type:types) {
        ofJson config = {
            {"name", "parameter"},
            {"type", type},
            {"minimum", 0.0},
            {"maximum", 20.0},
            {"value", 10.0}
        };
        
        GLSLEffect::setFloatParameter(config, parameters);
        
        REQUIRE(parameters.size() == 0);
    }
}

TEST_CASE("fails when using setIntParameter to set parameters with wrong types", "setIntParameter") {
    ofParameterGroup parameters;
    std::vector<string> types = {"", "int", "inteiro", "f", "float"};
    
    for(auto type:types) {
        ofJson config = {
            {"name", "parameter"},
            {"type", type},
            {"minimum", 0},
            {"maximum", 20},
            {"value", 10}
        };
        
        GLSLEffect::setIntegerParameter(config, parameters);
        
        REQUIRE(parameters.size() == 0);
    }
}


TEST_CASE("Throws exception when not passing mandatory fields", "checkMandatoryConfigurationFields") {
    for(auto field:{"", "ipsum", "lorem", "some bad field"}) {
        REQUIRE_THROWS(
                       GLSLEffect::checkMandatoryConfigurationFields({field, 0.0})
                       );
    }
}

TEST_CASE("Doesn't throw when passing the correct fields", "checkMandatoryConfigurationFields") {
    REQUIRE_NOTHROW(
                    GLSLEffect::checkMandatoryConfigurationFields({
        {"name", "parameter"},
        {"uniforms", "a bunch of uniforms that should be an array"}
    })
    );
}

TEST_CASE("Doesn't throw when passing the correct uniforms fields", "checkMandatoryUniformConfigurationFields") {
    REQUIRE_NOTHROW(
                    GLSLEffect::checkMandatoryUniformConfigurationFields({
        {"name", ""},
        {"type", ""},
        {"maximum", ""},
        {"minimum", ""},
        {"value", ""}
    })
                    );
}

/*
 NOTE: this is commented because it needs an OpenGL context.
 */
 /*
TEST_CASE("Can load a shader", "load") {
    GLSLEffect effect;
    
    ofSetDataPathRoot("data");
    
    REQUIRE(effect.isLoaded == false);
    
    effect.load("BlurX");
    
    REQUIRE(effect.isLoaded == true);
}
 */
