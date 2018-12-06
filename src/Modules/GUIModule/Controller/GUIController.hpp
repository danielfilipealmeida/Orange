//
//  GUIController.hpp
//  orange
//
//  Created by Daniel Almeida on 04/12/2018.
//

#ifndef GUIController_hpp
#define GUIController_hpp

#include <stdio.h>
#include "GUIFacadeInterface.hpp"


namespace Orange {
    namespace GUI {
        class GUIController {
            GUIFacadeInterface *facade;
        public:
            
            GUIController(GUIFacadeInterface *_facade);
            
            /*!
             Sets up the Graphic User Interface
             */
            void setup();
            
            /*!
             Draws the GUI
             */
            void draw();
            
        };
    }
}



#endif /* GUIController_hpp */
