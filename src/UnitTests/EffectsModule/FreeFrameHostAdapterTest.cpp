//
//  FreeFrameHostAdapterTest.cpp
//  UnitTests
//
//  Created by Daniel Almeida on 13/01/2019.
//
// IMPORTANT: this test is no longer in use because FF effects are not working
//

#include <stdio.h>
#include "catch.hpp"

#define private public

#include "FreeFrameHostAdapter.hpp"

using namespace Orange::Effects;

vector<string> testPlugins{"FFGLHeat", "FFGLMirror", "FFGLTile", "FFGLTime", "FFGLBrightness" };

TEST_CASE("FreeFrameHostAdapter loads all plugins on init", "constructor" ) {
    
    FreeFrameHostAdapter* ffHostAdapter = new Orange::Effects::FreeFrameHostAdapter();
    
    REQUIRE(ffHostAdapter->getHost()->listPluginFiles().size() == testPlugins.size());
}

TEST_CASE("FreeFrameHostAdapter can get a ofxFFPlugin* by it's name", "" ) {
    FreeFrameHostAdapter* ffHostAdapter = new Orange::Effects::FreeFrameHostAdapter();
    vector<string> expectedPluginNames = testPlugins;
    
    for (auto expectedPluginName : expectedPluginNames) {
        ofxFFPlugin* ofxFFPlugin = ffHostAdapter->getFreeFramePluginByName(expectedPluginName);
        REQUIRE(ofxFFPlugin!=NULL);
        REQUIRE(ofxFFPlugin->getName().compare(expectedPluginName) == 0);
    }

}
