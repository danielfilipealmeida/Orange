//
//  ofxTitleDecorator.hpp
//  orange
//
//  Created by Daniel Almeida on 18/04/2019.
//

#ifndef ofxTitleDecorator_hpp
#define ofxTitleDecorator_hpp

#include <stdio.h>
#include "ofxBaseGui.h"

class ofxTitleDecorator : public ofxBaseGui {
    friend class ofPanel;
    friend class ofxBaseGui;
 
    ofxBaseGui *decorated;
    ofVboMesh textMesh;
    
    
public:
    std::string title;
    
    ofxTitleDecorator(ofxBaseGui *_decorated);
    void draw();
};

#endif /* ofxTitleDecorator_hpp */
