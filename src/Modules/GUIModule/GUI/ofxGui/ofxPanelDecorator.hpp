// TODO:DELETE THIS
//  ofxPanelDecorator.hpp
//  orange
//
//  Created by Daniel Almeida on 27/12/2018.
//

#ifndef ofxPanelDecorator_hpp
#define ofxPanelDecorator_hpp

#pragma once

#include <stdio.h>
#include "ofxPanel.h"


class ofxPanelDecorator : public ofxPanel
{
    ofxPanel *decorated;
    float originalX;
public:
    
    void setDecorated(ofxPanel *_decorated);
    ofxPanel * setup(const std::string& collectionName="", const std::string& filename=ofxPanelDefaultFilename, float x = 10, float y = 10);
    void newColumn();
    void clear();
};

#endif /* ofxPanelDecorator_hpp */
