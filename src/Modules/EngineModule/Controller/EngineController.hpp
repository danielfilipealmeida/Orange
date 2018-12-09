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


namespace Orange {
    namespace Engine {
        
        class EngineController : public Orange::Base::DrawableInterface {
            Orange::Base::Repository<Orange::Layers::Layer*> layers;
            Orange::Layers::LayerController layerController;
            

            Engine engine;
            ofFbo fbo;
            
        public:
            
            /*!
             Constructor
             */
            EngineController();
            
            /*!
             Sets up the FBO
             */
            void setFbo();
            
            /*!
             Draws the Engine content
             \param float x
             \param float y
             \param float w
             \param float xh
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
             Sets the the active video in the current selected layer
             \param int visualIndex
             \return EngineController*
           */
            EngineController* setVisualIndex(int visualIndex);
            
            /*!
             Plays a visual in the currently selected layer.
             The visual must be already loaded on the layer and it's define by it's index in the Visuals repository
             \param int visualIndex
             \return EngineController*
             */
            EngineController* playVisual(int visualIndex);
            
            /*!
             Stops the visual currently playing on the Layer currently selected
             \return EngineController*
             */
            EngineController* stopVisual();
            
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
