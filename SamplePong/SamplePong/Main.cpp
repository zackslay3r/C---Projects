#include <iostream>
#include <SFML/Graphics.hpp>
int player1score = 0;
int player2score = 0;

bool intersects(sf::CircleShape& c1, sf::RectangleShape& rect2) {
	sf::FloatRect circle = c1.getGlobalBounds();
	sf::FloatRect rectangle = rect2.getGlobalBounds();
	return circle.intersects(rectangle);
}
int main() {
	sf::VideoMode videomode(400, 400);
	sf::RenderWindow window(videomode, "PONG");
	sf::CircleShape Ball;
	Ball.setFillColor(sf::Color::Red);
	Ball.setRadius(10);
	Ball.setPosition(100, 200);
	sf::RectangleShape firstPlayer;
	firstPlayer.setFillColor(sf::Color::Black);
	firstPlayer.setSize(sf::Vector2f(10, 50));
	firstPlayer.setPosition(30, 200);

	sf::RectangleShape secondPlayer;
	secondPlayer.setFillColor(sf::Color::Black);
	secondPlayer.setSize(sf::Vector2f(10, 50));
	secondPlayer.setPosition(370, 200);

	sf::RectangleShape outleft;
	outleft.setFillColor(sf::Color::Black);
	outleft.setSize(sf::Vector2f(10, 400));
	outleft.setPosition(390, 0);

	sf::RectangleShape outright;
	outright.setFillColor(sf::Color::Black);
	outright.setSize(sf::Vector2f(10, 400));
	outright.setPosition(0, 0);





	sf::RectangleShape mid;
	mid.setFillColor(sf::Color::Blue);
	mid.setSize(sf::Vector2f(20, 400));
	mid.setPosition(200, 0);

	sf::RectangleShape up;
	up.setFillColor(sf::Color::Blue);
	up.setSize(sf::Vector2f(20, 400));
	up.setPosition(400, 0);
	up.rotate(90);

	sf::RectangleShape down;
	down.setFillColor(sf::Color::Blue);
	down.setSize(sf::Vector2f(20, 400));
	down.setPosition(400, 380);
	down.rotate(90);
	sf::RectangleShape left;
	sf::RectangleShape right;
	sf::Vector2<float>ballSpeed(0.1, 0.1);








	while (window.isOpen()) {
		window.clear(sf::Color::Yellow);
		window.draw(mid);
		window.draw(Ball);
		window.draw(secondPlayer);
		window.draw(down);
		window.draw(up);
		window.draw(firstPlayer);
		window.draw(outleft);
		window.draw(outright);


		window.display();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			firstPlayer.move(0, -0.1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			firstPlayer.move(0, 0.1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			secondPlayer.move(0, -0.1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			secondPlayer.move(0, 0.1);
		}
		if (intersects(Ball, outleft)) {
			player1score++;
			Ball.setPosition(100, 200);
			std::cout << "Player1=  " << player1score << std::endl;
		}
		if (intersects(Ball, outright)) {
			player2score++;
			Ball.setPosition(100, 200);
			std::cout << "Player2 =  " << player2score << std::endl;
		}
		if (intersects(Ball, up) || (intersects(Ball, down))) {
			ballSpeed.y = -ballSpeed.y;
		}
		if (intersects(Ball, firstPlayer) || (intersects(Ball, secondPlayer))) {
			ballSpeed.x = -ballSpeed.x;
		}
		Ball.move(ballSpeed.x, ballSpeed.y);

	}

}