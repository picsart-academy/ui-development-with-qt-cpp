#include <iostream>

#include <iostream>

// Base class Shape
class Shape
{
    public:
        // Method to calculate the area
        double calculateArea() const
        {
            return 0; // Default implementation returns 0
        }
};

// Derived class Circle
class Circle : public Shape
{
    public:
        Circle(double r) : radius(r) 
        {}

        // Getter and setter for radius
        double getRadius() const
        {
            return radius;
        }

        void setRadius(double r)
        {
            radius = r;
        }

        // Overriding calculateArea method for Circle
        double calculateArea() const
        {
            return 3.14 * radius * radius;
        }
    private:
        double radius;
};

// Derived class Rectangle
class Rectangle : public Shape
{
    public:
        // Constructor
        Rectangle(double w, double h) : width(w), height(h) 
        {}

        // Getters and setters for width and height
        double getWidth() const
        {
            return width;
        }

        void setWidth(double w)
        {
            width = w;
        }

        double getHeight() const
        {
            return height;
        }

        void setHeight(double h)
        {
            height = h;
        }

        // Overriding calculateArea method for Rectangle
        double calculateArea() const
        {
            return width * height;
        }
    private:
        double width;
        double height;
};

int main()
{
    // Create objects of Circle and Rectangle
    Circle circle(13);
    Rectangle rectangle(14, 6);

    // Get and set radius of the circle
    std::cout << "Initial radius of the circle: " << circle.getRadius() << std::endl;
    circle.setRadius(7);
    std::cout << "New radius of the circle: " << circle.getRadius() << std::endl;

    // Get and set width and height of the rectangle
    std::cout << "Initial width of the rectangle: " << rectangle.getWidth() << std::endl;
    std::cout << "Initial height of the rectangle: " << rectangle.getHeight() << std::endl;
    rectangle.setWidth(5);
    rectangle.setHeight(8);
    std::cout << "New width of the rectangle: " << rectangle.getWidth() << std::endl;
    std::cout << "New height of the rectangle: " << rectangle.getHeight() << std::endl;

    // Calculate and display the areas
    std::cout << "Area of the circle: " << circle.calculateArea() << std::endl;
    std::cout << "Area of the rectangle: " << rectangle.calculateArea() << std::endl;

    return 0;
}