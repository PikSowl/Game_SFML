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
        int mx, my;
        int vx = 3, vy = 3; //cords of free space
        int grid[4][4];
        int scale = 40;

    public:
        Engine() {}
        ~Engine();

        sf::Event game;
        sf::Sprite background;
        sf::Sprite screen;
        vector<sf::Sprite> tiles;
        vector<sf::Texture> tileTextures;

        void Start();
        void Draw(sf::RenderWindow &window);
        void TryToFlick();
        void Victory(sf::RenderWindow &window);
    };
}