//
//  Engine.cpp
//  orange
//
//  Created by Daniel Almeida on 07/12/2018.
//

#include "Engine.hpp"


using namespace Orange::Engine;

Engine::Engine()
{
    currentLayerIndex = -1;
    width = 640;
    height = 480;
}

Engine::Engine(ofJson json)
{
    setFromJson(json);
}

ofJson Engine::toJson()
{
    return {
        {"width", width},
        {"height", height},
        {"currentLayerIndex", currentLayerIndex}
    };
}

void Engine::setFromJson(ofJson json)
{
    width = json["width"];
    height = json["height"];
    currentLayerIndex = json["currentLayerIndex"];
}
