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
#include "DrawableInterface.hpp"
#include <string>
#include "Video.hpp"
#include "Engine.hpp"
#include "EffectsController.hpp"
#include "PreferencesController.hpp"


namespace Orange {
    namespace Engine {
        
        class EngineController :
        public Orange::Base::DrawableInterface,
        private ofBaseUpdates
        {
        private:
            Orange::Base::Repository<shared_ptr<Orange::Layers::Layer> > layers;
            Orange::Layers::LayerController layerController;
            shared_ptr<Orange::Preferences::PreferencesController> preferencesController;
            Engine engine;
            
            std::map<unsigned int, std::string> layersLabels;
            
            
            
        public:
            ofFbo fbo;
            shared_ptr<Orange::Effects::EffectsController> effectsController;
            Base::Repository<shared_ptr<Visuals::BaseVisual> > loadedVisuals;
            Base::Repository<shared_ptr<Visuals::BaseVisual> > visualsToGenerateThumbnails;
            
            /*!
             Constructor
             */
            EngineController(shared_ptr<Orange::Preferences::PreferencesController> _preferencesController,
                             shared_ptr<Orange::Effects::EffectsController> _effectsController);
            
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
            
            void update();
            
            /*!
             Adds a new Layer with default configuration
             */
            shared_ptr<Orange::Layers::Layer> addLayer();
   
            /*!
             Gets the layer at the given index
             \param layer
             \return Orange::Layers::Layer
             */
            shared_ptr<Orange::Layers::Layer> getLayerAtIndex(unsigned int index);
            
            /*!
             Apply a lambda for each layer in the layer repository
             \param std::function<void (T)> lambda
             */
            void forEachLayer(std::function<void (shared_ptr<Orange::Layers::Layer>)> lambda);
            
            /*!
             Sets the index in the repository of the currently active layer.
             \param int layerIndex
             */
            void setLayerIndex(int layerIndex);
 
            /*!
             Returns the currently selected layer for edit
             \returns Orange::Layers::Layer*
             */
            shared_ptr<Orange::Layers::Layer> getCurrentLayer();
            
            /*!
             Sets the the active video in the current selected layer
             \param int visualIndex
             */
            void setVisualIndex(int visualIndex);
            
            /*!
             Plays a visual in the currently selected layer.
             The visual must be already loaded on the layer and it's define by it's index in the Visuals repository
             \param int visualIndex
             */
            void playVisual(int visualIndex);
            
            /*!
             Stops the visual currently playing on the Layer currently selected
             */
            void stopVisual();
            
            /*!
             Adds a new visual to the currently selected layer.
             \param Orange::Visuals::BaseVisual *visual
             */
            void addVisualToCurrentLayer(shared_ptr<Orange::Visuals::BaseVisual> visual);
            
            /*!
             Adds a Video to the current layer.
             \param string path
             */
            void addVideoToCurrentLayer(string path);
            
            /*!
             Loads a video from a path.
             This probly should go somewhere else and
             be a static method on another module
             that handles IO.
             \param string videoPath
             \return Orange::Visuals::Video*
             */
            shared_ptr<Visuals::Video> loadVideo(string path);
        

#pragma mark File methods
            
            /*!
             Sets up a new VJing set
             */
            void newSet();
            
            /*!
             Saves a file into the given path
             \param string filepath
             */
            void saveSet(std::string filepath);
            
            /*!
             Syncs the repository of visuals with all the unique loaded visuals on all the layers
             */
            void updateLoadedVisuals();
            
            /*!
             Open the file stored in the given path
             */
            bool openSet(std::string filepath);
            
            /*!
             Destroys all layers and visuals.
             Gets to an empty state
             */
            void closeSet();
            
            /*!
             Serialize all current data into a json variable
             \return ofJson
             */
            ofJson toJson();
            
            /*!
             Sets all data on the Engine using a json variable.
             This expects the engine to be completly clean
             \param ofJson json
             */
            void setFromJson(ofJson json);
        };
    }
}

#endif /* EngineController_hpp */
