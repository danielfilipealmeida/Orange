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
#include "OSFacadeInterface.hpp"
#include "Layer.hpp"

namespace Orange {
    namespace GUI {
        class GUIController {
            GUIFacadeInterface *facade;
            OSFacadeInterface *os;
            
            shared_ptr<Layers::Layer> layer;
        public:
            
            GUIController(GUIFacadeInterface *_facade, OSFacadeInterface *_os);
            
            /*!
             Sets up the Graphic User Interface
             */
            void setup();
            
            /*!
             Draws the GUI
             */
            void draw();
            
            /*!
             Sets the current selected layer and updates the GUI
             \param Orange::Layers::Layer *_layer
             */
            void setLayer(shared_ptr<Orange::Layers::Layer> _layer);
            
            
            void setupMenu();
        };
    }
}



#endif /* GUIController_hpp */
