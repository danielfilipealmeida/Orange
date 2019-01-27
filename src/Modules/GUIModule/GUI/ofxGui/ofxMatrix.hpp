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
#include "ofxPaginatedInterface.h"

template <class T>
class ofxMatrix : public ofxBaseGui, public ofxPaginatedInterface {
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
        auto shrink = [](ofRectangle &rectangle){
            rectangle.x++;
            rectangle.y++;
            rectangle.width -= 2;
            rectangle.height -= 2;
        };
        
        auto drawSelection = [shrink](ofRectangle rectangle) {
            ofSetLineWidth(2);
            ofSetColor(255,255,255);
            ofNoFill();
            shrink(rectangle);
            ofDrawRectangle(rectangle);
            ofSetColor(0,0,0, 96);
            shrink(rectangle);
            ofDrawRectangle(rectangle);
            ofSetColor(255,255,255);
            ofFill();
        };
        
        ofSetColor(0, 0, 0);
        ofFill();
        ofDrawRectangle(b);
        
        ofSetColor(255, 255, 255);
        
        auto iterator = value.get().begin() + page * (rows * columns);
        float x = b.getX();
        float y = b.getY();
        float w = b.getWidth() / columns;
        float h = b.getHeight() / rows;
        for (unsigned int row = 0; row < rows; row ++) {
            for (unsigned int column = 0; column < columns; column ++) {
                if(iterator != value.get().end()) {
                    T obj = *iterator;
                    ofRectangle rectangle = ofRectangle(x + (column * w), y + (row * h), w, h);
                    if (obj->isAllocated()) {
                        obj->draw(rectangle);
                    }
                    
                    
                    if (selectedCell == (row * columns + column) + (page * rows * columns)) {
                        drawSelection(rectangle);
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
    
    void setNumberOfPages(unsigned int _numberOfPages)
    {
        // do nothing
    }
    
    unsigned int getNumberOfPages()
    {
        unsigned int nItems = value.get().size();
        unsigned int result = (unsigned int) ceil ((float) nItems / (float)(columns  * rows));
        
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

};

#endif /* ofxMatrix_hpp */
