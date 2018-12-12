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
    Engine::EngineController engineController;
    ofFbo fbo = engineController.fbo;
    
    REQUIRE(fbo.getWidth() == engineController.engine.width);
    REQUIRE(fbo.getHeight() == engineController.engine.height);
}

TEST_CASE("EngineController can add layer", "" ) {
    Engine::EngineController engineController;
    
    engineController.addLayer();
    REQUIRE_THROWS(engineController.getCurrentLayer());
    
    engineController.setLayerIndex(0);
    REQUIRE(engineController.getCurrentLayer());
    
    REQUIRE_THROWS(engineController.setLayerIndex(1));
}
