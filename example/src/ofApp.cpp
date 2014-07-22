#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetVerticalSync(true);
    
    buttons.setup(); // this sets up the events etc..
    
    ButtonPanel * panel = buttons.addButtonPanel("Settings");
    panel->addListItem("Select a color:");
    panel->addSelectionItem("Red", colorSelect, COLOR_RED);
    panel->addSelectionItem("Green", colorSelect, COLOR_GREEN);
    panel->addSelectionItem("Blue", colorSelect, COLOR_BLUE);
    panel->addListItem("Dimensions");
    panel->addSliderItem("scale", 1, 5, fScale);
    panel->addSliderItem("rotation", 0, 90, fRotation);
    panel->addSliderItem("fps", 0, 300, fps);
    panel->addFlashItem("Reset", bReset);

    buttons.addSlideButton("FPS", 0, 300, fps);
}

//--------------------------------------------------------------
void ofApp::update(){
    fps += (ofGetFrameRate() - fps)/20; // update the fps
    
    if(bReset){ // check for the value of a "Flash item"
        fScale = 1;
        fRotation = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    switch (colorSelect) {
        case COLOR_RED:
            ofSetColor(255, 0, 0, 50);
            break;
        case COLOR_GREEN:
            ofSetColor(0, 255, 0, 50);
            break;
        case COLOR_BLUE:
            ofSetColor(0,0, 255, 50);
            break;
        default:
            ofSetColor(100, 100, 100, 50);
            break;
    }
    
    // draw something
    ofEnableAlphaBlending();
    ofFill();
    ofPushMatrix();
    {
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofScale(fScale, fScale);
        for(int i = 0; i < 5; i++){
            ofRotateZ(fRotation/5);
            ofRect(-100, -100, 200, 200);
            
        }
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}