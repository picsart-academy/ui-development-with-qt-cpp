#include <iostream>
#include <stdexcept>

template <typename T>
class Shape
{
public:
    virtual ~Shape() {} // Virtual destructor

    // Virtual function to calculate area
    virtual T calculateArea() const = 0;    
};

template <typename T>
class Circle : public Shape<T>
{
public:
    // Constructor
    Circle(T radius) : m_radius(radius) {}

    // Method to calculate area
    T calculateArea() const override;

    // Getter and setter for radius
    T getRadius() const;
    void setRadius(T radius);

private:
    T m_radius; // Radius of the circle
};

// Method to calculate area of the circle
template <typename T>
T Circle<T>::calculateArea() const
{
    // Check if radius is valid
    if (m_radius <= 0)
    {
        throw std::invalid_argument("Radius must be positive");
    }
    return 3.14 * m_radius * m_radius; // Calculate and return area
}

// Getter for radius
template <typename T>
T Circle<T>::getRadius() const
{
    return m_radius;
}

// Setter for radius
template <typename T>
void Circle<T>::setRadius(T radius)
{
    // Check if radius is valid
    if (radius <= 0)
    {
        throw std::invalid_argument("Radius must be positive");
    }
    m_radius = radius; // Set radius
}

template <typename T>
class Rectangle : public Shape<T>
{
public:
    // Constructor
    Rectangle(T width, T height) : m_width(width), m_height(height) {}

    // Method to calculate area
    T calculateArea() const override;

    // Getters and setters for width and height
    T getWidth() const;
    void setWidth(T width);
    T getHeight() const;
    void setHeight(T height);

private:
    T m_width; // Width of the rectangle
    T m_height; // Height of the rectangle
};

// Method to calculate area of the rectangle
template <typename T>
T Rectangle<T>::calculateArea() const
{
    // Check if width and height are valid
    if (m_width <= 0 || m_height <= 0)
    {
        throw std::invalid_argument("Width and height must be positive");
    }
    return m_width * m_height; // Calculate and return area
}

// Getter for width
template <typename T>
T Rectangle<T>::getWidth() const
{
    return m_width;
}

// Setter for width
template <typename T>
void Rectangle<T>::setWidth(T width)
{
    // Check if width is valid
    if (width <= 0)
    {
        throw std::invalid_argument("Width must be positive");
    }
    m_width = width; // Set width
}

// Getter for height
template <typename T>
T Rectangle<T>::getHeight() const
{
    return m_height;
}

// Setter for height
template <typename T>
void Rectangle<T>::setHeight(T height)
{
    // Check if height is valid
    if (height <= 0)
    {
        throw std::invalid_argument("Height must be positive");
    }
    m_height = height; // Set height
}

int main()
{
    try
    {
        // Create objects of Circle and Rectangle with different data types
        Circle<int> circleInt(5);
        Rectangle<double> rectangleDouble(4.1, 6.2);
        Circle<float> circleFloat(6.3);
        Rectangle<long> rectangleLong(7L, 15L);

        // Calculate and print areas
        std::cout << "Area of Circle<int>: " << circleInt.calculateArea() << std::endl;
        std::cout << "Area of Rectangle<double>: " << rectangleDouble.calculateArea() << std::endl;
        std::cout << "Area of Circle<float>: " << circleFloat.calculateArea() << std::endl;
        std::cout << "Area of Rectangle<long>: " << rectangleLong.calculateArea() << std::endl;
    } 
    catch (const std::exception& e)
    {
        // Catch and handle exceptions
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
