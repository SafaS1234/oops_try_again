#include <iostream>
#include <limits>

using namespace std;

//checks range
bool range(int input, int min, int max)
{
    return cin.peek() =='\n' && input >= min && input <= max; 
}

//converts a string to an integer
int stringToInt(const string& str) {
    int num = 0;
    char dig;

    for (size_t i = 0; i < str.size(); ++i) {
        dig = str[i];
        if (isdigit(dig)) {
            num = num * 10 + (dig - '0');
        }
    }

    return num;
}

//places the error message and input message at the appropriate places 
int inputValidation(int min, int max, const string inputMessage, 
                    const string errorMessage, int def_val = 100)
{
    int input;
    bool valid = false;
    string user_input;

    while(!valid)
    {
        cout << inputMessage;
        cin >> user_input;

        if (user_input == "exit")
        {
            return -1;
        }

        else if (user_input == "default")
        {
            return def_val;

        }

        //for numbers
        else
        {
            if (isdigit(user_input[0])) {
                // Convert string to integer
                input = stringToInt(user_input);
                if (range(input, min, max)) {
                    valid = true;
                } else {
                    cout << errorMessage << endl;
                }
            } else {
                cout << errorMessage << endl;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }

    }

    return input;
}

//main to get user input and print out message
int main()
{
    int min = 0,
        max = 100,
        def_value = 100,
        userValue;
    string inputMessage = "Please enter a value (\"default\" = 100,) \n",
           errorMessage = "Your value is invalid. \n";
    
    userValue = inputValidation(min, max, inputMessage, errorMessage,
                                def_value);

    if (userValue != -1)
    {
        cout << "The value chosen by the user is " << userValue << endl;
    }

    return 0;
}

