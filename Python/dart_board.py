# Dart Game
# CS 1181
# Show Pratoomratana
# 10/1/19
# Brandon Carpenter
# Create a game of darts that randomly throws darts and display's the dart score alongside the current score until
# the score reaches zero. If it goes past zero tell the user of a bust.

import random


'''Creates a function that throws the dart at random'''
def throw_dart():
    throw_score = random.randrange(0, 20)
    chance_to_double_triple_bull_bullseye = random.random()
    # Chance for a Bullseye is about .14%
    # Got this percent value from the internet from someone doing the math
    # of the surface area of the board in relation with the surface area of the bullseye.
    if chance_to_double_triple_bull_bullseye <= 0.0014:
        actual_score = 50
        return actual_score
    # Chance for a Bull is 0.9%. I added the 0.9% from the previous value
    elif chance_to_double_triple_bull_bullseye <= 0.01043:
        actual_score = 25
        return actual_score
    # Chance to get a triple is 5%. I added the 5% from the previous value
    elif chance_to_double_triple_bull_bullseye <= 0.06043:
        actual_score = throw_score * 3
        return actual_score
    # Chance to get a double is 15%
    elif chance_to_double_triple_bull_bullseye <= 0.21043:
        actual_score = throw_score * 2
        return actual_score
    # If it's not a special circumstance display the score
    else:
        actual_score = throw_score
        return actual_score


'''Creates a function that adds the score 
   of the throw to the total score'''
def play_darts():

    # Start the game at 301 points
    total_score = 301
    amount_of_throws = 0
    print('Starting Score:', total_score)

    score_tracker(total_score, throw_dart(), amount_of_throws)


# A while loop that will execute until the total score is less than or equal to zero
def score_tracker(total_score, current_throw, amount_of_throws):

    while total_score > 0:
        total_score -= current_throw
        amount_of_throws += 1

        total_score = check_if_score_is_zero(total_score, current_throw)

        print('Current Throw:', current_throw)
        print('Current Score:', total_score)
    return print('Total throws:', amount_of_throws)


# Checks to see if the total score is equal to or less than zero
def check_if_score_is_zero(total_score, current_throw):
    if total_score < 0:
        # When the total score goes past 0 add back the current throw to get back to the score before it exceeded 0.
        print('Bust!')
        total_score += current_throw
        return total_score
    elif total_score == 0:
        print('You Win!')
        return total_score
    else:
        return total_score


print(play_darts())