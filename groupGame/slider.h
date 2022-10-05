#ifndef SLIDER_H
#define SLIDER_H

#include <SFML/Graphics.hpp>
#include <iostream>

//slider source: https://github.com/N4G1/Slider-SFML
class SliderSFML
{
	sf::RectangleShape slider;
	sf::RectangleShape axis;
	sf::Font font;
	sf::Text text;
	float minValue;
	float maxValue;
	float xCord;
	float yCord;
	float axisWidth;
	float axisHeight;
	float sliderWidth;
	float sliderHeight;
	float sliderValue;
public:
	//default constructor
	SliderSFML() : slider() { };
	//constructor taking position argument
	SliderSFML(float x, float y);
	//functions described in cpp file
	sf::Text returnText(float x, float y, std::string z, int fontSize);
	void create(float min, float max);
	void logic(sf::RenderWindow &window);
	float getSliderValue();
	void setSliderValue(float newValue);
	void setSliderPercentValue(float newPercentValue);
	void draw(sf::RenderWindow & window);
};

#endif