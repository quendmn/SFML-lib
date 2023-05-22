#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    //�������� ����
    RenderWindow window(VideoMode(1440, 1024), "Alias"); // ��� �������� �������� L""

    // �������� ������
    Image icon;
    
    if (!icon.loadFromFile("images/icon.png")) return 1;  
    window.setIcon(32, 32, icon.getPixelsPtr());
    //�������� ����
    Texture background;
    background.loadFromFile("images/background.png");  // ������� ��������, ������� ����� ��������� � ������
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

        
        window.clear(); //�������
        window.draw(Backgound);
        window.display(); //������� ��� ������� ���������
    }
    return 0;
}