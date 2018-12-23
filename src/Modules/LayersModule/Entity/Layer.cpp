//
//  Layer.cpp
//  orange
//
//  Created by Daniel Almeida on 17/11/2018.
//

#include "Layer.hpp"
#include "BaseVisual.hpp"

using namespace Orange::Layers;

Layer::Layer()
{
    name = "Layer";
    alpha = 0.5;
    blendMode = OF_BLENDMODE_ALPHA;
    currentVisualIndex = -1;
}

Layer::Layer(ofJson json)
{
    setFromJson(json);
}

void Layer::setFbo(unsigned int _width, unsigned int _height)
{
    width = _width;
    height = _height;
    fbo.allocate(width, height, GL_RGBA);
}

unsigned int Layer::getWidth()
{
    return width;
}

unsigned int Layer::getHeight()
{
    return height;
}

void Layer::add(shared_ptr<Orange::Visuals::BaseVisual> visual)
{
    visuals.add(visual);
}

unsigned int Layer::getVisualsCount()
{
    return visuals.count();
}

shared_ptr<Orange::Visuals::BaseVisual> Layer::getCurrentVisual()
{
    if (currentVisualIndex < 0 || visuals.count() <= currentVisualIndex) {
        return NULL;
    }
    return visuals[currentVisualIndex];
}


/*
 TODO: add all the visuals using the repository to get all jsons
 */
ofJson Layer::toJson()
{
    return {
        {"width", width},
        {"height", height},
        {"name", name.get()},
        {"alpha", alpha.get()},
        {"blendMode", blendMode.get()},
        {"visuals", visuals.toJson()},
        {"currentVisualIndex", currentVisualIndex}
    };
}


void Layer::setFromJson(ofJson json)
{
    setFbo(json["width"], json["height"]);
    name.set(json["name"]);
    alpha.set(json["alpha"]);
    blendMode.set(json["blendMode"]);
    currentVisualIndex = json["currentVisualIndex"];
    
    // todo: visuals
}
