#pragma once

#include "ofMain.h"
#include "Video.hpp"
#include "Layer.hpp"
#include "Repository.hpp"

class ofApp : public ofBaseApp{
    //Orange::Visuals::Video video;
    Orange::Base::Repository<Orange::Layers::Layer> layers;
    
	public:
		void setup();
		void update();
		void draw();

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
