1. Currency Converter (4 pts)

Write a program that will convert U.S. dollar amounts to Japanese yen and to euros, storing the conversion factors in the constants YEN_PER_DOLLAR and EUROS_PER_DOLLAR. Use the following exchange rates:

1 Dollar = 98.93 Yen

1 Dollar = 0.74 Euros

Format your currency amounts in fixed-point notation, with two decimal places of precision, and be sure the decimal point is always displayed.

2. Monthly Payment (6 pts)

The monthly payment on a loan may be calculated by the following formula:

payment =(rate * (1+rate)^n) / ((1+rate)^n - 1) *l


Rate is the monthly interest rate, which is the annual interest rate divided by 12. (12 percent annual interest would be 1 percent monthly interest.) N is the number of payments, and LoanAmount is the amount of the loan. Write a program that asks for these values then displays a report similar to:

Loan Amount:            $ 10000.00
Yearly Interest Rate:          12%
Monthly Interest Rate:          1%
Number of Payments:             36
Monthly Payment:        $   332.14
Amount Paid Back:       $ 11957.15
Interest Paid:          $  1957.15
Be sure to properly format your output. You should display 3 decimal places for floating point numbers.

3. Word Game (5 pts)

Write a program that plays a word game with the user. The program should ask the user to enter the following:

Name

Age

City

College

Profession

After the user has entered these items, the program should display the following story, inserting the user’s input into the appropriate locations:

There once was a person named NAME who lived in CITY. At the age of AGE, NAME went to college at COLLEGE. NAME graduated and went to work as a PROFESSION.

Hint: You will need to use getline() to get inputs that have multiple words in them, for example, name, college etc.

4. Pizza Party

Suppose you are having a pizza party and need to decide how many pizzas you need to purchase if each person attending is expected to eat an average of four slices. The program should

Ask the user for the number of people who will be at the party

Ask the user for the diameter of the pizzas in inches to be ordered

Calculate and display the number of pizzas to purchase.

To calculate the number of slices in a pizza, use the following information:

Each slice should have an area of 14.125 inches.

To calculate the number of slices, simply divide the area of the pizza by 14.125.

The area of the pizza is calculated with this formula:

LaTeX: Area = \pi r^{2} A r e a = π r 2

Be sure to properly format your output. You should display 3 decimal places for floating point numbers.
