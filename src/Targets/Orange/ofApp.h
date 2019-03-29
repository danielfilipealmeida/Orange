#pragma once

#include "ofMain.h"
#include "Video.hpp"
#include "Layer.hpp"
#include "Repository.hpp"
#include "LayerController.hpp"
#include "GUIController.hpp"
#include "ofxGuiFacade.hpp"
#include "EngineController.hpp"
#include "OSFacadeInterface.hpp"
#include "FreeFrameHostAdapter.hpp"
#include "EffectsController.hpp"
#include "PreferencesController.hpp"

class ofApp : public ofBaseApp{
    /* Keys constants */
    enum KEYCODES {
        KEYCODE_SWITCH_LAYER_1 = 49,
        KEYCODE_SWITCH_LAYER_2 = 50,
        KEYCODE_SWITCH_LAYER_3 = 51,
        KEYCODE_SWITCH_LAYER_4 = 52
    };
    
    enum VISUALS_TRIGGER_CODES {
        KEYCODE_TRIGGER_LAYER1_VISUAL1 = 113,
        KEYCODE_TRIGGER_LAYER1_VISUAL2 = 119,
        KEYCODE_TRIGGER_LAYER1_VISUAL3 = 101,
        KEYCODE_TRIGGER_LAYER1_VISUAL4 = 114,
        
        KEYCODE_TRIGGER_LAYER2_VISUAL1 = 97,
        KEYCODE_TRIGGER_LAYER2_VISUAL2 = 115,
        KEYCODE_TRIGGER_LAYER2_VISUAL3 = 100,
        KEYCODE_TRIGGER_LAYER2_VISUAL4 = 102,

        KEYCODE_TRIGGER_LAYER3_VISUAL1 = 122,
        KEYCODE_TRIGGER_LAYER3_VISUAL2 = 120,
        KEYCODE_TRIGGER_LAYER3_VISUAL3 = 99,
        KEYCODE_TRIGGER_LAYER3_VISUAL4 = 118,

    };
    
    const std::string defaultAppTitleTemplate = "OrangeVj | <layer> | <visual>";
    
    /* TODO: move these pointers to shared pointers? */
    shared_ptr<Orange::Engine::EngineController> engineController;
    Orange::GUI::ofxGuiFacade *guiFacade;
    Orange::GUI::OSFacadeInterface *os;
    Orange::GUI::GUIController *guiController;
    shared_ptr<Orange::Preferences::PreferencesController> preferencesController;
    
    //shared_ptr<Orange::Effects::FreeFrameHostAdapter> ffHostAdapter;
    shared_ptr<Orange::Effects::EffectsController> effectsController;
    shared_ptr<ofAppBaseWindow> mainWindow, projectorWindow;

    
	public:
    
    /*!
     Loads a video from a path
     \param string videoPath
     \return Orange::Visuals::Video
     */
    Orange::Visuals::Video* loadVideo(string videoPath);
    

    void setup();
		void update();
		void draw();
    void drawProjector(ofEventArgs & args);
    void keyPressedProjector(ofKeyEventArgs & args);
    
    
    
    void setTestData();
    
    void setAppTitle();
    
    void handleLayerSwitch(int key);
    void handleVisualsTrigger(int key);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    /*!
     Sets the main window
     \param shared_ptr<ofAppBaseWindow> _mainWindow
     */
    void setMainWindow(shared_ptr<ofAppBaseWindow> _mainWindow);
    
    /*!
     Sets the projector window
     \param shared_ptr<ofAppBaseWindow> _projectorWindow
     */
    void setProjectorWindow(shared_ptr<ofAppBaseWindow> _projectorWindow);
};
