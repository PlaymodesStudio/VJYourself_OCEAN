#include "VideoGrabberNodeBased.h"
#include "VideoRendererNodeBased.h"
#include "LumaFilterNodeBased.h"
#include "VideoBufferNodeBased.h"
#include "VideoHeaderNodeBased.h"
#include "FeedbackFilterNodeBased.h"
#include "MultixFilter.h"
#include "VideoGrabberPS3EyeNodeBased.h"
#include "LooperFilter.h"

#include "ofApp.h"
#include "testNode.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofDisableArbTex();

    auto reg = make_shared<ofxOceanodeNodeRegistry>();
    
    reg->registerModel<testNode>();
    reg->registerModel<ofxPm::VideoGrabberNodeBased>();
    reg->registerModel<ofxPm::VideoRendererNodeBased>();
    reg->registerModel<ofxPm::LumaFilterNodeBased>();
    reg->registerModel<ofxPm::VideoBufferNodeBased>();
    reg->registerModel<ofxPm::VideoHeaderNodeBased>();
    reg->registerModel<ofxPm::FeedbackFilterNodeBased>();
    reg->registerModel<ofxPm::VideoGrabberPS3EyeNodeBased>();
    reg->registerModel<ofxPm::LooperFilter>();
    
    reg->registerModel<ofxPm::MultixFilter>();
    
    container = make_shared<ofxOceanodeContainer>(reg);
    canvas.setContainer(container);
    canvas.setup();
    controls = new ofxOceanodeControls(container);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,0,0);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), glm::vec2(ofGetWidth()-20,10));
    ofSetColor(0);
    ofDrawRectangle(0,0,640, 480);
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
