//
//  Layer.cpp
//  orange
//
//  Created by Daniel Almeida on 17/11/2018.
//

#include "Layer.hpp"
#include "BaseVisual.hpp"

using namespace Orange::Layers;


void Layer::draw(float x, float y, float w, float h) {
    if (currentVisual < 0 || currentVisual >= visuals.count()) {
        return;
    }
    
    visuals.getAt(currentVisual)->draw(x, y, w, h);
}

void Layer::render() {
    if (currentVisual < 0 || currentVisual >= visuals.count()) {
        return;
    }
    
    visuals.getAt(currentVisual)->render();
}


void Layer::add(Orange::Visuals::BaseVisual* visual)
{
    visuals.add(visual);
}
