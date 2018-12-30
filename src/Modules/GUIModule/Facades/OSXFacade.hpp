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
         
            shared_ptr<Engine::EngineController> engineController;
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
            void setEngineController(shared_ptr<Engine::EngineController> _engineController);
            
            /*!
             Sets up the Menu Bar
             */
            void setupMenuBar();
            
            /*!
             Opens a file using the engine, after an open event originated from the menu
             \param char *filepaeh
             */
            void saveFile(char *filepath);
            
            /*!
             Saves a file using the engine, after an open event originated from the menu
             \param char *filepaeh
             */
            void openFile(char *filepath);
            
            /*!
             Creates a new set by removing the current set from memory.
             */
            void newFile();
        };
    }
}

#endif /* OSX_hpp */
