//
//  ofxNavigator.hpp
//  orange
//
//  Created by Daniel Almeida on 23/01/2019.
//

#ifndef ofxNavigator_hpp
#define ofxNavigator_hpp

#include <stdio.h>

#include "ofxBaseGui.h"
#include "ofParameter.h"
#include "ofxInputField.h"
#include "ofxPaginatedInterface.h"

class ofxNavigator : public ofxBaseGui {
    friend class ofPanel;
   
    ofParameter<ofxPaginatedInterface *> element;
    ofRectangle previousRect, nextRect;
    
    ofVboMesh textMesh;
    Boolean hoverPrevious, hoverNext;
    Boolean clickPrevious, clickNext;
    
    void clear();
    void printText();
    void drawTriangles();
    
    
public:
    ofxNavigator();
    ~ofxNavigator();
    
    void setup(ofParameter<ofxPaginatedInterface *> _element, float width = defaultWidth, float height = defaultHeight);
    
    ofAbstractParameter & getParameter();
    bool mouseMoved(ofMouseEventArgs & args);
    bool mousePressed(ofMouseEventArgs & args);
    bool mouseDragged(ofMouseEventArgs & args);
    bool mouseReleased(ofMouseEventArgs & args);
    bool mouseScrolled(ofMouseEventArgs & args);
    
    void render();
    bool setValue(float mx, float my, bool bCheckBounds) ;
    void generateDraw();
    
    ofPath getPathFromRect(float x, float y, float w, float h);
    
};


#endif /* ofxNavigator_hpp */
