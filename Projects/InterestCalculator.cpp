#include <iostream>
#include "InterestCalculator.h"

	//setters. call the money class to set the user input 
	void Money::setInvestmentAmount(double t_investmentAmount) {
		m_investmentAmount = t_investmentAmount;
		m_investmentAmount = t_investmentAmount;
	}
	void Money::setMonthlyDeposit(double t_monthlyDeposit) {
		m_monthlyDeposit = t_monthlyDeposit;
	}
	void Money::setAnnualInterest(double t_annualInterest) {
		m_annualInterest = t_annualInterest;
	}
	void Money::setNumYears(int t_numYears) {
		m_numYears = t_numYears;
	}

	//getters.  Calls the money class to return the set input
	double Money::getInvestmentAmount() const {
		return m_investmentAmount;
	}
	double Money::getMonthlyDeposit() const {
		return m_monthlyDeposit;
	}
	double Money::getAnnualInterest() const {
		return m_annualInterest;
	}
	int Money::getNumYears() const {
		return m_numYears;
	}
