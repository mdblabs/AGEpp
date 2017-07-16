//
//  cMessage.hpp
//  TestSMFL
//
//  Created by Mariano de Diego Biosca on 24/11/16.
//  Copyright © 2016 Mariano de Diego Biosca. All rights reserved.
//

#ifndef cMessage_hpp
#define cMessage_hpp

//Standard
#include <stdio.h>
#include <string>

//Local


class Msg
{
private:
    int codeID;
    int senderID;
    int receiverID;
    std::string msg;
    
public:
    Msg(int cID, int sID, int rID, std::string ms);
    ~Msg();
    
    int getCode(){return this->codeID;}
    int getSender(){return this->senderID;}
    int getReceiver(){return this->receiverID;}
    std::string getMsg(){return this->msg;}
};


#endif /* cMessage_hpp */
