//
//  EffectsController.hpp
//  orange
//
//  Created by Daniel Almeida on 13/01/2019.
//

#ifndef EffectsController_hpp
#define EffectsController_hpp

#include <stdio.h>

#include "FreeFrameHostAdapter.hpp"

namespace Orange {
    namespace Effects {
        class EffectsController {
            FreeFrameHostAdapter *freeFrameHostAdapter;
            
        public:
            
            /*!
             Sets the FreeFrame host adapter to be used for applying free frame filters and generators
             \param FreeFrameHostAdapter
             */
            void setFreeFrameHostAdapter(FreeFrameHostAdapter *_adapter);
        };
    }
}



#endif /* EffectsController_hpp */
