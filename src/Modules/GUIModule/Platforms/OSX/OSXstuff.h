//
//  OSX.h
//  orange
//
//  Created by Daniel Almeida on 16/12/2018.
//


#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>



@interface OSXstuff : NSObject {
    void (^openHandler)(char* path);
}

- (IBAction) openFile:(id) sender;
- (IBAction) saveFile:(id) sender;
- (void) setMenu:(NSWindow *) window;
- (void) setOpenHandler: ( void (^)(char* path)) _openHandler;
@end



