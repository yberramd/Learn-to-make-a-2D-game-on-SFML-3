// Timber.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Timber", sf::Style::Default, sf::State::Fullscreen);

    sf::Texture textureBackground("graphics\\background.jpg");

    sf::Sprite spriteBackground(textureBackground);

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

        window.display();
    }
    
    return 0;
}