//
//  ofxList.hpp
//  orange
//
//  Created by Daniel Almeida on 02/04/2019.
//

#ifndef ofxList_hpp
#define ofxList_hpp

#include <stdio.h>

#include "ofMain.h"
#include "ofxBaseGui.h"
#include "ofParameter.h"
#include "ofxInputField.h"
#include "ofxPaginatedInterface.h"

#define OFX_LIST_HEIGHT 18

template <class T>
class ofxList : public ofxBaseGui, public ofxPaginatedInterface {
    friend class ofPanel;
    ofParameter<vector<T>> value;
    unsigned int page, numberOfLines;
    int selectedItem;
    
public:
    
    ofxList() {
        selectedItem = -1;
    };
    ~ofxList() {}
    
    void setup(ofParameter<vector<T>> _value, float width, float height)
    {
        value = _value;
        page = 0;
        b.x = b.y = 0;
        b.width = width;
        b.height = height;
        numberOfLines = (int) floor(height / OFX_LIST_HEIGHT);
        setNeedsRedraw();
    }
    
    void render() {
        ofSetColor(0, 0, 0);
        ofFill();
        ofDrawRectangle(b);
        
        ofSetColor(255, 255, 255);
        
        auto iterator = value.get().begin() + page * numberOfLines;
        float x = b.getX();
        float y = b.getY();
        float w = b.getWidth();
        float h = b.getHeight() / numberOfLines;
        for(unsigned int line = 0; line < numberOfLines; line++) {
             if(iterator != value.get().end()) {
                T obj = *iterator;
                 
                 ofRectangle rectangle = ofRectangle(x, y + (line * h), w, h);
                 
                 if (selectedItem == ( line + numberOfLines * page)) {
                     ofSetColor(getFillColor());
                     ofDrawRectangle(rectangle);
                 }
                 
                 ofSetColor(textColor);
                 ofVboMesh textMesh;
                 bindFontTexture();
                 textMesh = getTextMesh(obj, rectangle.x + textPadding, rectangle.y + 12);
                 textMesh.draw();
                 unbindFontTexture();
                 
                 iterator++;
             }
        }

    }
    ofAbstractParameter & getParameter() {
        return value;
    };
    bool mouseMoved(ofMouseEventArgs & args) {};
    bool mousePressed(ofMouseEventArgs & args) {
        if (!getShape().inside(args)) {
            return false;
        }
        
        
        float x = args.x - b.getX();
        float y = args.y - b.getY();
        float w = b.getWidth();
        float h = b.getHeight() / numberOfLines;
        
        selectedItem = ((unsigned int) floor( y / h)) + (page * numberOfLines);
        //selectedItem = ((unsigned int) floor(y / h)) * numberOfLines + (unsigned int) floor(x / w) + (columns * rows * page);
        
        return true;
        
    };
    bool mouseDragged(ofMouseEventArgs & args) {};
    bool mouseReleased(ofMouseEventArgs & args) {};
    bool mouseScrolled(ofMouseEventArgs & args) {};
    bool setValue(float mx, float my, bool bCheckBounds) {};
    void generateDraw() {};
    void setNumberOfPages(unsigned int _numberOfPages)
    {
        // do nothing
    }
    
    unsigned int getNumberOfPages()
    {
        unsigned int nItems = value.get().size();
        unsigned int result = (unsigned int) ceil ((float) nItems / (float)(numberOfLines));
        
        return result;
    }
    
    void setPage(unsigned int _page)
    {
        if (page > getNumberOfPages()) {
            return;
        }
        
        page = _page;
    }
    
    unsigned int getPage()
    {
        return page;
    }
    
    T getSelectedValue() {
        std::string result;
        
        if (value.get().empty()) return result;
        if ((int) selectedItem < 0) return result;
        if (this->selectedItem >= value.get().size()) return result;
        
        result = value.get().at(selectedItem);
        
        return result;
    }
    
};

#endif /* ofxList_hpp */
