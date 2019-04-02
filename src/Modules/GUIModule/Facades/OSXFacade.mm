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

void OSXFacade::setEngineController(shared_ptr<Engine::EngineController> _engineController)
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

void OSXFacade::newFile()
{
    engineController->newSet();
}

/* check here:
 https://github.com/glfw/glfw/blob/76afd4172727892286fe5728580021a26d198c49/src/cocoa_window.m#L738
 */
void OSXFacade::setupMenuBar()
{
    NSWindow *window = (NSWindow *) ofGetCocoaWindow();
    
    [osxStuff setMenu: window];
}

ofRectangle OSXFacade::getMainScreenAvailableRect() {
    ofRectangle rect;
    
    CGFloat menuBarHeight = [[NSApplication sharedApplication] mainMenu].menuBarHeight;
    
    NSScreen *mainScreen = [NSScreen mainScreen];
    NSRect frame = [mainScreen visibleFrame];
    
    rect.setSize(frame.size.width, frame.size.height- menuBarHeight);
    rect.setPosition(frame.origin.x, menuBarHeight);
    
    return rect;
}

ofRectangle OSXFacade::getWindowFrame(void *window)
{
    ofRectangle rect;
    
    NSRect frame = [(NSWindow *) window frame];
    
    rect.set(frame.origin.x, frame.origin.y, frame.size.width, frame.size.height);
    
    return rect;
}

float OSXFacade::getWindowTitleSize()
{
    return 22.0;
}
