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
            
            /* NOTE: is the following really needed now we're having here the engine controller ? */
            shared_ptr<Layers::Layer> layer;
            
            shared_ptr<Engine::EngineController> engineController;
            shared_ptr<Visuals::BaseVisual> currentVisual;
        public:
            
            ofParameter<int> currentFrame;
            
            GUIController(GUIFacadeInterface *_facade, OSFacadeInterface *_os);
            
            /*!
             Sets up the Graphic User Interface
             */
            void setup();
            
            /*!
             Sets up the Previews Panel
             */
            void setupPreviewsPanel();
            
            /*!
             Creates all the controls for all the effects in a Effects Controller
             */
            void setupEffectsInTarget(Orange::Effects::Target target);
            
            /*!
             Sets up the effects panel for all efects on the current layer
             */
            void setupEffectPanel();
            
            /*!
             Sets up the Layer Panel
             */
            void setupLayerPanel();

            /*!
             Sets up the Visual Panel
             */
            void setupVisualPanel();
            
            /*!
             [Add definition here]
             */
            void setupVisualsMatrixForLayer(shared_ptr<Orange::Layers::Layer> layer);
            
            
            /*!
             Updates the GUI
             */
            void update();
            
            /*!
             Draws the GUI
             */
            void draw();
            
            /*!
             Sets the current selected layer and updates the GUI
             \param shared_ptr<Orange::Layers::Layer> _layer
             */
            void setLayer(shared_ptr<Orange::Layers::Layer> _layer);
            
            /*!
             Sets the engine controller shared pointer to be used for fetching needed app information to be displayed on the GUI
             \param shared_ptr<Engine::EngineController> _engineController
            */
            void setEngineController(shared_ptr<Engine::EngineController> _engineController);
            
            /*!
             Configures the application menu
             */
            void setupMenu();
            
          
            shared_ptr<Orange::Visuals::Video> getCurrentVideo();
            
            /*!
             method executed when the param is changed
             \param unsigned int & currentFrame
             */
            void currentFrameChanged(int & currentFrame);
        };
    }
}



#endif /* GUIController_hpp */
