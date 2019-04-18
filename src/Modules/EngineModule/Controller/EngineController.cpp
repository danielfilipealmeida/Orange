//
//  EngineController.cpp
//  orange
//
//  Created by Daniel Almeida on 05/12/2018.
//

#include "EngineController.hpp"

using namespace Orange::Engine;


EngineController::EngineController(shared_ptr<Orange::Preferences::PreferencesController> _preferencesController,
                                   shared_ptr<Orange::Effects::EffectsController> _effectsController)
{
    preferencesController = _preferencesController;
    effectsController = _effectsController;
    effectsController->width = engine.width;
    effectsController->height = engine.height;

    
    setFbo();
}

void EngineController::setFbo()
{
    fbo.allocate(engine.width, engine.height, GL_RGB);
}

void EngineController::render()
{
    ofFill();
    
    unsigned int layerCount = 1;
    layers.forEach([&](shared_ptr<Orange::Layers::Layer> layer) {
        layerController.setLayer(layer);
        layerController.render();
        effectsController->process(layer->fbo, (Effects::Target)  layerCount);
        layerCount++;
    });
    
    fbo.begin();
    ofClear(0, 0, 0);
    layers.forEach([&](shared_ptr<Orange::Layers::Layer> layer) {
        layerController.setLayer(layer);
        
        layerController.draw(0, 0, engine.width, engine.height);
    });
    fbo.end();
    
    effectsController->process(fbo, Effects::Target::Output);
}

void EngineController::draw(float x, float y, float w, float h)
{
    ofColor(255,255,255);
    ofClear(0, 0, 0);
    fbo.draw(x, y, w, h);
}

shared_ptr<Orange::Layers::Layer> EngineController::addLayer()
{
    shared_ptr<Layers::Layer> layer = std::make_shared<Layers::Layer>();
    layer->setPreferencesController(preferencesController);
    layer->setFbo(engine.width, engine.height);
    layers.add(layer);
    
    return layer;
}

void EngineController::forEachLayer(std::function<void (shared_ptr<Orange::Layers::Layer>)> lambda)
{
    layers.forEach(lambda);
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
    if (visualIndex < 0) {
        return;
    }
    
    if (getCurrentLayer()->currentVisualIndex == visualIndex) {
        // todo: retrigger!
    }
    
    
    shared_ptr<Visuals::BaseVisual> previousVisual = getCurrentLayer()->getCurrentVisual();
    if (previousVisual != NULL && getCurrentLayer()->currentVisualIndex != visualIndex) {
        previousVisual->stop();
    }
    
    // return if the current selected visual isn't loaded
    if (getCurrentLayer()->getVisualsCount() <= visualIndex) {
        return;
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
    shared_ptr<Visuals::Video> video = std::make_shared<Visuals::Video>(Visuals::Video());
    try {
        video->open(path);
    }
    catch (std::runtime_error *exception) {
        cout << exception->what();
    }
    
    return video;
}

void EngineController::newSet()
{
    closeSet();
    
    addLayer()->name="Layer 1";
    addLayer()->name="Layer 2";
}

void EngineController::saveSet(std::string filepath)
{
    ofJson json = toJson();
    
    ofSavePrettyJson(filepath, json);
}

void EngineController::updateLoadedVisuals() {
    loadedVisuals.empty();
    layers.forEach([&](shared_ptr<Orange::Layers::Layer> layer) {
        layer->visuals.forEach([&](shared_ptr<Orange::Visuals::BaseVisual> visual) {
            bool alreadyLoaded = false;
            
            loadedVisuals.forEach([&](shared_ptr<Orange::Visuals::BaseVisual> loadedVisual) {
                if (loadedVisual->hash.compare(visual->hash) == 0) alreadyLoaded = true;
            });
            
            if (alreadyLoaded) return;
            
            loadedVisuals.add(visual);
        });
    });
}

bool EngineController::openSet(std::string filepath)
{
    closeSet();
    
    try {
        ofJson json = ofLoadJson(filepath);
        if (json.is_null()) {
            throw new std::runtime_error("File " + filepath+ " not found");
        }
        setFromJson(json);
        
        setLayerIndex(0);
        updateLoadedVisuals();
    }
    catch(std::runtime_error *exception)
    {
        ofLog(OF_LOG_WARNING, "%s", exception->what());
        ofSystemAlertDialog(exception->what());
        
        return false;
    }
    
    return true;
}

void EngineController::closeSet()
{
    if (layers.empty()) {
        return;
    }
    
    layers.clear();
}

ofJson EngineController::toJson()
{
    ofJson json;
    
    json["engine"] = engine.toJson();
    json["layers"] = layers.toJson();
    
    return json;
}

void EngineController::setFromJson(ofJson json)
{
    engine.setFromJson(json["engine"]);
    
    for (auto& layerJson : json["layers"]) {
        shared_ptr<Layers::Layer> newLayer = addLayer();
        
        newLayer->setFromJson(layerJson);
    }
}
