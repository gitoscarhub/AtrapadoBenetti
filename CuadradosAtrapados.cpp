#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>


using namespace sf;
using namespace std;
Texture rojo;
Texture amarillo;

Sprite cuadrado;



int main(){



	RenderWindow App(VideoMode(800, 800), "AtrapadoBenetti");

	amarillo.loadFromFile("cuad_yellowbis.png");
	rojo.loadFromFile("rcircle.png");
	cuadrado.setTexture(amarillo);
	cuadrado.setPosition(200, 200);
	

	

	while (App.isOpen()) {

		Event evt;
		while (App.pollEvent(evt))
		{
			if (evt.type == Event::Closed)
				App.close();

		}
		
		if (Keyboard::isKeyPressed (Keyboard::Space))
		{
			cuadrado.setTexture(rojo);
			
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			
			cuadrado.move(-3, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			cuadrado.move(3, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			cuadrado.move(0, -3);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			cuadrado.move(0, 3);
			
		}
		
		
		FloatRect spriteBounds = cuadrado.getGlobalBounds();
		FloatRect windowBounds = App.getView().getViewport();

		if (!windowBounds.contains(Vector2f(spriteBounds.left, spriteBounds.top)))
		{
			cuadrado.setPosition(max(cuadrado.getPosition().x, windowBounds.left),
				max(cuadrado.getPosition().y, windowBounds.top));
			/*cuadrado.setPosition(min(cuadrado.getPosition().x, windowBounds.left + windowBounds.width - spriteBounds.width),
				min(cuadrado.getPosition().y, windowBounds.top /* + windowBounds.height - spriteBounds.height));*/


			//ESTA PARTE DEL CODIGO NO RESPONDE, Y NO ME DESCRIBE ERROR DE ARGUMENTOS PERO DESAPARECE EL SPRITE
		}
		
		
		App.clear(Color::White);
		App.draw(cuadrado);
		App.display();
	}
		return 0;
	}
