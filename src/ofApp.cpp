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
#include "FrameInspector.h"
#include "VideoTrioRendererNodeBased.h"
#include "EdgeBlendNodeBased.h"
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofDisableArbTex();
    ofSetVerticalSync(false);
    ofBackground(20,20,20);
    
    auto reg = make_shared<ofxOceanodeNodeRegistry>();
    auto treg = make_shared<ofxOceanodeTypesRegistry>();
    reg->registerModel<ofxPm::VideoGrabberNodeBased>("Video");
    reg->registerModel<ofxPm::VideoRendererNodeBased>("Video");
    reg->registerModel<ofxPm::VideoRendererWindowNodeBased>("Video");
    reg->registerModel<ofxPm::LumaFilterNodeBased>("Video");
    reg->registerModel<ofxPm::VideoBufferNodeBased>("Video");
    reg->registerModel<ofxPm::VideoHeaderNodeBased>("Video");
    reg->registerModel<ofxPm::FeedbackFilterNodeBased>("Video");
    reg->registerModel<ofxPm::VideoGrabberPS3EyeNodeBased>("Video");
    reg->registerModel<ofxPm::LooperFilter>("Video");
    reg->registerModel<ofxPm::VideoTrioRendererNodeBased>("Video");
    reg->registerModel<ofxPm::FrameInspector>("Video");
    reg->registerModel<ofxPm::MultixFilter>("Video");
    reg->registerModel<ofxPm::EdgeBlendNodeBased>("Video");

    treg->registerType<ofxPm::VideoFrame>();
    treg->registerType<ofxPm::VideoBufferNodeBased*>();
    

    container = make_shared<ofxOceanodeContainer>(reg, treg);
    canvas.setContainer(container);
    canvas.setup();
    controls = make_unique<ofxOceanodeControls>(container);
    
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
