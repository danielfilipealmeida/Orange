//
//  OSX.m
//  orange
//
//  Created by Daniel Almeida on 16/12/2018.
//

#import "OSXstuff.h"



@implementation OSXstuff


- (void) setOpenHandler: ( void (^)(char* path)) _openLambda
{
    openHandler = _openLambda;
}

- (IBAction) openFile:(id) sender
{
    NSOpenPanel *panel = [NSOpenPanel openPanel];
    [panel setAllowedFileTypes:@[@"vjs"]];
    [panel beginWithCompletionHandler:^(NSInteger result){
        if (result == NSFileHandlingPanelOKButton) {
            NSURL* path = [[panel URLs] objectAtIndex:0];
            //((OSXstuff *) sender)->openDile
            
            //facadeChannel();
        }
    }];
    
    
}

- (IBAction) saveFile:(id) sender
{
    
    NSSavePanel *panel = [NSSavePanel savePanel];
    [panel setAllowedFileTypes:@[@"vjs"]];
    /*
    [panel beginWithCompletionHandler:^(NSInteger result){
        if (result == NSFileHandlingPanelOKButton) {
            NSURL* path = [panel URL];
            //((OSXstuff *) sender)->openDile
            NSDictionary *data = @{
                                   @"action": @"saveSet",
                                   @"filePath": path
                                   };
            openLambda((char *)[[path absoluteString] cStringUsingEncoding:NSASCIIStringEncoding]);
        
        // cStringUsingEncoding:NSASCIIStringEncoding
        }
    }];
    */
    if ([panel runModal] == NSModalResponseOK) {
        NSURL* url = [panel URL];
        NSString *path = [[url absoluteString] stringByReplacingOccurrencesOfString:@"file://" withString:@""];
        
        char *pathChar = (char *)[path cStringUsingEncoding:NSASCIIStringEncoding];
        openHandler(pathChar);
        //NSLog([path absoluteString]);
    };
    
}

- (void) setMenu:(NSWindow *) window
{
    
    
    
    NSMenu* bar = [[NSApplication sharedApplication] mainMenu];
    [bar removeAllItems];
    
    // App Menu
    NSMenuItem* appMenuItem = [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
    NSMenu* appMenu = [[NSMenu alloc] init];
    [appMenu addItemWithTitle:@"About" action:NULL keyEquivalent:@"?"];
    [appMenu addItem:[NSMenuItem separatorItem]];
    [appMenu addItemWithTitle:@"Preferences" action:NULL keyEquivalent:@"P"];
    [appMenu addItem:[NSMenuItem separatorItem]];
    [appMenu addItemWithTitle:@"Exit" action:@selector(terminate:) keyEquivalent:@"q"];
    [appMenuItem setSubmenu:appMenu];
    
    // File Menu
    NSMenuItem *fileMenuItem = [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
    NSMenu* fileMenu = [[NSMenu alloc] initWithTitle:@"File"];
    [fileMenuItem setSubmenu:fileMenu];
    [fileMenu addItemWithTitle:@"New" action:NULL keyEquivalent:@"n"];
    [fileMenu addItem:[NSMenuItem separatorItem]];
    [[fileMenu addItemWithTitle:@"Open" action:@selector(openFile:) keyEquivalent:@"o"] setTarget:self];
    [fileMenu addItem:[NSMenuItem separatorItem]];
    [fileMenu addItemWithTitle:@"Save" action:@selector(save:) keyEquivalent:@"s"];
    [[fileMenu addItemWithTitle:@"Save As..." action:@selector(saveFile:) keyEquivalent:@"S"] setTarget: self];
    
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

@end
