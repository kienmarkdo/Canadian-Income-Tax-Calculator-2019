#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <conio.h>

using namespace std;
// Note: Can add more options such as "Include other deductibles ie: union dues, insurance, etc."

// ============================ FUNCTIONS ===============================
// function prototype
int introMenu();
void citation();
void pressEnterToContinue();
void displayTax();

// functions
int introMenu()
{
    int choice = 0;
    cout << "_______________________________________________________________________________________________________" << endl << endl;
    cout << "Hello and welcome to Kien Do's Canada Income Tax Calculator (2019)" << endl << endl;
    cout << "** All results are calculated based on the 2019 Canadian Federal Tax Bracket.**" << endl << endl;
    cout << "_______________________________________________________________________________________________________" << endl << endl;
    cout << "\t\t Select Menu Options" << endl << endl;
    cout << "\t 0. Sources and citation." << endl;
    cout << "\t 1. Calculate my tax." << endl;
    cout << "\t 9. Quit." << endl << endl;
    cout << "Select your option: ";
    cin >> choice;

    system("CLS");
    return choice;
}

void citation()
{
    cout << "\t Canada Federal Tax Brackets 2019: " << endl;
    cout << "https://www.canada.ca/en/revenue-agency/services/tax/individuals/frequently-asked-questions-individuals/canadian-income-tax-rates-individuals-current-previous-years.html";
    cout << endl << endl;
    cout << "\t Federal Basic Personal Amount (BPA):" << endl;
    cout << "https://www.canada.ca/en/revenue-agency/services/tax/individuals/topics/about-your-tax-return/tax-return/completing-a-tax-return/deductions-credits-expenses/line-300-basic-personal-amount.html";
    cout << endl << endl;
    pressEnterToContinue();
    return;
}

void pressEnterToContinue()
{
    char enter;
    cout << "Press ENTER to continue . . ." << endl << endl;
    enter = getch();
    while (enter != '\r')
    {
        cout << "ERROR: Press ENTER to continue . . ." << endl;
        enter = getch();
    }
    return;
}

void displayTax()
{
    float income = 0;
    float tax = 0;
    float taxable = 0;
    float netIncome = 0;
    float BPA = 11809;
    float percentage = 0;
    float biweekly = 0;

    cout << "Enter your gross yearly income and I will display the:" << endl << endl;
    cout << "\t    - Amount of tax and net income." << endl;
    cout << "\t    - Percentage of income loss through tax." << endl;
    cout << "\t    - Net income for the year." << endl;
    cout << "\t    - Bi-weekly income after tax." << endl << endl;

    cout << "Enter yearly income before tax: $ ";
    cout << fixed; // fixed and set precision make the program only take 2 numbers after the decimal
    cout << setprecision(2);
    cin >> income;

    while (income < 0)
    {
        cout << "You can't have negative income." << endl;
        cout << "Enter yearly income before tax: $ ";
        cin >> income;
    }

    taxable = income - BPA;

    if (income >= 0 && income <= 11809)
    {
        cout << "Your amount is below the Personal Basic Amount. You are not taxed on your income." << endl;
        system("PAUSE");
        return;
    }

    if (taxable <= 47630)
    {
        tax = 0.15 * taxable;
    }
    else if (taxable > 47630 && taxable <= 95259)
    {
        tax = 0.205*(taxable - 47630) + 7144.5;
    }
    else if (taxable > 95259 && taxable <= 147667)
    {
        tax = 0.26*(taxable - 95259) + 17888.14;
    }
    else if (taxable > 147667 && taxable <= 210371)
    {
        tax = 0.29*(taxable - 147667) + 31514.22;
    }
    else if (taxable > 210371)
    {
        tax = 0.33*(taxable - 210371) + 49698.38;
    }

    percentage = (tax/income) * 100;
    netIncome = income - tax;
    biweekly = netIncome/26;
    cout << endl;
    cout << "Total tax                  : $ " << tax << endl << endl;
    cout << "Percentage                 : " << percentage << " %" << endl << endl;
    cout << "Net income for the year    : $ " << netIncome << endl << endl;
    cout << "Bi-weekly income after tax : $ " << biweekly << endl << endl;
    pressEnterToContinue();
    //system("PAUSE");   // for CodeBlocks IDE
    return;
}
int main()
{
    int menuOption = 0;
    bool repeat = true;

    do
    {
        menuOption = introMenu();

        switch (menuOption)
        {
        case 0:
            citation();
            break;
        case 1:
            displayTax();
            break;
        case 9:
            repeat = false;
            break;
        default:
            cout << "Error. Invalid option." << endl;
            system("PAUSE");
            break;
        }
        system("CLS");
    } while (repeat == true);

    cout << "Thank you for using my tax calculator!" << endl;
    cout << "Your creator, Kien Do." << endl;


    return 0;
}
