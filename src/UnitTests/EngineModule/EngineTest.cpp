//
//  EngineTest.cpp
//  UnitTests
//
//  Created by Daniel Almeida on 20/12/2018.
//

#include <stdio.h>
#include "catch.hpp"
#include "Engine.hpp"

using namespace Orange::Engine;

TEST_CASE("Can get Engine json", "toJson" ) {
    Engine engine;
    
     ofJson json = engine.toJson();
    
    REQUIRE(json["width"] == 640);
    REQUIRE(json["height"] == 480);
    REQUIRE(json["currentLayerIndex"] == -1);
}

TEST_CASE("Can set Engine attributes from json", "setFromJson" ) {
    Engine engine;
    
    engine.setFromJson({
        {"width", 720},
        {"height", 576},
        {"currentLayerIndex", 0}
    });
 
    REQUIRE(engine.width == 720);
    REQUIRE(engine.height == 576);
    REQUIRE(engine.currentLayerIndex == 0);
}

