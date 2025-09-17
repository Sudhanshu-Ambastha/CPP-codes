#include "file_handler.h"
#include <fstream>
#include <vector>

void saveExpensesToFile(const vector<Expense> &expenses, const string &filename)
{
    ofstream outFile(filename, ios::app);
    if (!outFile.is_open())
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    for (const auto &expense : expenses)
    {
        outFile << "Category: " << expense.category
                << ", Amount: $" << expense.amount
                << ", Date: " << expense.date << endl;
    }

    outFile.close();
    cout << "Expenses successfully saved to " << filename << endl;
}