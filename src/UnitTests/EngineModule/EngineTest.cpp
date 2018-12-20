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
    
    
}
