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
OSXFacade *osxFacade;

OSXFacade::OSXFacade() {
    osxStuff = [[OSXstuff alloc] init];
    [osxStuff setFacade:this];
    osxFacade = this;
}

void OSXFacade::setEngineController(Engine::EngineController *_engineController)
{
    engineController = _engineController;
}

void OSXFacade::saveFile(char *filepath)
{
    std::string pathStr(filepath);
    engineController->saveSet(pathStr);
}

void OSXFacade::openFile(char *filepath)
{
    std::string pathStr(filepath);
    engineController->saveSet(pathStr);
}

/* check here:
 https://github.com/glfw/glfw/blob/76afd4172727892286fe5728580021a26d198c49/src/cocoa_window.m#L738
 */
void OSXFacade::setupMenuBar()
{
    NSWindow *window = (NSWindow *) ofGetCocoaWindow();
    
    [osxStuff setMenu: window];
}

