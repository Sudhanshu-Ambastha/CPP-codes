#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>
#include <vector>
#include "expense.hpp"

using namespace std;

// Function declaration
void saveExpensesToFile(const vector<Expense> &expenses, const string &filename);

#endif // FILE_HANDLER_H