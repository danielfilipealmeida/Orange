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

void OSX::setupMenuBar()
{ 
    NSWindow *window = (NSWindow *) ofGetCocoaWindow();
    NSMenu *menu = [[NSMenu alloc] initWithTitle: @"File"];
    [menu addItemWithTitle:@"Open" action:SEL() keyEquivalent:@"CMD S"];
    
    [window setMenu: menu];
}
