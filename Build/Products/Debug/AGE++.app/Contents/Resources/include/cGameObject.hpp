//
//  cObject.hpp
//  TestSMFL
//
//  Created by Mariano de Diego Biosca on 19/11/16.
//  Copyright © 2016 Mariano de Diego Biosca. All rights reserved.
//

#ifndef cGameObject_hpp
#define cGameObject_hpp

#include <stdio.h>

//Standard
#include <stdio.h>
#include <list>
#include <tuple>
#include <SFML/Graphics.hpp>

//Local
#include "cMessage.hpp"
#include "cMessageBus.hpp"

class GameObject
{
private:
    
protected:
    MessageBus* msgBus;
    std::list <std::string> messagesList;
    sf::RenderWindow* window;
    std::tuple <int,int> position;
    std::tuple <int,int> size;
    
    sf::Texture* texture;
    sf::Sprite*  sprite;

public:
    GameObject(MessageBus* msgBus, sf::RenderWindow* window);
    ~GameObject();
    
    virtual void handleMessage(Msg *msg) = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    
    void setPosition(std::tuple<int,int> pos);
    std::tuple<int,int> getPosition(){return position;};
    
    void setSize(std::tuple<int,int> size);
    std::tuple<int,int> getSize(){return size;};
    
    /*NO: dependerá de si es desde una imagen,etc
    void setTexture(sf::Texture* texture);
    sf::Texture* getTexture(){return texture;};
    
    void setSrpite(sf::Texture* texture);
    sf::Texture* getTexture(){return texture;};
     */
    
};


#endif /* cGameObject_hpp */
