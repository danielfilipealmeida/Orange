//
//  GUIElement.hpp
//  orange
//
//  Created by Daniel Almeida on 14/10/2019.
//

#ifndef GUIElement_hpp
#define GUIElement_hpp

#include <stdio.h>
#include <string>
#include "ofMain.h"

namespace Orange {
namespace GUI {

enum Type {
    TypeElement,
    TypeButton
};

struct Element {
    Type type;
    ofRectangle rect;
    ofColor background, border;
    float borderWidth;
    unsigned int zIndex;
    bool hover;
};
    
struct Button : Element {
    std::string caption;
    bool pressed;
};
    
    
/**
 Template function for applying a lambda to each value in a
 */
template <class T>
void forEachElement(std::vector<T> elements, std::function<void (T)> lambda)
{
    for(T element:elements) {
        lambda(element);
    }
}

}
}




#endif /* GUIElement_hpp */
