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
#include "Engine.hpp"
#include "VideoController.hpp"

namespace Orange {
    namespace Engine {
        
        class EngineController : public
            Base::DrawableInterface {
            Base::Repository<Orange::Layers::Layer*> layers;
            Layers::LayerController layerController;
            std::vector<Visuals::VideoController *> videoControllers;

                
            Engine engine;
            ofFbo fbo;
            
        public:
            EngineController();
            
            void setFbo();
            
            /*!
             Draws the Engine content
             */
            void draw(float x, float y, float w, float h);
            
            /*!
             Renders a frame of the engine
             */
            void render();
            
            /*!
             Adds a new Layer with default configuration
             \return EngineController*
             */
            EngineController* addLayer();
            
            /*!
             Sets the index in the repository of the currently active layer.
             \param int layerIndex
             \return EngineController*
             */
            EngineController* setLayerIndex(int layerIndex);
 
            /*!
             Returns the currently selected layer for edit
             \returns Orange::Layers::Layer*
             */
            Orange::Layers::Layer* getCurrentLayer();

            
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
