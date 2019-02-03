//
//  EngineControllerTest.cpp
//  UnitTests
//
//  Created by Daniel Almeida on 10/12/2018.
//

#include <stdio.h>
#include "catch.hpp"

#define private public

#include "EngineController.hpp"

using namespace Orange;



TEST_CASE("EngineController sets the FBO on construction", "" ) {
    Engine::EngineController *engineController;
    shared_ptr<Effects::EffectsController> effectsController;
    shared_ptr<Effects::FreeFrameHostAdapter> ffAdapter;

    ffAdapter = make_shared<Effects::FreeFrameHostAdapter>();
    effectsController = make_shared<Effects::EffectsController>(ffAdapter);
    
    engineController = new Engine::EngineController(effectsController);
    
    ofFbo fbo = engineController->fbo;
    
    REQUIRE(fbo.getWidth() == engineController->engine.width);
    REQUIRE(fbo.getHeight() == engineController->engine.height);
}

TEST_CASE("EngineController can add layer", "" ) {
    Engine::EngineController *engineController;
    shared_ptr<Effects::EffectsController> effectsController;
    shared_ptr<Effects::FreeFrameHostAdapter> ffAdapter;
    
    ffAdapter = make_shared<Effects::FreeFrameHostAdapter>();
    effectsController = make_shared<Effects::EffectsController>(ffAdapter);
    
    engineController = new Engine::EngineController(effectsController);
    
    engineController->addLayer();
    REQUIRE_THROWS(engineController->getCurrentLayer());
    
    engineController->setLayerIndex(0);
    REQUIRE(engineController->getCurrentLayer());
    
    REQUIRE_THROWS(engineController->setLayerIndex(1));
}

TEST_CASE("Can Load Set", "load" ) {
    Engine::EngineController *engineController;
    shared_ptr<Effects::EffectsController> effectsController;
    shared_ptr<Effects::FreeFrameHostAdapter> ffAdapter;
    
    ofSetDataPathRoot("");
    
    ffAdapter = make_shared<Effects::FreeFrameHostAdapter>();
    effectsController = make_shared<Effects::EffectsController>(ffAdapter);
    
    engineController = new Engine::EngineController(effectsController);
    engineController->openSet("data/TestSet01.vjs");
    
    ofJson json = engineController->toJson();
    
    REQUIRE(json["engine"].is_null() == false);
    REQUIRE(json["engine"]["width"] == 640);
    REQUIRE(json["engine"]["height"] == 480);
    REQUIRE(json["layers"].is_null() == false);
    REQUIRE(json["layers"].is_array() == true);
    REQUIRE(json["layers"].size() == 2 );
    REQUIRE(json["layers"].at(0)["visuals"].size() == 2 );
    REQUIRE(json["layers"].at(1)["visuals"].size() == 2 );
}
