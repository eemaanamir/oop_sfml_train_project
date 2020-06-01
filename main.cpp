#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>


class Button
{
    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;
    int x;
    int y;
    int width;
    int height;
    sf::Color color;
    public:
    Button(float x, float y, float width, float height,sf::Font* font,std::string text,sf::Color color)
    {
        this->x=x;
        this->y=y;
        this->width=width;
        this->height=height;
        this->shape.setPosition(sf::Vector2f(x,y));
        this->shape.setSize(sf::Vector2f(width,height));
        this->font=font;
        this->text.setFont(*this->font);
        this->text.setString(text);
        this->text.setFillColor(sf::Color::Black);
        this->text.setCharacterSize(16);
        this->text.setPosition(x+5,y+5);

        this->shape.setFillColor(color);
    }
    void render(sf::RenderWindow& win)
    {
        win.draw(this->shape);
        win.draw(this->text);
    }
    bool isPressed(sf::Vector2i mousePosition)
    {
        if(mousePosition.x<x+width && mousePosition.x>x && mousePosition.y<y+height && mousePosition.y>y)
            return true;
        return false;
    }
};



int main()
{

    sf::RenderWindow window(sf::VideoMode(1125, 562.5), "TRAIN STATION APP",sf::Style::Close);

    sf::RectangleShape background(sf::Vector2f(1125.0f,562.5f));
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("background.jpg");
    background.setTexture(&backgroundTexture);

    sf::Font buttonFont;
    buttonFont.loadFromFile("Raleway-Medium.ttf");

    Button quitButton(950,500,120,30,&buttonFont,"Quit",sf::Color(255,255,255,180));
    Button printButton(950,460,120,30,&buttonFont,"Print Train",sf::Color(255,255,255,180));
    Button findButton(950,420,120,30,&buttonFont,"Find Bogie",sf::Color(255,255,255,180));
    Button reserveButton(950,380,120,30,&buttonFont,"Reserve Bogie",sf::Color(255,255,255,180));
    Button deleteButton(950,340,120,30,&buttonFont,"Delete Bogie",sf::Color(255,255,255,180));
    Button addButton(950,300,120,30,&buttonFont,"Add Bogie",sf::Color(255,255,255,180));

    sf::Font titleFont;
    titleFont.loadFromFile("PlayfairDisplay-Bold.otf");

    sf::Text Heading1;
    Heading1.setString("WELCOME TO PLATFORM  9 3/4");
    Heading1.setFont(titleFont);
    Heading1.setCharacterSize(40);
    Heading1.setFillColor(sf::Color(255,255,255,255));
    Heading1.setOutlineColor(sf::Color::Black);
    Heading1.setPosition(75,40);

    sf::Text Heading2;
    Heading2.setString("THIS IS YOUR HOGWARTS EXPRESS!!");
    Heading2.setFont(titleFont);
    Heading2.setCharacterSize(20);
    Heading2.setFillColor(sf::Color(255,255,255,255));
    Heading2.setOutlineColor(sf::Color::Black);
    Heading2.setPosition(180,100);

    sf::Text Heading3;
    Heading3.setString("Please select one \nof the following \noptions to proceed:");
    Heading3.setFont(titleFont);
    Heading3.setCharacterSize(16);
    Heading3.setFillColor(sf::Color(255,255,255,255));
    Heading3.setPosition(935,230);

    while (window.isOpen())
    {

        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            if(quitButton.isPressed(mousePosition))
                window.close();
            else if(addButton.isPressed(mousePosition))
            {

            }
            else if(deleteButton.isPressed(mousePosition))
            {

            }
            else if(reserveButton.isPressed(mousePosition))
            {

            }
            else if(findButton.isPressed(mousePosition))
            {

            }
            else if(printButton.isPressed(mousePosition))
            {

            }
        }

        window.clear();
        window.draw(background);

        window.draw(Heading1);
        window.draw(Heading2);
        window.draw(Heading3);

        addButton.render(window);
        deleteButton.render(window);
        reserveButton.render(window);
        findButton.render(window);
        printButton.render(window);
        quitButton.render(window);


        window.display();
    }

    return 0;
}
