#include <iostream>

// Base INTERFACE class Shape
class Shape
{
    public:
        // Pure virtual function to calculate the area
        virtual double calculateArea() const = 0;
};

class Circle : public Shape
{
    public:
        Circle(double r) : radius(r)
        {}

        // Implementation of the calculateArea method for Circle
        double calculateArea() const override
        {
            return 3.14159 * radius * radius;
        }
    private:
        double radius;
};

class Rectangle : public Shape
{
    public:
        Rectangle(double w, double h) : width(w), height(h)
        {}

        // Implementation of the calculateArea method for Rectangle
        double calculateArea() const override
        {
            return width * height;
        }
    private:
        double width;
        double height;
};

void showArea(const Shape* const); 

int main()
{
    Circle circle(5);
    Rectangle rectangle(4, 6);

    // Show area of circle and rectangle
    showArea(&circle);
    showArea(&rectangle);

    return 0;
}


// Function to show the area of a shape
void showArea(const Shape* const shape)
{
    std::cout << "Area of the shape: " << shape->calculateArea() << std::endl;
}