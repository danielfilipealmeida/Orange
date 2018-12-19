//
//  OSX.cpp
//  orange
//
//  Created by Daniel Almeida on 13/12/2018.
//

#include "OSXFacade.hpp"
#include <Cocoa/Cocoa.h>
#include "OSXstuff.h"
#include "Engine.hpp"

#include <string>

using namespace Orange::GUI;

OSXstuff *osxStuff;

OSXFacade::OSXFacade() {
    osxStuff = [[OSXstuff alloc] init];
    [osxStuff setOpenHandler: ^(char *path) {
        std::string pathStr(path);
        engineController->save(pathStr);
    }];
}

void OSXFacade::setEngineController(Engine::EngineController *_engineController)
{
    engineController = _engineController;
}

/* check here:
 https://github.com/glfw/glfw/blob/76afd4172727892286fe5728580021a26d198c49/src/cocoa_window.m#L738
 */
void OSXFacade::setupMenuBar()
{
    NSWindow *window = (NSWindow *) ofGetCocoaWindow();
    
    [osxStuff setMenu: window];
}

