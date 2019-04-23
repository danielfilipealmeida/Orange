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
#include "DrawableInterface.hpp"
#include "ofMain.h"
#include "PreferencesController.hpp"
#include "EffectsController.hpp"

namespace Orange {
    namespace Layers {
        
        class LayerController :
        public Orange::Base::DrawableInterface,
        public ofBaseUpdates
        {
        private:
            
            /*!
             The layer that the controller is getting data from
             */
            shared_ptr<Layer> layer;
            
            /*!
             Fetches the current selected visual.
             */
             shared_ptr<Visuals::BaseVisual> getVisual();
            
        public:
            
            /*!
             Constructor
             */
            LayerController();
            
            LayerController(shared_ptr<Effects::EffectsController> _effectsController);
            
            
            
            
            /*!
             Sets the layer that will be affected by the controller actions
             \param Layer _layer
             */
            void setLayer(shared_ptr<Layer> _layer);
            
            /*!
             Draws the video
             \param float x
             \param float y
             \param float w
             \param float h
             */
            void draw(float x, float y, float w, float h);
            
            /*!
             Render the content of the layer
             */
            void render();
            
            /*!
             Updates the layer and all added visuals
             */
            void update();
            
            /*!
             Returns the Layer's texture
             \returns ofTexture&
             */
            ofTexture& getTexture();
        };
    }
}


#endif /* LayerController_hpp */
