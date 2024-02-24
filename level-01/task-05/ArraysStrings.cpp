#include <iostream>
#include <cstring> // Include the header file for string manipulation functions

int maximum(const int* arr, int size); // Function to find the maximum value in the array
int minimum(const int* arr, int size); // Function to find the minimum value in the array
double average(const int* arr, int size); // Function to calculate the average value in the array

int strLength(const char* arr);
void strConcatenate(char* dest, const char* src);

int main()
{
    // Define and populate an array of integers
    const int size = 5;
    int numbers[size] = {10, 20, 5, 15, 25};

    // Find and display the maximum value in the array
    std::cout << "Maximum value in the array: " << maximum(numbers, size) << std::endl;

    // Find and display the minimum value in the array
    std::cout << "Minimum value in the array: " << minimum(numbers, size) << std::endl;

    // Calculate and display the average value in the array
    std::cout << "Average value in the array: " << average(numbers, size) << std::endl;

    // Define character arrays
    const int maxSize = 100;
    char str1[maxSize] = "Hello, ";
    char str2[] = "world!";

    // Concatenate str2 to str1
    strConcatenate(str1, str2);
    std::cout << "Concatenated string: " << str1 << std::endl;

    // Calculate and display the length of the concatenated string
    int length = strLength(str1);
    std::cout << "Length of the concatenated string: " << length << std::endl;

    return 0;
}

int maximum(const int* arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
    }
    return max;
}

int minimum(const int* arr, int size)
{
    int min = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

double average(const int* arr, int size)
{
    double sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    return sum / size;
}

int strLength(const char* arr)
{
    int length = 0;
    while (arr[length] != '\0')
    {
        ++length;
    }
    return length;
}

void strConcatenate(char* dest, const char* src)
{
    int destLength = strLength(dest);
    int srcLength = strLength(src);
    for (int i = 0; i < srcLength; ++i)
    {
        dest[destLength + i] = src[i];
    }
    dest[destLength + srcLength] = '\0';
}