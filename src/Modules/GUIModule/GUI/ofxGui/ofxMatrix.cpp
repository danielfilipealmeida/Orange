//
//  ofxMatrix.cpp
//  orange
//
//  Created by Daniel Almeida on 19/01/2019.
//

#include "ofxMatrix.hpp"

/*
void ofxMatrix::setup(ofParameter<vector<T>> _value, float width, float height)
{
    value = _value;
    
    columns = rows = 2;
    page = 0;
    
    b.x = 0;
    b.y = 0;
    b.width = b.height = width;
    
    setNeedsRedraw();
}

ofAbstractParameter & ofxMatrix::getParameter()
{
    return value;
}

bool  ofxMatrix::mouseMoved(ofMouseEventArgs & args)
{
    
}

bool  ofxMatrix::mousePressed(ofMouseEventArgs & args)
{
    
}

bool  ofxMatrix::mouseDragged(ofMouseEventArgs & args)
{
    
}

bool  ofxMatrix::mouseReleased(ofMouseEventArgs & args)
{
    
}

bool  ofxMatrix::mouseScrolled(ofMouseEventArgs & args)
{
    
}

bool ofxMatrix::setValue(float mx, float my, bool bCheckBounds)
{
    
}

void ofxMatrix::generateDraw()
{
    
}


void ofxMatrix::render()
{
    ofSetColor(255, 255, 255, 255);
    
    auto iterator = value.get().begin();
    float x = b.getX();
    float y = b.getX();
    float w = b.getWidth() / columns;
    float h = b.getHeight() / rows;
    for (unsigned int row = 0; row < rows; row ++) {
        for (unsigned int column = 0; column < columns; column ++) {
            //texture.draw(b.getX(), b.getY(), b.getWidth(), b.getHeight());
            
            if(iterator != value.get().end()) {
                ofTexture texture = *iterator;
                texture.draw(x + (column * w), y + (rows + h), w, h);
                
                iterator++;
            }
            
        }
    }
    
}
 */
