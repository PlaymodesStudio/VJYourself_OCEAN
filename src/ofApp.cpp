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
#include "kaleidoscopeNodeBased.h"
#include "RepeaterFilter.h"

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofDisableArbTex();
    ofSetVerticalSync(true);
    ofBackground(20,20,20);
    
    auto reg = make_shared<ofxOceanodeNodeRegistry>();
    auto treg = make_shared<ofxOceanodeTypesRegistry>();
    reg->registerModel<ofxPm::VideoGrabberNodeBased>("Video/Grabber");
    reg->registerModel<ofxPm::VideoRendererNodeBased>("Video/Renderer");
    reg->registerModel<ofxPm::VideoRendererWindowNodeBased>("Video/Renderer");
    reg->registerModel<ofxPm::LumaFilterNodeBased>("Video/Filter");
    reg->registerModel<ofxPm::VideoBufferNodeBased>("Video/Basic");
    reg->registerModel<ofxPm::VideoHeaderNodeBased>("Video/Basic");
    reg->registerModel<ofxPm::FeedbackFilterNodeBased>("Video/Filter");
    reg->registerModel<ofxPm::VideoGrabberPS3EyeNodeBased>("Video/Grabber");
    reg->registerModel<ofxPm::RepeaterFilter>("Video/Filter");
    reg->registerModel<ofxPm::LooperFilter>("Video/Filter");
    reg->registerModel<ofxPm::VideoTrioRendererNodeBased>("Video/Renderer");
    reg->registerModel<ofxPm::FrameInspector>("Video/Basic");
    reg->registerModel<ofxPm::MultixFilter>("Video/Filter");
    reg->registerModel<ofxPm::EdgeBlendNodeBased>("Video/Filter");
    reg->registerModel<ofxPm::kaleidoscopeNodeBased>("Video/Filter");

    
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
