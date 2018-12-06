//
//  EngineController.hpp
//  orange
//
//  Created by Daniel Almeida on 05/12/2018.
//

#ifndef EngineController_hpp
#define EngineController_hpp

#include <stdio.h>
#include "Repository.hpp"
#include "Layer.hpp"
#include "LayerController.hpp"
#include "DrawableInterface.h"
#include <string>
#include "Video.hpp"

namespace Orange {
    namespace Engine {
        
        class EngineController : public Orange::Base::DrawableInterface {
            Orange::Base::Repository<Orange::Layers::Layer*> layers;
            Orange::Layers::LayerController layerController;

            unsigned int currentLayerIndex;
            
            Orange::Layers::Layer* getCurrentLayer();
            
        public:
            EngineController();
            
            /*!
             Draws the Engine content
             */
            void draw(float x, float y, float w, float h);
            
            /*!
             Renders a frame of the engine
             */
            void render();
            
            /*!
             */
            EngineController* addLayer();
            
            /*!
             */
            EngineController* setLayerIndex(int layerIndex);
            
            /*!
             */
            EngineController* setVisualIndex(int visualIndex);
            
            /*!
             */
            EngineController* addVisualToCurrentLayer(Orange::Visuals::BaseVisual *visual);
            
            /*!
             */
            EngineController* addVideoToCurrentLayer(std::string path);
            
            /*!
             Loads a video from a path.
             This probly should go somewhere else and
             be a static method on another module
             that handles IO
             */
            Orange::Visuals::Video* loadVideo(string videoPath);

        };
    }
}

#endif /* EngineController_hpp */
