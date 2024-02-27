#ifndef _SORTING_APPLICATION_H_
#define _SORTING_APPLICATION_H_

#include "FileHandler.h"
#include "SortingStrategy.h"

// Class representing the sorting application
class SortingApplication
{
    public:
        // Constructor
        SortingApplication() : m_fileHandler{}, m_sortingStrategy{}
        {}
        
        // Destructor
        ~SortingApplication();

        // Copy constructor
        SortingApplication(const SortingApplication&);

        // Move constructor
        SortingApplication(SortingApplication&&);

        // Copy assignment operator
        SortingApplication& operator=(const SortingApplication&);

        // Move assignment operator
        SortingApplication& operator=(SortingApplication&&);

        // Method to start the application
        void startApplication();

    private:
        // Helper method to display the elements of an array
        void showArray(const std::vector<int>&) const;

        // Helper method to get the input file name from the user
        std::string getInputFileName() const;

        // Helper method to get the output file name from the user
        std::string getOutputFileName() const;

        // Helper method to get the sorting strategy from the user
        void getSortingStrategy();

    private:
        FileHandler m_fileHandler;             // Object for handling file operations
        SortingStrategy* m_sortingStrategy;    // Pointer to the selected sorting strategy
};

// Destructor definition
SortingApplication::~SortingApplication()
{
    if (m_sortingStrategy)
    {
        delete m_sortingStrategy;
        m_sortingStrategy = nullptr;
    }
}

// Copy constructor definition
SortingApplication::SortingApplication(const SortingApplication& oth) : m_fileHandler{}
{
    m_sortingStrategy = oth.m_sortingStrategy->copy();
}

// Move constructor definition
SortingApplication::SortingApplication(SortingApplication&& oth) : m_fileHandler{std::move(oth.m_fileHandler)}
{
    m_sortingStrategy = oth.m_sortingStrategy;
    oth.m_sortingStrategy = nullptr;
}

// Copy assignment operator definition
SortingApplication& SortingApplication::operator=(const SortingApplication& oth)
{
    if (this != &oth)
    {
        if (m_sortingStrategy)
        {
            delete m_sortingStrategy;
        }
        m_sortingStrategy = oth.m_sortingStrategy->copy();
    }
    return *this;
}

// Move assignment operator definition
SortingApplication& SortingApplication::operator=(SortingApplication&& oth)
{
    if (this != &oth)
    {
        std::swap(m_sortingStrategy, oth.m_sortingStrategy);
        std::swap(m_fileHandler, oth.m_fileHandler);
    }
    return *this;
}

// Method to display the elements of an array
void SortingApplication::showArray(const std::vector<int>& array) const
{
    for (int x : array)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

// Helper method to get the input file name from the user
std::string SortingApplication::getInputFileName() const
{
    // Prompt the user for the input file name
    std::string inputFileName;
    std::cout << "Enter the name of the input file: ";
    std::cin >> inputFileName;
    return inputFileName;
}

// Helper method to get the output file name from the user
std::string SortingApplication::getOutputFileName() const
{
    // Prompt the user for the output file name
    std::string outputFileName;
    std::cout << "Enter the name of the output file: ";
    std::cin >> outputFileName;
    return outputFileName;
}

// Helper method to get the sorting strategy from the user
void SortingApplication::getSortingStrategy()
{
    // Prompt the user to select a sorting algorithm
    std::cout << "Select a sorting algorithm:\n";
                
    int choice = 0;
    do
    {
        std::cout << "1. Bubble Sort\n"
                    "2. Selection Sort\n"
                    "3. Insertion Sort\n";
        std::cin >> choice;
        switch (choice)
        {
            case 1:
                m_sortingStrategy = new BubbleSort();
                break;
            case 2: 
                m_sortingStrategy = new SelectionSort();
                break;
            case 3:
                m_sortingStrategy = new InsertionSort();
                break;
            default:
                std::cerr << "Invalid choice! Please try again.\n";
                break;
        }
    } while (!m_sortingStrategy);
    return;
}

// Method to start the application
void SortingApplication::startApplication()
{
    std::cout << "Hello, you are in the sorting app. Let's get started" << std::endl;
    std::string inputFileName = this->getInputFileName();
    std::vector<int> array = m_fileHandler.readArrayFromFile(inputFileName);
    if (array.empty())
    {
        return;
    }
    std::cout << "Array values is:" << std::endl;
    this->showArray(array);
    this->getSortingStrategy();
    m_sortingStrategy->sort(array);
    std::cout << "Sorted array values is:" << std::endl;
    this->showArray(array);
    std::string outputFileName = this->getOutputFileName();
    m_fileHandler.saveArrayToFile(outputFileName, array);
    std::cout << "Sorted array save in the " << outputFileName << " file." << std::endl;
    int choice = 0;
    std::cout << "If you want to restart the application, write 1: ";
    std::cin >> choice;
    if (1 == choice)
    {
        this->startApplication();
    }
    return; 
}

#endif //_SORTING_APPLICATION_H_
