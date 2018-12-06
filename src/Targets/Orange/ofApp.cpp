#include "ofApp.h"
#include "Video.hpp"



//--------------------------------------------------------------
void ofApp::setup() {
    engineController = new Orange::Engine::EngineController();
    
    engineController->addLayer()
        ->setLayerIndex(0)
        ->addVideoToCurrentLayer("Bolas001.mov")
        ->setVisualIndex(0);
    
    engineController->addLayer()
        ->setLayerIndex(1)
        ->addVideoToCurrentLayer("AnemicCinema001.mp4")
        ->setVisualIndex(0);
    
    
    /* set up the gui */
    guiFacade = new Orange::GUI::ofxGuiFacade();
    guiController = new Orange::GUI::GUIController(guiFacade);
    guiController->setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    engineController->render();
}

//--------------------------------------------------------------
void ofApp::draw(){
    engineController->draw(0, 0, ofGetWidth(), ofGetHeight());
    guiController->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
