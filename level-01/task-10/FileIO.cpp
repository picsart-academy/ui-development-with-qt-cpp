#include <iostream>
#include <fstream> // To use file stream input-output operations
#include <vector>
#include <string>

int main()
{
    // Create a vector of names
    std::vector<std::string> names = {"Real Madrid", "Barcelona", "Arsenal", "Manchester United", 
                        "Paris Saint-Germain", "Manchester City", "Inter Milan", "Bayern Munich"};

    // Define the file name
    std::string fileName("example.txt");

    // Open the file for writing
    std::ofstream outputFile(fileName);

    // Check if the file is successfully opened
    if (!outputFile)
    {
        std::cerr << "Failed to open the file for writing: " << fileName << std::endl;
        return 1;
    }

    // Write names to the file
    for (int i = 0; i < names.size(); ++i)
    {
        outputFile << names[i] << std::endl;
    }

    // Close the file
    outputFile.close();

    // Open the file for reading
    std::ifstream inputFile(fileName);

    // Check if the file is successfully opened
    if (!inputFile)
    {
        std::cerr << "Failed to open the file for reading: " << fileName << std::endl;
        return 1;
    }

    // Read and print the contents of the file
    std::cout << "Contents of " << fileName << ":" << std::endl;
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::cout << line << std::endl;
    }

    // Close the file
    inputFile.close();

    return 0;
}
