#include "ofApp.h"
#include "Video.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    
    try {
        video.open(ofFilePath::getAbsolutePath("Bolas001.mov"));
    }
    catch (std::runtime_error *exception) {
        cout << exception->what();
        
        ofExit(-1);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    video.render();
}

//--------------------------------------------------------------
void ofApp::draw(){
    video.draw(0, 0, ofGetWidth(), ofGetHeight());
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
