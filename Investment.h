#ifndef PROJECT_TWO_INVESTMENT_H_
#define PROJECT_TWO_INVESTMENT_H_

class Investment {
public:
    Investment();
    void run();

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;

    void getUserInput();
    void displayInput();
    void displayWithoutDeposits();
    void displayWithDeposits();
    void displayReport(bool t_includeDeposits);
};

#endif