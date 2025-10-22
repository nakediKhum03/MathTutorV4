/*
* Title:       Math Tutor V3
*Programer(s): Ethan Hoge & Khumo Nakedi
*Date:         10/10/2025
*Github URL:   https://github.com/nakediKhum03/MathTutorV3
*Description:  A simple math tutor that will eventually turn into a big program to help students with their math
*              randomized integer number with math types for the user to solve. The users name is read in the getline
*              and given either an addition, subtraction, multiplication or division operation problem. The if-else
*              statement assists for the user for if they get an answer wrong after three separate attempts ,then
*              the correct answer will be displayed. Then it'll ask if the user wants to continue on to more questions.
*              If the user gets three right in a row the it'll level them up making the questions harder by making the
*              max random number +10 the previous. And if hey get 3 incorrect, they'll level down and the max random
*              number will be -10 unless the level is already the lowest.
*
*/




#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
using namespace std;


int main() {
    const int MAX_ATTEMPTS = 3;
    const int LEVEL_CHANGE = 10; //How much to increase the range when leveling up and down

    enum MATH_TYPE {MT_ADD = 1, MT_SUB = 2, MT_MUL = 3, MT_DIV = 4};
    MATH_TYPE mathType = MT_ADD;

    string userName;
    int userAnswer = 0;
    int leftNum = 0;
    int rightNum = 0;
    char mathOperator ='?';
    int totalNum = 0;
    int tempNum = 0;
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int mathLevel = 1;
    int currentRange = LEVEL_CHANGE;

    string userInput = "?";

    cout <<  "******************************************************************************************************" << endl; // Simply a header stating what this program is.
    cout <<  "*                               Welcome to the Simply Silly Math Tutor                               *" << endl;
    cout <<  "******************************************************************************************************" << endl;
    cout << endl;

    cout << "Fun math facts:" << endl;

    cout << "    * 1000 is the only number with an {A} in it form one to one thousand" << endl;   // listing a few math facts for the user's entertainment
    cout << "    * There is no Roman numeral for zero" << endl;
    cout << "    * The largest prime digit has over 24 million digits" << endl;
    cout << "    * In a room of 23 people, there is a greater than 50% chance that two will share the same birthday" << endl;
    cout << endl;    // formatting whitespace
    cout <<  "******************************************************************************************************" << endl;
    cout << endl;    // formatting whitespace

    cout << "What is your name?" << endl; // where the user puts there name
    getline (cin,userName); // gets the user's fullnames with getline
    cout << "Welcome, " << userName << ", to the Simply Silly Math Tutor!" << endl; // prints and welcomes the user
    cout << endl;



    do {
        srand(time(0)); // Randomizing numbers
        leftNum = rand() % (currentRange - 1) + 1;
        rightNum = rand() % (currentRange - 1) + 1;
        mathType = static_cast<MATH_TYPE>(rand() % 4 + 1);

        switch (mathType) { // logic behind generating problems based of the math type
            case MT_ADD:
                mathOperator = '+';
            totalNum = leftNum + rightNum; // answer for addition
            break;
            case MT_SUB:
                mathOperator = '-';
            if (rightNum>leftNum) { // making sure that we won't get a negative number when subtracting
                tempNum = leftNum;
                leftNum = rightNum;
                rightNum = tempNum;
            }
            totalNum = leftNum - rightNum; // answer for subtraction
            break;
            case MT_MUL:
                mathOperator = '*';
            totalNum = leftNum * rightNum; //answer for multiplication
            break;
            case MT_DIV:
                mathOperator = '/';
            totalNum = leftNum; // makes sure there is no fractions and correct answer
            leftNum = leftNum * rightNum; // makes sure there is no fractions
            break;
            default: // if math type is invalid and it ends the program
                cout << "invaild math type!" << endl;
            cout << "contact Ethan or Khumo for help" << endl;
            return -1;
        }

        cout << "[Level #" << mathLevel << "] " << userName << ", what is " << leftNum << " " << mathOperator << " " << rightNum << " = " << "?" << endl; // displays the question

        for (int i = 0; i < MAX_ATTEMPTS; i++) { //Lets them try agian 3 times
            while (!(cin>>userAnswer)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\tInvalid input!" << endl;
                cout << "\tPlease enter a number:" << endl;
            }// end of while loop

            if (userAnswer == totalNum) {  // logic to check if the user inputs the right answer
                totalCorrect++;
                cout << "Excellent Job Einstein!" << endl;
                break;
            } else {
                cout << "Incorrect sorry :(" << endl;
                if (i < 2) { // won't show try again after the last attempt
                    cout << 2 - i << " attempt/s left." << endl;
                    cout << "Try Again" << endl;
                }
            }
        }// end of for loop

        if (userAnswer != totalNum) {
            cout << "The correct answer was " << totalNum << endl;
            totalIncorrect++;
            cout << endl;
        }

        if (totalCorrect ==3 ) { // Level Up logic
            mathLevel++;
            totalCorrect = 0;
            totalIncorrect = 0;
            currentRange += LEVEL_CHANGE;
            cout << "You are currently on level " << mathLevel << endl;
            cout << "Your new range is now from 1 to " << currentRange << endl;
            cout << endl;
        }
        else if (totalIncorrect ==3 && mathLevel >1) { // Level Down logic
            mathLevel--;
            totalCorrect = 0;
            totalIncorrect = 0;
            currentRange -= LEVEL_CHANGE;
            cout << "You are currently on level " << mathLevel << endl;
            cout << "Your range is now from 1 to " << currentRange << endl;
            cout << endl;
        } // end of if-else

        getline (cin, userInput);

        while (true) {
            cout << "Do you want to continue (y=yes || n=no)? " << endl;
            getline (cin, userInput);

            for (int i = 0; i < userInput.size(); i++) {
                userInput.at(i) = tolower(userInput.at(i));
            }

            if (userInput == "y" || userInput == "yes" ||
                userInput == "n" || userInput == "no") {
                break;
            } else {
                cout << "Invalid input, please try again..." << endl;
                cout << endl;
            }
        }// end of while true loop


    } while (userInput == "yes" || userInput == "y"); // end of do-while







    cout << endl; // formating white space
    cout << "That's all folks!" << endl; // showing that this code can not check answer
    cout << "Come back for version four to see what is in store!" << endl; // Showing that there is a version two coming
    cout << "End of program" << endl; // end of program

    cout << endl;
    return 0;
}
