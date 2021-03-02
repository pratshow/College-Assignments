# Caesar Cipher
# CS 1181
# Show Pratoomratana
# 10/8/19
# Brandon Carpenter
# Create a program that takes the input of a string and cipher's
# it by selecting the letter x spaces later in the alphabet.


# Imports necessary file
import random
import string

'''
Main function to get the values from the user and encrypt the inputted string
'''
def use_cipher():

    # Uses function to ask and check if the value entered is valid
    cipher_key = check_key()

    # Asks the user for the text they would like to encrypt and checks to make sure it's a valid entry
    text_to_encrypt = check_text()

    # Prints the encrypted text
    print(encrypter(text_to_encrypt, cipher_key))

    # Asks if you would like to make another cipher
    start_again()


'''
Checks to see if the entered text is only lowercase letters and spaces
'''
def check_text():
    text_to_encrypt = input("Enter the text you would like to encrypt.(lowercase letters and spaces only)")
    idx = 0                                                             # Sets the staring index at zero
    empty_string = ""                                                   # Makes an empty string to build on
    while idx < len(text_to_encrypt):                                   # Loop executes the length of the string
        current_char = text_to_encrypt[idx]                             # Gets the current letter at it's index
        if current_char not in string.ascii_lowercase and current_char not in " ":  # Checks if the current letter
            print('Please enter only lowercase letters and spaces.')                # is lowercase or a space
            new_text = check_text()                                     # Run check again with new input
            return new_text

        else:
            empty_string += current_char        # Adds the letter to the empty string
            idx += 1                            # Goes up by one to access the next index
            if idx == len(text_to_encrypt):     # When all indexes have been accessed
                return empty_string             # Return the string that was being built


'''
Function that checks if the entered key is between 0 and 25 or 100
'''
def check_key():

    # Gets an input from the user
    cipher_key = input("What key would you like to use(number between 0 and 25 or 100 for a random key)?")

    # Validates that the entered value is an integer with a try/except block
    try:
        key = int(cipher_key)
    except:
        print("Invalid Input, please try again.")       # If the value is not an intiger, make the user try again
        new_key = check_key()
        return new_key

    # if the key is between 0 and 25 or 100, print the key. Otherwise make user try again.
    if key <= 25 and key >=0:
        print("The chosen key is:", key)

    elif key == 100:
        key = random.randrange(0, 26)
        print("The randomly chosen key is:", key)

    else:
        print("Invalid Input, please try again.")
        new_key = check_key()
        return new_key
    return key


'''
Creates a function to take the string and key and encrypts it.
'''
def encrypter(string_to_encrypt, cipher_key):

    # Defines variables that will be used in the loop
    # Defines the alphabet so the program can access it's index
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    # Creates an empty string so the program can add the encrypted text into it
    encrypted_string = ""
    # Gets the length of the string entered so we can access it's index
    string = len(string_to_encrypt)

    # Creates a loop that will iterate the amount of times of the index of the string
    for idx in range(string):
        # Probably a better way to do this rather than updating the
        # variable over and over but this is what worked for me
        current_char = string_to_encrypt[idx]           # Takes the letter at the current index in the loop
        if current_char == " ":                         # Checks if the character is a space
            encrypted_string += current_char            # If it is a space add the space to the encrypted string
        else:
            encrypted_char = alphabet.find(current_char)    # Gets the index of the current letter
            encrypted_char += cipher_key                    # Adds the index to the cipher key
            encrypted_char = check_overlap(encrypted_char)  # Uses function to check if it overlaps the alphabet
            encrypted_char = alphabet[encrypted_char]       # Finds the letter of the new index
            encrypted_string += encrypted_char              # Adds the new letter to the empty string
    return encrypted_string


'''
Checks to see if the new charter index will exceed 25 so it can start over at the beginning of the alphabet
'''
def check_overlap(letter_index):
    if letter_index < 25:               # If the index doesn't exceed 25 return the letter
        return letter_index
    else:                               # If the index does exceed 25 take the remainder of the index return the letter
        letter_index %= 26
        return letter_index

'''
Asks the user if they would like to make a new cipher
'''
def start_again():
    again = input("Would you like to create a new Caesar Cipher?(Y/N)")
    if again == 'Y' or again == 'y' or again == 'yes':                      # If Y start the cipher again
        use_cipher()                                                        # Otherwise end the program.


use_cipher()        # Runs the cipher

