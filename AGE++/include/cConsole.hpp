//
//  cConsole.hpp
//  TestSMFL
//
//  Created by Mariano de Diego Biosca on 19/11/16.
//  Copyright © 2016 Mariano de Diego Biosca. All rights reserved.
//

#ifndef cConsole_hpp
#define cConsole_hpp

//Standard
#include <stdio.h>
#include <list>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

//Local
#include "cMessage.hpp"
#include "cMessageBus.hpp"
#include "cGameObject.hpp"

#define NUMBER_OF_LINES    15
#define SCREEN_RATIO        4
#define ID                  0

class Console : public GameObject
{
private:
    bool active;
    sf::Font consoleFont;
    sf::Text consoleText;    
    
    double appendNewLine(std::string line);
    
public:
    Console(MessageBus* msgBus, sf::RenderWindow* window);
    ~Console();
    
    void activate();
    bool isActive(){return this->active;};
    
    void handleMessage(Msg *msg);
    void sendCommand(std::string strMsg);
    
    void update();
    void draw();    
};

#endif /* cConsole_hpp */
