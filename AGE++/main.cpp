
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1024, 768), "AGE++ Test");
    
    MessageBus* theMsgBus = new MessageBus();
    Console* theConsole = new Console(theMsgBus,window);
    int mTest = 0;
    std::cout << resourcePath() << std::endl;
    

    // Start the game loop
    while (window->isOpen())
    {
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            {
                theConsole->activate();
                
            }
            
            // Close window: exit
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window->close();
            }
            
        }
        
        
        // Clear screen
        window->clear();

        // Update the window
        
        std::string msg = "Test";
        msg.append(std::to_string(mTest));
        mTest++;
        
        theConsole->sendCommand(msg);
        theConsole->handleMessage(theMsgBus->getMessage());
        theConsole->draw();
        window->display();
    }

    return EXIT_SUCCESS;
}
