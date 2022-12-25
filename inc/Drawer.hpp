#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using std::vector;


namespace ps
{
    class Engine
    {
    private:

    public:
        Engine() {}
        ~Engine();

        sf::Event game;
        sf::Sprite background;
        vector<sf::Sprite> tiles;
        vector<sf::Texture> tileTextures;

        void Start();
        void Draw(sf::RenderWindow &window);
    };
}