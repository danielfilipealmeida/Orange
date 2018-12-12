//
//  ofxPreview.cpp
//  orange
//
//  Created by Daniel Almeida on 11/12/2018.
//

#include "ofxPreview.hpp"
#include "ofFbo.h"

ofxPreview::ofxPreview()
{
    
}

ofxPreview::~ofxPreview()
{
    
}


void ofxPreview::setup(ofParameter<ofFbo*> _value, float width, float height)
{
    value = _value;
    ofFbo *fbo = (ofFbo*) value.get();
    
    b.x = 0;
    b.y = 0;
    b.width = width;
    b.height = width * fbo->getHeight() / fbo->getWidth();
    setNeedsRedraw();
}

ofAbstractParameter & ofxPreview::getParameter()
{
    return value;
}

bool  ofxPreview::mouseMoved(ofMouseEventArgs & args)
{
    
}

bool  ofxPreview::mousePressed(ofMouseEventArgs & args)
{
    
}

bool  ofxPreview::mouseDragged(ofMouseEventArgs & args)
{
    
}

bool  ofxPreview::mouseReleased(ofMouseEventArgs & args)
{
    
}

bool  ofxPreview::mouseScrolled(ofMouseEventArgs & args)
{
    
}

void ofxPreview::render()
{
    ofFbo *fbo = (ofFbo*) value.get();
    
    fbo->draw(b.getX(), b.getY(), b.getWidth(), b.getHeight());
}

bool ofxPreview::setValue(float mx, float my, bool bCheckBounds)
{
    
}

void ofxPreview::generateDraw()
{
    
}
