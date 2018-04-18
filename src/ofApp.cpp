#include "VideoGrabberNodeBased.h"
#include "VideoRendererNodeBased.h"
#include "VideoRendererWindowNodeBased.h"
#include "LumaFilterNodeBased.h"
#include "VideoBufferNodeBased.h"
#include "VideoHeaderNodeBased.h"
#include "FeedbackFilterNodeBased.h"
#include "MultixFilter.h"
#include "VideoGrabberPS3EyeNodeBased.h"
#include "LooperFilter.h"
#include "FrameRateCalculator.h"

#include "ofApp.h"
#include "testNode.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofDisableArbTex();
    ofSetVerticalSync(false);
    ofBackground(20,20,20);
    
    auto reg = make_shared<ofxOceanodeNodeRegistry>();
    
    //reg->registerModel<testNode>();
    reg->registerModel<ofxPm::VideoGrabberNodeBased>("Video");
    reg->registerModel<ofxPm::VideoRendererNodeBased>("Video");
    reg->registerModel<ofxPm::VideoRendererWindowNodeBased>("Video");
    reg->registerModel<ofxPm::LumaFilterNodeBased>("Video");
    reg->registerModel<ofxPm::VideoBufferNodeBased>("Video");
    reg->registerModel<ofxPm::VideoHeaderNodeBased>("Video");
    reg->registerModel<ofxPm::FeedbackFilterNodeBased>("Video");
    reg->registerModel<ofxPm::VideoGrabberPS3EyeNodeBased>("Video");
    reg->registerModel<ofxPm::LooperFilter>("Video");
    reg->registerModel<ofxPm::FrameRateCalculator>("Video");
    reg->registerModel<ofxPm::MultixFilter>("Video");
    

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
