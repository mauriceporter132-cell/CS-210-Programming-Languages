#include <iostream>
#include <iomanip>
#include <limits>
#include "Investment.h"

using namespace std;

Investment::Investment() {
    m_initialInvestment = 0.0;
    m_monthlyDeposit = 0.0;
    m_annualInterest = 0.0;
    m_numberOfYears = 0;
}

// Gets investment information from the user.
void Investment::getUserInput() {
    cout << "**********************************" << '\n';
    cout << "*********** Data Input ***********" << '\n';

    cout << "Initial Investment Amount: $";
    cin >> m_initialInvestment;

    cout << "Monthly Deposit: $";
    cin >> m_monthlyDeposit;

    cout << "Annual Interest: %";
    cin >> m_annualInterest;

    cout << "Number of Years: ";
    cin >> m_numberOfYears;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Displays the information entered by the user.
void Investment::displayInput() {
    cout << fixed << setprecision(2);

    cout << '\n';
    cout << "**********************************" << '\n';
    cout << "*********** Data Input ***********" << '\n';
    cout << "Initial Investment Amount: $" << m_initialInvestment << '\n';
    cout << "Monthly Deposit: $" << m_monthlyDeposit << '\n';
    cout << "Annual Interest: %" << m_annualInterest << '\n';
    cout << "Number of Years: " << m_numberOfYears << '\n';
    cout << "Press Enter to continue . . .";
    cin.get();
}

// Displays investment growth without monthly deposits.
void Investment::displayWithoutDeposits() {
    cout << '\n';
    cout << "Balance and Interest Without Additional Monthly Deposits" << '\n';
    cout << "==================================================================" << '\n';

    displayReport(false);
}

// Displays investment growth with monthly deposits.
void Investment::displayWithDeposits() {
    cout << '\n';
    cout << "Balance and Interest With Additional Monthly Deposits" << '\n';
    cout << "==================================================================" << '\n';

    displayReport(true);
}

// Calculates and displays the investment report.
void Investment::displayReport(bool t_includeDeposits) {
    double balance = m_initialInvestment;
    double monthlyInterest;
    double yearlyInterest = 0.0;
    double depositAmount;

    cout << left
        << setw(10) << "Year"
        << setw(25) << "Year End Balance"
        << "Year End Earned Interest" << '\n';

    cout << "------------------------------------------------------------------" << '\n';

    for (int month = 1; month <= m_numberOfYears * 12; ++month) {

        if (t_includeDeposits) {
            depositAmount = m_monthlyDeposit;
        }
        else {
            depositAmount = 0.0;
        }

        monthlyInterest =
            (balance + depositAmount) *
            ((m_annualInterest / 100.0) / 12.0);

        balance = balance + depositAmount + monthlyInterest;

        yearlyInterest = yearlyInterest + monthlyInterest;

        if (month % 12 == 0) {
            int year = month / 12;

            cout << fixed << setprecision(2);
            cout << left << setw(10) << year;
            cout << "$" << setw(24) << balance;
            cout << "$" << yearlyInterest << '\n';

            yearlyInterest = 0.0;
        }
    }
}

// Runs the investment program.
void Investment::run() {
    char choice;

    do {
        getUserInput();
        displayInput();

        displayWithoutDeposits();
        displayWithDeposits();

        cout << '\n';
        cout << "Would you like to test another investment? (Y/N): ";
        cin >> choice;
        cout << '\n';

    } while (choice == 'Y');

    cout << "Program ended." << '\n';
}