#include <iostream>

int main()
{
    int number = 0; // Declare and initialize an integer variable named number
    std::cout << "Please enter a value for the number: "; // Prompt the user to enter a value for the number
    std::cin >> number; // Read the value entered by the user and store it in the number variable

    // Check if the number is positive, negative, or zero
    if (number > 0) // If number is greater than 0
    {
        std::cout << "Number is positive" << std::endl;
    } 
    else if (number < 0) // If number is less than 0
    {
        std::cout << "Number is negative" << std::endl;
    } 
    else // If number is equal to 0
    {
        std::cout << "Number is zero" << std::endl;
    }

    int score = 0; // Declare and initialize an integer variable named score
    std::cout << "Please enter the student's score: "; // Prompt the user to enter the student's score
    std::cin >> score; // Read the score entered by the user and store it in the score variable

    char grade = '\0'; // Declare and initialize a character variable named grade with null character '\0'

    // Assign a grade based on the student's score using switch-case
    switch (score) // Evaluate the value of score
    {
        case 90 ... 100: // If score is in the range 90-100 (inclusive)
            grade = 'A'; // Assign grade 'A'
            break; // Exit the switch statement
        case 80 ... 89: // If score is in the range 80-89 (inclusive)
            grade = 'B'; // Assign grade 'B'
            break;
        case 70 ... 79: // If score is in the range 70-79 (inclusive)
            grade = 'C'; // Assign grade 'C'
            break;
        case 60 ... 69: // If score is in the range 60-69 (inclusive)
            grade = 'D'; // Assign grade 'D'
            break;
        default: // If score does not match any of the above cases
            grade = 'F'; // Assign grade 'F'
    }

    std::cout << "Student's grade is " << grade << std::endl; // Output the student's grade to the console

    // Print numbers from 1 to 10 using a loop
    for (int i = 1; i < 11; ++i) // Loop from 1 to 10
    {
        std::cout << i << '\t'; // Output the current number followed by a tab character ('\t')
    }
    std::cout << std::endl; // Output a newline character to move to the next line

    return 0;
}
