#include <iostream>
#include <stdexcept>

// Base class Shape
class Shape
{
    public:
        virtual ~Shape() {}
        
        // Method to calculate area (potentially throws exception)
        virtual double calculateArea() const = 0;
};

// Derived class Circle
class Circle : public Shape
{
    public:
        // Constructor
        Circle(double radius) : m_radius(radius)
        {}

        // Method to calculate area
        double calculateArea() const override
        {
            if (m_radius <= 0)
            {
                throw std::invalid_argument("Radius must be positive");
            }
            return 3.14 * m_radius * m_radius;
        }

        double getRadius() const
        {
            return m_radius;
        }

        void setRadius(double radius)
        {
            if (radius <= 0)
            {
                throw std::invalid_argument("Radius must be positive");
            }
            m_radius = radius;
        }

    private:
        double m_radius;
};

// Derived class Rectangle
class Rectangle : public Shape
{
    public:
        // Constructor
        Rectangle(double width, double height) : m_width(width), m_height(height)
        {}

        // Method to calculate area
        double calculateArea() const override
        {
            if (m_width <= 0 || m_height <= 0)
            {
                throw std::invalid_argument("Width and height must be positive");
            }
            return m_width * m_height;
        }

        double getWidth() const
        {
            return m_width;
        }

        void setWidth(double width)
        {
            if (width <= 0)
            {
                throw std::invalid_argument("Width must be positive");
            }
            m_width = width;
        }

        double getHeight() const
        {
            return m_height;
        }

        void setHeight(double height)
        {
            if (height <= 0)
            {
                throw std::invalid_argument("Height must be positive");
            }
            m_height = height;
        }
    private:
        double m_width;
        double m_height;
};

int main()
{
    try
    {
        // Create objects of Circle and Rectangle
        Circle circle(5);
        Rectangle rectangle(4, 6);

        // Calculate and print areas
        std::cout << "Area of Circle: " << circle.calculateArea() << std::endl;
        std::cout << "Area of Rectangle: " << rectangle.calculateArea() << std::endl;

        circle.setRadius(-5);
        rectangle.setHeight(0);
    } catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
