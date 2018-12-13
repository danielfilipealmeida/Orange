//
//  LayerTest.cpp
//  UnitTests
//
//  Created by Daniel Almeida on 09/12/2018.
//

#include <stdio.h>
#include "catch.hpp"
#include "Layer.hpp"
#include "Video.hpp"

using namespace Orange;


TEST_CASE( "Layer is initiated without visuals", "" ) {

    Layers::Layer *layer;
    shared_ptr<Visuals::BaseVisual> visual;
    
    layer = new Layers::Layer();
    
    REQUIRE(layer->getVisualsCount() == 0);
    
    visual = layer->getCurrentVisual();
    
    REQUIRE(visual.get() == NULL);
}


TEST_CASE("Can add Visual to Layer", "") {
    Layers::Layer *layer;
    shared_ptr<Visuals::BaseVisual> visual;
    
    layer = new Layers::Layer();
    
    visual = std::make_shared<Visuals::Video>();
    layer->add(visual);
    
    REQUIRE(layer->getVisualsCount() == 1);
}

TEST_CASE("Can get Visual from Layer", "") {
    Layers::Layer *layer;
    shared_ptr<Visuals::BaseVisual> visual;
    
    layer = new Layers::Layer();
    
    visual = std::make_shared<Visuals::Video>();
    layer->add(visual);
    layer->currentVisualIndex = 0;
    REQUIRE(layer->getCurrentVisual() == visual);
}

TEST_CASE("Can unset visual on Layer", "") {
    Layers::Layer *layer;
    shared_ptr<Visuals::BaseVisual> visual;
    
    layer = new Layers::Layer();
    
    visual = std::make_shared<Visuals::Video>();
    layer->add(visual);
    
    layer->currentVisualIndex = 0;
    layer->currentVisualIndex = -1;
    REQUIRE(layer->getCurrentVisual().get() == NULL);
}
