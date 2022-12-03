//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Programmer: Parker Davis
// For CSC 201
//
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <fstream>

using namespace std;



struct Car
{
    string name;
    string state;
    int price;
    int quantity;
    float mpg;
    char rating;

    void printSelf()
    {
        cout << "Name: " << name << endl;
        cout << "State: " << state << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "MPG: " << mpg << endl;
        cout << "Rating: " << rating << endl;
        cout << endl;
    }
};



struct Profile
{
    string name;
    string state;
    string preference;

    bool created = false; // To check if user has a profile already

    void createProfile()
    {
        // User enters name, state, and preference according to prompts.
        cout << "*******************************" << endl;
        cout << "Enter name: ";
        cin >> name;
        
        cout << "Enter state: ";
        cin >> state;

        cout << "Enter car preference: ";
        cin >> preference;

        created = true;
    }

    void viewProfile()
    {
        // Display user's profile information
        cout << "*******************************" << endl;
        cout << "Name: " << name << endl;
        cout << "State: " << state << endl;
        cout << "Preference: " << preference << endl;
    }

    void updateProfile()
    {
        int choice;

        // Prompt user for aspect of profile they want to change
        cout << "*******************************" << endl;
        cout << "Update Name.............press 0" << endl;
        cout << "Update State............press 1" << endl;
        cout << "Update Preference.......press 2" << endl;

        cin >> choice;

        // Then prompt them for new value depending on previous choice
        if (choice == 0)
        {
            cout << "Enter new name: ";
            cin >> name;
        }
        else if (choice == 1)
        {
            cout << "Enter new state: ";
            cin >> state;
        }
        else if (choice == 2)
        {
            cout << "Enter new preference: ";
            cin >> preference;
        }
        else // If choice isn't between 0-2, say invalid. User must run updateProfile again.
        {
            cout << "Invalid choice." << endl;
        }
    }
};


/* menu()
   Int-Returning function
   Pre-Conditions: None
   Post-Conditions: An integer between 0-8 is returned. 8 Being a default value for out of range choices.*/
int menu();


/* menu()
   Void Function
   Pre-Conditions: inventory array is passed
   Post-Conditions: Correct car information is shown depending on user's choice.*/
void searchInventory(Car[20], string);


int main()
{
    Profile user;
    Car inventory[20]; // Array for car inventory, all cars are stored in this. Inventory file has 20 lines, user cannot add new cars in program.

    // Open inventory file
    ifstream inven_raw("Inventory.txt");

    // Temp variables for Car creation purposes.
    string raw_name;
    string raw_state;
    int raw_price;
    int raw_quantity;
    float raw_mpg;
    char raw_rating;

    int i = 0; // inventory[] index

    // For each line in Inventory.txt, assign each element to temp variable.
    while (inven_raw >> raw_name >> raw_state >> raw_price >> raw_quantity >> raw_mpg >> raw_rating)
    {
        // Assign each temp variable to corresponding variable inside Car struct
        inventory[i].name = raw_name;
        inventory[i].state = raw_state;
        inventory[i].price = raw_price;
        inventory[i].quantity = raw_quantity;
        inventory[i].mpg = raw_mpg;
        inventory[i].rating = raw_rating;
        
        // Finally incremement the index
        i++;
    }

    bool program_is_running = true;
    // The Main Program Loop runs as long as the variable program_is_running is true.
    // It stays true until the user inputs '7'.
    while (program_is_running)
    {
        switch(menu()) // Switches the entered integer from menu()
        {
            case 0: // Create Profile
                if (!user.created) // If user has not created a profile, create profile.
                {
                    user.createProfile();
                }
                else // Else, tell user they have a profile.
                {
                    cout << "*******************************" << endl;
                    cout << "You have already created a profile." << endl;
                }
                break;
            
            case 1: // View Profile
                if (user.created) // Only show user profile if they have created a profile.
                {
                    user.viewProfile();
                }
                else // Else, tell user they have not created a profile.
                {
                    cout << "*******************************" << endl;
                    cout << "You have not created a profile to view." << endl;
                }
                break;
            
            case 2: // Update Profile
                if (user.created) // Only let user update profile if profile is created
                {
                    user.updateProfile();
                }
                else // Else, tell user they have not created a profile.
                {
                    cout << "*******************************" << endl;
                    cout << "You have not created a profile to update." << endl;
                }
                break;
            
            case 3: // Search Inventory
                searchInventory(inventory, user.preference);
                break;
            case 4: // Update Inventory
                cout << 4 << endl;
                break;
            case 5: // Print Inventory
                cout << 5 << endl;
                break;
            case 6: // Car Loan
                cout << 6 << endl;
                break;
            case 7: // Exit
                program_is_running = false;
                break;
            default:
                cout << "Invalid Input Given, try again." << endl;
        }
    }

    cout << endl;
    cout << "Thank you for using the Car Inventory Program." << endl;
    cout << endl;

    return 0;
}


