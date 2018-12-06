//
//  EngineController.cpp
//  orange
//
//  Created by Daniel Almeida on 05/12/2018.
//

#include "EngineController.hpp"

using namespace Orange::Engine;


EngineController::EngineController()
{
    currentLayerIndex = -1;
}

void EngineController::render(){
    layers.forEach([&](Orange::Layers::Layer *layer) {
        layerController.setLayer(*layer);
        layerController.render();
    });
}

void EngineController::draw(float x, float y, float w, float h) {
    ofEnableAlphaBlending();
    layers.forEach([&](Orange::Layers::Layer *layer) {
        layerController.setLayer(*layer);
        layerController.draw(x, y, w, h);
    });
    ofDisableAlphaBlending();
}

EngineController* EngineController::addLayer()
{
    layers.add(new Orange::Layers::Layer());
    
    return this;
}

EngineController* EngineController::setLayerIndex(int layerIndex)
{
    currentLayerIndex = layerIndex;
    
    return this;
}

EngineController* EngineController::setVisualIndex(int visualIndex)
{
    getCurrentLayer()->currentVisual = visualIndex;
    
    return this;
}

Orange::Layers::Layer* EngineController::getCurrentLayer() {
    if (currentLayerIndex < 0) {
        throw new std::runtime_error("No selected Layer");
    }
    
    return layers.getAt(currentLayerIndex);
}

EngineController* EngineController::addVideoToCurrentLayer(std::string path)
{
    Orange::Visuals::Video *video = loadVideo(path);
    return addVisualToCurrentLayer(video);
}

EngineController* EngineController::addVisualToCurrentLayer(Orange::Visuals::BaseVisual *visual) {
    getCurrentLayer()->add(visual);
    
    return this;
}

Orange::Visuals::Video* EngineController::loadVideo(string videoPath) {
    Orange::Visuals::Video* video = new Orange::Visuals::Video();
    try {
        video->open(videoPath);
        video->play();
    }
    catch (std::runtime_error *exception) {
        cout << exception->what();
        
        ofExit(-1);
    }
    
    return video;
}
