#include <iostream>
#include <limits>

using namespace std;

//checks range
bool range(int input, int min, int max)
{
    return cin.peek() =='\n' && input >= min && input <= max; 
}

//places the error message and input message at the appropriate places 
int inputValidation(int min, int max, const string inputMessage, 
                    const string errorMessage)
{
    int input;
    bool valid = false;

    while(!valid)
    {
        cout << inputMessage;

        if(cin >> input && range(input, min, max))
        {
            valid = true;
        }

        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << errorMessage << endl;
        }
    }

    return input;
}

//main to get user input and print out message
int main()
{
    int min = 0,
        max = 100,
        userValue;
    string inputMessage = "Please enter a value \n",
           errorMessage = "Your value is invalid. \n";
    
    userValue = inputValidation(min, max, inputMessage, errorMessage);

    cout << "The value chose by the user is " << userValue << endl;

    return 0;

}

