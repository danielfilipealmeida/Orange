//
//  FreeFrameHostAdapterTest.cpp
//  UnitTests
//
//  Created by Daniel Almeida on 13/01/2019.
//

#include <stdio.h>
#include "catch.hpp"

#define private public

#include "FreeFrameHostAdapter.hpp"

using namespace Orange::Effects;

TEST_CASE("FreeFrameHostAdapter loads all plugins on init", "constructor" ) {
    
    FreeFrameHostAdapter* ffHostAdapter = new Orange::Effects::FreeFrameHostAdapter();
    
    vector<string> expectedPluginNames = {"FFGLHeat", "FFGLMirror" };
    
    for (auto expectedPluginName : expectedPluginNames) {
        ofxFFPlugin* ofxFFPlugin = ffHostAdapter->getFreeFramePluginByName(expectedPluginName);
        
        REQUIRE(ofxFFPlugin!=NULL);
    }

}

TEST_CASE("FreeFrameHostAdapter can get a ofxFFPlugin* by it's name", "" ) {
    
}
