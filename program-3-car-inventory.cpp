//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Programmer: Parker Davis
// For CSC 201
//
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>

using namespace std;


/* menu()
   Int-Returning function
   Pre-Conditions: None
   Post-Conditions: Integer is returned. 0-8 should be the only possible outcomes. 8 Being a default value for out of range choices.*/
int menu();


struct Profile
{
    string name;
    string state;
    string preference;

    void createProfile()
    {
        cin >> name;
    }
};


int main()
{
    bool program_is_running = true;
    // The Main Program Loop runs as long as the variable program_is_running is true.
    // It stays true until the user inputs '7'.
    while (program_is_running)
    {
        switch(menu()) // Switches the entered integer from menu()
        {
            case 0:
                cout << 0 << endl;
                break;
            case 1:
                cout << 1 << endl;
                break;
            case 2:
                cout << 2 << endl;
                break;
            case 3:
                cout << 3 << endl;
                break;
            case 4:
                cout << 4 << endl;
                break;
            case 5:
                cout << 5 << endl;
                break;
            case 6:
                cout << 6 << endl;
                break;
            case 7:
                program_is_running = false;
                break;
            default:
                cout << "Invalid Input Given, try again." << endl;
        }
    }

    cout << endl;
    cout << "Thank you for using the Car Inventory Program." << endl;

    return 0;
}


int menu()
{
    // User enters a choice from the displayed menu.
    // Menu not yet implemented.
    int choice;
    cout << "Input: ";
    cin >> choice;
    return choice;
}