//
//  ofxTitleDecorator.cpp
//  orange
//
//  Created by Daniel Almeida on 18/04/2019.
//

#include "ofxTitleDecorator.hpp"

ofxTitleDecorator::ofxTitleDecorator(ofxBaseGui *_decorated) {
    decorated = _decorated;
}

void ofxTitleDecorator::draw() {
    decorated->draw();
    
    ofSetColor(0,0,0, 128);
    ofFill();
    ofDrawRectangle(b.x, b.y, b.width, 16);
    
    ofSetColor(textColor);
    bindFontTexture();
    textMesh = getTextMesh(title, b.x + textPadding, b.y + 12);
    textMesh.draw();
    unbindFontTexture();
    ofSetColor(255, 255, 255, 0);
}
