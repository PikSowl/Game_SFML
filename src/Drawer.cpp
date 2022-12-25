#include <Drawer.hpp>
#include <experimental/random>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using std::string;
using std::vector;

namespace ps
{
    void Engine::Start(){
        sf::RenderWindow  window(sf::VideoMode(26*scale, 26*scale), "15 puzzle ");

        sf::Texture field;
        field.loadFromFile("assets/field.png");
        background.setTexture(field);
        background.scale(scale,scale);

        string textureName;
        tiles.resize(16);
        tileTextures.resize(16);

        for(int i = 1; i < 16; i++){
            textureName = "";
            if (i > 9){
                textureName = char(49);
            }
            textureName.push_back(char(i%10 + 48));
            textureName += ".png";
            tileTextures.at(i).loadFromFile("assets/" + textureName);
            tiles.at(i).setTexture(tileTextures.at(i));
            tiles.at(i).scale(scale,scale);
        }

        Generate();
        Draw(window);
    }

    void Engine::Generate (){
        std::experimental::reseed();
        int a, b;
        for(int i = 1; i < 16; i++)
            grid[(i-1)%4][((i-1)/4)%4] = 0;

        for(int i = 1; i < 16; i++) {
            a = std::experimental::randint(0, 3);
            b = std::experimental::randint(0, 3);
            if (grid[a][b] == 0){
                grid[a][b] = i;
                tiles.at(i).setPosition(scale*(1 + a*6), scale*(1 + b*6));
            }
            else i--;
        }
        int loyd = 0;
        for (int i = 0; i < 16; i++) {
            for (int j = i + 1; j < 16; j++) {
                if (grid[(i) % 4][((i) / 4) % 4] > grid[(j) % 4][((j) / 4) % 4]) loyd+=1;
            }
        }
        if (loyd%2!=0) Generate();
    }

    void Engine::Draw(sf::RenderWindow &window){
        while (window.isOpen())
        {
            window.clear();
            window.draw(background);
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            mx = (pos.x - scale)/scale/6;
            my = (pos.y - scale)/scale/6;


            while (window.pollEvent(game)){
                if(game.type == sf::Event::EventType::Closed)
                    window.close();
                if(game.type == sf::Event::MouseButtonPressed)
                    if (game.mouseButton.button  == sf::Mouse::Left) TryToFlick();
            }
            for(int i = 0; i < 16; i++)
                window.draw(tiles.at(i));
            window.display();

            for(int i = 1; i<16; i++){
                if (grid[(i-1)%4][int((i-1)/4)%4] != i)
                   i = 16;
                if (i == 15){
                    Victory(window);
                }
            }
        }
    }

    void Engine::TryToFlick(){
        if ((vx-1<=mx && vx+1>=mx && vy-1<=my && vy+1>=my)&&(vx==mx || vy==my)&&!(vx==mx && vy==my)){
            int num = grid[mx][my];
            tiles.at(num).setPosition(scale*(1 + 6*vx), scale*(1 + 6*vy));
            grid[vx][vy] = num;
            vx = mx;
            vy = my;
        }
    }

    void Engine::Victory(sf::RenderWindow &window){

        sf::Texture win;
        win.loadFromFile("assets/win.png");
        screen.setTexture(win);
        screen.scale(scale,scale);

        while (window.isOpen()){
            window.clear();
            window.draw(screen);
            while (window.pollEvent(game)) {
                if (game.type == sf::Event::EventType::Closed)
                    window.close();
            }
            window.display();
        }
    }

    Engine::~Engine() = default;
}