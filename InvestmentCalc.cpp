/*
 * 5-3.cpp

 *
 *  Created on: Mar 31, 2025
 *      Author: spencerbelkna_snhu
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>


// Class to handle investment calculations
class InvestmentCalculator {
private:
    double initialInvestment; // Starting amount of the investment
    double monthlyDeposit;    // Amount added to the investment every month
    double annualInterestRate; // Yearly interest rate as a percentage
    int numYears;             // Total number of years for the investment

public:
    // Constructor to initialize the values provided by the user
    InvestmentCalculator(double initInvest, double monthlyDep, double annualRate, int years) {
        initialInvestment = initInvest;
        monthlyDeposit = monthlyDep;
        annualInterestRate = annualRate;
        numYears = years;
    }

    // Function to calculate yearly balances without monthly deposits
    void calculateWithoutMonthlyDeposits() {
        cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
        cout << "==========================================================" << endl;
        cout << setw(10) << "Year" << setw(25) << "Year End Balance" << setw(30) << "Year End Earned Interest" << endl;

        double openingAmount = initialInvestment;
        double earnedInterest;

        // Loop through each year
        for (int year = 1; year <= numYears; year++) {
            // Calculate interest for the year
            earnedInterest = openingAmount * (annualInterestRate / 100);
            openingAmount += earnedInterest; // Update the balance with the interest

            // Print out the results for the year
            cout << setw(10) << year << setw(25) << fixed << setprecision(2) << openingAmount
                 << setw(30) << earnedInterest << endl;
        }
    }

    // Function to calculate yearly balances with monthly deposits
    void calculateWithMonthlyDeposits() {
        cout << "\nBalance and Interest With Additional Monthly Deposits\n";
        cout << "==========================================================" << endl;
        cout << setw(10) << "Year" << setw(25) << "Year End Balance" << setw(30) << "Year End Earned Interest" << endl;

        double openingAmount = initialInvestment;
        double earnedInterest = 0;
        double closingBalance = initialInvestment;

        // Loop through each year
        for (int year = 1; year <= numYears; year++) {
            earnedInterest = 0; // Reset yearly earned interest

            // Loop through each month
            for (int month = 1; month <= 12; month++) {
                double monthlyInterest = (openingAmount + monthlyDeposit) * ((annualInterestRate / 100) / 12);
                openingAmount += monthlyDeposit + monthlyInterest; // Update the balance for the month
                earnedInterest += monthlyInterest; // Add to the total interest for the year
            }
            closingBalance = openingAmount;

            // Print out the results for the year
            cout << setw(10) << year << setw(25) << fixed << setprecision(2) << closingBalance
                 << setw(30) << earnedInterest << endl;
        }
    }
};

// Function to get user input and validate it
double getValidInput(const string &prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (value >= 0) {
                break; // Valid input, exit the loop
            } else {
                cout << "Invalid input. Please enter a positive number.\n";
            }
        } else {
            cin.clear(); // Clear invalid input flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid number.\n";
        }
    }
    return value;
}

int main() {
    cout << "Welcome to the Airgead Banking Investment Calculator!\n";

    // Prompt the user for inputs
    double initialInvestment = getValidInput("Enter the initial investment amount in dollars: ");
    double monthlyDeposit = getValidInput("Enter the monthly deposit amount in dollars: ");
    double annualInterestRate = getValidInput("Enter the annual interest rate (as a percentage): ");
    int numYears = static_cast<int>(getValidInput("Enter the number of years for the investment: "));

    // Create an instance of the InvestmentCalculator class
    InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterestRate, numYears);

    // Display results for both scenarios
    calculator.calculateWithoutMonthlyDeposits();
    calculator.calculateWithMonthlyDeposits();

    cout << "\nThank you for using the Airgead Banking Investment Calculator!\n";
    return 0;
}

