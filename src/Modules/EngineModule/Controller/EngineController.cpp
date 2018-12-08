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
    setFbo();
}

void EngineController::setFbo()
{
    fbo.allocate(engine.width, engine.height, GL_RGB);
}

// todo: work with an fbo
void EngineController::render(){
    fbo.begin();
    ofEnableAlphaBlending();
    
    ofClear(0, 0, 0);
    layers.forEach([&](Orange::Layers::Layer *layer) {
        layerController.setLayer(*layer);
        layerController.render();
        layerController.draw(0, 0, engine.width, engine.height);
    });
    ofDisableAlphaBlending();
    fbo.end();
    
    /*
    layers.forEach([&](Orange::Layers::Layer *layer) {
        layerController.setLayer(*layer);
        layerController.draw(x, y, w, h);
    });
     */
    
}

void EngineController::draw(float x, float y, float w, float h) {
    ofColor(255,255,255);
    ofClear(0, 0, 0);
    
    fbo.draw(x, y, w, h);
}

EngineController* EngineController::addLayer()
{
    layers.add(new Orange::Layers::Layer());
    
    return this;
}

EngineController* EngineController::setLayerIndex(int layerIndex)
{
    engine.currentLayerIndex = layerIndex;
    
    return this;
}

EngineController* EngineController::setVisualIndex(int visualIndex)
{
    getCurrentLayer()->currentVisual = visualIndex;
    
    return this;
}

Orange::Layers::Layer* EngineController::getCurrentLayer() {
    if (engine.currentLayerIndex < 0) {
        throw new std::runtime_error("No selected Layer");
    }
    
    if (engine.currentLayerIndex >= layers.count()) {
        throw new std::runtime_error("Invalid Layer");
    }
    
    return layers.getAt(engine.currentLayerIndex);
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
