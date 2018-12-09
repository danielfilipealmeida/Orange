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
        
        class Engine : public Orange::Base::EntityInterface {
            
            
        public:
            int currentLayerIndex;
            
            int width, height;
            
            Engine();
        };
        
    }
}

#endif /* Engine_hpp */
