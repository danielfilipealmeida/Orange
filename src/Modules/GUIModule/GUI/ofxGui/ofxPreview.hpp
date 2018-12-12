//
//  ofxPreview.hpp
//  orange
//
//  Created by Daniel Almeida on 11/12/2018.
//

#ifndef ofxPreview_hpp
#define ofxPreview_hpp

#include "ofxBaseGui.h"
#include "ofParameter.h"
#include "ofxInputField.h"

class ofxPreview : public ofxBaseGui{
    friend class ofPanel;
    ofParameter<ofFbo*> value;
    
public:
    ofxPreview();
    ~ofxPreview();
    
    void setup(ofParameter<ofFbo*> _value, float width = defaultWidth, float height = defaultHeight);
    
    ofAbstractParameter & getParameter();
    bool mouseMoved(ofMouseEventArgs & args);
    bool mousePressed(ofMouseEventArgs & args);
    bool mouseDragged(ofMouseEventArgs & args);
    bool mouseReleased(ofMouseEventArgs & args);
    bool mouseScrolled(ofMouseEventArgs & args);
    void render();
    bool setValue(float mx, float my, bool bCheckBounds) ;
    void generateDraw();
};

#endif /* ofxPreview_hpp */
