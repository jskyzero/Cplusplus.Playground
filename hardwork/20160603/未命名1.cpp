#include<iostream>

using namespace std;

class Rectangle
{
  private:
    double width, height;
  public:
    Rectangle()
    {
    	width = 0;
    	height = 0;
	}
    Rectangle(double width, double height)
    {
    	this->width = width;
    	this->height = height;
	}
    double getWidth()
    {
    	return this->width;
	}
    double getHeight()
    {
    	return this->height;
	}
    void setWidth(double width)
    {
    	this->width = width;
	}
    void setHeight(double height)
{
	this->height = height;
}
    double getArea()
    {
    	return (this->height * this->width);
	}
    double getPerimeter()
    {
    	return (2 * (this->height + this->width));
	}
}; 
