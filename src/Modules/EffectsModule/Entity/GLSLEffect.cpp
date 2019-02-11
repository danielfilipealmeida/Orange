//
//  GLSLEffect.cpp
//  orange
//
//  Created by Daniel Almeida on 03/02/2019.
//

#include "GLSLEffect.hpp"

using namespace Orange::Effects;

void GLSLEffect::load(std::string shaderName)
{
    shader.load("effects/glsl/" + shaderName);
}

void GLSLEffect::process(ofFbo &fbo)
{
    if (!internalFbo.isAllocated()) {
        internalFbo.allocate(fbo.getWidth(), fbo.getHeight());
    }
    
    internalFbo.begin();
    shader.begin();
    fbo.draw(0,0);
    shader.end();
    internalFbo.end();
    std::swap(fbo, internalFbo);
    
    /*
    return;
    ofImage image;
    image.setFromPixels(pixels);
    
    shader.begin();
    shader.setUniform1f("blurAmnt", 8);
    
    image.draw(0,0,10,10);
    ofSetColor(255, 255, 255);
    ofDrawBox(10,10,100,100);
    ofDrawRectangle(10,10,100,100);
    shader.end();
    
    
    //ofSaveImage(image, "/Users/daniel/out.png");
   */
    
}
