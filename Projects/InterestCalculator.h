#pragma once
//header guards help to avoid errors that arise when the same function or variable is defined more than once by the mistake of a programmer.
#ifndef INTEREST_CALCULATOR_H
#define INTEREST_CALCULATOR_H

/* The accompanying .pdf states that is is good practice to use m_ for member variables and t_ for function variables
* so that is what I am using in this file. It actually makes it easier to track variables in writting the setters and getters
* in the seconday .cpp file.
 */

class Money {

	//public variables that are accessible to the user. Passes the function variable into the set function.
	public:
		void setInvestmentAmount(double t_investmentAmount);
		void setMonthlyDeposit(double t_monthlyDeposit);
		void setAnnualInterest(double t_AnnualInterest);
		void setNumYears(int t_numYears);

	//Initializes the get
		double getInvestmentAmount() const;
		double getMonthlyDeposit() const;
		double getAnnualInterest() const;
		int getNumYears() const;

		//print method with three parameters. Designed to be called in main()
		void printDetails(int year, double yearEndBalance, double interestEarned) {
			std::cout << "   "<<year << "  		 $" << yearEndBalance << "  		  $" << interestEarned << std::endl;
		}
     //private variables that are inaccecible to the user.  All are initialized.   
	private:
		double m_investmentAmount = 0.0;
		double m_monthlyDeposit = 0.0;
		double m_annualInterest = 0.0;
		int m_numYears =0;
	
};

#endif
