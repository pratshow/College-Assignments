# skee_ball.py
# Brandon Carpenter
# 9/24/2019
# CS/INFO 1181
# Professor: Brandon Carpenter
# Description: An awesome skee ball game

import random

'''
This is the main game application. I knows about the game rules, but 
has abstracted out functionality to decrease the responsibility of this function
'''
def standard_skee_ball(desired_score):

    # start off with empty score and rolls total
    current_score = 0
    total_rolls = 0

    # Execute the body of this code until we reach the desired score
    while current_score < desired_score:

        current_roll_points = make_roll()               # make a roll
        total_rolls += 1                                # increase number of rolls
        print_current_roll_points(current_roll_points)  # print the roll

        # this game checks for a 0. That will make the score reset
        current_score = check_for_score_reset(current_roll_points, current_score)
            
        print_current_score(current_score)              # print the current score after totaling (or reseting)

    return total_rolls  # Total rolls it took to get to desired score


'''
Rolls the ball and uses random number between 0 and 100
to use for the odds of getting each score
Returns role score
'''
def make_roll():
    # Gets a random number between 0 and 100
    random_number = random.randint(0, 101)

    roll_points = None
    # 40% chance of getting 5 points
    if random_number >= 60:
        roll_points = 5
    # 20% chance of getting 15
    elif random_number >= 40:
        roll_points = 15
    # 15% chance of getting 20
    elif random_number >= 25:
        roll_points = 20
    # 10% chance of getting 25
    elif random_number >= 15:
        roll_points = 25
    # 10% chance of getting a 30
    elif random_number >= 5:
        roll_points = 30
    # 5% chance of getting 0
    else:
        roll_points = 0
    # returns the roll's points
    return roll_points


def check_for_score_reset(roll_points, current_score):
    # If the throw was a 0, we have to start over!
    if roll_points == 0:
        print("MISSED! I have to start over!")
        # set current score to 0 (starting over)
        current_score = 0
    # else just increase the total score
    else:
        current_score += roll_points
    # returns the newly set current score
    return current_score

'''
Simply prints the current score with a message
Accepts the current score
'''
def print_current_score(current_score):
    print("Current score: " + str(current_score))

'''
Simply prints a given roll's points with a message
Accepts the current score
'''
def print_current_roll_points(current_roll_points):
    print("Roll points: " + str(current_roll_points))


'''
Main application called at the bottom. You don't HAVE to do this if you don't want to
You can just have this logic stand alone without a function
'''
def main():
    print(standard_skee_ball(100))

# calls the main function
main()