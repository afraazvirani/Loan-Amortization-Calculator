// ============================================================
// Name    : Afraaz Virani
// Course  : COSC 1437 — Programming Fundamentals II
// Date    : 6/9/26
// Program : Chapter 5 Major Project
// Option  : B — Loan Amortization
// Purpose : Calculating a loan repayment schedule with each month's interest charge, 
// principal payment, and remaining balance.
// ============================================================

// ===== Section 1 — Pseudocode Design Block =====
/*
Main Algorithm:

Declare integer MONTHS_PER_YEAR = 12
Declare real ROUND_OFF = 0.01

Declare real loanAmount
Declare real annualInterestRate
Declare real monthlyPayment
Declare real firstMonthInterest

Declare integer columnCount
Declare real remainingBalance
Declare integer month
Declare character choice
Declare integer rowCount
Declare real monthlyInterest
Declare real principalPayment
Declare real endingBalance
Declare boolean foundMonth

Declare real totalInterestPaid
Declare real percentRepaid
Declare integer numberOfBars
Declare integer barCount
Declare character runAgain

Format decimal output using fixed and setprecision(2)

Part B

do
    Print "Enter the loan amount: $"
    Input loanAmount

    if loanAmount <= 0 then
        Print "Error: Loan amount must be positive"
    end if
while loanAmount <= 0

do
    Print "Enter the annual interest rate as a percentage: "
    Input annualInterestRate

    if annualInterestRate <= 0 then
        Print "Error: Interest rate must be positive"
    end if
while annualInterestRate <= 0

do
    Print "Enter the monthly payment: $"
    Input monthlyPayment

    if monthlyPayment <= 0 then
        Print "Error: Monthly payment must be greater than zero"
    end if
while monthlyPayment <= 0

firstMonthInterest = loanAmount * annualInterestRate / MONTHS_PER_YEAR / 100

if monthlyPayment <= firstMonthInterest then
    Print blank line
    Print "Warning: Your monthly payment is too low to repay this loan"
    Print "The first month's interest is: $", firstMonthInterest
    Print "Your monthly payment must be greater than the monthly interest"
    return 0
else
    Print blank line
    Print "Loan information accepted successfully"
end if

Part C

Print blank line
Print "Amortization Table"

columnCount = 1

while columnCount <= 5

    if columnCount == 1 then
        Print "Month" right aligned in width 8

    else if columnCount == 2 then
        Print "Beginning Balance" right aligned in width 20

    else if columnCount == 3 then
        Print "Interest Paid" right aligned in width 18

    else if columnCount == 4 then
        Print "Principal Paid" right aligned in width 18

    else
        Print "Ending Balance" right aligned in width 18

    end if

    columnCount = columnCount + 1

end while

Print blank line

remainingBalance = loanAmount
month = 1
choice = 'Y'

while choice != 'N' AND choice != 'n' AND remainingBalance > 0

    for rowCount = 1 to 12 while remainingBalance > 0

        monthlyInterest = remainingBalance * annualInterestRate / MONTHS_PER_YEAR / 100
        principalPayment = monthlyPayment - monthlyInterest

        if monthlyPayment > remainingBalance + monthlyInterest then
            principalPayment = remainingBalance
            endingBalance = 0
        else
            endingBalance = remainingBalance - principalPayment
        end if

        Print month right aligned in width 8
        Print remainingBalance right aligned in width 20
        Print monthlyInterest right aligned in width 18
        Print principalPayment right aligned in width 18
        Print endingBalance right aligned in width 18

        remainingBalance = endingBalance
        month = month + 1

    end for

    if remainingBalance > 0 then
        Print blank line
        Print "Show next 12 months? Enter Y to continue or N to stop: "
        Input choice
    end if

end while

foundMonth = false
remainingBalance = loanAmount
month = 1

while remainingBalance > 0 AND foundMonth == false

    monthlyInterest = remainingBalance * annualInterestRate / MONTHS_PER_YEAR / 100
    principalPayment = monthlyPayment - monthlyInterest

    if principalPayment > monthlyInterest then
        foundMonth = true
        Print blank line
        Print "Congratulations"
        Print "Your principal payment becomes greater than your interest payment in month number: ", month
        Print blank line
        Print blank line
        break
    else
        remainingBalance = remainingBalance - principalPayment
        month = month + 1
    end if

end while

Part D

remainingBalance = loanAmount
month = 1
totalInterestPaid = 0.0

while remainingBalance > 0

    monthlyInterest = remainingBalance * annualInterestRate / MONTHS_PER_YEAR / 100
    principalPayment = monthlyPayment - monthlyInterest

    if principalPayment < ROUND_OFF then
        month = month + 1
        continue
    end if

    if monthlyPayment > remainingBalance + monthlyInterest then
        principalPayment = remainingBalance
        endingBalance = 0.0
    else
        endingBalance = remainingBalance - principalPayment
    end if

    totalInterestPaid = totalInterestPaid + monthlyInterest

    Print month right aligned in width 18
    Print remainingBalance right aligned in width 18
    Print monthlyInterest right aligned in width 18
    Print principalPayment right aligned in width 18
    Print endingBalance right aligned in width 18

Part E

    percentRepaid = loanAmount - endingBalance
    percentRepaid = percentRepaid / loanAmount
    numberOfBars = percentRepaid * 20 converted to integer

    Print "["

    for barCount = 1 to 20

        if barCount <= numberOfBars then
            Print "#"
        else
            Print "-"
        end if

    end for

    Print "]"
    remainingBalance = endingBalance
    month = month + 1

end while

Print blank line
Print "Total interest paid: $", totalInterestPaid

Part F

if principalPayment > monthlyInterest then
    foundMonth = true
    Print crossover month message
    break
end if

if principalPayment < ROUND_OFF then
    month = month + 1
    continue
end if

Part G

do
    Print blank line
    Print "Would you like to run a new loan scenario? Enter Y or N: "
    Input runAgain

    if runAgain != 'Y' AND runAgain != 'y' AND runAgain != 'N' AND runAgain != 'n' then
        Print "Invalid choice. Please enter Y or N"
    end if

while runAgain != 'Y' AND runAgain != 'y' AND runAgain != 'N' AND runAgain != 'n'

if runAgain == 'Y' OR runAgain == 'y' then
    Print "The program will restart with new loan values"
else
    Print "Thank you for your time. Goodbye"
end if

return 0
*/



