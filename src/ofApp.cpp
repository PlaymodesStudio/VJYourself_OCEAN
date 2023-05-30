#include "ofxOceanodePlaymodes.h"
#include "ofxOceanodeTextures.h"
#include "ofxOceanodeVectorGraphics.h"
#include "ofxOceanodeCollection.h"
#include "scriptModule.h"
//#include "viscaControl.h"

#include "ofxOceanodeMidiController.h"


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetEscapeQuitsApp(false);
    ofDisableArbTex();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    isGuiCollapsed=false;
    
    ofxOceanodePlaymodes::registerCollection(oceanode);
    ofxOceanodeTextures::registerCollection(oceanode);
    ofxOceanodeVectorGraphics::registerCollection(oceanode);
    ofxOceanodeCollection::registerModels(oceanode);
    oceanode.registerModel<scriptModule>("Scripting");
//    oceanode.registerModel<viscaControl>("VISCA");
    
    // setup oceanode
    oceanode.setup();

//    // WNDR Sequence Start stuff
//    /////////////////////////////
    ofxOscSender sender;
    sender.setup("localhost", 8000);
    ofxOscMessage m;
    m.setAddress("t/stop");
    sender.sendMessage(m);
    ofxOscMessage m2;
    m2.setAddress("t/time");
    m2.addFloatArg(0);
    sender.sendMessage(m2);
    sleep(2);
    string preset = *ofBufferFromFile("startupPreset.txt").getLines().begin();
    oceanode.loadPreset("Presets/" + preset);
//    oceanode.loadPreset("Presets/SHOW/1--Macros_File");
    ofxOscMessage m3;
    m3.setAddress("t/play");
    sender.sendMessage(m3);
}

//--------------------------------------------------------------
void ofApp::update()
{
    oceanode.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    oceanode.draw();
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
