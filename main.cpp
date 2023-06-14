#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

using namespace sf;

const int H = 20;
const int W = 10;

int field[H][W] = { 0 };
int s = 34;

struct P
{
    int x, y;
}a[4], b[4];

int figures[7][4] = {
    1,3,5,7,
    2,4,5,7,
    3,5,4,6,
    3,5,4,7,
    2,3,5,7,
    3,5,7,6,
    2,3,4,5,
};

bool check() {
    for (int i = 0; i < 4; i++)
        if (a[i].x < 0 || a[i].x >= W || a[i].y >= H)
            return 0;
        else if (field[a[i].y][a[i].x])
            return 0;

    return 1;
}

int main()
{
    srand(time(0));

    RenderWindow window(VideoMode(W * s, H * s), "Tetris!");

    Texture t1;
    t1.loadFromFile("C:/Users/Глеб/Downloads/tiles.png");
    


    Sprite tiles(t1);

    int dx = 0, colorNum = 1;
    bool rotate = false;
    float timer = 0, delay = 0.3;
    Clock clock;
    bool ad = true;

    int g = 0;

    Texture go;
    go.loadFromFile("C:/Users/Глеб/Downloads/gameover.png");
    Sprite gameover(go);
    gameover.setPosition(10, 300);
    gameover.setScale(0.4, 0.4);

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed)
                if (event.key.code == Keyboard::Up)
                    rotate = true;
                else if (event.key.code == Keyboard::Right)
                    dx = 1;
                else if (event.key.code == Keyboard::Left)
                    dx = -1;
        }


        if (Keyboard::isKeyPressed(Keyboard::Down))
            delay = 0.05;

        for (int i = 0; i < 4; i++) {
            b[i] = a[i];
            a[i].x += dx;
        }

        if (!check()) {
            for (int i = 0; i < 4; i++)
                a[i] = b[i];
        }

        if (rotate) {
            P p = a[1];
            for (int i = 0; i < 4; i++) {
                int x = a[i].y - p.y;
                int y = a[i].x - p.x;

                a[i].x = p.x - x;
                a[i].y = p.y + y;
            }

            if (!check()) {
                for (int i = 0; i < 4; i++)
                    a[i] = b[i];
            }
        }

        if (timer > delay) {
            for (int i = 0; i < 4; i++) {
                b[i] = a[i];
                a[i].y += 1;
            }

            if (!check()) {
                for (int i = 0; i < 4; i++)
                    field[b[i].y][b[i].x] = colorNum;
                colorNum = 1 + rand() % 7;
                int n = rand() % 7;
                for (int i = 0; i < 4; i++) {
                    a[i].x = figures[n][i] % 2;
                    a[i].y = figures[n][i] / 2;
                }
            }

            timer = 0;
        }

        
        for (int i = 0; i < 4; i++) {
            if (a[i].y > 0 && a[i].y < 4) 
                g++;
            else if (a[i].y >= 4) 
                g = 0;
        }

        std::cout << g << "\n";

        if (ad) {
            int n = rand() % 7;
            if (a[0].x == 0)
                for (int i = 0; i < 4; i++) {
                    a[i].x = figures[n][i] % 2;
                    a[i].y = figures[n][i] / 2;
                }
            ad = false;
        }

        int k = H - 1;
        for (int i = H - 1; i > 0; i--) {
            int count = 0;
            for (int j = 0; j < W; j++) {
                if (field[i][j])
                    count++;
                field[k][j] = field[i][j];
            }
            if (count < W)
                k--;
        }

        dx = 0;
        rotate = false;
        delay = 0.3;

        window.clear(Color::White);

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++) {
                if (field[i][j] == 0)
                    continue;
                tiles.setTextureRect(IntRect(field[i][j] * s, 0, s, s));
                tiles.setPosition(j * s, i * s);
                window.draw(tiles);
            }

        for (int i = 0; i < 4; i++) {
            tiles.setTextureRect(IntRect(colorNum * s, 0, s, s));
            tiles.setPosition(a[i].x * s, a[i].y * s);
            window.draw(tiles);
        }

        if (g > 2000) 
            window.draw(gameover);

        window.display();
    }

    return 0;
}