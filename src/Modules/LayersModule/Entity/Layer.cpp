//
//  Layer.cpp
//  orange
//
//  Created by Daniel Almeida on 17/11/2018.
//

#include "Layer.hpp"
#include "BaseVisual.hpp"

using namespace Orange::Layers;

unsigned int layerNumber = 0;

Layer::Layer()
{
    name = "Layer " + std::to_string(layerNumber + 1);
    alpha = 0.5;
    blendMode = OF_BLENDMODE_ALPHA;
    currentVisualIndex = -1;
    
    layerNumber++;
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
