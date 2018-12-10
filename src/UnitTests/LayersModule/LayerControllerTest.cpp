//
//  LayerControllerTest.cpp
//  UnitTests
//
//  Created by Daniel Almeida on 09/12/2018.
//

#include <stdio.h>
#include "catch.hpp"

#define private public

#include "LayerController.hpp"
#include "Video.hpp"


using namespace Orange;


TEST_CASE("LayerController initiates without a layer set", "" ) {
    Layers::LayerController layerControler;

    REQUIRE(layerControler.layer == NULL);
    REQUIRE(layerControler.getVisual() == NULL);
}


TEST_CASE("Can fetch visuals from Layer", "") {
    Layers::LayerController layerControler;
    Layers::Layer *layer = new Layers::Layer();
    Visuals::Video *video = new Visuals::Video();
    
    layer->add(video);
    layer->currentVisualIndex = 0;
    
    layerControler.setLayer(layer);
    
    REQUIRE(layerControler.getVisual() == video);
}
