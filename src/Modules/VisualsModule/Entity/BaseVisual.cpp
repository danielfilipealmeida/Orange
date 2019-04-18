//
//  BaseVisual.cpp
//  orange
//
//  Created by Daniel Almeida on 02/12/2018.
//

#include "BaseVisual.hpp"

using namespace Orange::Visuals;

BaseVisual::BaseVisual()
{
    std::hash<std::string> hash_function;
    size_t str_hash = hash_function(ofToString(ofGetElapsedTimeMicros()));

    hash = ofToString(str_hash);
}

void BaseVisual::draw(float x, float y, float w, float h)
{}

void BaseVisual::render()
{}

ofJson BaseVisual::toJson()
{
    return {};
}
 
void BaseVisual::setFromJson(ofJson json)
{
    
}
