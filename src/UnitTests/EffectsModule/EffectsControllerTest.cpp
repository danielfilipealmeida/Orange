#include <stdio.h>
#include "catch.hpp"

#define private public

#include "EffectsController.hpp"

using namespace Orange::Effects;

TEST_CASE("GLSL effects folder is added on init", "constructor" ) {
    ofSetDataPathRoot("data");
    
    EffectsController controller;
    
    REQUIRE(controller.searchPaths.size() == 1);
    REQUIRE(controller.searchPaths.at(0) == "data/effects/glsl");
}

TEST_CASE("Can filter all json files from a vector of files", "filterJsonFiles" ) {
    std::vector<string> fileNames = {"ipsum.txt", "lorem.gif", "laboriosam.json", "magnis.json"};
    std::vector<ofFile> files;
    
    for(auto fileName:fileNames) {
        ofFile file;
        file.open(ofToDataPath(fileName));
        files.push_back(file);
    }
    
    EffectsController controller;
    
    std::vector<ofFile> filteredFiles = controller.filterJsonFiles(files);
    REQUIRE(filteredFiles.size() == 2);
    REQUIRE(filteredFiles.at(0).getFileName() == "laboriosam.json");
    REQUIRE(filteredFiles.at(1).getFileName() == "magnis.json");
    
}

TEST_CASE("Can scan all glsl effects", "scanEffects" ) {
    ofSetDataPathRoot("data");
    
    EffectsController controller;
    controller.scanEffects();
    
    REQUIRE(controller.foundFilters.size() == 5);
    
    std::vector<string> expectedFoundFilters = {"BlurX", "BlurY", "Displacement", "Invert", "Layer"};
    for(auto filterName:expectedFoundFilters) {
        REQUIRE_NOTHROW(
                        controller.foundFilters.at(filterName)
                        );
    }
    
}

TEST_CASE("Can get the names of all found filters", "getEffectsNames" ) {
    ofSetDataPathRoot("data");
    
    EffectsController controller;
    controller.scanEffects();
    
    std::vector<string> foundFiltersNames = controller.getEffectsNames();
    
    REQUIRE(foundFiltersNames.size() == 5);
    REQUIRE(foundFiltersNames.at(0) == "BlurX");
    REQUIRE(foundFiltersNames.at(1) == "BlurY");
    REQUIRE(foundFiltersNames.at(2) == "Displacement");
    REQUIRE(foundFiltersNames.at(3) == "Invert");
    REQUIRE(foundFiltersNames.at(4) == "Layer");
}
