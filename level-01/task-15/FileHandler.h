#ifndef _FILE_HANDLER_H_
#define _FILE_HANDLER_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Class for handling file input and output operations
class FileHandler
{
    public:
        // Method to read an array of integers from a file
        std::vector<int> readArrayFromFile(const std::string&) const;

        // Method to save an array of integers to a file
        void saveArrayToFile(const std::string&, const std::vector<int>&) const;
};

// Method to read an array of integers from a file
std::vector<int> FileHandler::readArrayFromFile(const std::string& fileName) const
{
    std::vector<int> result;
    // Open the input file
    std::ifstream inputFile(fileName, std::fstream::out); // If the file is not found, it will not be created
    // Check if file open is successful
    if (!inputFile)
    {
        std::cerr << "Failed to open the file for reading: " << fileName << std::endl;
        return result; // Return empty array if file open fails
    }
    int num = 0;
    // Read integers from file and store them in the result vector
    while (inputFile >> num)
    {
        result.push_back(num);
    }
    // Close the input file
    inputFile.close();
    return result;
}

// Method to save an array of integers to a file
void FileHandler::saveArrayToFile(const std::string& fileName, const std::vector<int>& array) const
{
    // Open the output file
    std::ofstream outputFile(fileName);
    // Check if file open is successful
    if (!outputFile)
    {
        std::cerr << "Failed to open the file for writing: " << fileName << std::endl;
        return;
    }
    // Write integers from the array to the output file
    for (int i = 0; i < array.size(); ++i)
    {
        outputFile << array[i] << " ";
    }
    // Close the output file
    outputFile.close();
}

#endif //_FILE_HANDLER_H_
