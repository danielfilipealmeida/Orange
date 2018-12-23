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
            /*!
             Get all entity attributes encoded in a json variable
             \return ofJson
             */
            virtual ofJson toJson() = 0;
            
            /*!
            Sets all the entity's attributes from a json variable
             \param ofJson json
             */
            virtual void setFromJson(ofJson json) = 0;
        };
    }
}



#endif /* EntityInterface_hpp */
