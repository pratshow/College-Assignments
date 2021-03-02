# Date night calculator
# CS 1181
# Show Pratoomratana
# 11/20/2019
# Brandon/Carpenter
# Create a GUI program that will ask for various costs for a date and calculate the cost of the date for you.

import tkinter as tk            # Imports GUI modules
from tkinter import ttk

win = tk.Tk()                   # Creates the window for the widgets


'''
Function to do the calculations
'''
def calculateTotal():
    totalBeforeTipTax = travelVar.get() + dinnerVar.get() + entVar.get()     # Adds the cost before tip and tax
    dinnerTip = (tipVar.get() / 100) * dinnerVar.get()                       # Gets the cost of the tip
    beforeTax = dinnerTip + totalBeforeTipTax                                # Adds the tip to the total
    costOfDate = ((taxVar.get() / 100) * beforeTax) + beforeTax              # Calculates tax and adds it to the total
    displayTotal['text'] = '$' + str(round(costOfDate, 2))                   # Adds the cost of the date to the widget


'''
Choice of radio buttons for the desired transportation
'''
travelVar = tk.IntVar()                                             # Sets the variable for the radio button

travelFrame = ttk.LabelFrame(win, text='Travel')                    # Makes frame for witch the radio buttons reside
travelFrame.grid(row=1, column=1, sticky=tk.N)                      # Places the frame on the top with some padding

publicTransport = ttk.Radiobutton(travelFrame,                      # Another option for public transit
                                  text='Public Transport($2)',
                                  value='2',
                                  variable=travelVar)

carButton = ttk.Radiobutton(travelFrame,
                            text='Car($10)',                        # Button for a car option with the
                            value='10',
                            variable=travelVar)                     # value for the amount it will cost

uberButton = ttk.Radiobutton(travelFrame,                           # Another option for Uber/Lyft
                             text='Uber/Lyft($20)',
                             value = '20',
                             variable=travelVar)

horseButton = ttk.Radiobutton(travelFrame,                          # Another option for a Horse carriage
                             text='Horse Carriage($300)',
                             value='300',
                             variable=travelVar)

publicTransport.grid(row=1, column=1, sticky=tk.W)                  # Organizes the buttons in the frame
carButton.grid(row=2, column=1, sticky=tk.W)                        # and pushes them to the left side
uberButton.grid(row=3, column=1, sticky=tk.W)
horseButton.grid(row=4, column=1, sticky=tk.W)


'''
Choice of radio buttons for the desired form of entertainment
'''
entVar = tk.IntVar()                                                # Sets variable for the radio button

entertainmentFrame = ttk.LabelFrame(win, text='Entertainment')      # Creates frame
entertainmentFrame.grid(row=2, column=1, sticky=tk.W + tk.N)

stargazeButton = ttk.Radiobutton(entertainmentFrame,                # Same idea just different buttons
                                 text='Stargazing($0)',
                                 value='0',
                                 variable=entVar)

carnivalButton = ttk.Radiobutton(entertainmentFrame,
                                 text='Carnival($15)',
                                 value='15',
                                 variable=entVar)

moviesButton = ttk.Radiobutton(entertainmentFrame,
                               text='Movies($30)',
                               value='30',
                               variable=entVar)

stargazeButton.grid(row=1, column=1, sticky=tk.W + tk.N)            # Placing the buttons on the grid
carnivalButton.grid(row=2, column=1, sticky=tk.W + tk.N)
moviesButton.grid(row=3, column=1, sticky=tk.W + tk.N)


'''
Choice of radio buttons for the desired Dinner
'''
dinnerVar = tk.IntVar()                                             # Setting the variable for the radio buttons

dinnerFrame = ttk.LabelFrame(win, text='Dinner')                    # Set up the frame to but the buttons into
dinnerFrame.grid(row=1, column=2, sticky=tk.N, padx=5)

picnicButton = ttk.Radiobutton(dinnerFrame,                         # Same idea again
                               text='Picnic($5)',
                               value='5',
                               variable=dinnerVar)

fastFoodButton = ttk.Radiobutton(dinnerFrame,
                                 text = 'Fast Food($20)',
                                 value='20',
                                 variable=dinnerVar)

restaurantButton = ttk.Radiobutton(dinnerFrame,
                                   text='Restaurant($30)',
                                   value='30',
                                   variable=dinnerVar)
#if dinnerVar.get == '30':

picnicButton.grid(row=1, column=2, sticky=tk.W)
fastFoodButton.grid(row=2, column=2, sticky=tk.W)
restaurantButton.grid(row=3, column=2, sticky=tk.W)


'''
Slider that allows you to choose how much of a tip to leave if you select restaurant option
'''
# I couldn't figure out how to make the slider appear only when you click dinner without putting the slider
# in a function. But if I put it into a function I can't access it's variable with .get.
tipVar = tk.IntVar()  # Sets up variable name

sliderFrame = ttk.LabelFrame(win, text='Tip(%)')    # Creating a frame for the slider
sliderFrame.grid(row=1, column=3, sticky=tk.W)

slider = tk.Scale(sliderFrame,                      # Similar idea but with a slider instead
                  from_=0, to=35,                   # Value for the range of the slider
                  orient=tk.VERTICAL,               # How it's oriented
                  width=15, length=90,              # Adjusting it's size
                  variable=tipVar)                  # Assigning the variable so I can access it's value

slider.grid(row=1, column=1, sticky=tk.W + tk.N)    # Places it on the grid


'''
Counter box that lets you choose how much is paid in taxes
'''
taxVar = tk.IntVar()                                    # Sets up variable

taxFrame = ttk.LabelFrame(win, text='Taxes(%)')         # Creates the frame
taxFrame.grid(row=2, column=2, sticky=tk.W + tk.N)      # Places it on the grid

spinBox = tk.Spinbox(taxFrame,                          # Sets the counters properties
                     from_=0, to=35,
                     width=5,
                     justify=tk.LEFT,
                     textvariable=taxVar)

spinBox.grid(row=1, column=1, sticky=tk.E)              # Places it on the grid


'''
Button that calculates the cost of the selected items
'''
costButton = ttk.Button(win, text='Calculate Cost', command=calculateTotal)     # Button to execute the function
costButton.grid(row=3, column=3, sticky=tk.E + tk.S)                            # Adds it to the grid


'''
Button to exit the program
'''
quit = ttk.Button(win, text='Quit', command=win.destroy)    # Simple quit button that destroys the window when pressed
quit.grid(row=3, column=1 , sticky=tk.W + tk.S)


'''
An area to display the total cost of the date
'''
totalCostFrame = ttk.LabelFrame(win, text='Cost')                           # Frame for the total
totalCostFrame.grid(row=2, column=3, sticky=tk.E + tk.N)

simpleLabel = ttk.Label(totalCostFrame, text='Date Total:')                 # Labeling it
simpleLabel.grid(row=1, column=1)

displayTotal = ttk.Label(totalCostFrame, text='---', anchor="center")       # Area for the total, '---' is a placeholder
displayTotal.grid(row=2, column=1)                                          # before the user hits calculate cost


win.mainloop()                                                              # Mainloop to wait for user input
