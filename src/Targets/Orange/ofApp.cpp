#include "ofApp.h"
#include "Video.hpp"

Orange::Visuals::Video* ofApp::loadVideo(string videoPath) {
    Orange::Visuals::Video* video = new Orange::Visuals::Video();
    try {
        video->open(videoPath);
        video->play();
    }
    catch (std::runtime_error *exception) {
        cout << exception->what();
        
        ofExit(-1);
    }
    
    return video;
}

//--------------------------------------------------------------
void ofApp::setup() {
    Orange::Layers::Layer layer1, layer2;
    Orange::Visuals::Video* video;
    
    
    layer1.add(loadVideo(ofFilePath::getAbsolutePath("Bolas001.mov")));
    layer2.add(loadVideo(ofFilePath::getAbsolutePath("AnemicCinema001.mp4")));
    layer1.blendMode = OF_BLENDMODE_SUBTRACT;
    layer2.blendMode = OF_BLENDMODE_ALPHA;
    layer1.alpha = 0.3;
    layer2.alpha = 0.4;
    
    layer1.currentVisual = layer2.currentVisual = 0;
    layers.add(layer1);
    layers.add(layer2);
}

//--------------------------------------------------------------
void ofApp::update(){
    layers.forEach([&](Orange::Layers::Layer layer) {
        layerController.setLayer(layer);
        layerController.render();
    });
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    layers.forEach([&](Orange::Layers::Layer layer) {
        layerController.setLayer(layer);
        layerController.draw(0, 0, ofGetWidth(), ofGetHeight());
    });
    ofDisableAlphaBlending();
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
