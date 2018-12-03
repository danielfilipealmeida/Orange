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
            float alpha;
            Orange::Base::Repository<Orange::Visuals::BaseVisual *> visuals;
            int currentVisual;
            
            /*!
             Adds a Visual
             */
            void add(Orange::Visuals::BaseVisual* visual);
        };
        
    }
}


#endif /* Layer_hpp */
