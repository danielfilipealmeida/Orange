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

void ofxPreview::drawTitle() {
    ofSetColor(0,0,0, 128);
    ofFill();
    ofDrawRectangle(b.x, b.y, b.width, 16);
    
    ofSetColor(textColor);
    bindFontTexture();
    textMesh.draw();
    unbindFontTexture();
    ofSetColor(255, 255, 255, 0);
}

void ofxPreview::render()
{
    ofSetColor(255, 255, 255, 255);
    ofFbo *fbo = (ofFbo*) value.get();
    
    fbo->draw(b.getX(), b.getY(), b.getWidth(), b.getHeight());
    
    if (title.empty()) {
        return;
    }
    drawTitle();
}

bool ofxPreview::setValue(float mx, float my, bool bCheckBounds)
{
    
}

void ofxPreview::generateDraw()
{
    
}

void ofxPreview::setTitle(std::string _title)
{
    title = _title;
    textMesh = getTextMesh(title, b.x + textPadding, b.y + 12);
}
