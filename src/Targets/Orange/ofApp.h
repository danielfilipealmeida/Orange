#pragma once

#include "ofMain.h"
#include "Video.hpp"
#include "Layer.hpp"
#include "Repository.hpp"
#include "LayerController.hpp"
#include "GUIController.hpp"
#include "ofxGuiFacade.hpp"
#include "EngineController.hpp"

class ofApp : public ofBaseApp{
    /* Keys constants */
    enum KEYCODES {
        KEYCODE_SWITCH_LAYER_1 = 49,
        KEYCODE_SWITCH_LAYER_2 = 50,
        KEYCODE_SWITCH_LAYER_3 = 51,
        KEYCODE_SWITCH_LAYER_4 = 52
        
    };
    
    Orange::Engine::EngineController *engineController;
    Orange::GUI::ofxGuiFacade *guiFacade;
    Orange::GUI::GUIController *guiController;
    
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
    
    void handleLayerSwitch(int key);

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
		
};