#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // ===== Section 2 — Input & Validation =====
    const int MONTHS_PER_YEAR = 12;  // fixed initializing as double.
    const double ROUND_OFF = 0.01;
    const int MAX_COLUMNS = 5;
    const int MAX_DISPLAY_ROWS = 12;
    const int PROGRESS_BAR_WIDTH = 20;
    const int PERCENT_DIVISOR = 100;

    double loanAmount;
    double annualInterestRate;
    double monthlyPayment;
    double firstMonthInterest;
    
    int columnCount;
    double remainingBalance;
    int month;
    char choice;
    int rowCount;
    double monthlyInterest;
    double principalPayment;
    double endingBalance;
    bool foundMonth;

    double totalInterestPaid;

    double percentRepaid;
    int numberOfBars;
    int barCount;

    char runAgain;


    cout << fixed << setprecision(2);

    do
    {
        cout << "Enter the loan amount: $";
        cin >> loanAmount;

        if (loanAmount <= 0)
        {
            cout << "Error: Loan amount must be positive." << endl;
        }

    } while (loanAmount <= 0);

    do
    {
        cout << "Enter the annual interest rate as a percentage: ";
        cin >> annualInterestRate;

        if (annualInterestRate <= 0)
        {
            cout << "Error: Interest rate must be positive." << endl;
        }

    } while (annualInterestRate <= 0);

    do
    {
        cout << "Enter the monthly payment: $";
        cin >> monthlyPayment;

        if (monthlyPayment <= 0)
        {
            cout << "Error: Monthly payment must be greater than zero." << endl;
        }

    } while (monthlyPayment <= 0);

    firstMonthInterest = loanAmount * (annualInterestRate / MONTHS_PER_YEAR / PERCENT_DIVISOR);

    if (monthlyPayment <= firstMonthInterest)
    {
        cout << endl;
        cout << "Warning: Your monthly payment is too low to repay this loan." << endl;
        cout << "The first month's interest is: $" << firstMonthInterest << "." << endl;
        cout << "Your monthly payment must be greater than the monthly interest." << endl;

        return 0;    // added guard as it was still printing the table / stuck in infinite loop as the remainingBalance kept increasing and never reached zero.
    }

    else
    {
        cout << endl;
        cout << "Loan information accepted successfully." << endl;
    }


    // ===== Section 3 — Loop Type Showcase =====
    cout << endl;
    cout << "Amortization Table" << endl;

    // Counter-controlled loop:
    // This loop is used because the number of columns is known already.
    columnCount = 1;

    while (columnCount <= MAX_COLUMNS)
    {
        if (columnCount == 1)
        {
            cout << right << setw(8) << "Month";
        }
        else if (columnCount == 2)
        {
            cout << right << setw(20) << "Beginning Balance";
        }
        else if (columnCount == 3)
        {
            cout << right << setw(18) << "Interest Paid";
        }
        else if (columnCount == 4)
        {
            cout << right << setw(18) << "Principal Paid";
        }
        else
        {
            cout << right << setw(18) << "Ending Balance";
        }

        columnCount = columnCount + 1;
    }

    cout << endl;

    remainingBalance = loanAmount;
    month = 1;
    choice = 'Y';

    // Sentinel-controlled loop:
    // This loop is used because the user controls when to stop by entering N or n.
    while (choice != 'N' && choice != 'n' && remainingBalance > 0)
    {
        // For loop:
        // This loop is used because each display window prints up to 12 rows.
        for (rowCount = 1; rowCount <= MAX_DISPLAY_ROWS && remainingBalance > 0; rowCount = rowCount + 1)
        {
            monthlyInterest = remainingBalance * (annualInterestRate / MONTHS_PER_YEAR / PERCENT_DIVISOR);
            principalPayment = monthlyPayment - monthlyInterest;

            if (monthlyPayment > remainingBalance + monthlyInterest)
            {
                principalPayment = remainingBalance;
                endingBalance = 0;
            }
            else
            {
                endingBalance = remainingBalance - principalPayment;
            }

            cout << right << setw(8) << month;
            cout << right << setw(20) << remainingBalance;
            cout << right << setw(18) << monthlyInterest;
            cout << right << setw(18) << principalPayment;
            cout << right << setw(18) << endingBalance << endl;

            remainingBalance = endingBalance;
            month = month + 1;
        }

        if (remainingBalance > 0)
        {
            cout << endl;
            cout << "Show next 12 months? Enter Y to continue or N to stop: ";
            cin >> choice;
        }
    }

    // Flag-controlled loop:
    // This loop searches until the first month where principal paid is greater than interest paid.
    foundMonth = false;
    remainingBalance = loanAmount;
    month = 1;

    while (remainingBalance > 0 && foundMonth == false)
    {
        monthlyInterest = remainingBalance * (annualInterestRate / MONTHS_PER_YEAR / PERCENT_DIVISOR);
        principalPayment = monthlyPayment - monthlyInterest;

        if (principalPayment > monthlyInterest)
        {
            foundMonth = true;
            
            cout << endl;
            cout << "Congratulations!" << endl;
            cout << "Your principal payment becomes greater than your interest payment in month number: " << month << endl;
            cout << endl;
            cout << endl;

            break;   //===== Section 6 — break and continue Demonstration =====
        }
        else
        {
            remainingBalance = remainingBalance - principalPayment;
            month = month + 1;
        }
    }

    // ===== Section 4 — Core Loop Logic =====
    remainingBalance = loanAmount;
    month = 1;
    totalInterestPaid = 0.0;

    while (remainingBalance > 0)
    {
        monthlyInterest = remainingBalance * (annualInterestRate / MONTHS_PER_YEAR / PERCENT_DIVISOR);
        principalPayment = monthlyPayment - monthlyInterest;


        // ===== Section 6 — break and continue Demonstration =====
        if (principalPayment < ROUND_OFF)
        {
            month = month + 1;
            continue;
        }


        if (monthlyPayment > remainingBalance + monthlyInterest)
        {
            principalPayment = remainingBalance;
            endingBalance = 0.0;
        }
        
        else
        {
            endingBalance = remainingBalance - principalPayment;
        }

        totalInterestPaid = totalInterestPaid + monthlyInterest;

        cout << right << setw(18) << month;
        cout << setw(18) << remainingBalance;
        cout << setw(18) << monthlyInterest;
        cout << setw(18) << principalPayment;
        cout << setw(18) << endingBalance << endl;


        // ===== Section 5 — Nested Control Structures =====
        percentRepaid = (loanAmount - endingBalance) / loanAmount;
        numberOfBars = (int) (percentRepaid * 20);

        cout << "[";

        for (barCount = 1; barCount <= PROGRESS_BAR_WIDTH; barCount = barCount + 1)
        {
            if (barCount <= numberOfBars)
            {
                cout << "#";
            }
            
            else
            {
                cout << "-";
            }
        }

        cout << "]" << endl;

        remainingBalance = endingBalance;
        month = month + 1;

    }

    cout << endl;
    cout << "Total interest paid: $" << totalInterestPaid << endl;

    // ===== Section 7 — do...while Input Validation =====
    do
    {
        cout << endl;
        cout << "Would you like to run a new loan scenario? Enter Y or N: ";
        cin >> runAgain;

        if (runAgain != 'Y' && runAgain != 'y' && runAgain != 'N' && runAgain != 'n')
        {
            cout << "Invalid choice. Please enter Y or N." << endl;
        }

    } while (runAgain != 'Y' && runAgain != 'y' && runAgain != 'N' && runAgain != 'n');

    if (runAgain == 'Y' || runAgain == 'y')
    {
        cout << "The program will restart with new loan values." << endl;
    }

    else
    {
        cout << "Thank you for your time. Goodbye!" << endl;
    }


    return 0;
}

