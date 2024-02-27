#ifndef _SORTING_STRATEGY_H_
#define _SORTING_STRATEGY_H_

#include <vector>
#include <utility>

// Abstract base class for sorting strategies
class SortingStrategy
{
    public:
        // Virtual destructor
        virtual ~SortingStrategy() {}

        // Pure virtual method to perform sorting
        virtual void sort(std::vector<int>&) const = 0;

        // Pure virtual method to create a copy of the sorting strategy
        virtual SortingStrategy* copy() const = 0;
};

// Bubble sort strategy
class BubbleSort : public SortingStrategy
{
    public:
        // Sort method implementation for bubble sort
        void sort(std::vector<int>&) const override;

        // Method to create a copy of the bubble sort strategy
        SortingStrategy* copy() const override;
};

// Sort method implementation for bubble sort
void BubbleSort::sort(std::vector<int>& array) const
{
    bool swapped = false;
    int size = array.size();
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            return;
        }
    }
}

// Method to create a copy of the bubble sort strategy
SortingStrategy* BubbleSort::copy() const
{
    return new BubbleSort(*this);
}

// Selection sort strategy
class SelectionSort : public SortingStrategy
{
    public:
        // Sort method implementation for selection sort
        void sort(std::vector<int>&) const override;

        // Method to create a copy of the selection sort strategy
        SortingStrategy* copy() const override;
};

// Sort method implementation for selection sort
void SelectionSort::sort(std::vector<int>& array) const
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
            std::swap(array[i], array[minIndex]);
        }
    }
}

// Method to create a copy of the selection sort strategy
SortingStrategy* SelectionSort::copy() const
{
    return new SelectionSort(*this);
}

// Insertion sort strategy
class InsertionSort : public SortingStrategy
{
    public:
        // Sort method implementation for insertion sort
        void sort(std::vector<int>&) const override;

        // Method to create a copy of the insertion sort strategy
        SortingStrategy* copy() const override;
};

// Sort method implementation for insertion sort
void InsertionSort::sort(std::vector<int>& array) const
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

// Method to create a copy of the insertion sort strategy
SortingStrategy* InsertionSort::copy() const
{
    return new InsertionSort(*this);
}

#endif //_SORTING_STRATEGY_H_
