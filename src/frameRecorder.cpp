//
//  frameRecorder.cpp
//  VJYourself_OCEAN
//
//  Created by Eduard Frigola Bagué on 29/04/2019.
//

#include "frameRecorder.h"

namespace ofxPm{

frameRecorder::frameRecorder() : ofxOceanodeNodeModel("Texture Recorder"){
    //parameters->add(phasorIn.set("Phasor In", 0, 0, 1));
    parameters->add(paramFrameIn.set("Frame In", VideoFrame()));
    parameters->add(record.set("Record", false));
    parameters->add(autoRecLoop.set("Auto Rec Loop", false));
    parameters->add(filename.set("Filename", "recTest"));
    parameters->add(opacity.set("Opacity", 1, 0, 1));
    parameters->add(frameNum.set("Frame Num", 0, 0, 9999));
    parameters->add(doneSaving.set("Done Saving"));
    
    listeners.push(phasorIn.newListener(this, &frameRecorder::phasorInListener));
    listeners.push(record.newListener(this, &frameRecorder::recordListener));
    listeners.push(paramFrameIn.newListener(this, &frameRecorder::newVideoFrame));
    oldPhasor = 0;
    frameCounter = 0;
    recorderIsSetup = false;
}

void frameRecorder::phasorInListener(float &f){
    if(autoRecLoop){
        if(f < oldPhasor){
            record = !record;
        }
    }
    oldPhasor = f;
}

void frameRecorder::newVideoFrame(VideoFrame & frame)
{
    if(!frame.isNullPtr()){
        if(record){
            if(!frame.isNull()){
                ofImage img;
                img.setFromPixels(frame.getPixelsRef());
                for(auto &p : img.getPixels()){
                    p *= opacity;
                }
                img.save("recordings/" + filename.get() +  "_" + initRecordingTimestamp + "/" + filename.get() + "_" + ofToString(frameNum, 4, '0') + ".png");
                doneSaving.trigger();
            }
        }
    }
}

void frameRecorder::inputListener(ofTexture* &texture){
    if(texture != nullptr){
        if(record){
            if(texture != nullptr){
                ofImage img;
                texture->readToPixels(img.getPixels());
                img.save("recordings/" + filename.get() +  "_" + initRecordingTimestamp + "/" + filename.get() + "_" + ofToString(frameCounter, 4, '0') + ".png");
            }
            frameCounter++;
        }
    }
}

void frameRecorder::recordListener(bool &b){
    if(b){
        initRecordingTimestamp = ofGetTimestampString();
        frameCounter = 0;
    }else{
        parameters->getBool("Auto Rec Loop") = false;
    }
}

}
