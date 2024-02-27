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
        // Constructors and Destructor
        FileHandler() : m_inputFile{}, m_outputFile{} {}
        FileHandler(const std::string&, const std::string&);
        FileHandler(const FileHandler&) = delete;
        FileHandler& operator=(const FileHandler&) = delete;
        FileHandler(FileHandler&&);
        FileHandler& operator=(FileHandler&&);
        ~FileHandler();

        // Public Member Functions
        void closeInputFile(); // Close the input file stream
        void closeOutputFile(); // Close the output file stream

        // Read an array of integers from a file
        std::vector<int> readArrayFromFile(std::string);
        std::vector<int> readArrayFromFile();

        // Save an array of integers to a file
        void saveArrayToFile(std::string, const std::vector<int>&);
        void saveArrayToFile(const std::vector<int>&);
    private:
        std::ifstream m_inputFile; // Input file stream
        std::ofstream m_outputFile; // Output file stream
        std::string m_inputFileName; // Name of the input file
        std::string m_outputFileName; // Name of the output file
};

// Constructor with filename parameters
FileHandler::FileHandler(const std::string& inputFile, const std::string& outputFile) : 
    m_inputFile{inputFile}, m_outputFile{outputFile}, m_inputFileName{inputFile}, m_outputFileName{outputFile}
{}

// Move Constructor
FileHandler::FileHandler(FileHandler&& oth) : 
    m_inputFile{std::move(oth.m_inputFile)}, m_outputFile{std::move(oth.m_outputFile)},
    m_inputFileName{std::move(oth.m_inputFileName)}, m_outputFileName{std::move(oth.m_outputFileName)}
{}

// Move Assignment Operator
FileHandler& FileHandler::operator=(FileHandler&& oth)
{
    if (this != &oth)
    {
        closeInputFile();
        closeOutputFile();
        std::swap(m_inputFile, oth.m_inputFile);
        std::swap(m_outputFile, oth.m_outputFile);
        std::swap(m_inputFileName, oth.m_inputFileName);
        std::swap(m_outputFileName, oth.m_outputFileName);
    }
    return *this;
}

// Destructor
FileHandler::~FileHandler()
{
    closeInputFile();
    closeOutputFile();
}

// Close the input file stream
void FileHandler::closeInputFile()
{
    if (m_inputFile.is_open())
    {
        m_inputFile.close();
    }
    m_inputFileName.clear(); // Clear the filename
}

// Close the output file stream
void FileHandler::closeOutputFile()
{
    if (m_outputFile.is_open())
    {
        m_outputFile.close();
    }
    m_inputFileName.clear(); // Clear the filename
}

// Read an array of integers from a file
std::vector<int> FileHandler::readArrayFromFile(std::string fileName)
{
    std::vector<int> result;
    // Open the input file
    m_inputFile.open(fileName);
    m_inputFileName = std::move(fileName); // Assign the filename
    // Check if file open is successful
    if (!m_inputFile)
    {
        std::cerr << "Failed to open the file for reading: " << m_inputFileName << std::endl;
        return result; // Return empty array if file open fails
    }
    int num = 0;
    // Read integers from file and store them in the result vector
    while (m_inputFile >> num)
    {
        result.push_back(num);
    }
    return result;
}

// Read an array of integers from a file
std::vector<int> FileHandler::readArrayFromFile()
{
    std::vector<int> result;
    // Check if file open is successful
    if (!m_inputFile)
    {
        std::cerr << "Failed to open the file for reading: " << m_inputFileName << std::endl;
        return result; // Return empty array if file open fails
    }
    int num = 0;
    // Read integers from file and store them in the result vector
    while (m_inputFile >> num)
    {
        result.push_back(num);
    }
    return result;
}

// Save an array of integers to a file
void FileHandler::saveArrayToFile(std::string fileName, const std::vector<int>& array)
{
    this->closeOutputFile(); // Close the output file stream
    // Open the output file
    m_outputFile.open(fileName);
    m_inputFileName = std::move(fileName); // Assign the filename
    // Check if file open is successful
    if (!m_outputFile)
    {
        std::cerr << "Failed to open the file for writing: " << m_inputFileName << std::endl;
        return;
    }
    // Write integers from the array to the output file
    for (int i = 0; i < array.size(); ++i)
    {
        m_outputFile << array[i] << " ";
    }
}

// Save an array of integers to a file
void FileHandler::saveArrayToFile(const std::vector<int>& array)
{
    // Check if file open is successful
    if (!m_outputFile)
    {
        std::cerr << "Failed to open the file for writing: " << m_outputFileName << std::endl;
        return;
    }
    // Write integers from the array to the output file
    for (int i = 0; i < array.size(); ++i)
    {
        m_outputFile << array[i] << " ";
    }
}

#endif //_FILE_HANDLER_H_
