# Expense-Tracker-Splitter

## A brief overview of the project:

This project is a basic expense splitter and settler program. It allows users to input the names of individuals and the amount spent by each person, and then calculates the total spendings and the amount each person should pay. It also includes a function to settle the expenditure among the individuals.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Installation instructions:

1. This program requires a C++ compiler to run.<br>
2. Clone or download the project from GitHub.<br>
3. Navigate to the project directory in your terminal/command prompt.<br>
4. Compile the program using the command: g++ -o expense_splitter expense_splitter.cpp .<br>
5. Run the program using the command: ./expense_splitter. <br>

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Usage instructions:

1. Run the program and enter the number of people involved in the expenditure.<br>
2. Enter the names of each person.<br>
3. Enter the amount spent by each person.<br>
4. Select the options from the menu to add more money, see the amounts spent by each person, or settle the expenditure.<br>

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Code structure:

The program is divided into several functions, each responsible for a specific task. The main function, "main()", handles user input and calls the other functions to perform calculations. <br> 

The program is written in C++ and consists of 5 functions:<br> 

1. ***'AddMoney'*** function prompts the user to enter the name of a person and the amount spent by that person.<br>
2. ***'See'*** function displays the names of the people and the amount spent by each person.<br>
3. ***'TotalSpendings'*** function calculates the total spendings.<br>
4. ***'PerHead function'*** calculates the amount to be paid by each person.<br>
5. ***'Settle'*** function calculates and displays the amount to be paid by one person to another to settle the expenditure.<br>

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Examples:

**Input:** <br>
Number of people: 3 <br>
Names: John, Jane, Jack <br>
Amounts spent: 100, 200, 150 <br>

**Output:** <br>
Total spendings: 450 <br>
Amount per head: 150 <br>
John should pay 0 to Jane, and 50 to Jack. <br>
Jane should pay 50 to John. <br>
Jack should pay 0 to John and 50 to Jane. <br>

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Known issues:

1. The program does not check for duplicate names. <br>
2. The program does not handle decimal input for number of people. <br>
3. The program does not handle negative input for amount spent. <br>

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Changelog:

v1.0: Initial release of the program with basic expense splitting and settling functionality. <br>

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Contact information:

If you have any questions or concerns about the program, please contact me via my GitHub profile. <br>
