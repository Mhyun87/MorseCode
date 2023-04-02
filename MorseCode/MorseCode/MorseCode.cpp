#include <iostream>
#include <string>    
using namespace std;

int main()
{
    char again;    //do while loop variable
    do {

        const int LENGTH = 255;      //variable length constant
        char input[LENGTH];          //initialize array of chars

        static int MORSESIZE = 40;		// size of table 
       
        static char LETTERMATCH[40] = { ' ',',','.','?','0','1','2','3','4','5','6','7','8','9','A','B','C','D','E', 'F',
                                           'G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
        //							    [SP]    ,        .       ?        0        1       2      3      4        5
        static string MORSECODE[40] = { " ","--..--",".-.-.-","..--..","-----",".----","..---","...--","....-",".....",
            //								    6       7       8       9     A     B       C     D    E    F
                                            "-.....","--...","---..","----.",".-","-...","-.-.","-..",".","..-.",
            //								   G     H     I     J     K      L    M    N     O     P
                                            "--.","....","..",".---","-.-",".-..","--","-.","---",".--.",
            //								  Q      R     S    T    U     V      W      X     Y      Z
                                            "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };



        cout << "Please enter message to be converted to Morse Code," << endl;
        cout << "no more than 255 characters in length." << endl;    //display
        cout << "\nENTER Message : " << endl;

        cin.getline(input, LENGTH);      //user input in array

        int count = 0;
        for (count = 0; count < strlen(input); count++)           //input array
        {
            input[count] = toupper(input[count]);
        }



        int x, y;
        for (x = 0; x < strlen(input); x++)           //input array
        {

            for (y = 0; y < sizeof(LETTERMATCH); y++)    //letter array
            {
                if (input[x] == LETTERMATCH[y])             //if first element from array X matches element in same place at array Y
                {
                    cout << input[x] << "  " << MORSECODE[y] << endl;       //print out the same element from morsee code array
                }
            }



        }
        cout << "\nWould you like to run it again? Y or N: ";          //do while loop
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');           //buffer clear
    } while (again == 'y' || again == 'Y');

}