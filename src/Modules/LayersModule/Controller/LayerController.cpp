//
//  LayerController.cpp
//  orange
//
//  Created by Daniel Almeida on 03/12/2018.
//

#include "LayerController.hpp"

using namespace Orange::Layers;


Orange::Visuals::BaseVisual *LayerController::getVisual(Orange::Layers::Layer &layer) {
    if (layer.currentVisual < 0 || layer.currentVisual >= layer.visuals.count()) {
        return NULL;
    }
    
    return  layer.visuals.getAt(layer.currentVisual);
}

void LayerController::setLayer(Layer _layer) {
    layer = _layer;
}

void LayerController::render() {
    Orange::Visuals::BaseVisual * currentVisual = getVisual(layer);
    
    if (currentVisual == NULL) {
        return;
    }
    
    currentVisual->render();
}

void LayerController::draw(float x, float y, float w, float h) {
    Orange::Visuals::BaseVisual * currentVisual = getVisual(layer);
    
    if (currentVisual == NULL) {
        return;
    }
    
    currentVisual->draw(x, y, w, h);
}

