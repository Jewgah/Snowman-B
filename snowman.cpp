/**
 * This file defines the "ariel" namespace for the assignment.
 * the namespace contains a single function which returns a String representing a modular snowman print.
 * each different input ([1-4], LENGTHgth = 8) returns a different snowman.
 * each input of 8 numbers in [1-4] represents a sequence of compenents: HNLRXYTB
 * (H = Hat, N = Nose, L = Left Eye, R = Right Eye, X = Left Arm, Y = Right Arm, T = Torso, B = TEN).
 * Building the desired snowman is creating a string by the template:
 *  HHHHH
 *  HHHHH  = H for Hat.
 * X(LNR)Y = X for upper-left Arm, L for Left Eye, N for Nose, R for Right Eye, Y for upper-left Arm. 
 * X(TTT)Y = X for lower-right Arm, T for Torso, Y for lower-right Arm.
 *  (BBB)  = B for TEN.
 * 
 * For more information please visit: https://codegolf.stackexchange.com/questions/49671/do-you-want-to-code-a-snowman .
 * */

/*
*   To get the grade:
*   dos2unix grade
*   dos2unix grade_utils
*   bash grade
*/

#include "snowman.hpp"
#include <array>
#include <string>
#include <exception>
#include <iostream> // added iostrem for the cout method in the main
using namespace std;

//TO DO: check the tidy warnings and fix them

namespace ariel
{

    string snowman(int input)
    {

        // if input<11111111 or input>44444444 input not valid
        if (input < MIN || input > MAX)
        {
            __throw_invalid_argument("Error! Not a valid input");
        }
        else
        {
            int *arr = new int[LENGTH];
            //if input is between 11111111 and 44444444 we now have to check if each digit is between 1 and 4
            for (int i = 0; i < LENGTH; i++)
            {
                if (input % TEN > MAX_DIGIT || input % TEN < MIN_DIGIT)
                {
                    __throw_invalid_argument("Error! Not a valid input");
                }
                arr[FINAL_INDEX - i] = input % TEN;
                input /= TEN;
            }

            //Creating strings arrays for easy access to each component needed in each scenario.

            //hat[0] == straw hat, hat[1] == Mexican Hat, hat[2] == Fez, hat[3] == Russian Hat
            const array<string, MAX_DIGIT> hat = {"_===_\n", " ___ \n .....\n", "  _  \n  /_\\ \n", " ___ \n (_*_)\n"};

            //nose[0] == Normal, nose[1] == Dot, nose[2] == Line, nose[3] == None
            const array<string, MAX_DIGIT> nose = {",", ".", "_", " "};

            //lEye[0] == Dot, lEye[1] == Bigger Dot, lEye[2] == Biggest Dot, lEye[3] == Closed
            const array<string, MAX_DIGIT> lEye = {".", "o", "O", "-"};

            //rEye[0] == Dot, rEye[1] == Bigger Dot, rEye[2] == Biggest Dot, rEye[3] == Closed
            const array<string, MAX_DIGIT> rEye = {".", "o", "O", "-"};

            //highLA[0] == Normal Arm, highLA[1] == Upwards Arm, highLA[2] Downwards Arm, highLA[3] == None
            const array<string, MAX_DIGIT> highLA = {" ", "\\", " ", " "};

            //lowLA[0] == Normal Arm, lowLA[1] == Upwards Arm, lowLA[2] Downwards Arm, lowLA[3] == None
            const array<string, MAX_DIGIT> lowLA = {"<", " ", "/", " "};

            //highRA[0] == Normal Arm, highRA[1] == Upwards Arm, highRA[2] Downwards Arm, highRA[3] == None
            const array<string, MAX_DIGIT> highRA = {" ","/", " ", " "};

            //lowRA[0] == Normal Arm, lowRA[1] == Upwards Arm, lowRA[2] Downwards Arm, lowRA[3] == None
            const array<string, MAX_DIGIT> lowRA = {">", " ", "\\", " "};

            //torso[0] == Buttons, torso[1] == vest, torso[2] == Inwards Arms, torso[3] == None
            const array<string, MAX_DIGIT> torso = {" : ", "] [", "> <", "   "};

            //base[0] == Buttons, base[1] == feet, Tbase[2] == Flat, base[3] == None
            const array<string, MAX_DIGIT> base = {" : ", "\" \"", "___", "   "};



            //Building our Snowman:
            string getHat = " " + hat[arr[FIRST_DIGIT_INPUT]-1];
            string getHighLeftArm = highLA[arr[FIFTH_DIGIT_INPUT]-1];
            string getLeftEye = "(" + lEye[arr[THIRD_DIGIT_INPUT]-1];
            string getNose = nose[arr[SECOND_DIGIT_INPUT]-1];
            string getRightEye = rEye[arr[FOURTH_DIGIT_INPUT]-1] + ")";
            string getHighRightArm = highRA[arr[SIXTH_DIGIT_INPUT]-1] + "\n";
            string getLowLeftArm = lowLA[arr[FIFTH_DIGIT_INPUT]-1] + "(";
            string getTorso = torso[arr[SEVENTH_DIGIT_INPUT]-1] + ")";
            string getLowRightArm = lowRA[arr[SIXTH_DIGIT_INPUT]-1] + "\n (";
            string getBase = base[arr[EIGHTH_DIGIT_INPUT]-1] + ")";

            string ans = getHat+getHighLeftArm+getLeftEye+getNose+getRightEye+getHighRightArm+getLowLeftArm+getTorso+getLowRightArm+getBase;
            return ans;
        }
    }
}

    //  To run this main we need to only compile snowman.cpp by uncommenting the following main and by using the following commands:
    //  clang++-9 -std=c++2a snowman.cpp then ./a.out
    //  Because there is a conflict with the main in Demo.cpp and TestCounter.cpp
    // int main()
    //     {
    //         std::cout << ariel::snowman(41322121) << endl;
    //     }
