# Project 1
# CS 1181
# Show Pratoomratana
# August 26, 2019
# Brandon Carpenter
# Description - Create a mortgage calculator that the user can enter data into.

# This asks the amount of the home from the user.
str_amount = input("what is the total amount of your home?")
# This changes the input from the user into a float number so they can input decimals.
amount = float(str_amount)

# This will print the amount the user entered.
print("Total amount of your home: $", amount)

# This asks for the interest rate of the home.
str_interest = input('What is the annual interest rate of your home?')
# This changes the interest rate from the user into a float function.
interest = float(str_interest)

# Makes the interest into a decimal that the program can use for the math.
real_interest = (interest / 100)
# Calculates the interest per month
monthly_interest = (real_interest / 12)

# This will print the interest rate.
print ('Interest of your home:', interest, '%')

# Asks for the term of the loan
str_term = input('What is the term of your loan in months?')
# Changes the input from the user to a integer.
term = int(str_term)

# Displays the length of loans in months.
print('Term of loan:', term, 'months')

# gives the function in the parenthesis
one_plus_rate = (1 + monthly_interest)

# Does the top calculation (interest(1 + interest ^term))
top_equation = (monthly_interest * (one_plus_rate ** term))

# Does the bottom calculation (1 + interest ^term -1)
bottom_equation = ((one_plus_rate ** term) - 1)

# This will calculate the mortgage payment
mortgage_payment = (amount * (top_equation / bottom_equation))

# Gives the monthly mortgage payment
print('Your monthly mortgage payment is:$', mortgage_payment)