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
    spriteTree.setScale({0.5f, 0.8f});
    spriteTree.setPosition({700, 0});

    //Cloud
    sf::Texture textureCloud("graphics\\cloud.png");
    sf::Sprite spriteCloud1(textureCloud);
    sf::Sprite spriteCloud2(textureCloud);
    sf::Sprite spriteCloud3(textureCloud);

    spriteCloud1.setPosition({0,0});
    spriteCloud2.setPosition({0,250});
    spriteCloud3.setPosition({0,500});

    // Are the coulds currently on screen ?
    bool cloud1Active1 = false;
    bool cloud1Active2 = false;
    bool cloud1Active3 = false;

    // How fast is each cloud ?
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;
    
    //Bee
    sf::Texture textureBee("graphics\\bee.png");
    sf::Sprite spriteBee(textureBee);
    spriteBee.setScale({0.3f, 0.3f});
    spriteBee.setPosition({0, 500});

    //Is the bee currently moving
    bool beeActive = false;
    // How fast can the bee fly
    float beeSpeed = 0.0f;

    // Randomness 
    int number = (rand() % 100);

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
        
        // Clear everything from the last frame
        window.clear();

        // We draw the game scene here 
        window.draw(spriteBackground);

        // The clouds
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        // The tree
        window.draw(spriteTree);
        // Thee bee
        window.draw(spriteBee);
        
        // Show what we drew
        window.display();
    }
    
    return 0;
}