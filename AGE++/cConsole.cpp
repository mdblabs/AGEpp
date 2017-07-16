//
//  cConsole.cpp
//  TestSMFL
//
//  Created by Mariano de Diego Biosca on 19/11/16.
//  Copyright © 2016 Mariano de Diego Biosca. All rights reserved.
//

//Standard
#include <iostream>

//Local
#include "cConsole.hpp"
#include "ResourcePath.hpp"

Console::Console(MessageBus* msgBus, sf::RenderWindow* window):GameObject(msgBus,window)
{
    this->active = false;
    this->messagesList.push_front("");
    if (!this->consoleFont.loadFromFile(resourcePath().append("/assets/fonts/TerminalVector.ttf")))
    {
        std::cout << "Error cargando la tipografia." << std::endl;
    }
    else
    {
        this->consoleText.setFont(this->consoleFont);
    }
    
}

void Console::activate()
{
    this->active = !this->active;
}

double Console::appendNewLine(std::string line)
{
    if(!line.empty())
    {
        this->messagesList.push_front(line);
        return line.size();
    }
    return 0;
}

void Console::handleMessage(Msg *msg)
{
    if(msg!=NULL)
    {
        std::string line = "Msg Code:";
        line.append(std::to_string(msg->getCode()));
        line.append(" -- Sender:");
        line.append(std::to_string( msg->getSender()));
        line.append(" -- Msg:");
        line.append(msg->getMsg());
        line.append(" -- Receiver:");
        line.append(std::to_string(msg->getReceiver()));
        line.append(" -- Bus Size:");
        line.append(std::to_string(msgBus->getBusSize()));
        
        this->appendNewLine(line);        
        
        if(this->messagesList.size()>NUMBER_OF_LINES)
        {
            this->messagesList.pop_back();
        }
        
        
        if(msg->getReceiver() == ID)
        {
            msgBus->popMessage();
        }
    }
}

void Console::sendCommand(std::string strMsg)
{
    if(!strMsg.empty())
    {
        
        Msg* msg_p = new Msg(1, 0, 0, strMsg);
        if(msg_p!=NULL)
        {
            this->msgBus->pushMessage(msg_p);
        }
    }
}

void Console::update()
{
    
}

void Console::draw()
{
    sf::Vector2u windowSize = this->window->getSize();
    int consoleHeight = windowSize.y / SCREEN_RATIO;
    sf::RectangleShape consoleBackground(sf::Vector2f((float)windowSize.x, (float) consoleHeight));
    sf::Color bgColor(173, 186, 173);
    bgColor.a = 50;
    consoleBackground.setFillColor(bgColor);
    consoleBackground.setPosition(0, windowSize.y - consoleHeight);
    int textSize = consoleHeight/NUMBER_OF_LINES;
    int textX = 0;
    int textY = windowSize.y - consoleHeight;
    
    sf::String st;
    if(this->isActive())
    {
        this->window->draw(consoleBackground);
        int lineNumber = 0;
        
        for (std::list<std::string>::iterator it=this->messagesList.begin(); it != this->messagesList.end(); ++it)
        {
            std::string consoleLine = ">";
            consoleLine.append(it->c_str());
            this->consoleText.setString(consoleLine);
            this->consoleText.setCharacterSize(textSize);
            this->consoleText.setFillColor(sf::Color::Green);
            this->consoleText.setPosition(textX, textY + textSize*lineNumber);
            this->window->draw(this->consoleText);
            lineNumber++;
        }
    }
    else
    {
    }
}

