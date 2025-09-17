# Simple C++ Expense Tracker

This project is a basic console-based **Personal Expense Tracker** system implemented in C++. It allows a user to input expense details and stores the data in a local text file. The system demonstrates key concepts of **modular programming** and **file handling** using a multi-file structure.

---

### Features

-   **Expense Tracking**: Record and manage personal expenses with details such as category, amount, and date.
-   **File Storage**: Automatically creates and appends expense data to a text file named `expenses_log.txt`.
-   **Modular Design**: The codebase is split into three distinct files to showcase a multi-file project structure, ideal for collaborative development.

---

### Project Structure

The project is organized into the following files:

-   `expense.h`: Defines the `Expense` class, which acts as a data structure to hold expense information.
-   `file_handler.h`: Declares the `saveExpensesToFile` function, providing an interface for the file I/O operations.
-   `file_handler.cpp`: Implements the `saveExpensesToFile` function, which handles opening, writing to, and closing the output file.
-   `main.cpp`: Contains the main program logic, including user interaction and calls to functions from other files.

---

### How to Compile and Run

To compile and run the program, you'll need a C++ compiler like **g++**.

1.  **Clone or download** the project files to your local machine.
2.  **Open a terminal** or command prompt and navigate to the project directory.
3.  **Compile the source files** using the following command. This links all the necessary components into a single executable file.

    ```bash
    g++ main.cpp file_handler.cpp -o expense_tracker
    ```

    * **Note**: On Windows, the command will typically produce `expense_tracker.exe`.

4.  **Run the executable** from your terminal to start the program.

    ```bash
    ./expense_tracker
    ```

---

### Usage

Once the program is running, follow the on-screen prompts to enter your expense details.

-   Enter the expense **category** (e.g., Food, Rent).
-   Enter the **amount** as a numerical value.
-   Enter the **date** in a `YYYY-MM-DD` format.
-   After each entry, you will be asked if you want to add another expense. Type **`y`** for yes or **`n`** for no.