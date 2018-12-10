//
//  LayerController.cpp
//  orange
//
//  Created by Daniel Almeida on 03/12/2018.
//

#include "LayerController.hpp"

using namespace Orange::Layers;

LayerController::LayerController() {
    layer = NULL;
}

Orange::Visuals::BaseVisual *LayerController::getVisual() {
    if (
        layer == NULL ||
        layer->currentVisualIndex < 0 ||
        layer->currentVisualIndex >= layer->visuals.count()
        ) {
        return NULL;
    }
    
    return layer->visuals.getAt(layer->currentVisualIndex);
}

void LayerController::setLayer(Layer *_layer) {
    layer = _layer;
}

void LayerController::render() {
    Orange::Visuals::BaseVisual * currentVisual = getVisual();
    
    if (currentVisual == NULL) {
        return;
    }
    
    currentVisual->render();
}

void LayerController::draw(float x, float y, float w, float h) {
    if (layer == NULL) {
        return;
    }
    
    Orange::Visuals::BaseVisual * currentVisual = getVisual();
    
    if (currentVisual == NULL) {
        return;
    }
    
    ofEnableBlendMode(layer->blendMode);
    ofSetColor(255,255,255, layer->alpha * 255);;

    currentVisual->draw(x, y, w, h);
}

