//
//  manualOscillatorBank.cpp
//  MIRABCN_Generator
//
//  Created by Eduard Frigola on 30/08/2017.
//
//

#include "manualOscillatorBank.h"

manualOscillatorBank::manualOscillatorBank() : baseIndexer(100, "Manual Oscillator Bank"){
    
    parameters->add(phasorIn.set("Phasor In", 0, 0, 1));
    putParametersInParametersGroup(parameters);
    parameters->add(manualInput.set("Manual In", 0, 0, 1));
    parameters->add(damping.set("Damping", 0, 0, 1));
    parameters->add(dampingPow.set("Damping Pow", 0, -40, 40));
    parameters->add(output.set("Output", {0}, {0}, {1}));
    
    phasorInEvent = phasorIn.newListener(this, &manualOscillatorBank::computeValues);
    
    bufferIndex = 0;
    oldPhasor = 0;
    bufferOverflow = 0;
}

void manualOscillatorBank::presetRecallBeforeSettingParameters(ofJson &json){
    if(json.count("Size") == 1){
        parameters->getInt("Size") = ofToInt(json["Size"]);
    }
}


void manualOscillatorBank::computeValues(float &f){
    if(oldPhasor > f) bufferOverflow++;
    oldPhasor = f;
    
    indexedBuffer.push_front(make_pair(f+bufferOverflow, manualInput));
    
    vector<float>   tempOut;
    tempOut.resize(indexs.size(), 0);
    
    int minBufferOverflow = 1000;
    for(int i = 0; i < indexs.size(); i++){
        float newBuffIndex = f+bufferOverflow - float(indexs[i]);
        for(int j = 1; j < indexedBuffer.size(); j++){
            if(signbit(indexedBuffer[j-1].first - newBuffIndex) != signbit(indexedBuffer[j].first - newBuffIndex)){
                //Average tempOut[i] = (indexedBuffer[j-1].second + indexedBuffer[j].second)*0.5;
                
                if (abs(indexedBuffer[j-1].first - newBuffIndex) <= abs(indexedBuffer[j].first - newBuffIndex)) {
                    tempOut[i] = indexedBuffer[j-1].second;
                }else{
                    tempOut[i] = indexedBuffer[j].second;
                }
                    
                //Damping
                if(dampingPow < 0){
                    tempOut[i] *= pow((1-(indexs[i]*damping)), 1/(float)(-dampingPow + 1));
                }else{
                    tempOut[i] *= pow((1-(indexs[i]*damping)), (dampingPow + 1));
                }
                j = indexedBuffer.size();
            }
        }

        minBufferOverflow = min((int)newBuffIndex, minBufferOverflow);
    }
    if((int)indexedBuffer.back().first < minBufferOverflow){
        bufferOverflow--;
        while((int)indexedBuffer.back().first < minBufferOverflow){
            indexedBuffer.pop_back();
        }
        for(auto &bufPos : indexedBuffer){
            bufPos.first -= 1;
        }
    }
    
    output = tempOut;
}
