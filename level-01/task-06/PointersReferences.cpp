#include <iostream>

void manipulateByReference(int& ref);
void manipulateByPointer(int* ptr);

int main()
{
    int num = 10; // Declare an integer variable
    int* ptr = &num; // Declare a pointer variable and assign the address of num to it
    int& ref = num; // Declare a reference variable and initialize it to num

    // Output the initial value of num
    std::cout << "Initial value of num: " << num << std::endl;

    // Manipulate the data using the pointer
    *ptr = 20; // Assign 20 to the value pointed by ptr

    // Output the value of num after manipulation using the pointer
    std::cout << "Value of num after manipulation using pointer: " << num << std::endl;

    // Manipulate the data using the reference
    ref = 30; // Assign 30 to ref, which updates the value of num directly

    // Output the value of num after manipulation using the reference
    std::cout << "Value of num after manipulation using reference: " << num << std::endl;

    // Call function to manipulate data using pass by reference
    manipulateByReference(num);

    // Output the value of num after manipulation using pass by reference
    std::cout << "Value of num after manipulation using pass by reference: " << num << std::endl;

    // Call function to manipulate data using pass by pointer
    manipulateByPointer(&num);

    // Output the value of num after manipulation using pass by pointer
    std::cout << "Value of num after manipulation using pass by pointer: " << num << std::endl;

    return 0;
}

// Function to manipulate data using pass by reference
void manipulateByReference(int& ref)
{
    ref += 10; // Increment the value by 10
}

// Function to manipulate data using pass by pointer
void manipulateByPointer(int* ptr)
{
    *ptr += 10; // Increment the value pointed by ptr by 10
}