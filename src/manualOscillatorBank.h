//
//  manualOscillatorBank.h
//  MIRABCN_Generator
//
//  Created by Eduard Frigola on 30/08/2017.
//
//

#ifndef manualOscillatorBank_h
#define manualOscillatorBank_h

#include "baseIndexer.h"

class manualOscillatorBank: public baseIndexer{
public:
    manualOscillatorBank();
    ~manualOscillatorBank(){};
    
    void presetRecallBeforeSettingParameters(ofJson &json) override;
    
    void presetHasLoaded() override{
        output = {0};
    }
    
private:
    void computeValues(float &f);
    
    ofEventListener phasorInEvent;
    
    ofParameter<float>  manualInput;
    deque<float>        buffer;
    deque<pair<float, float>>    indexedBuffer;
    int bufferOverflow;
    float               bufferIndex;
    ofParameter<float>  phasorIn;
    float               oldPhasor;
    ofParameter<float>  damping;
    ofParameter<float>  dampingPow;
    ofParameter<vector<float>>  output;
};

#endif /* manualOscillatorBank_h */
