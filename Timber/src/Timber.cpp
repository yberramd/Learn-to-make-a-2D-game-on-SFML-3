// Timber.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Timber", sf::Style::Default, sf::State::Fullscreen);

    // Background
    sf::Texture textureBackground("graphics\\background.jpg");
    sf::Sprite spriteBackground(textureBackground);

    //Tree
    sf::Texture textureTree("graphics\\tree.png");
    sf::Sprite spriteTree(textureTree);
    spriteTree.setScale({0.45f, 0.8f});
    spriteTree.setPosition({500, 0});

    //Cloud
    sf::Texture textureCloud("graphics\\cloud.png");
    sf::Sprite spriteCloud(textureCloud);

    //Bee
    sf::Texture textureBee("graphics\\bee.png");
    sf::Sprite spriteBee(textureBee);

    //In Game Variables :

    int playerScore = 0;

    bool isAlive = true;

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }
        
        window.clear();

        window.draw(spriteBackground);
        window.draw(spriteCloud);
        window.draw(spriteTree);
        window.draw(spriteBee);
        

        window.display();
    }
    
    return 0;
}