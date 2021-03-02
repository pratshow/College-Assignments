# Grade Report
# CS 1181
# Show Pratoomratana
# 10/31/2019
# Brandon Carpenter
# Create a grade report that randomly generates 35 grades and gives the letter grades in a list of tuples.

import random

'''
Function to give the letter grade based off the percentage score.
'''
def letter_grade(score):
    if score >= 93:
        return "A"
    elif 90 <= score <= 92.99:
        return "A-"
    elif 87 <= score <= 89.99:
        return "B+"
    elif 83 <= score <= 86.99:
        return "B"
    elif 80 <= score <= 82.99:
        return "B-"
    elif 77 <= score <= 79.99:
        return "C+"
    elif 73 <= score <= 76.99:
        return "C"
    elif 70 <= score <= 72.99:
        return "C-"
    elif 67 <= score <= 69.99:
        return "D+"
    elif 63 <= score <= 66.99:
        return "D"
    elif 60 <= score <= 62.99:
        return "D-"
    else:
        return "F"


'''
Generate the grades and make a tuple out of those values and append the tuple to the list.
Along with calculating the average, highest, and lowest scores.
'''
def list_of_grades():
    list_of_tuples = []                                                         # Empty list to add tuples to
    for each_grade in range(35):                                                # For loop runs for 35 grades
        # Random number for each grade. Divided by 100 to get a decimal(Got the idea off the internet)
        current_grade = (random.randint(5000, 10000)/100)
        grade_tuple = (current_grade, letter_grade(current_grade))              # Creates tuples with score and letter
        list_of_tuples.append(grade_tuple)                                      # Appends that tuple to the list

        print(format(grade_tuple[0], ">15.2f"), grade_tuple[1].ljust(0))   # Prints each value in the tuple

    low_score = min(list_of_tuples)                                 # Gets the smallest grade from the tuple
    high_score = max(list_of_tuples)                                # Gets the largest grade from the tuple

    print("Class Average:", ave_grade(list_of_tuples))              # Prints the average using the average function
    print("Lowest Score:", low_score[0])                            # Prints the lowest score without the letter grade
    print("Highest Score:", high_score[0])                          # Prints the highest score without the letter grade
    return list_of_tuples


'''
Adds all the values of grades and divides them by the amount of the grade to get the average.
'''
def ave_grade(score):
    total = 0                                   # Initialize total at the value of 0
    for each_grade in range(35):                # For loop that runs 35 times(the amount of grades)
        current_grade = score[each_grade][0]    # Get the current grade within the specific tuple
        total += current_grade                  # Adds that grade to the total
    return format(total/35, "2.2f")             # Returns the grades total divided by 35 to get the average


CS_grades = ["Grades for Computer Science(%):", "Computer Science letter grade:"]

# Prints the grades header and formats it to have a space between them
print(format(CS_grades[0], ">0s"), (format(CS_grades[1], ">30s")))

list_of_grades()

