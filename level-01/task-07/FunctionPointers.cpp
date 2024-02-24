#include <iostream>

// Function pointer type for sorting functions
typedef void (*SortFunction)(int*, int);

void bubbleSort(int* array, int size) ;
void selectionSort(int* array, int size);

int main() 
{
    // Array of unsorted integers
    int array[] = {5, 2, 9, 1, 7};

    // Function pointer for sorting algorithm
    SortFunction sortFunc = nullptr;

    // Prompt the user to select a sorting algorithm
    std::cout << "Select a sorting algorithm:\n"
                 "1. Bubble Sort\n"
                 "2. Selection Sort\n";
    int choice = 0;
    std::cin >> choice;

    // Assign the corresponding sorting function based on user's choice
    switch (choice)
    {
        case 1:
            sortFunc = bubbleSort;
            break;
        case 2:
            sortFunc = selectionSort;
            break;
        default:
            std::cout << "Invalid choice! Exiting...\n";
            return 1;
    }

    // Invoke the selected sorting algorithm using the function pointer
    sortFunc(array, sizeof(array) / sizeof(array[0]));

    // Display the sorted array
    std::cout << "Sorted array:";
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
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
        // If no two elements were swapped in the inner loop, the array is already sorted
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
        // Swap the minimum element with the current element if they are different
        if (minIndex != i)
        {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}