//
//  GUIController.hpp
//  orange
//
//  Created by Daniel Almeida on 14/10/2019.
//

#ifndef GUIController_hpp
#define GUIController_hpp

#include <stdio.h>
#include <vector>
#include "GUIElements.hpp"

namespace Orange {
    namespace GUI {
        class GUIController {
            
            std::vector<shared_ptr<Element>> elements;
            
        public:
            GUIController();
            void update();
            void draw();
        };
    }
}

#endif /* GUIController_hpp */