// ===== Section 8 — Avoiding Bugs / Debugging Commentary =====
/*
1. Off-by-one error:
An off-by-one error was possible in the progress bar loop as it must print exactly 20 characters.
So I started the loop from 1 and ended it at 20, printing exactly 20 characters.

2. Infinite loop prevention:
An infinite loop was possible in the core loop logic while loop.
To prevent the loop from running forever, the program updates reaminingBalance = endingBalance at the end of each month.
Which is then checked if remainingBalance > 0 at each iteration.

3. Division by zero:
Division occurs when calculating percentRepaid in Section 5:
percentRepaid = (loanAmount - endingBalance) / loanAmount;
The program uses a do...while loop to make sure loanAmount is positive before this division happens.

4. Software patches:
In Section 4, I was tempted to fix negative ending balances by just printing zero whenever the balance became negative. 
The real root cause is that the final monthly payment may be larger than the amount still owed, and the user may pay extra.
I fixed it properly by checking whether:

if (monthlyPayment > remainingBalance + monthlyInterest)
        {
            principalPayment = remainingBalance;
            endingBalance = 0.0;
        }

If that was true, the program made principalPayment = remainingBalance and endingBalance = 0.0.

5. Semicolon after loop header:
If I accidentally placed a semicolon at the end of your most important while or for loop header,
that would make the loop itself be disconnected from the condition that would terminate the loop, causing an infinite loop.
To check for this, I double checked there were no extra semicolon at the end of each while, for, and do...while loop.
*/