int menu()
{
    int choice;

    // User enters a choice from the displayed menu.
    cout << "*******************************" << endl;
    cout << "         CSC INVENTORY" << endl;
    cout << "*******************************" << endl;
    cout << "Create Profile..........press 0" << endl;
    cout << "View Profile............press 1" << endl;
    cout << "Update Profile..........press 2" << endl;
    cout << "Search Inventory........press 3" << endl;
    cout << "Update Inventory........press 4" << endl;
    cout << "Print Inventory.........press 5" << endl;
    cout << "Car Loan................press 6" << endl;
    cout << "Exit....................press 7" << endl;

    cin >> choice;

    if (cin.fail()) // Activates if User does not input an int, or inputs an int too large
    {
    cin.clear(); // Clears the cin
    cin.ignore(512, '\n'); // And ignores the rest of the input
    
    choice = 8; // And set choice to 8 to reach default: in switch statement
    }

    return choice;
}


void searchInventory(Car inventory[20], string user_preference)
{
    string choice; // Using a string variable here to avoid bad inputs
    string search_term;
    int search_value;
    char search_rate;

    int amount_found = 0; // Increments when matching item is found.
    // If none are found, tell user no matches were found for their search term.

    cout << "*******************************" << endl;
    cout << "Search by name.........press 1" << endl;
    cout << "Search by state.........press 2" << endl;
    cout << "Search by quanity.......press 3" << endl;
    cout << "Search by preference....press 4" << endl;
    cout << "Search by rating........press 5" << endl;
    cout << "Search by price.........press 6" << endl;
    cout << "Return to main menu.....press 7" << endl;

    cin >> choice;
    cout << "*******************************" << endl;

    if (choice == "1") // Names
    {
        cout << "Enter name to search for: ";
        cin >> search_term;

        for (int i = 0; i < 20; i++) // 20 iterations, for the inventory array.
        {
            if (inventory[i].name == search_term) // If matching item is found...
            {
                inventory[i].printSelf(); // Print the information of the matching car...
                amount_found++; // And increment found counter.
            }
        }
    }
    else if (choice == "2") // States
    {
        cout << "Enter state to search for: ";
        cin >> search_term;

        for (int i = 0; i < 20; i++) // 20 iterations, for the inventory array.
        {
            if (inventory[i].state == search_term) // If matching item is found...
            {
                inventory[i].printSelf(); // Print the information of the matching car...
                amount_found++; // And increment found counter.
            }
        }
    }
    else if (choice == "3") // Quantities
    {
        cout << "Enter quantity to search for: ";
        cin >> search_value;

        for (int i = 0; i < 20; i++) // 20 iterations, for the inventory array.
        {
            if (inventory[i].quantity <= search_value) // If matching item is found...
            {
                inventory[i].printSelf(); // Print the information of the matching car...
                amount_found++; // And increment found counter.
            }
        }
    }
    else if (choice == "4") // Preference
    {
        // No need to search to check user preference
        for (int i = 0; i < 20; i++) // 20 iterations, for the inventory array.
        {
            if (inventory[i].name == user_preference) // If matching item is found...
            {
                inventory[i].printSelf(); // Print the information of the matching car...
                amount_found++; // And increment found counter.
            }
        }
    }
    else if (choice == "5") // Ratings
    {
        cout << "Enter rating to search for: ";
        cin >> search_rate;

        for (int i = 0; i < 20; i++) // 20 iterations, for the inventory array.
        {
            if (inventory[i].rating == search_rate) // If matching item is found...
            {
                inventory[i].printSelf(); // Print the information of the matching car...
                amount_found++; // And increment found counter.
            }
        }
    }
    else if (choice == "6") // Price
    {
        cout << "Enter value to search for: ";
        cin >> search_value;

        for (int i = 0; i < 20; i++) // 20 iterations, for the inventory array.
        {
            if (inventory[i].price <= search_value) // If matching item is found...
            {
                inventory[i].printSelf(); // Print the information of the matching car...
                amount_found++; // And increment found counter.
            }
        }
    }
    else if(choice != "7")
    {
        cout << "Invalid choice, returning to main menu." << endl;
    }

    // After whatever choice that was searched for has been through, check if amount_found is still 0
    if (amount_found == 0)
    {
        cout << "No matching items were found." << endl; // Tell user that the search didn't work.
    }
}