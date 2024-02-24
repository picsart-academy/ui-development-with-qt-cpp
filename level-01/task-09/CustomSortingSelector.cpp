#include <iostream>

// Enum for sorting strategies
enum class SortingStrategy
{
    BUBBLE_SORT,
    SELECTION_SORT
};

typedef void (*SortFunction)(int*, int);

// Struct to represent a sorting option
struct SortingOption
{
    SortingStrategy strategy;
    SortFunction sortFunc;
};


void bubbleSort(int* array, int size);
void selectionSort(int* array, int size);


int main()
{
    // Array of sorting options
    SortingOption sortingOptions[] = {
        {SortingStrategy::BUBBLE_SORT, bubbleSort},
        {SortingStrategy::SELECTION_SORT, selectionSort}
    };

    // Prompt the user to select a sorting algorithm
    std::cout << "Select a sorting algorithm:\n"
                 "1. Bubble Sort\n"
                 "2. Selection Sort\n";
    int choice = 0;
    std::cin >> choice;

    // Select the sorting option based on user's choice
    SortingOption selectedOption;
    switch (choice)
    {
        case 1:
            selectedOption = sortingOptions[0];
            break;
        case 2:
            selectedOption = sortingOptions[1];
            break;
        default:
            std::cout << "Invalid choice! Exiting...\n";
            return 1;
    }

    // Initialize an array of integers with unsorted values
    int array[] = {13, 2, 6, 1, 7, 8, 3, 12, -5};
    int size = sizeof(array) / sizeof(*array);

    // Execute the selected sorting strategy
    selectedOption.sortFunc(array, size);

    // Display the sorted array
    std::cout << "Sorted array:";
    for (int i = 0; i < size; ++i)
    {
        std::cout << " " << array[i];
    }
    std::cout << std::endl;

    return 0;
}

// Bubble sort algorithm
void bubbleSort(int* array, int size)
{
    bool swapped = false;
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
void selectionSort(int* array, int size)
{
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