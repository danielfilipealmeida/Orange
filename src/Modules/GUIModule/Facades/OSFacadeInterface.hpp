//
//  OSInterface.hpp
//  orange
//
//  Created by Daniel Almeida on 13/12/2018.
//

#ifndef OSInterface_h
#define OSInterface_h

#include <string>
#include "EngineController.hpp"


namespace Orange {
    namespace GUI {
        
        /*!
         Interface implemented by all OS Facades for implementing specific OS functionalities.
         */
        class OSFacadeInterface {
            
        public:

            /*!
             Sets up the Menu Bar
             */
            virtual void setupMenuBar() = 0;
            
            /*!
             Sets the engine object.
             This is needed to communicate with the engine
             \param Engine::EngineController *_engineController
             */
            virtual void setEngineController(shared_ptr<Engine::EngineController> _engineController) = 0;
            
        
        };
    }
}
#endif /* OSInterface_h */
