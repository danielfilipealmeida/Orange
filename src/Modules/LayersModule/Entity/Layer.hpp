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



// TODO: pass all methods to controllers and use Entities only to store data.
// Use controllers instead
namespace Orange {
    namespace Layers {
     
        /*!
         Implements a Layer entity
         */
        class Layer
        {
        public:
            /*!
             Transparency value from 0.0 to 1.0
             */
            float alpha;
            
            /*!
             The blend mode of the layer.
             
             Available blend modes:
                - OF_BLENDMODE_DISABLED
                - OF_BLENDMODE_ALPHA
                - OF_BLENDMODE_ADD
                - OF_BLENDMODE_SUBTRACT
                - OF_BLENDMODE_MULTIPLY
                - OF_BLENDMODE_SCREEN
             */
            ofBlendMode blendMode;
            
            Orange::Base::Repository<Orange::Visuals::BaseVisual *> visuals;
            int currentVisual; // this should go to the Layer Controller
            
            
            Layer();
            
            /*!
             Adds a Visual
             */
            void add(Orange::Visuals::BaseVisual* visual);
        };
        
    }
}


#endif /* Layer_hpp */
