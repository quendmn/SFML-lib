#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    //создание окна
    RenderWindow window(VideoMode(1440, 1024), "Alias"); // для русского названия L""

    // создание иконки
    Image icon;
    
    if (!icon.loadFromFile("images/icon.png")) return 1;  
    window.setIcon(32, 32, icon.getPixelsPtr());
    //создание фона
    Texture background;
    background.loadFromFile("images/background.png");  // создали текстуру, которую нужно применять к фигуре
    RectangleShape Backgound(Vector2f(1440, 1024));
    Backgound.setTexture(&background);
    Backgound.setPosition(Vector2f(0, 0));
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        
        window.clear(); //очищает
        window.draw(Backgound);
        window.display(); //выводит все объекты отрисовки
    }
    return 0;
}