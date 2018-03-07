#include "VideoGrabberNodeBased.h"
#include "VideoRendererNodeBased.h"
#include "LumaFilterNodeBased.h"

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
    
    container = new ofxOceanodeContainer(reg);
    canvas.setContainer(container);
    
    canvas.setup();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString(ofToString(ofGetFrameRate()), glm::vec2(0,10));
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
