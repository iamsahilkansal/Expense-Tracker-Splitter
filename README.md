## Expense-Tracker-Splitter

# A brief overview of the project:

This project is a basic expense splitter and settler program. It allows users to input the names of individuals and the amount spent by each person, and then calculates the total spendings and the amount each person should pay. It also includes a function to settle the expenditure among the individuals.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Installation instructions:

This program requires a C++ compiler to run.
Clone or download the project from GitHub
Navigate to the project directory in your terminal/command prompt
Compile the program using the command: g++ -o expense_splitter expense_splitter.cpp
Run the program using the command: ./expense_splitter

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Usage instructions:

Run the program and enter the number of people involved in the expenditure.
Enter the names of each person.
Enter the amount spent by each person.
Select the options from the menu to add more money, see the amounts spent by each person, or settle the expenditure.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Code structure:

The program is divided into several functions, each responsible for a specific task. The main function, "main()", handles user input and calls the other functions to perform calculations. 

The program is written in C++ and consists of 5 functions:

'AddMoney()' function prompts the user to enter the name of a person and the amount spent by that person.
'See()' function displays the names of the people and the amount spent by each person.
'TotalSpendings()' function calculates the total spendings.
'PerHead function()' calculates the amount to be paid by each person.
'Settle()' function calculates and displays the amount to be paid by one person to another to settle the expenditure.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Examples:

Input:
Number of people: 3
Names: John, Jane, Jack
Amounts spent: 100, 200, 150

Output:
Total spendings: 450
Amount per head: 150
John should pay 0 to Jane, and 50 to Jack.
Jane should pay 50 to John.
Jack should pay 0 to John and 50 to Jane.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Known issues:

The program does not check for duplicate names.
The program does not handle decimal input for number of people.
The program does not handle negative input for amount spent.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Changelog:

v1.0: Initial release of the program with basic expense splitting and settling functionality.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Contact information:

If you have any questions or concerns about the program, please contact me via my GitHub profile.
