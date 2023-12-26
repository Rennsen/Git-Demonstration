#include <iostream>
#include <string>

int main()
{
    // Declare variables to store user input
    std::string fullName, country, dateOfBirth;
    int age;

    // Function declarations
    int calculateID(const std::string &text);
    void clearInputBuffer();

    // Prompt user for input
    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);

    std::cout << "Enter your country: ";
    std::getline(std::cin, country);

    std::cout << "Enter your age: ";
    std::cin >> age;

    clearInputBuffer(); // Clear the newline character from the input buffer

    std::cout << "Enter your date of birth (MM/DD/YYYY): ";
    std::getline(std::cin, dateOfBirth);

    // Create ID using ASCII conversion method
    int id = calculateID(fullName) + calculateID(country) + age + calculateID(dateOfBirth);

    // Display the generated ID
    std::cout << "\nYour generated ID is: " << id << std::endl;

    return 0;
}

// Function to calculate ID using ASCII conversion method
int calculateID(const std::string &text)
{
    int id = 0;
    for (char c : text)
    {
        id += static_cast<int>(c);
    }
    return id;
}

// Function to clear input buffer
void clearInputBuffer()
{
    std::cin.ignore(32767, '\n'); // Clear up to 32767 characters or until a newline is encountered
}
