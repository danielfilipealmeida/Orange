//
//  ofxMatrix.hpp
//  orange
//
//  Created by Daniel Almeida on 19/01/2019.
//

#ifndef ofxMatrix_hpp
#define ofxMatrix_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxBaseGui.h"
#include "ofParameter.h"
#include "ofxInputField.h"

template <class T>
class ofxMatrix : public ofxBaseGui{
    friend class ofPanel;
    ofParameter<vector<T>> value;
    
    unsigned int columns, rows, page;
    int selectedCell = -1;
    
public:
    ofxMatrix() {};
    ~ofxMatrix() {}
    
    void setup(ofParameter<vector<T>> _value, float width, float height)
    {
        value = _value;
        columns = rows = 2;
        page = 0;
        b.x = b.y = 0;
        b.width = width;
        b.height = height;
        setNeedsRedraw();
    }
    
    void render() {
        
        ofSetColor(255, 255, 255);
        
        auto iterator = value.get().begin();
        float x = b.getX();
        float y = b.getY();
        float w = b.getWidth() / columns;
        float h = b.getHeight() / rows;
        for (unsigned int row = 0; row < rows; row ++) {
            for (unsigned int column = 0; column < columns; column ++) {
                if(iterator != value.get().end()) {
                    T obj = *iterator;
                    ofRectangle rectangle = ofRectangle(x + (column * w), y + (row * h), w, h);
                    obj->draw(rectangle);
                    
                    if (selectedCell == (row * columns + column) + (page * rows * columns)) {
                        ofSetLineWidth(2);
                        ofSetColor(255,255,255);
                        ofNoFill();
                        ofDrawRectangle(rectangle);
                        ofSetColor(0,0,0);

                        ofDrawRectangle(ofRectangle(rectangle.x + 1, rectangle.y + 1, rectangle.width - 2, rectangle.height - 2));
                        
                        ofSetColor(255,255,255);
                        ofFill();
                    }
                    
                    
                    iterator++;
                }
            }
        }
        
    };
    ofAbstractParameter & getParameter() {
        return value;
    };
    bool mouseMoved(ofMouseEventArgs & args) {};
    bool mousePressed(ofMouseEventArgs & args) {
        if (!getShape().inside(args)) {
            return;
        }
        
        float x = args.x - b.getX();
        float y = args.y - b.getY();
        float w = b.getWidth() / columns;
        float h = b.getHeight() / rows;
        
        selectedCell = ((unsigned int) floor(y / h)) * rows + (unsigned int) floor(x / w) + (columns * rows * page);
    };
    bool mouseDragged(ofMouseEventArgs & args) {};
    bool mouseReleased(ofMouseEventArgs & args) {};
    bool mouseScrolled(ofMouseEventArgs & args) {};
    bool setValue(float mx, float my, bool bCheckBounds) {};
    void generateDraw() {};

};

#endif /* ofxMatrix_hpp */
