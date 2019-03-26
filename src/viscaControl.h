//
//  viscaControl.h
//  VJYourself_OCEAN
//
//  Created by Eduard Frigola on 28/02/2019.
//

#ifndef viscaControl_h
#define viscaControl_h

#include "ofxOceanodeNodeModel.h"
#include "ofxNetwork.h"

class viscaControl : public ofxOceanodeNodeModel{
public:
    viscaControl() : ofxOceanodeNodeModel("Visca Control"){}
    
    void setup() override;
    void update(ofEventArgs &a) override;
    
   void presetSave(ofJson &json) override{
        json["Cam_Position"] = cameraPosition;
        json["Cam_Focus"] = cameraFocus;
        json["Cam_Zoom"] = cameraZoom;
    };
    
    void presetRecallAfterSettingParameters(ofJson &json) override{
        cameraPosition = json["Cam_Position"];
        cameraFocus = json["Cam_Focus"];
        cameraZoom = json["Cam_Zoom"];
        setCameraView.trigger();
    }
    
private:
    void receiveInquiry(vector<char> &data);
    
    ofEventListeners listeners;
    
    ofParameter<string> ip;
    ofParameter<string> port;
    ofParameter<bool> up;
    ofParameter<bool> down;
    ofParameter<bool> left;
    ofParameter<bool> right;
    ofParameter<void> getCameraView;
    ofParameter<void> setCameraView;
    
    ofxUDPManager udpConnection;
    vector<char> cameraPosition;
    vector<char> cameraFocus;
    vector<char> cameraZoom;
};

#endif /* viscaControl_h */
