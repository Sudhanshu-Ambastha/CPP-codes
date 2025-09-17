#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <string>

using namespace std;

class Expense
{
public:
    string category;
    double amount;
    string date;

    // Default constructor
    Expense() : amount(0.0) {}

    // Parameterized constructor
    Expense(string cat, double amt, string dt) : category(cat), amount(amt), date(dt) {}
};

#endif // EXPENSE_H