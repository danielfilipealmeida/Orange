//
//  EntityInterface.hpp
//  orange
//
//  Created by Daniel Almeida on 20/11/2018.
//

#ifndef EntityInterface_hpp
#define EntityInterface_hpp

#include <stdio.h>
#include "ofJson.h"

namespace Orange {
    namespace Base {
        
        /*!
         Implements the interface of an entity, to be used by repositories
         */
        class EntityInterface {
        public:
            virtual ofJson toJson() = 0;
        };
    }
}



#endif /* EntityInterface_hpp */
