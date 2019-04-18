//
//  PreferencesControllerTest.cpp
//  UnitTests
//
//  Created by Daniel Almeida on 02/02/2019.
//

#include <stdio.h>
#include "catch.hpp"

#define private public

#include "PreferencesController.hpp"


using namespace Orange::Preferences;


TEST_CASE("Calculates the hash of a string", "")
{
    PreferencesController *controller;
    
    controller = new PreferencesController("Test Application");
    
    std::string result = controller->getHash("test value");
    
    REQUIRE(result.compare("6899574726085076102") == 0);
}

TEST_CASE("Calculates md5 of a string", "")
{
    PreferencesController *controller;
    
    controller = new PreferencesController("Test Application");
    std::string result = controller->md5("test value");
    
    REQUIRE(result.compare("098f6bcd4621d373cade4e832627b4f") == 0);
}

#ifdef TARGET_OSX
TEST_CASE("Gets the path to the Preferences folder for OS X", "") {
    PreferencesController *controller;
    
    controller = new PreferencesController("Test Application");
    std::string result = controller->getPreferencesPath();
    
    REQUIRE(result.compare(ofFilePath::getUserHomeDir() + "/Library/Application Support/Test Application") == 0);
}

TEST_CASE("Gets thumbnail full path ", "") {
    PreferencesController *controller;
    
    controller = new PreferencesController("Test Application");
    std::string result = controller->getThumbnailPath("SomeVideo.mp4");
    
    REQUIRE(result.compare(ofFilePath::getUserHomeDir()  + "/Library/Application Support/Test Application/thumbnails/13701071389904099399.mp4") == 0);
}

#endif

#ifdef TARGET_LINUX
TEST_CASE("Gets the path to the Preferences folder for Linux", "") {
    PreferencesController *controller;
    
    controller = new PreferencesController("Test Application");
    std::string result = controller->getPreferencesPath();
    
    REQUIRE(result.compare(ofFilePath::getUserHomeDir()  + "/.test_application") == 0);
}
#endif



TEST_CASE("Can save Thumbnail", "") {
    
}

TEST_CASE("Can load Thumbnail", "" ) {

}
