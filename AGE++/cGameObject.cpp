//
//  cObject.cpp
//  TestSMFL
//
//  Created by Mariano de Diego Biosca on 19/11/16.
//  Copyright © 2016 Mariano de Diego Biosca. All rights reserved.
//

#include "cGameObject.hpp"


GameObject::GameObject(MessageBus* msgBus, sf::RenderWindow* window)
{
    this->msgBus = msgBus;
    if(window != nullptr)
    {
        this->window = window;
    }
    else
    {
        std::cout << "Error referenciando la ventana.";
        this->window = nullptr;
    }
    std::get<0>(this->position) = 0;
    std::get<1>(this->position) = 0;
    
    std::get<0>(this->size) = 0;
    std::get<1>(this->size) = 0;
    
    this->texture = nullptr;
    this->sprite = nullptr;
}

GameObject::~GameObject()
{
    if(this->msgBus!=NULL)
    {
        delete this->msgBus;
    }
}

