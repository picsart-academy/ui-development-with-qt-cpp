#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Enum for sorting strategies
enum class SortingStrategy
{
    BUBBLE_SORT,
    SELECTION_SORT,
    INSERTION_SORT
};

typedef void (*SortFunction)(std::vector<int>&);

struct SortingOption
{
    SortingStrategy strategy;
    SortFunction sortFunc;
};


void bubbleSort(std::vector<int>& array);
void selectionSort(std::vector<int>& array);
void insertionSort(std::vector<int>& array);
std::vector<int> readArrayFile(const std::string& fileName);
void writeArrayFile(const std::string& fileName, const std::vector<int>& array);

int main()
{
    // Array of sorting options
    SortingOption sortingOptions[] = {
        {SortingStrategy::BUBBLE_SORT, bubbleSort},
        {SortingStrategy::SELECTION_SORT, selectionSort},
        {SortingStrategy::INSERTION_SORT, insertionSort}
    };

    // Prompt the user for the input file name
    std::string inputFileName;
    std::cout << "Enter the name of the input file: ";
    std::cin >> inputFileName;

    // Read the array of integers from the input file
    std::vector<int> array = readArrayFile(inputFileName);
    if (array.empty())
    {
        return 1; // Exit if reading from file fails
    }
    // Prompt the user to select a sorting algorithm
    std::cout << "Select a sorting algorithm:\n"
                "1. Bubble Sort\n"
                "2. Selection Sort\n"
                "3. Insertion Sort\n";
    int choice = 0;
    std::cin >> choice;

    // Validate user's choice
    if (choice < 1 || choice > 3)
    {
        std::cerr << "Invalid choice! Exiting...\n";
        return 1;
    }
    // Select the sorting option based on user's choice
    SortingOption selectedOption = sortingOptions[choice - 1];

    // Execute the selected sorting strategy
    selectedOption.sortFunc(array);

    // Prompt the user for the output file name
    std::string outputFileName;
    std::cout << "Enter the name of the output file: ";
    std::cin >> outputFileName;

    // Save the sorted array to the output file
    writeArrayFile(outputFileName, array);

    std::cout << "Sorting completed. Sorted array saved to " << outputFileName << std::endl;

    return 0;
}

// Bubble sort algorithm
void bubbleSort(std::vector<int>& array)
{
    bool swapped = false;
    int size = array.size();
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                // Swap elements if they are in the wrong order
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            return;
        }
    }
}

// Selection sort algorithm
void selectionSort(std::vector<int>& array)
{
    int size = array.size();
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

// Insertion sort algorithm
void insertionSort(std::vector<int>& array)
{
    int size = array.size();
    for (int i = 1; i < size; ++i)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

// Function to read an array of integers from a file
std::vector<int> readArrayFile(const std::string& fileName)
{
    std::vector<int> result;
    std::ifstream inputFile(fileName, std::fstream::out); //f the file is not found, it will not be created
    if (!inputFile)
    {
        std::cerr << "Failed to open the file for reading: " << fileName << std::endl;
        return result; // Return empty array if file open fails
    }
    int num = 0;
    while (inputFile >> num)
    {
        result.push_back(num);
    }
    inputFile.close();
    return result;
}

// Function to save an array of integers to a file
void writeArrayFile(const std::string& fileName, const std::vector<int>& array)
{
    std::ofstream outputFile(fileName);
    if (!outputFile)
    {
        std::cerr << "Failed to open the file for reading: " << fileName << std::endl;
        return;
    }
    for (int i = 0; i < array.size(); ++i)
    {
        outputFile << array[i] << " ";
    }
    outputFile.close();
}