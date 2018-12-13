//
//  OSInterface.hpp
//  orange
//
//  Created by Daniel Almeida on 13/12/2018.
//

#ifndef OSInterface_h
#define OSInterface_h

namespace Orange {
    namespace GUI {
        
        class OSInterface {
            
        public:
            
            virtual void setupMenuBar() = 0;
        };
    }
}
#endif /* OSInterface_h */
