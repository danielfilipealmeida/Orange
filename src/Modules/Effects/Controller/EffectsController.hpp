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
#include "EffectBase.hpp"
#include "Repository.hpp"

namespace Orange {
    namespace Effects {
        class EffectsController {
            shared_ptr<FreeFrameHostAdapter> adapter;
            
            Orange::Base::Repository<shared_ptr<Orange::Effects::EffectBase>> effects;
          
        public:
            float width, height;
            
            /*!
             Constructor.
             Sets the FreeFrame host adapter to be used for applying free frame filters and generators
             \param FreeFrameHostAdapter
             */
            EffectsController(shared_ptr<FreeFrameHostAdapter> _adapter);
            
            /*!
             Addes a new Filter by it's name
             */
            void newFreeFameEffect(string name);
            
            void process(ofFbo &fbo);
        };
    }
}



#endif /* EffectsController_hpp */
