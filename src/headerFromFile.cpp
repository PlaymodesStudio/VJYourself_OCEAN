//
//  headerFromFile.cpp
//  VJYourself_OCEAN
//
//  Created by Eduard Frigola Bagué on 29/04/2019.
//

#include "headerFromFile.h"

void headerFromFile::setup(){
    currentframe = 0;
    parameters->add(fileName.set("Filename", ""));
    parameters->add(process.set("Process", false));
    parameters->add(currentframe.set("Current Frame", 0, 0, 1));
    parameters->add(next.set("Next"));
    parameters->add(fileIndex.set("File Index", 0, 0, 9));
    parameters->add(headerPos.set("Header", 0, 0, 1));
    parameters->add(opacity.set("Opacity", 0, 0, 1));
    
    listeners.push(fileName.newListener([this](string &s){
        if(s == "") return;
        
        if(s == "open"){
            auto result = ofSystemLoadDialog("Select file", false, ofToDataPath(""));
            s = result.fileName;
        }
        
        ofFile file(s);
        
        if(!file.exists()){
            fileName = "";
        }
        
        ofBuffer buffer(file);
        
        int size = 0;
        for(auto &line: buffer.getLines()){
            vector<string> split = ofSplitString(line, "\r");
            size = split.size();
        }
        
        fileIndexs.resize(size, 0);
        headerPositions.resize(size, 0);
        opacities.resize(size, 0);
        currentframe = 0;
        currentframe.setMax(size);
        string toSend = currentframe.getName();
        parameterChangedMinMax.notify(toSend);
        
        for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
            for(auto &line : ofSplitString(*it, "\r")){
                //Split line into strings
                vector<string> numbers = ofSplitString(line, ", ");
                int currentline = ofToInt(numbers[0]);
                numbers = ofSplitString(numbers[1], " ");
                fileIndexs[currentline] = ofToInt(numbers[0])-3;
                headerPositions[currentline] = ofToFloat(numbers[1]);
                opacities[currentline] = ofToFloat(ofSplitString(numbers[2], ";")[0]);
            }
        }
    }));
    
    listeners.push(process.newListener([this](bool &b){
        if(b){
            fileIndex = fileIndexs[currentframe];
            opacity = opacities[currentframe];
            headerPos = headerPositions[currentframe];
        }
    }));
    
    listeners.push(next.newListener([this](){
        if(fileName.get() != "" && process){
            currentframe++;
            fileIndex = fileIndexs[currentframe];
            opacity = opacities[currentframe];
            headerPos = headerPositions[currentframe];
            if(currentframe >= currentframe.getMax()) process = false;
        }
    }));
}

void headerFromFile::update(ofEventArgs &a){
//    if(process){
//        if(currentframe < currentframe.getMax()){
//            next.trigger();
//        }else{
//            process = false;
//            currentframe = 0;
//        }
//    }
}
