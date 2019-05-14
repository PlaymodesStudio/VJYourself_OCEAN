//
//  frameRecorder.h
//  VJYourself_OCEAN
//
//  Created by Eduard Frigola Bagué on 29/04/2019.
//

#ifndef frameRecorder_h
#define frameRecorder_h

#include "VideoSink.h"
#include "ofxOceanodeNodeModel.h"

namespace ofxPm{

class frameRecorder : public VideoSink, public ofxOceanodeNodeModel{
public:
    frameRecorder();
    ~frameRecorder(){};
    
     void newVideoFrame(VideoFrame & frame);
    
private:
    void phasorInListener(float &f);
    void inputListener(ofTexture* &texture);
    void recordListener(bool &b);
    
    ofEventListeners listeners;
    
    ofParameter<float>  phasorIn;
    ofParameter<bool>   record;
    ofParameter<bool>   autoRecLoop;
    ofParameter<string> filename;
    ofParameter<float> opacity;
    ofParameter<int>    frameNum;
    ofParameter<void> doneSaving;
    
    int width, height;
    bool recorderIsSetup;
    
    float oldPhasor;
    int frameCounter;
    string initRecordingTimestamp;
    
    ofFbo fbo;
};
}

#endif /* frameRecorder_h */
