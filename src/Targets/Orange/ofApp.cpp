#include "ofApp.h"
#include "Video.hpp"
#include "OSXFacade.hpp"
#include "GLFW/glfw3.h"


//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(30);
    ofSetWindowTitle("OrangeVJ");
    
    ofEnableSetupScreen();
    engineController = new Orange::Engine::EngineController();
    
    engineController->addLayer()->name="Layer 1";
    engineController->setLayerIndex(0);
    engineController->addVideoToCurrentLayer("Bolas001.mov");
    engineController->addVideoToCurrentLayer("AnemicCinema001.mp4");
    
    engineController->addLayer()->name="Layer 2";
    engineController->setLayerIndex(1);
    engineController->addVideoToCurrentLayer("AnemicCinema002.mp4");
    engineController->addVideoToCurrentLayer("AnemicCinema003.mp4");
    
    guiFacade = new Orange::GUI::ofxGuiFacade();
    os = new Orange::GUI::OSXFacade();
    os->setEngineController(engineController);
    guiController = new Orange::GUI::GUIController(guiFacade, os);

    
    engineController->setLayerIndex(0);
    guiController->setLayer(engineController->getCurrentLayer());
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


void ofApp::handleLayerSwitch(int key)
{
    switch (key) {
        case ofApp::KEYCODE_SWITCH_LAYER_1:
            engineController->setLayerIndex(0);
            break;
        
        case ofApp::KEYCODE_SWITCH_LAYER_2:
            engineController->setLayerIndex(1);
            break;
            
        case ofApp::KEYCODE_SWITCH_LAYER_3:
            engineController->setLayerIndex(2);
            break;
            
        case ofApp::KEYCODE_SWITCH_LAYER_4:
            engineController->setLayerIndex(3);
            break;
        default:
            
            break;
    }
    
    try {
         guiController->setLayer(engineController->getCurrentLayer());
    } catch (std::runtime_error *exception) {
        cout << exception->what() << endl;
    }
}

void ofApp::handleVisualsTrigger(int key)
{
    switch (key) {
        case ofApp::KEYCODE_TRIGGER_LAYER1_VISUAL1:
            engineController->playVisual(0);
            break;

        case ofApp::KEYCODE_TRIGGER_LAYER1_VISUAL2:
            engineController->setLayerIndex(0);
            engineController->playVisual(1);
            break;

        case ofApp::KEYCODE_TRIGGER_LAYER1_VISUAL3:
            engineController->setLayerIndex(0);
            engineController->playVisual(2);
            break;

        case ofApp::KEYCODE_TRIGGER_LAYER1_VISUAL4:
            engineController->setLayerIndex(0);
            engineController->playVisual(3);
            break;

        case ofApp::KEYCODE_TRIGGER_LAYER2_VISUAL1:
            engineController->setLayerIndex(1);
            engineController->playVisual(0);
            break;
            
        case ofApp::KEYCODE_TRIGGER_LAYER2_VISUAL2:
            engineController->setLayerIndex(1);
            engineController->playVisual(1);
            break;
            
        case ofApp::KEYCODE_TRIGGER_LAYER2_VISUAL3:
            engineController->setLayerIndex(1);
            engineController->playVisual(2);
            break;
            
        case ofApp::KEYCODE_TRIGGER_LAYER2_VISUAL4:
            engineController->setLayerIndex(1);
            engineController->playVisual(3);
            break;

        case ofApp::KEYCODE_TRIGGER_LAYER3_VISUAL1:
            engineController->setLayerIndex(2);
            engineController->playVisual(0);
            break;
            
        case ofApp::KEYCODE_TRIGGER_LAYER3_VISUAL2:
            engineController->setLayerIndex(2);
            engineController->playVisual(1);
            break;
            
        case ofApp::KEYCODE_TRIGGER_LAYER3_VISUAL3:
            engineController->setLayerIndex(2);
            engineController->playVisual(2);
            break;
            
        case ofApp::KEYCODE_TRIGGER_LAYER3_VISUAL4:
            engineController->setLayerIndex(2);
            engineController->playVisual(3);
            break;

        default:
            
            break;
    }
}

void ofApp::keyPressed(int key){
    cout << "in:  "  << key << endl;
    
    //int state = glfwGetKey(ofGetCocoaWindow(), GLFW_KEY_LEFT_SHIFT);
    //cout << state << endl;
    
    try {
        handleLayerSwitch(key);
        handleVisualsTrigger(key);
    }
    catch (std::runtime_error *exception) {
        cout << exception->what();
    }
    
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    cout << "out: "  << key << endl;
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
