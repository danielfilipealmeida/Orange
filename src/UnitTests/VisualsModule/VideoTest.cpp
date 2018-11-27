//
//  VideoTest.cpp
//  UnitTests
//
//  Created by Daniel Almeida on 21/11/2018.
//

#include <stdio.h>
#include "catch.hpp"
#include "Repository.h"
#include "Video.hpp"

#include <iostream>
#include <cstdlib>

using namespace Orange;

TEST_CASE( "Video Repository stores and fetches visuals", "" ) {
    Base::Repository<Visuals::Video> videoRepository;
    Visuals::Video video;
    
    ofSetDataPathRoot("");
    
    string absolutePath = ofFilePath::getAbsolutePath("data/red.mp4");
    video.open(absolutePath);
    
    videoRepository.add(video);
    
    REQUIRE(videoRepository.getAt(0).getPath() == absolutePath);
}

TEST_CASE( "Opening non existing video throws exception", "") {
    Visuals::Video video;
    
    ofSetDataPathRoot("");
    
    string absolutePath = ofFilePath::getAbsolutePath("data/some_non_existing_file.mp4");
    
    REQUIRE_THROWS(video.open(absolutePath));
    
    try {
        video.open(absolutePath);
    }
    catch (std::runtime_error *exception) {
        REQUIRE(exception->what() == "File '" + absolutePath +"' not found.");
    }
    
}
