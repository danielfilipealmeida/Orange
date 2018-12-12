//
//  LayerController.hpp
//  orange
//
//  Created by Daniel Almeida on 03/12/2018.
//

#ifndef LayerController_hpp
#define LayerController_hpp

#include <stdio.h>
#include "Layer.hpp"
#include "DrawableInterface.h"
#include "ofMain.h"

namespace Orange {
    namespace Layers {
        
        class LayerController : public Orange::Base::DrawableInterface {
        private:
            
            /*!
             The layer that the controller is getting data from
             todo. move this to a pointer
             */
            Layer *layer;
            
            /*!
             Fetches the current selected visual.
             */
             Orange::Visuals::BaseVisual *getVisual();
        
        public:
            
            /*!
             Constructor
             */
            LayerController();
            
            /*!
             Sets the layer that will be affected by the controller actions
             \param Layer _layer
             */
            void setLayer(Layer *_layer);
            
            /*!
             Draws the video
             \param float x
             \param float y
             \param float w
             \param float h
             */
            void draw(float x, float y, float w, float h);
            
            /*!
             Prepares the video
             */
            void render();
        };
    }
}


#endif /* LayerController_hpp */
