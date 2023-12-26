#include <iostream>
#include <string>
#include <unordered_map>

// Function declarations
std::unordered_map<int, std::tuple<std::string, std::string, int, std::string>> getUserDatabase();
void displayUserInfo(int id, const std::unordered_map<int, std::tuple<std::string, std::string, int, std::string>> &userDatabase);

int main()
{
    // Get user database (simulated database)
    std::unordered_map<int, std::tuple<std::string, std::string, int, std::string>> userDatabase = getUserDatabase();

    // Prompt user to enter the generated ID
    int enteredID;
    std::cout << "Enter the generated ID: ";
    std::cin >> enteredID;

    // Display user information based on the entered ID
    displayUserInfo(enteredID, userDatabase);

    return 0;
}

// Function to retrieve user information from the database
std::unordered_map<int, std::tuple<std::string, std::string, int, std::string>> getUserDatabase()
{
    std::unordered_map<int, std::tuple<std::string, std::string, int, std::string>> userDatabase;

    // Simulated user data
    userDatabase[123456] = std::make_tuple("John Doe", "USA", 25, "01/15/1998");
    userDatabase[789012] = std::make_tuple("Alice Smith", "Canada", 30, "05/20/1993");
    userDatabase[2552] = std::make_tuple("Rayan Derradji", "Algeria", 18, "08/31/2005");
    
    return userDatabase;
}

// Function to display user information based on the entered ID
void displayUserInfo(int id, const std::unordered_map<int, std::tuple<std::string, std::string, int, std::string>> &userDatabase)
{
    auto it = userDatabase.find(id);

    if (it != userDatabase.end())
    {
        // User found, display information
        std::cout << "\nUser Information:\n";
        std::cout << "Full Name: " << std::get<0>(it->second) << "\n";
        std::cout << "Country: " << std::get<1>(it->second) << "\n";
        std::cout << "Age: " << std::get<2>(it->second) << "\n";
        std::cout << "Date of Birth: " << std::get<3>(it->second) << "\n";
    }
    else
    {
        // User not found
        std::cout << "\nUser not found for the entered ID.\n";
    }
}
