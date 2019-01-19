//
//  EffectBase.h
//  orange
//
//  Created by Daniel Almeida on 13/01/2019.
//

#ifndef EffectBase_h
#define EffectBase_h

#include "DrawableInterface.hpp"
#include "ofMain.h"

namespace Orange {
    namespace Effects {
        class EffectBase {
        public:
            virtual void process(ofTexture &tex) = 0;
        };
    }
}


#endif /* EffectBase_h */
