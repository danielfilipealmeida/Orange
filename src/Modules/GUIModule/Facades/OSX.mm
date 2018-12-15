//
//  OSX.cpp
//  orange
//
//  Created by Daniel Almeida on 13/12/2018.
//

#include "OSX.hpp"
#include <Cocoa/Cocoa.h>

using namespace Orange::GUI;

OSX::OSX() {
    
}

/* check here:
 https://github.com/glfw/glfw/blob/76afd4172727892286fe5728580021a26d198c49/src/cocoa_window.m#L738
 */
void OSX::setupMenuBar()
{ 
    NSWindow *window = (NSWindow *) ofGetCocoaWindow();
    
    
    //NSMenu *menu = [[NSMenu alloc] initWithTitle:@"File"];
    
    NSMenu* bar = [[NSApplication sharedApplication] mainMenu];
    [bar removeAllItems];
    
    // App Menu
    NSMenuItem* appMenuItem = [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
    NSMenu* appMenu = [[NSMenu alloc] init];
    [appMenu addItemWithTitle:@"About" action:SEL() keyEquivalent:@"?"];
    [appMenu addItem:[NSMenuItem separatorItem]];
    [appMenu addItemWithTitle:@"Preferences" action:SEL() keyEquivalent:@"P"];
    [appMenu addItem:[NSMenuItem separatorItem]];
    [appMenu addItemWithTitle:@"Exit" action:@selector(terminate:) keyEquivalent:@"q"];
    [appMenuItem setSubmenu:appMenu];
    
    // File Menu
    NSMenuItem *fileMenuItem = [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
    NSMenu* fileMenu = [[NSMenu alloc] initWithTitle:@"File"];
    [fileMenuItem setSubmenu:fileMenu];
    [fileMenu addItemWithTitle:@"New" action:NULL keyEquivalent:@"n"];
    [fileMenu addItem:[NSMenuItem separatorItem]];
    [fileMenu addItemWithTitle:@"Open" action:@selector(open:) keyEquivalent:@"o"];
    [fileMenu addItem:[NSMenuItem separatorItem]];
    [fileMenu addItemWithTitle:@"Save" action:@selector(save:) keyEquivalent:@"s"];
    [fileMenu addItemWithTitle:@"Save As..." action:@selector(saveDocumentAs:) keyEquivalent:@"S"];
    
    // Window Menu
   
    NSMenuItem* windowMenuItem =
    [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
    NSMenu* windowMenu = [[NSMenu alloc] initWithTitle:@"Window"];
   // [NSApp setWindowsMenu:windowMenu];
    [windowMenuItem setSubmenu:windowMenu];
    
    [windowMenu addItemWithTitle:@"Minimize"
                          action:@selector(performMiniaturize:)
                   keyEquivalent:@"m"];
    [windowMenu addItemWithTitle:@"Zoom"
                          action:@selector(performZoom:)
                   keyEquivalent:@""];
    [windowMenu addItem:[NSMenuItem separatorItem]];
    [windowMenu addItemWithTitle:@"Bring All to Front"
                          action:@selector(arrangeInFront:)
                   keyEquivalent:@""];
    [windowMenu addItemWithTitle:@"Toggle Fullscreen"
                          action:@selector(toggleFullScreen:)
                   keyEquivalent:@""];
    
}
