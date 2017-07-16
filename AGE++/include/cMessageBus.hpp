//
//  cMessageBus.hpp
//  TestSMFL
//
//  Created by Mariano de Diego Biosca on 19/11/16.
//  Copyright © 2016 Mariano de Diego Biosca. All rights reserved.
//

#ifndef cMessageBus_hpp
#define cMessageBus_hpp

//Standard
#include <stdio.h>
#include <queue>
#include <string>
#include <iostream>

//Local
#include "cMessage.hpp"

class MessageBus
{
private:
    std::queue<Msg*> msgQueue;
    
public:
    MessageBus();
    ~MessageBus();
        
    int pushMessage(Msg* msg);
    int popMessage();
    Msg* getMessage();
    unsigned long getBusSize(){return this->msgQueue.size();}
};

#endif /* cMessageBus_hpp */
