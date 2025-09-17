#include <iostream>
#include <vector>
#include "expense.h"
#include "file_handler.h"

using namespace std;

void getExpenseDetails(vector<Expense> &expenses);

int main()
{
    vector<Expense> myExpenses;
    string filename = "expenses_log.txt";

    getExpenseDetails(myExpenses);

    saveExpensesToFile(myExpenses, filename);

    cout << "Program finished. Check the '" << filename << "' file for details." << endl;

    return 0;
}

void getExpenseDetails(vector<Expense> &expenses)
{
    char choice;
    do
    {
        string category, date;
        double amount;

        cout << "Enter expense category (e.g., Food, Rent): ";
        getline(cin >> ws, category);

        cout << "Enter amount: $";
        cin >> amount;

        cout << "Enter date (e.g., YYYY-MM-DD): ";
        getline(cin >> ws, date);

        expenses.emplace_back(category, amount, date);

        cout << "Do you want to add another expense? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}