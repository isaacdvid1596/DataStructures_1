#include <SFML\Graphics.hpp>
#include <iostream>


int main()
{

	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial",sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setFillColor(sf::Color::Red);
	player.setOrigin(50.0f, 50.0f);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
				{
			case sf::Event::Closed :
				window.close();
				break;
			case sf::Event::Resized :
				//std::cout <<"New Window Width : "<<evnt.size.width<<"New Window Height : "<< evnt.size.height << std::endl; 
				printf("New Window Width: %i New Window Height : %i \n ", evnt.size.width, evnt.size.height);
				break;	
			case sf::Event::TextEntered :
				if(evnt.text.unicode < 128)
				printf("%c", evnt.text.unicode);
				}


			if (evnt.type == evnt.Closed)
					{
				window.close();
					}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition((float)mousePos.x, (float)(mousePos.y));
		}


		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f, 0.1f);
		}
		*/

		window.clear();
		window.draw(player);
		window.display();

	}

}