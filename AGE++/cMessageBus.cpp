//
//  cMessageBus.cpp
//  TestSMFL
//
//  Created by Mariano de Diego Biosca on 19/11/16.
//  Copyright © 2016 Mariano de Diego Biosca. All rights reserved.
//

#include "cMessageBus.hpp"


MessageBus::MessageBus()
{
}

MessageBus::~MessageBus()
{
}

int MessageBus::pushMessage(Msg* msg)
{
    if(msg!=NULL)
    {
        this->msgQueue.push(msg);
    }
    return 1;
}

int MessageBus::popMessage()
{
    this->msgQueue.pop();
    return 0;
}

Msg* MessageBus::getMessage()
{
    if(!this->msgQueue.empty())
    {
        return this->msgQueue.back();
    }
    
    return NULL;
}
