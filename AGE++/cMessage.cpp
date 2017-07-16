//
//  cMessage.cpp
//  TestSMFL
//
//  Created by Mariano de Diego Biosca on 24/11/16.
//  Copyright © 2016 Mariano de Diego Biosca. All rights reserved.
//

#include "cMessage.hpp"

Msg::Msg(int cID, int sID, int rID, std::string ms)
{
    this->codeID = cID;
    this->senderID = sID;
    
    //Receiver ID = 0, to send to everyone.
    this->receiverID = 0;
    if(rID!= 0)
    {
        this->receiverID = rID;
    }
    this->msg = "";
    if(!ms.empty())
    {
        this->msg = ms;
    }
    
}