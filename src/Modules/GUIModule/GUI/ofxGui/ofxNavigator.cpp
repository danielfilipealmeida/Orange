//
//  ofxNavigator.cpp
//  orange
//
//  Created by Daniel Almeida on 23/01/2019.
//

#include "ofxNavigator.hpp"


auto addToRect = [](ofRectangle rectangle, ofPoint point) -> ofRectangle {
    ofRectangle result = rectangle;
    
    rectangle.x += point.x;
    rectangle.y += point.y;
    
    return rectangle;
};

ofxNavigator::ofxNavigator()
{
    hoverPrevious = hoverNext = clickPrevious = clickNext = FALSE;
}

ofxNavigator::~ofxNavigator()
{}

void ofxNavigator::setup(ofParameter<ofxPaginatedInterface *> _element, float width, float height)
{
    element = _element;
    b.x = 0;
    b.y = 0;
    b.width = width;
    b.height = height;
    setNeedsRedraw();

    previousRect.set(width - (2*height), 0, height, height);
    nextRect.set(width - height, 0, height, height);
}


ofAbstractParameter & ofxNavigator::getParameter()
{
    return element;
}

bool  ofxNavigator::mouseMoved(ofMouseEventArgs & args)
{
    hoverPrevious = addToRect(previousRect, ofPoint(b.x, b.y)).inside(args.x, args.y);
    hoverNext = addToRect(nextRect, ofPoint(b.x, b.y)).inside(args.x, args.y);
}

bool  ofxNavigator::mousePressed(ofMouseEventArgs & args)
{
    ofRectangle button = previousRect;
    button.x+=b.x;
    button.y+=b.y;
    if (button.inside(args.x, args.y) ) {
        unsigned int page = element.get()->getPage();
        if (page > 0) {
            element.get()->setPage(page - 1);
        }
    }
    
    button = nextRect;
    button.x+=b.x;
    button.y+=b.y;
    if (button.inside(args.x, args.y) ) {
        unsigned int page = element.get()->getPage();
        if (page < element.get()->getNumberOfPages() - 1) {
            element.get()->setPage(page + 1);
        }
    }
    
    clickNext = hoverNext;
    clickPrevious = hoverPrevious;
}

bool  ofxNavigator::mouseDragged(ofMouseEventArgs & args)
{
    
}

bool  ofxNavigator::mouseReleased(ofMouseEventArgs & args)
{
    clickNext = false;
    clickPrevious = false;
}

bool  ofxNavigator::mouseScrolled(ofMouseEventArgs & args)
{
    
}

void ofxNavigator::clear() {
    ofSetColor(0, 0, 0, 255);
    ofFill();
    ofDrawRectangle(b);
}

void ofxNavigator::printText() {
    std::string text;
    text = ofToString(element.get()->getPage() + 1) + " of " + ofToString(element.get()->getNumberOfPages());
    ofSetColor(textColor);
    bindFontTexture();
    textMesh = getTextMesh(text, b.x + textPadding, b.y + 12);
    textMesh.draw();
    unbindFontTexture();
}

void ofxNavigator::drawTriangles() {
    ofSetLineWidth(1);
    
    ofSetColor(textColor, clickPrevious ? 128 : 255);
    hoverPrevious ? ofFill() : ofNoFill();
    
    float space = 3;
    ofDrawTriangle(b.x + previousRect.x + space, b.y + previousRect.y + (previousRect.height / 2.0),
                   b.x + previousRect.x + previousRect.width - space, b.y + previousRect.y +  previousRect.height - space,
                   b.x + previousRect.x + previousRect.width - space , b.y + previousRect.y + space);
    
    ofSetColor(textColor, clickNext ? 128 : 255);
    hoverNext ? ofFill() : ofNoFill();
    ofDrawTriangle(
                   b.x + nextRect.x + space, b.y + nextRect.y +  nextRect.height - space,
                   b.x + nextRect.x + + nextRect.width - space, b.y + nextRect.y + (nextRect.height / 2.0),
                   b.x + nextRect.x + space , b.y + nextRect.y + space);
}

void ofxNavigator::render()
{
    clear();
    printText();
    drawTriangles();
}

ofPath ofxNavigator::getPathFromRect(float x, float y, float w, float h)
{
    ofPath button;
    
    button.moveTo(x, y);
    button.lineTo(x+w, y);
    button.lineTo(x+w, y +h);
    button.lineTo(x, y+h);
    button.lineTo(x, y);
     
    return button;
    
}
bool ofxNavigator::setValue(float mx, float my, bool bCheckBounds)
{
    
}

void ofxNavigator::generateDraw()
{
    
}
