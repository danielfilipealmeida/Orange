#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"
#include "OSXFacade.hpp"

#define _GLFW_USE_MENUBAR
#define APP_WINDOW_WIDTH 1024
#define APP_WINDOW_HEIGHT 768
#define SUB_WINDOWS_WIDTH 320
#define PROJECTOR_WINDOW_HEIGHT 240
#define EFFECTS_WINDOW_HEIGHT 240
#define WINDOW_SPACE 2

class AppWindow {
    ofGLFWWindowSettings settings;
    shared_ptr<ofAppBaseWindow> window;
    std::string title;
    int x, y;
  
public:
    AppWindow(int _width, int _height, std::string _title) {
        settings.setSize(_width, _height);
        settings.resizable = false;
        title = _title;
    };
    
    void setSharedContext(const shared_ptr<ofAppBaseWindow> &mainWindow) {
        settings.shareContextWith = mainWindow;
    };
    
    ofGLFWWindowSettings getSettings() {
        return settings;
    }
    
    void createWindow() {
        window = ofCreateWindow(settings);
        updateWindow();
    }
    
    void setSize(int _w, int _h) {
        settings.setSize(_w, _h);
        
        if (window == nullptr) return;
        
        updateWindow();
    }
    
    void setPosition(int _x, int _y) {
        x = _x;
        y = _y;
        
        if (window == nullptr) return;
        
        updateWindow();
    }
    
    void updateWindow() {
        window->setVerticalSync(false);
        window->setWindowTitle(title);
        window->setWindowPosition(x, y);
        window->setWindowShape(settings.getWidth(), settings.getHeight());
    }
    
    shared_ptr<ofAppBaseWindow> getWindow() {
        return window;
    }
    
    void shareContextWithAppWindow(AppWindow *appWindow) {
        settings.shareContextWith = appWindow->getWindow();
    }
    
    ofRectangle getFrame() {
        ofRectangle frame;
        void * cocoaWindow = window->getCocoaWindow();
        frame = Orange::GUI::OSXFacade::getWindowFrame(cocoaWindow);
        frame.setPosition(x, y);
        
        //frame.set(x, y, settings.getWidth(), settings.getHeight());
        
        return frame;
    }
};

static void setupProjectorWindowListeners(
                                          const shared_ptr<ofApp> &mainApp,
                                          const shared_ptr<ofAppBaseWindow> &projectorWindow
                                          ) {
    ofAddListener(projectorWindow->events().draw, mainApp.get(), &ofApp::drawProjector);
    ofAddListener(projectorWindow->events().keyPressed, mainApp.get(), &ofApp::keyPressedProjector);
}

static void setupWindowsPositions(AppWindow *mainWindow, AppWindow *projectorWindow) {
    ofRectangle visibleRect;
#ifdef TARGET_OSX
    visibleRect  = Orange::GUI::OSXFacade::getMainScreenAvailableRect();
#else
    visibleRect.setPosition(0,0);
    visibleRect.setSize(ofGetScreenWidth(), ofGetScreenHeight());
#endif
    
    mainWindow->setSize(visibleRect.width - SUB_WINDOWS_WIDTH - WINDOW_SPACE, visibleRect.height);
    mainWindow->setPosition(0, visibleRect.y);
    projectorWindow->setPosition(mainWindow->getFrame().width + WINDOW_SPACE, mainWindow->getFrame().y);
}

int main( ){
    AppWindow *mainWindow, *projectorWindow;
    
    mainWindow = new AppWindow(APP_WINDOW_WIDTH, APP_WINDOW_HEIGHT, "Orange");
    mainWindow->createWindow();
    
    projectorWindow = new AppWindow(SUB_WINDOWS_WIDTH,PROJECTOR_WINDOW_HEIGHT, "Projector");
    projectorWindow->shareContextWithAppWindow(mainWindow);
    projectorWindow->createWindow();
    
    
    shared_ptr<ofApp> mainApp(new ofApp);
    mainApp->setMainWindow(mainWindow->getWindow());
    mainApp->setProjectorWindow(projectorWindow->getWindow());
    
    setupProjectorWindowListeners(mainApp, projectorWindow->getWindow());
    setupWindowsPositions(mainWindow, projectorWindow);
    
    /* Run the application */
    ofRunApp(mainWindow->getWindow(), mainApp);
    ofRunMainLoop();
}
