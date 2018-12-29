//
//  ofxPanelDecorator.cpp
//  orange
//
//  Created by Daniel Almeida on 27/12/2018.
//

#include "ofxPanelDecorator.hpp"


void ofxPanelDecorator::setDecorated(ofxPanel *_decorated) {
    decorated = _decorated;
}


ofxPanel * ofxPanelDecorator::setup(const std::string& collectionName, const std::string& filename, float x, float y){
    originalX = x;
    registerMouseEvents();
    return (ofxPanel*)ofxGuiGroup::setup(collectionName,filename,x,y);
}

void ofxPanelDecorator::newColumn()
{
    b.x = b.x + b.width;
    b.y = getPosition().y;
}

void ofxPanelDecorator::clear() {
    b.x = originalX;
    ofxGuiGroup::clear();
}
