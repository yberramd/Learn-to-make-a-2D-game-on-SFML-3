// Timber.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::Window window(sf::VideoMode({ 1920, 1080 }), "Timber", sf::Style::Default);

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

    }

    return 0;
}