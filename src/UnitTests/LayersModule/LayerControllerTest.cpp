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

    REQUIRE(layerControler.layer.get() == NULL);
    REQUIRE(layerControler.getVisual().get() == NULL);
}


TEST_CASE("Can fetch visuals from Layer", "") {
    Layers::LayerController layerControler;
    shared_ptr<Layers::Layer> layer = make_shared<Layers::Layer>();
    shared_ptr<Visuals::Video> video = std::make_shared<Visuals::Video>();
    
    layer->add(video);
    layer->currentVisualIndex = 0;
    
    layerControler.setLayer(layer);
    
    REQUIRE(layerControler.getVisual() == video);
}
