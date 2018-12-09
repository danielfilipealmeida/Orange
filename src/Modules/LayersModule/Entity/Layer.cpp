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
    name = "Layer " + std::to_string(layerNumber);
    alpha = 0.5;
    blendMode = OF_BLENDMODE_ALPHA;
    currentVisualIndex = -1;
    
    layerNumber++;
}

void Layer::add(Orange::Visuals::BaseVisual* visual)
{
    visuals.add(visual);
}

unsigned int Layer::getVisualsCount()
{
    return visuals.count();
}

Orange::Visuals::BaseVisual* Layer::getCurrentVisual()
{
    if (currentVisualIndex < 0 || visuals.count() <= currentVisualIndex) {
        return NULL;
    }
    return visuals[currentVisualIndex];
}
