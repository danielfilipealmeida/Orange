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

void EngineController::render(){
    
    layers.forEach([&](shared_ptr<Orange::Layers::Layer> layer) {
        layerController.setLayer(layer);
        layerController.render();
    });
    
    fbo.begin();
    ofClear(0, 0, 0);
    layers.forEach([&](shared_ptr<Orange::Layers::Layer> layer) {
        layerController.setLayer(layer);
        layerController.draw(0, 0, engine.width, engine.height);
    });
    fbo.end();
}

void EngineController::draw(float x, float y, float w, float h) {
    ofColor(255,255,255);
    ofClear(0, 0, 0);
    
    fbo.draw(x, y, w, h);
}

shared_ptr<Orange::Layers::Layer> EngineController::addLayer()
{
    shared_ptr<Layers::Layer> layer = std::make_shared<Layers::Layer>();
    layer->setFbo(engine.width, engine.height);
    
    layers.add(layer);
    
    return layer;
}

void EngineController::setLayerIndex(int layerIndex)
{
    if (layerIndex >= layers.count()) {
        throw new std::runtime_error("Layer doesn't exist.");
    }
    engine.currentLayerIndex = layerIndex;
}

void EngineController::setVisualIndex(int visualIndex)
{
    getCurrentLayer()->currentVisualIndex = visualIndex;
}

void EngineController::playVisual(int visualIndex)
{
    if (visualIndex < 0 || getCurrentLayer()->getVisualsCount() <= visualIndex)
    {
        return;
    }
    
    
    if (getCurrentLayer()->currentVisualIndex == visualIndex) {
        // todo: retrigger!
    }
    
    
    shared_ptr<Visuals::BaseVisual> previousVisual = getCurrentLayer()->getCurrentVisual();
    if (previousVisual != NULL)
    {
        previousVisual->stop();
    }
    
    setVisualIndex(visualIndex);
    
    shared_ptr<Visuals::BaseVisual> currentVisual = getCurrentLayer()->getCurrentVisual();
    
    if (currentVisual != NULL) {
        currentVisual->play();
    }
}


void EngineController::stopVisual()
{
    setVisualIndex(0);
}


shared_ptr<Orange::Layers::Layer> EngineController::getCurrentLayer() {
    if (engine.currentLayerIndex < 0 || engine.currentLayerIndex >= layers.count()) {
        throw new std::runtime_error("No selected Layer");
    }
    
    if (engine.currentLayerIndex >= layers.count()) {
        throw new std::runtime_error("Invalid Layer");
    }
    
    return layers.getAt(engine.currentLayerIndex);
}

void EngineController::addVideoToCurrentLayer(string path)
{
    shared_ptr<Visuals::Video> video = loadVideo(path);
    return addVisualToCurrentLayer(video);
}

void EngineController::addVisualToCurrentLayer(shared_ptr<Orange::Visuals::BaseVisual> visual) {
    getCurrentLayer()->add(visual);
}

shared_ptr<Orange::Visuals::Video> EngineController::loadVideo(string path) {
    shared_ptr<Orange::Visuals::Video> video = std::make_shared<Orange::Visuals::Video>(Orange::Visuals::Video());
    try {
        video->open(path);
    }
    catch (std::runtime_error *exception) {
        cout << exception->what();
    }
    
    return video;
}


void EngineController::save(std::string filepath)
{
    ofJson json = toJson();
    
    ofSaveJson(filepath, json);
}

void EngineController::open(std::string filepath)
{
    
}

ofJson EngineController::toJson()
{
    ofJson json;
    
    json["engine"] = engine.toJson();
    json["layers"] = layers.toJson();
    
    return json;
}
