//
//  OSX.hpp
//  orange
//
//  Created by Daniel Almeida on 13/12/2018.
//

#ifndef OSX_hpp
#define OSX_hpp

#include <stdio.h>
#include "OSInterface.hpp"

#include "ofMain.h"

namespace Orange {
    namespace GUI {
        
        class OSX : public OSInterface {
         
        public:
            
            OSX();
            void setupMenuBar();
        };
    }
}

#endif /* OSX_hpp */
