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
- (void) setMenu:(NSWindow *) window;
@end



