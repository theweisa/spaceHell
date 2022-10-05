#include "slider.h"

//slider source: https://github.com/N4G1/Slider-SFML
SliderSFML::SliderSFML(float x, float y)
{
	// Initialize the coordinate to specify the location of slider
	xCord = x;
	yCord = y;
	// Initiallize the dimention of axis (=the part which is fixed)
	axisHeight = 10.f;
	axisWidth = 200.f;
	// Initialize the dimention of slider (=the part which we move)
	sliderWidth = 20.f;
	sliderHeight = 30.f;

	// Change the file name to load the font we use in the game
	if (!font.loadFromFile("Fonts/Minecraft.ttf"))
		std::cout << "Error loading font\n";

	// Set the font and color of text (=the number on slider)
	text.setFont(font);
	text.setFillColor(sf::Color::White);

	// Set the position, origin, size and color of rectangle object to be axis
	axis.setPosition(x, y);
	axis.setOrigin(0.f, axisHeight / 2.f);
	axis.setSize(sf::Vector2f(axisWidth, axisHeight));
	axis.setFillColor(sf::Color(63, 63, 63));
	// Set the position, origin, size and color of rectangle object to be slider
	slider.setPosition(x, y);
	slider.setOrigin(sliderWidth / 2, sliderHeight / 2);
	slider.setSize(sf::Vector2f(sliderWidth, sliderHeight));
	slider.setFillColor(sf::Color(192, 192, 192));
}

sf::Text SliderSFML::returnText(float x, float y, std::string z, int fontSize)
{
	// Set the size, position, and containts of text and return it
	text.setCharacterSize(fontSize);
	text.setPosition(x, y);
	text.setString(z);
	return text;
}

void SliderSFML::create(float min, float max)
{
	// Set the position of slider to the minimum value (=the left most)
	sliderValue = min;
	// Set the minimum and maximum values to specify the range of axis
	minValue = min;
	maxValue = max;
}

void SliderSFML::logic(sf::RenderWindow &window)
{
	// If a mouse position is on the slider and its left button is pressed
	if (slider.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
		&& sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		// If a mouse position is at the point on the axis
		if (sf::Mouse::getPosition(window).x >= xCord && sf::Mouse::getPosition(window).x <= xCord + axisWidth)
		{
			// Set the position of slider to the location where the mouse is
			slider.setPosition(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(yCord));
			// Caliculate at what value the slider is within the range of axis
			sliderValue = (minValue + ((slider.getPosition().x - xCord) / axisWidth * (maxValue - minValue)));
		}
	}
}

float SliderSFML::getSliderValue()
{
	// Return the value of the position of slider in the range of axis
	return sliderValue;
}

void SliderSFML::setSliderValue(float newValue)
{
	// If new value is within therange of axis
	if (newValue >= minValue && newValue <= maxValue)
	{
		// Set the value of the position of slider to the new value
		sliderValue = newValue;
		// Caliculate where the new value is located within the range of axis
		float diff = maxValue - minValue;
		float diff2 = newValue - minValue;
		float zzz = axisWidth / diff;
		float posX = zzz * diff2;
		posX += xCord;
		// Set the x-position of slider to the new value (the y-position remains unchanged)
		slider.setPosition(posX, yCord);
	}
}

void SliderSFML::setSliderPercentValue(float newPercentValue)
{
	// If new percent value is between 0 and 100
	if (newPercentValue >= 0 && newPercentValue <= 100)
	{
		// Caliculate where the new percent value is located within 0-100%
		sliderValue = newPercentValue / 100 * maxValue;
		// Set the x-position of slider to the new percent value (the y-position remains unchanged)
		slider.setPosition(xCord + (axisWidth*newPercentValue / 100), yCord);
	}
}

void SliderSFML::draw(sf::RenderWindow &window)
{
	// Move the slider using window.
	logic(window);
	// Display the text for minimum value of slider
	window.draw(returnText(xCord - 10, yCord + 5, std::to_string((int)minValue), 20));
	// Display the rectangle object to be axis
	window.draw(axis);
	// Display the text for maximum value for slider
	window.draw(returnText(xCord + axisWidth - 10, yCord + 5, std::to_string((int)maxValue), 20));
	// Display the rectangle object to be slider
	window.draw(slider);
	// Display the text for the value of the location of slider on the axis
	window.draw(returnText(slider.getPosition().x - sliderWidth, slider.getPosition().y - sliderHeight, std::to_string((int)sliderValue), 15));
}
