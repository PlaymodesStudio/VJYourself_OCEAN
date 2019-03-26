//
//  viscaControl.cpp
//  VJYourself_OCEAN
//
//  Created by Eduard Frigola on 28/02/2019.
//

#include "viscaControl.h"

void viscaControl::setup(){
    cameraPosition.resize(8, -1);
    cameraFocus.resize(4, -1);
    cameraZoom.resize(4, -1);
    parameters->add(ip.set("IP", "192.168.5.163"));
    parameters->add(port.set("Port", "1259"));
    //parameters->add(up.set("Up", false));
    //parameters->add(down.set("Down", false));
    //parameters->add(left.set("Left", false));
    //parameters->add(right.set("Right", false));
    parameters->add(getCameraView.set("Get Cam View"));
    parameters->add(setCameraView.set("Set Cam View"));
    
    listeners.push(ip.newListener([this](string &_ip){
        ofxUDPSettings settings;
        settings.sendTo(ip, ofTo<unsigned short>(port));
        settings.blocking = false;
        udpConnection.Setup(settings);
    }));
    listeners.push(port.newListener([this](string &_port){
        ofxUDPSettings settings;
        settings.sendTo(ip, ofTo<unsigned short>(port));
        settings.blocking = false;
        udpConnection.Setup(settings);
    }));
    
    listeners.push(getCameraView.newListener([this](){
        //Cam position
        vector<char> message = {static_cast<char>(0x81), static_cast<char>(0x09), static_cast<char>(0x06), static_cast<char>(0x12), static_cast<char>(0xFF)};
        udpConnection.Send(message.data(), message.size());
        vector<char> response(11);
        receiveInquiry(response);
        cameraPosition = vector<char>(response.begin()+2, response.end()-1);
        
        //Cam Focus
        message = {static_cast<char>(0x81), static_cast<char>(0x09), static_cast<char>(0x04), static_cast<char>(0x48), static_cast<char>(0xFF)};
        udpConnection.Send(message.data(), message.size());
        response.resize(7);
        receiveInquiry(response);
        cameraFocus = vector<char>(response.begin()+2, response.end()-1);
        
        //Cam Zoom
        message = {static_cast<char>(0x81), static_cast<char>(0x09), static_cast<char>(0x04), static_cast<char>(0x47), static_cast<char>(0xFF)};
        udpConnection.Send(message.data(), message.size());
        response.resize(7);
        receiveInquiry(response);
        cameraZoom = vector<char>(response.begin()+2, response.end()-1);
        
    }));
    
    listeners.push(setCameraView.newListener([this](){
        vector<char> temp(3, 0);
        while(udpConnection.Receive(temp.data(), temp.size()) != 0);
        
        //Cam position
        vector<char> message = {static_cast<char>(0x81), static_cast<char>(0x01), static_cast<char>(0x06), static_cast<char>(0x02), static_cast<char>(0x18), static_cast<char>(0x18)};
        message.insert(message.end(), cameraPosition.begin(), cameraPosition.end());
        message.insert(message.end(), static_cast<char>(0xFF));
        udpConnection.Send(message.data(), message.size());
        
        vector<char> completition(3, 0);
        while(completition[1] != static_cast<char>(0x51)){
            udpConnection.Receive(completition.data(), completition.size());
        }
        
        temp = vector<char>(3, 0);
        while(udpConnection.Receive(temp.data(), temp.size()) != 0);
        
        //Cam Zoom
        message = {static_cast<char>(0x81), static_cast<char>(0x01), static_cast<char>(0x04), static_cast<char>(0x47)};
        message.insert(message.end(), cameraZoom.begin(), cameraZoom.end());
        message.insert(message.end(), static_cast<char>(0xFF));
        udpConnection.Send(message.data(), message.size());
        
        completition = vector<char>(3, 0);
        while(completition[1] != static_cast<char>(0x51)){
            udpConnection.Receive(completition.data(), completition.size());
        }
        
        //Cam Focus
        message = {static_cast<char>(0x81), static_cast<char>(0x01), static_cast<char>(0x04), static_cast<char>(0x48)};
        message.insert(message.end(), cameraFocus.begin(), cameraFocus.end());
        message.insert(message.end(), static_cast<char>(0xFF));
        udpConnection.Send(message.data(), message.size());
        
        
    }));
}

void viscaControl::update(ofEventArgs &a){
    /*
    if(up && down){
        up = false;
        down = false;
    }
    if(left && right){
        left = false;
        right = false;
    }
    
    vector<char> message = {static_cast<char>(0x81), static_cast<char>(0x01), static_cast<char>(0x06), static_cast<char>(0x01), static_cast<char>(0x18), static_cast<char>(0x18)};
    
    if(up){
        if(left){
            message.insert(message.end(), {static_cast<char>(0x01), static_cast<char>(0x01)});
        }else if(right){
            message.insert(message.end(), {static_cast<char>(0x02), static_cast<char>(0x01)});
        }else{
            message.insert(message.end(), {static_cast<char>(0x03), static_cast<char>(0x01)});
        }
    }else if(down){
        if(left){
            message.insert(message.end(), {static_cast<char>(0x01), static_cast<char>(0x02)});
        }else if(right){
            message.insert(message.end(), {static_cast<char>(0x02), static_cast<char>(0x02)});
        }else{
            message.insert(message.end(), {static_cast<char>(0x03), static_cast<char>(0x02)});
        }
    }else{
        if(left){
            message.insert(message.end(), {static_cast<char>(0x01), static_cast<char>(0x03)});
        }else if(right){
            message.insert(message.end(), {static_cast<char>(0x02), static_cast<char>(0x03)});
        }else{
            message.insert(message.end(), {static_cast<char>(0x03), static_cast<char>(0x03)});
        }
    }
    message.insert(message.end(), static_cast<char>(0xFF));
    //udpConnection.Send(message.data(), message.size());
     */
}

void viscaControl::receiveInquiry(vector<char> &data){
    bool validResponse = false;
    while(!validResponse){
        validResponse = udpConnection.Receive(data.data(), data.size()) != 0;
        validResponse = validResponse && data[data.size()-1] == static_cast<char>(0xFF);
    }
}
