#include <iostream>
#include <string>

// Enum for days of the week
enum DayOfWeek
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

// Struct representing a Date
struct Date
{
    int day;
    int month;
    int year;
};

DayOfWeek calculateDayOfWeek(const Date& date);
void printDate(DayOfWeek dayOfWeek, const Date& date);
std::string weekDayToString(DayOfWeek dayOfWeek);

int main()
{
    // Create a Date object
    Date today = {23, 2, 2024};

    // Print the day of the week and the date
    printDate(Friday, today);

    return 0;
}

// Function to print the day of the week and the date
void printDate(DayOfWeek dayOfWeek, const Date& date)
{
    // Print the day of the week and the date in a readable format
    std::cout << "Day of the week: " << weekDayToString(dayOfWeek) << std::endl;
    std::cout << "Date: " << date.day << "/" << date.month << "/" << date.year << std::endl;
}

// Function to convert DayOfWeek enum value to string
std::string weekDayToString(DayOfWeek dayOfWeek)
{
    switch (dayOfWeek) 
    {
        case Saturday:
            return "Saturday";
        case Sunday:
            return "Sunday";
        case Monday:
            return "Monday";
        case Tuesday:
            return "Tuesday";
        case Wednesday:
            return "Wednesday";
        case Thursday:
            return "Thursday";
        case Friday:
            return "Friday";
        default:
            return "Invalid day";
    }
}
