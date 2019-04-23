//
//  OSX.m
//  orange
//
//  Created by Daniel Almeida on 16/12/2018.
//

#import "OSXstuff.h"


@implementation OSXstuff

- (void) setFacade:(Orange::GUI::OSXFacade *) _facade
{
    facade = _facade;
}

- (IBAction) openFile:(id) sender
{
    NSOpenPanel *panel = [[NSOpenPanel alloc] init];
    [panel setAllowedFileTypes:@[@"vjs"]];
    
     if ([panel runModal] == NSModalResponseOK) {
         NSURL* url = [panel URL];
         NSString *path = [[url absoluteString] stringByReplacingOccurrencesOfString:@"file://" withString:@""];
         
         char *pathChar = (char *)[path cStringUsingEncoding:NSASCIIStringEncoding];
         facade->openFile(pathChar);
     };
         
    
    [panel release];
    
    return;
    /*
    NSOpenPanel *panel = [NSOpenPanel openPanel];
    [panel setAllowedFileTypes:@[@"vjs"]];
    
    if ([panel runModal] == NSModalResponseOK) {
        NSURL* url = [panel URL];
        NSString *path = [[url absoluteString] stringByReplacingOccurrencesOfString:@"file://" withString:@""];
        
        char *pathChar = (char *)[path cStringUsingEncoding:NSASCIIStringEncoding];
        facade->saveFile(pathChar);
    };
    
    [panel release];
     */
}

- (char *) getPathFromURL:(NSURL *)url {
    NSString *path = [[url absoluteString] stringByReplacingOccurrencesOfString:@"file://" withString:@""];
    
    char *pathChar = (char *)[path cStringUsingEncoding:NSASCIIStringEncoding];
    return pathChar;
}

- (IBAction) saveFile:(id) sender
{
    NSOpenPanel *panel = [[NSOpenPanel alloc] init];
    [panel setAllowedFileTypes:@[@"vjs"]];
   
    if ([panel runModal] == NSModalResponseOK) {
        NSURL* url = [panel URL];
        char * pathChar = [self getPathFromURL:url];
        facade->saveFile(pathChar);
    };
    
    [panel release];
}

- (IBAction) newFile:(id) sender
{
    NSAlert *alert = [[NSAlert alloc] init];
    alert.messageText = @"Are you sure you want to start a new VJ set?";
    alert.informativeText = @"You will loose the current set. Please save your changes before starting a new set.";
    [alert addButtonWithTitle:@"OK"];
    [alert addButtonWithTitle:@"Cancel"];
   
    NSModalResponse response = [alert runModal];
    if (response != 1000) { //  NSModalResponseOK not working?!
        return;
    }
    
    [alert release];
    
    facade->newFile();
}

- (IBAction) quit:(id) sender
{
    NSAlert *alert = [[NSAlert alloc] init];
    alert.messageText = @"Are you sure you want to quit?";
    alert.informativeText = @"You will loose the current set. Please save your changes before quitting.";
    [alert addButtonWithTitle:@"Quit"];
    [alert addButtonWithTitle:@"Keep Vjing"];
    
    NSModalResponse response = [alert runModal];
    if (response != 1000) { //  NSModalResponseOK not working?!
        return;
    }
    
    [alert release];
    
    [NSApp terminate:self];
}

- (IBAction) about:(id) sender
{    
}

- (IBAction) importVisuals:(id) sender
{
    
    NSOpenPanel *panel = [[NSOpenPanel alloc] init];
    panel.canChooseFiles = true;
    panel.canChooseDirectories = true;
    panel.allowsMultipleSelection = true;
    
    //[panel setAllowedFileTypes:@[@"mov", @"avi", @"mkv", ]];
    
    if ([panel runModal] == NSModalResponseOK) {
        NSArray<NSURL *> *URLs = [panel URLs];
        
        for (id url in URLs) {
            char * pathChar = [self getPathFromURL:url];
            facade->addVideo(pathChar);
        }
    };
    
    [panel release];
    
    // need to update the GUI! how?
}

- (void)setApplicationMenu:(NSMenu *)bar {
    NSMenuItem* appMenuItem = [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
    NSMenu* appMenu = [[NSMenu alloc] init];
    [[appMenu addItemWithTitle:@"About" action:NULL keyEquivalent:@"?"] setTarget: self];
    [appMenu addItem:[NSMenuItem separatorItem]];
    [appMenu addItemWithTitle:@"Preferences" action:NULL keyEquivalent:@"P"];
    [appMenu addItem:[NSMenuItem separatorItem]];
    [[appMenu addItemWithTitle:@"Exit" action:@selector(quit:) keyEquivalent:@"q"] setTarget:self];
    [appMenuItem setSubmenu:appMenu];
}

- (void)setFileMenu:(NSMenu *)bar {
    NSMenuItem *fileMenuItem = [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
    NSMenu* fileMenu = [[NSMenu alloc] initWithTitle:@"File"];
    [fileMenuItem setSubmenu:fileMenu];
    [[fileMenu addItemWithTitle:@"New" action:@selector(newFile:) keyEquivalent:@"n"]  setTarget:self];
    [fileMenu addItem:[NSMenuItem separatorItem]];
    [[fileMenu addItemWithTitle:@"Open" action:@selector(openFile:) keyEquivalent:@"o"] setTarget:self];
    [fileMenu addItem:[NSMenuItem separatorItem]];
    [fileMenu addItemWithTitle:@"Save" action:@selector(save:) keyEquivalent:@"s"];
    [[fileMenu addItemWithTitle:@"Save As..." action:@selector(saveFile:) keyEquivalent:@"S"] setTarget: self];
    [fileMenu addItem:[NSMenuItem separatorItem]];
    [[fileMenu addItemWithTitle:@"Import Visuals"
                         action:@selector(importVisuals:)
                  keyEquivalent:@""
      ] setTarget: self];
}

- (void)setWindowMenu:(NSMenu *)bar {
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

- (void) setLayersMenu: (NSMenu *)bar
{
    NSMenuItem* layersMenuItem =
    [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
    NSMenu* layersMenu = [[NSMenu alloc] initWithTitle:@"Layers"];
    [layersMenuItem setSubmenu:layersMenu];
    
    [layersMenu addItemWithTitle:@"Add Layer"
                          action:NULL
                   keyEquivalent:@""];
    [layersMenu addItemWithTitle:@"Delete Layer"
                          action:NULL
                   keyEquivalent:@""];
    [layersMenu addItem:[NSMenuItem separatorItem]];
    [layersMenu addItemWithTitle:@"Set Layer 1"
                          action:NULL
                   keyEquivalent:@"1"];
    [layersMenu addItemWithTitle:@"Set Layer 2"
                          action:NULL
                   keyEquivalent:@"2"];
    [layersMenu addItemWithTitle:@"Set Layer 3"
                          action:NULL
                   keyEquivalent:@"3"];
    [layersMenu addItemWithTitle:@"Set Layer 4"
                          action:NULL
                   keyEquivalent:@"4"];
    [layersMenu addItem:[NSMenuItem separatorItem]];
    [layersMenu addItemWithTitle:@"Rename current Layer"
                          action:NULL
                   keyEquivalent:@""];
}

- (void) setMenu:(NSWindow *) window
{
    NSMenu* bar = [[NSApplication sharedApplication] mainMenu];
    [bar removeAllItems];
    
    [self setApplicationMenu:bar];
    [self setFileMenu:bar];
    [self setLayersMenu:bar];
    [self setWindowMenu:bar];
}

@end
