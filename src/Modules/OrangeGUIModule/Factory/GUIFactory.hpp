//
//  GUIFactory.hpp
//  orange
//
//  Created by Daniel Almeida on 14/10/2019.
//

#ifndef GUIFactory_hpp
#define GUIFactory_hpp

#include <stdio.h>
#include "GUIElements.hpp"
#include "ofJson.h"

namespace Orange {
    namespace GUI {
        class GUIFactory {
        
        public:
            static shared_ptr<Element> newElement(ofJson data);
            static void drawElement(shared_ptr<Element> element);
            
            static shared_ptr<Element> newButton(ofJson data);
            static void drawButton(shared_ptr<Element> element);
            
            static void draw(shared_ptr<Element> element);
            
        private:
            static void setElementRect(shared_ptr<Element> element, ofJson data);
            static void setElementDefaultBackgroundAndBorder(shared_ptr<Element> element);
            
            static void drawElementBox(shared_ptr<Element> element);
        };
    }
}



#endif /* GUIFactory_hpp */
