#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

#define _GLFW_USE_MENUBAR
#define APP_WINDOW_WIDTH 1024
#define APP_WINDOW_HEIGHT 768
#define PROJECTOR_WINDOW_WIDTH 320
#define PROJECTOR_WINDOW_HEIGHT 240
#define WINDOW_SPACE 10

static ofGLFWWindowSettings getMainWindowSettings() {
    ofGLFWWindowSettings mainWindowSettings;
    mainWindowSettings.setSize(APP_WINDOW_WIDTH, APP_WINDOW_HEIGHT);
    mainWindowSettings.resizable = true;
    return mainWindowSettings;
}

static ofGLFWWindowSettings getProjectorWindowSettings(const shared_ptr<ofAppBaseWindow> &mainWindow) {
    ofGLFWWindowSettings projectorWindowSettings;
    projectorWindowSettings.setSize(PROJECTOR_WINDOW_WIDTH, PROJECTOR_WINDOW_HEIGHT);
    projectorWindowSettings.resizable = true;
    projectorWindowSettings.shareContextWith = mainWindow;
    return projectorWindowSettings;
}


static void setupProjectorWindowListeners(const shared_ptr<ofApp> &mainApp, const shared_ptr<ofAppBaseWindow> &projectorWindow) {
    ofAddListener(projectorWindow->events().draw, mainApp.get(), &ofApp::drawProjector);
    ofAddListener(projectorWindow->events().keyPressed, mainApp.get(), &ofApp::keyPressedProjector);
}

static void setupWindowsPositions(const shared_ptr<ofAppBaseWindow> &mainWindow, const shared_ptr<ofAppBaseWindow> &projectorWindow) {
    unsigned int screenWidth = ofGetScreenWidth();
    unsigned int screenHeight = ofGetScreenHeight();
    float projectorWindowPositionY = mainWindow->getWindowPosition()[1];
    mainWindow->setWindowPosition((screenWidth - APP_WINDOW_WIDTH - PROJECTOR_WINDOW_WIDTH - WINDOW_SPACE) / 2.0, projectorWindowPositionY);
    projectorWindow->setWindowPosition(mainWindow->getWindowPosition()[0] + APP_WINDOW_WIDTH + WINDOW_SPACE, projectorWindowPositionY);
}

int main( ){
    /* Sets up and creates the main window */
    ofGLFWWindowSettings mainWindowSettings = getMainWindowSettings();
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(mainWindowSettings);
    
    /* Sets up and creates the projector window */
    ofGLFWWindowSettings projectorWindowSettings = getProjectorWindowSettings(mainWindow);
    shared_ptr<ofAppBaseWindow> projectorWindow = ofCreateWindow(projectorWindowSettings);
    projectorWindow->setVerticalSync(false);
    
    /* Sets up the app, the listeners of the projector and the position of the windows */
    shared_ptr<ofApp> mainApp(new ofApp);
    mainApp->setProjectorWindow(projectorWindow);
    setupProjectorWindowListeners(mainApp, projectorWindow);
    setupWindowsPositions(mainWindow, projectorWindow);
    
    /* Run the application */
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
}
