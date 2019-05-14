//
//  headerFromFile.h
//  VJYourself_OCEAN
//
//  Created by Eduard Frigola Bagué on 29/04/2019.
//

#ifndef headerFromFile_h
#define headerFromFile_h

#include "ofxOceanodeNodeModel.h"

class headerFromFile : public ofxOceanodeNodeModel{
public:
    headerFromFile() : ofxOceanodeNodeModel("Header From File"){};
    ~headerFromFile(){};
    
    void setup() override;
    void update(ofEventArgs &a) override;
    
private:
    ofParameter<string> fileName;
    ofParameter<bool> process;
    ofParameter<int> currentframe;
    ofParameter<void> next;
    ofParameter<int> fileIndex;
    ofParameter<float> headerPos;
    ofParameter<float> opacity;
    
    ofEventListeners listeners;
    
    vector<int> fileIndexs;
    vector<float> headerPositions;
    vector<float> opacities;
};

#endif /* headerFromFile_h */
