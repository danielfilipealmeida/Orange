//
//  Layer.hpp
//  orange
//
//  Created by Daniel Almeida on 17/11/2018.
//

#ifndef Layer_hpp
#define Layer_hpp

#include <stdio.h>
#include "Repository.hpp"
#include "BaseVisual.hpp"
#include "ofMain.h"
#include "PreferencesController.hpp"


// TODO: pass all methods to controllers and use Entities only to store data.
// Use controllers instead
namespace Orange {
    namespace Layers {
     
        /*!
         Implements a Layer entity
         */
        class Layer : public Orange::Base::EntityInterface
        {
            unsigned int width, height;
            shared_ptr<Orange::Preferences::PreferencesController> preferencesController;
            
        public:

#pragma mark public attributes
   
            ofFbo fbo;
            std::map<int, std::map<int, std::string>> labels;
            
            /*!
             Constructor that receives a json
             \param ofJson json
             */
            Layer(ofJson json);
            
            /*!
             Gets the width of the layer
             \param unsigned int
             */
            unsigned int getWidth();
            
            /*!
             Gets the height of the layer
             \param unsigned int
             */
            unsigned int getHeight();

            /*!
             Sets up the FBO
             */
            void setFbo(unsigned int _width, unsigned int _height);
            
            /*!
             The Layer name, to be displayed on the gui
            */
            ofParameter<string> name;
            
            /*!
             Transparency value from 0.0 to 1.0
             */
            ofParameter<float> alpha;
            
            /*!
             The blend mode of the layer.
             
             Available blend modes:
                - OF_BLENDMODE_DISABLED - 0
                - OF_BLENDMODE_ALPHA    - 1
                - OF_BLENDMODE_ADD      - 2
                - OF_BLENDMODE_SUBTRACT - 3
                - OF_BLENDMODE_MULTIPLY - 4
                - OF_BLENDMODE_SCREEN   - 5
             */
            ofParameter<int> blendMode;
            
            /*!
             All the visuals in the layer
             */
            Base::Repository<shared_ptr<Visuals::BaseVisual> > visuals;
            
            /*!
             The current visual. check if it's possible to transform this int a ofParameter
             */
            int currentVisualIndex; 
            
#pragma mark public methods
            
            /*!
             Constructor
             */
            Layer();
            
            /*!
             Get the currently set visual or null if none
             \return Orange::Visuals::BaseVisual|NULL
             */
            shared_ptr<Orange::Visuals::BaseVisual> getCurrentVisual();
            
            /*!
             Adds a Visual
             \param Orange::Visuals::BaseVisual* visual
             */
            void add(shared_ptr<Orange::Visuals::BaseVisual> visual);
            
            /*!
             Removes a Visual in the layer by it's index in the repository
             \param unsigned int
             */
            void removeByIndex(unsigned int index);
            
            /*!
             Returns the total ammount of visuals in this layer
             \returns unsigned int
             */
            unsigned int getVisualsCount();
            
            /*!
             Returns the Layer information in JSON format.
             \returns ofJson
             */
            ofJson toJson();
            
            /*!
             
             */
            void setFromJson(ofJson json);
            
            vector<ofImage *> getVisualsThumbs();
            
            void setPreferencesController(shared_ptr<Orange::Preferences::PreferencesController> _preferencesController);
        };
        
    }
}


#endif /* Layer_hpp */
