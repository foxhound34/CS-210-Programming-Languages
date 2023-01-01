#include <iostream>//used for input/output streams
#include <iomanip>//used to set precision
#include <cctype>//used for lowercase character function
#include <stdexcept> //used for exception handling
#include "InterestCalculator.h" //header file

/* While doing research for this project I came across information that stated "using namespace std;" 
* is considered bad practice because C++ updates may cause issues. To that end, I did not use it in this project.
*/

int main() {
    //initialization of variables
    double initialDeposit = 0.0;
    double interestRate = 0.0;
    double monthlyDeposit = 0.0;
    double totalInterestEarned = 0.0;
    double monthlyInterestRate = 0.0;
    char continueProgram = 'x';
    int years = 1;

    //initialization of object to call class
    Money myObj;

    do {//Do while loop that keeps program running until user quits at the end
        try { //try block to catch negative number input
            std::cout << std::setprecision(2) << std::fixed; // set precision of output to two decimal places
            std::cout << std::endl;
            std::cout << "  **********************************" << std::endl;
            std::cout << "  ********** Data Input ************" << std::endl;
            std::cout << "  Initial Investment Amount: ";

            std::cin >> initialDeposit;// stored user input in variable
            if (initialDeposit < 0) {//negative numbers throw an error and program moves to the catch block
                throw std::runtime_error::runtime_error("Invalid number");//Displays error message
            }
            myObj.setInvestmentAmount(initialDeposit);//set the user input by calling the call memeber function 
            std::cout << "  Monthly Deposit: ";
            std::cin >> monthlyDeposit;
            if (monthlyDeposit < 0) {
                throw std::runtime_error::runtime_error("Invalid number");
            }
            myObj.setMonthlyDeposit(monthlyDeposit);
            std::cout << "  Annual Interest: ";
            std::cin >> interestRate;
            if (interestRate < 0) {
                throw std::runtime_error::runtime_error("Invalid number");
            }
            myObj.setAnnualInterest(interestRate);
            std::cout << "  Number of years: ";
            std::cin >> years;
            if (years < 0) {
                throw std::runtime_error::runtime_error("Invalid number");
            }
            myObj.setNumYears(years);
        }
        catch (std::runtime_error& excpt) {//catch for runtime errors
            std::cout << "  Error : Negative number Entered" << std::endl;
            continue;// contiues through the while loop until only positve numbers are inputted 
        }
        // learned from https://www.digitalocean.com/community/tutorials/system-pause-command-c-plus-plu
        system("pause"); //waits for user to press any key before continuing. Prints output to display 

        std::cout << std::endl;
        std::cout << "  **********************************" << std::endl;
        std::cout << "  ********** Data Input ************" << std::endl;

        //This section calls the member class to get the stored user inputs
        std::cout << "  Initial Investment Amount:  $" << myObj.getInvestmentAmount() << std::endl;
        std::cout << "  Monthly Deposit:  $" << myObj.getMonthlyDeposit() << std::endl;
        std::cout << "  Annual Interest:  " << myObj.getAnnualInterest() << "%" << std::endl;
        std::cout << "  Number of years:  " << myObj.getNumYears() << std::endl;
        system("pause");
        system("CLS");//clears display

        std::cout << std::endl;
        std::cout << "     Balance and Interest Without Additional Monthly Deposits    " << std::endl;
        std::cout << "  ===============================================================" << std::endl;
        std::cout << "  Year         Year End Balance     Year End Earned Interest" << std::endl;
        std::cout << "  --------------------------------------------------------------" << std::endl;

        double currentBalance = myObj.getInvestmentAmount();
        double newBalance = 0.0;

        /* While loop that calculates interest on current balance, adds to current balance, then makes that the new balance.
        * the inner loop adds +1 to the month each time through. Once 12 iterations occur the outer loop adds +1 to the year
        * this continues until the iteration of years equals the number of years the user inputed.
        */
        int startYear = 0;
        while (startYear < myObj.getNumYears()) {
            int month = 0;
            totalInterestEarned = 0.0;
            while (month < 12) {
                totalInterestEarned += currentBalance * ((interestRate / 100) / 12);//calculates cumulative interest
                newBalance = (currentBalance * (1 + (interestRate / 100) / 12));
                currentBalance = newBalance;
                month += 1;
            }
            startYear += 1;

            //calls the method to print the details of the loop
            myObj.printDetails(startYear, newBalance, totalInterestEarned);
        }

        std::cout << std::endl;
        std::cout << "        Balance and Interest With Additional Monthly Deposits    " << std::endl;
        std::cout << "  ===============================================================" << std::endl;
        std::cout << "  Year         Year End Balance     Year End Earned Interest" << std::endl;
        std::cout << "  --------------------------------------------------------------" << std::endl;

        //Functions below are the same as above with the exception of an additional monthly deposit
        currentBalance = myObj.getInvestmentAmount() + myObj.getMonthlyDeposit();
        newBalance = 0.0;

        startYear = 0;
        while (startYear < myObj.getNumYears()) {
            int month = 0;
            totalInterestEarned = 0.0;
            while (month < 12) {
                totalInterestEarned += currentBalance * ((interestRate / 100) / 12);
                newBalance = (currentBalance * (1 + (interestRate / 100) / 12));
                currentBalance = newBalance + myObj.getMonthlyDeposit();
                month += 1;
            }
            startYear += 1;

            myObj.printDetails(startYear, newBalance, totalInterestEarned);
        }
        //Beaks the loop if user enters N or n
        std::cout << std::endl;
        std::cout << "  Press any key to enter new numbers or (N/n) to quit" << std::endl;
        std::cin >> continueProgram;
        continueProgram = tolower(continueProgram);//converts all input to lowercase

    }while (continueProgram != 'n');

    //closes program
    return 0;
}