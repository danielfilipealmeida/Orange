//
//  OSX.h
//  orange
//
//  Created by Daniel Almeida on 16/12/2018.
//

#import "OSXFacade.hpp"
#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>



@interface OSXstuff : NSObject {
    Orange::GUI::OSXFacade *facade;
}

- (void) setFacade:(Orange::GUI::OSXFacade *) _facade;
- (IBAction) openFile:(id) sender;
- (IBAction) saveFile:(id) sender;
- (IBAction) newFile:(id) sender;
- (IBAction) quit:(id) sender;
- (IBAction) about:(id) sender;
- (void) setMenu:(NSWindow *) window;
- (void) setApplicationMenu:(NSMenu *)bar;
- (void) setFileMenu:(NSMenu *)bar;
- (void) setLayersMenu: (NSMenu *)bar;
- (void) setWindowMenu:(NSMenu *)bar;

- (char *) getPathFromURL:(NSURL *)url;

@end



