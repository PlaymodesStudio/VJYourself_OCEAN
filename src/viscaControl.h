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
    viscaControl() : ofxOceanodeNodeModel("Visca Control"){
        isPersistent = false;
    }
    
    void setup() override;
    void update(ofEventArgs &a) override;
    
   void presetSave(ofJson &json) override{
        json["Cam_Position"] = cameraPosition;
        json["Cam_Focus"] = cameraFocus;
        json["Cam_Zoom"] = cameraZoom;
    };
    
    void loadCustomPersistent(ofJson &json) override{
        isPersistent = true;
    }
    
    void presetRecallAfterSettingParameters(ofJson &json) override{
        if(isPersistent){
            cameraPosition = json["Cam_Position"];
            cameraPositionGui = ofToString(vector<int>{cameraPosition[3] + (cameraPosition[2] * 16) + (cameraPosition[1] * 16 * 16) + (cameraPosition[0] * 16 * 16 * 16) , cameraPosition[7] + (cameraPosition[6] * 16) + (cameraPosition[5] * 16 * 16) + (cameraPosition[4] * 16 * 16 * 16)});
            cameraFocus = json["Cam_Focus"];
            cameraFocusGui = ofToString(cameraFocus[3] + (cameraFocus[2] * 16) + (cameraFocus[1] * 16 * 16) + (cameraFocus[0] * 16 * 16 * 16));
            cameraZoom = json["Cam_Zoom"];
            cameraZoomGui = ofToString(cameraZoom[3] + (cameraZoom[2] * 16) + (cameraZoom[1] * 16 * 16) + (cameraZoom[0] * 16 * 16 * 16));
            setCameraView.trigger();
        }
        isPersistent = false;
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
    ofParameter<string> cameraPositionGui;
    ofParameter<string> cameraFocusGui;
    ofParameter<string> cameraZoomGui;
    
    ofxUDPManager udpConnection;
    vector<char> cameraPosition;
    vector<char> cameraFocus;
    vector<char> cameraZoom;
    
    bool isPersistent;
};

#endif /* viscaControl_h */
