//
//  OSX.hpp
//  orange
//
//  Created by Daniel Almeida on 13/12/2018.
//

#ifndef OSX_hpp
#define OSX_hpp

#include <stdio.h>

#include "OSFacadeInterface.hpp"

#include "ofMain.h"



namespace Orange {
    namespace GUI {
        
        /*!
         Implements a Facade for funtionality needed to run on OSX
        */
        class OSXFacade : public OSFacadeInterface {
         
            Engine::EngineController *engineController;
        public:
            
            /*!
             Constructor. Instatiates the on Objective-C that implements all the OSX code
             */
            OSXFacade();
            
            /*!
             Sets the engine object.
             This is needed to communicate with the engine
             \param Engine::EngineController *_engineController
             */
            void setEngineController(Engine::EngineController *_engineController);
            
            /*!
             Sets up the Menu Bar
             */
            void setupMenuBar();
        };
    }
}

#endif /* OSX_hpp */
