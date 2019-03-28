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
#include "scriptModule.h"
#include "GatorFilter.h"
#include "VideoPsLayer.h"
#include "VideoMixer2Ch.h"
#include "VideoFileGrabber.h"
#include "ColorCorrectFilter.h"
#include "GammaFilter.h"
#include "VideoSpliter.h"
#include "VideoSwitcher.h"
#include "BeatControl.h"
#include "Multix3DFilter.h"
//#include "ISFFilter.h"
#include "HalfToneFilter.h"
#include "inputProcessingFilter.h"
#include "manualOscillatorBank.h"
#include "viscaControl.h"

#include "ofxOceanodeMidiController.h"


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofDisableArbTex();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    isGuiCollapsed=false;
    
    // create registry and type registry
    auto reg = make_shared<ofxOceanodeNodeRegistry>();
    auto treg = make_shared<ofxOceanodeTypesRegistry>();
    
    // register models
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
    reg->registerModel<ofxPm::GatorFilter>("Video/Filter");
    reg->registerModel<ofxPm::VideoPsLayer>("Video/Mixer");
    reg->registerModel<ofxPm::VideoMixer2Ch>("Video/Mixer");
    reg->registerModel<ofxPm::VideoFileGrabber>("Video/Grabber");
    reg->registerModel<ofxPm::ColorCorrectFilter>("Video/Filter");
    reg->registerModel<ofxPm::GammaFilter>("Video/Filter");
    reg->registerModel<ofxPm::VideoSpliter>("Video/Mixer");
    reg->registerModel<ofxPm::VideoSwitcher>("Video/Mixer");
    reg->registerModel<ofxPm::BeatControl>("Video/Basic");
    reg->registerModel<ofxPm::Multix3DFilter>("Video/Filter");
//    reg->registerModel<ofxPm::ISFFilter>("Video/Filter");
    reg->registerModel<ofxPm::HalfToneFilter>("Video/Filter");
    reg->registerModel<ofxPm::inputProcessingFilter>("Video/Filter");

    reg->registerModel<scriptModule>("Scripting");
    reg->registerModel<manualOscillatorBank>("Generators");
    reg->registerModel<viscaControl>("VISCA");
    
    // register types
    treg->registerType<ofxPm::VideoFrame>();
    treg->registerType<ofxPm::VideoBufferNodeBased*>();
    
    // create container, canvas
    container = make_shared<ofxOceanodeContainer>(reg, treg);
    canvas.setContainer(container);
    canvas.setup();

    // persistent ...
    container->loadPersistent();

    /*
    // persistent modules
    ofxOceanodeNode & vTrio = container->createPersistentNode<ofxPm::VideoTrioRendererNodeBased>();
    
    // call a function in one of the persistent modules
    dynamic_cast<ofxPm::VideoTrioRendererNodeBased&>(vTrio.getNodeModel()).showMyExternalWindow(true);
    */
    
    // create controls (preset,bpm,midi tabs)
    controls = make_unique<ofxOceanodeControls>(container);
    
    
    
}

//--------------------------------------------------------------
void ofApp::update()
{
    bool isMidiLearning = controls->get<ofxOceanodeMidiController>()->getIsMidiLearn();
    if(isMidiLearning) ofBackground(60,20,20);
    else ofBackground(20,20,20);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,0,0);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), glm::vec2(10,ofGetHeight() - 10));
//    ofSetColor(0);
//    ofDrawRectangle(0,0,640, 480);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(ofGetKeyPressed(OF_KEY_COMMAND)){
        if(key == 'p') container->savePersistent();
        else if(key == 'u') container->updatePersistent();
        else if(key == 'c') container->collapseGuis();
        else if(key == 'e') container->expandGuis();
        else if(key == 's') container->saveCurrentPreset();
        else if(key == 'r') container->resetPhase();
    }
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
