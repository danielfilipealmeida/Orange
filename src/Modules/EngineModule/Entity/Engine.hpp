//
//  Engine.hpp
//  orange
//
//  Created by Daniel Almeida on 07/12/2018.
//

#ifndef Engine_hpp
#define Engine_hpp

#include <stdio.h>
#include "EntityInterface.hpp"
#include "ofMain.h"


namespace Orange {
    namespace Engine {
        
        class Engine : public Base::EntityInterface {
            
            
        public:
            /*!
             The index in the Layer Repository of the currently selecter Layer. There should always be a selected layer when there are layers ser
             If no layers are set on the app then it should be -1
            */
            int currentLayerIndex;
            
            /*!
             The width and height of the FBO.
             All visuals will be stretched to fit this dimensions
             */
            int width, height;
            
            /*!
             The constructor of the Engine.
             Sets up some default data
             */
            Engine();
            
            Engine(ofJson json);
            
            /*!
             Returns all engine attributes serialized in a json varible
             */
            ofJson toJson();
            
            /*!
             Sets the engine attributes from a json variable
             */
            void setFromJson(ofJson json);
        };
        
    }
}

#endif /* Engine_hpp */
