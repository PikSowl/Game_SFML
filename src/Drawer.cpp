#include <Drawer.hpp>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace ps
{
    void Engine::Start(){
        sf::RenderWindow window(sf::VideoMode(1040, 1040), "15 puzzle ");

        sf::Texture field;
        field.loadFromFile("assets/field.png");
        background.setTexture(field);
        background.scale(40,40);

        string textureName;
        sf::Texture tileTexture;
        tiles.resize(16);
        tileTextures.resize(16);

        for(int i = 1; i < 16; i++){
            textureName = "";
            if (i > 9){
                textureName = 49;
            }
            textureName.push_back(i%10 + 48);
            textureName += ".png";
            tileTextures.at(i).loadFromFile("assets/" + textureName);
            tiles.at(i).setTexture(tileTextures.at(i));
            tiles.at(i).scale(40,40);
            tiles.at(i).setPosition(40 + ((i-1)%4)*240, 40 + (((i-1)/4)%4)*240);
        }
        Draw(window);
    }

    void Engine::Draw(sf::RenderWindow &window){
        while (window.isOpen())
        {
            window.draw(background);
            while (window.pollEvent(game)){
                if(game.type == sf::Event::EventType::Closed)
                    window.close();
            }
            for(int i = 0; i < 16; i++)
                window.draw(tiles.at(i));
            window.display();
        }
    }

    Engine::~Engine() {}
}