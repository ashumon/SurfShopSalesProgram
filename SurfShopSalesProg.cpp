// Johnny Utah: Point Break Surf Shop
// Display a menu for the user to:
// 1.) Show program usage, accept input S, P, C, T, or Q
// 2.) Purchase a surfboard (xxxsmall, small, medium, or large) input size/quantity
// 3.) Display current purchases output - sizes and quantities of purchases
// 4.) Display total amount due outputs totals by size and total amount due
//      -- create an outfile with a receipt for the purchases
// 5.) Rinse and Repeat until user gets bored or spends all their money
// We will use functions to accomplish our goals
// Inputs are S, P, C, T, or Q for menu options
// constants:
// Small = 175
// Medium = 190
// Large = 200
// 
//

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <fstream>

using namespace std;


// our little header may as well be a function. I was lazy and didn't use iomanip for this but it wasn't required for this assignment
void Greeting()
{
    cout << "************************************************************" << endl;
    cout << "***** Welcome to my Johnny Utah's PointBreak Surf Shop *****" << endl;
    cout << "************************************************************" << endl;
    cout << endl;

}

// this function gives us our menu for the user so they know how to use the program
void ShowUsage()
{
    cout << "To show program usage 'S' " << endl;
    cout << "To purchase a surfboard press 'P' " << endl;
    cout << "To display current purchases press 'C' " << endl;
    cout << "To display total amount due press 'T' " << endl;
    cout << "To quit the program press 'Q' " << endl;
    cout << endl;
    cout << "Please enter a selection: ";
}


// here is where we tell the program how much of what size we want
// UTAH! Get me two!
void MakePurchase(int& iTotalXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
    int quantity;
    char size;
    cout << "Please enter the quantity and type ( X=xxxsmall, S=small, M=medium, L=large) of surfboard you would like to purchase: ";
    cin >> quantity >> size;


    switch (tolower(size)) {
    case('s'):
        iTotalSmall = iTotalSmall + quantity;
        break;

    case('m'):
        iTotalMedium = iTotalMedium + quantity;
        break;
    case('l'):
        iTotalLarge = iTotalLarge + quantity;
        break;
    case('x'):
        iTotalXSmall = iTotalXSmall + quantity;
        break;
    }

}

// this keeps track of how much we are buying

void DisplayPurchase(const int iTotalXSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
    string XSmallBoard = "The total number of xxxsmall surfboards is: ";
    string SmallBoard = "The total number of small surfboards is: ";
    string MediumBoard = "The total number of medium surfboards is: ";
    string LargeBoard = "The total number of large surfboards is: ";

    if (iTotalSmall > 0) {
        cout << SmallBoard << iTotalSmall << endl;

    }
    if (iTotalMedium > 0) {
        cout << MediumBoard << iTotalMedium << endl;

    }
    if (iTotalLarge > 0) {
        cout << LargeBoard << iTotalLarge << endl;

    }
    if (iTotalXSmall > 0) {
        cout << XSmallBoard << iTotalXSmall << endl;
    }
    if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0 && iTotalXSmall == 0) {
        cout << "No purchases made yet." << endl;

    }

}
// this function totals how much we are spending
// you're sayin the FBI is gonna pay me to learn to surf?
void DisplayTotal(const int iTotalXSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
    double const xsmallPrice = 42.00;
    double const smallPrice = 175.00;
    double const mediumPrice = 190.00;
    double const largePrice = 200.00;
    double total = 0.00;

    //file variable
    ofstream outFile;

    //open the file and verify it opens. Program will exit if file did not open
    outFile.open("Order.txt");
    
    outFile << "************************************************************" << endl;
    outFile << "***** Welcome to my Johnny Utah's PointBreak Surf Shop *****" << endl;
    outFile << "************************************************************" << endl;
    outFile << endl;

    if (iTotalSmall > 0) {
        cout << "The total number of small surfboards is: " << iTotalSmall << " at a total of $" << setprecision(2) << fixed << iTotalSmall * smallPrice << endl;
        total = total + (smallPrice * iTotalSmall);
        outFile << "The total number of small surfboards is: " << iTotalSmall << " at a total of $" << setprecision(2) << fixed << iTotalSmall * smallPrice << endl;
    }
    if (iTotalMedium > 0) {
        cout << "The total number of medium surfboards is: " << iTotalMedium << " at a total of $" << setprecision(2) << fixed << iTotalMedium * mediumPrice << endl;
        total = total + (mediumPrice * iTotalMedium);
        outFile << "The total number of medium surfboards is: " << iTotalMedium << " at a total of $" << setprecision(2) << fixed << iTotalMedium * mediumPrice << endl;
    }
    if (iTotalLarge > 0) {
        cout << "The total number of large surfboards is: " << iTotalLarge << " at a total of $" << setprecision(2) << fixed << iTotalLarge * largePrice << endl;
        total = total + (largePrice * iTotalLarge);
        outFile << "The total number of large surfboards is: " << iTotalLarge << " at a total of $" << setprecision(2) << fixed << iTotalLarge * largePrice << endl;
    }
    if (iTotalXSmall > 0) {
        cout << "The total number of xxxsmall surfboards is: " << iTotalXSmall << " at a total of $" << setprecision(2) << fixed << iTotalXSmall * xsmallPrice << endl;
        total = total + (xsmallPrice * iTotalXSmall);
        outFile << "The total number of xxxsmall surfboards is: " << iTotalXSmall << " at a total of $" << setprecision(2) << fixed << iTotalXSmall * xsmallPrice << endl;
    }

    cout << "Amount due: $" << setprecision(2) << fixed << total << endl;
    outFile << "Amount due: $" << setprecision(2) << fixed << total << endl;
    outFile << "Thank you" << endl;

}

int main()
{
    int iTotalXSmall = 0;
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;

    Greeting();

    ShowUsage();

    

    //speak into the microphone, squid brain!
    char selection;
    cin >> selection;

    while (selection != 'q' && selection != 'Q') {


        if (selection == 's') {
            ShowUsage();
            cout << endl;
        }


        else if (selection == 'p' || selection == 'P') {
            MakePurchase(iTotalXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
            cout << endl;
        }


        else if (selection == 'c' || selection == 'C') {
            DisplayPurchase(iTotalXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
            cout << endl;
        }

        else if (selection == 't' || selection == 'T') {
            DisplayTotal(iTotalXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
            cout << endl;
        }


        else
        {
            cout << "Invalid selection. Try again." << endl;

        }



        cout << "Please enter a selection: ";
        cin >> selection;




    }

    // this is stimulating, but we're out of here
    cout << "Thank you" << endl;
    system("pause");
    return 0;




}







