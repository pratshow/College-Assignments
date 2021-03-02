import tkinter as tk
from tkinter import ttk

'''
Calculate Cost function is the event handler for the button push
'''
def calculateCost():

    # Get the tax result and turn it into a decimal
    taxDecimal = taxResult.get() / 100
    # multiply the guest total by the entree choice (the value is an integer)
    dinnerBeforeTax = guestResults.get() * entreeResult.get()
    # get the amount of tax
    taxAmount = dinnerBeforeTax * taxDecimal
    # add the tax to dinner cost
    dinnerCost = dinnerBeforeTax + taxAmount

    # total label at key = text (dictionary) gets assigned this string amount
    totalLabel["text"] = "$" + str(round(dinnerCost, 2))


'''
Create the main window
'''
# creates a variable instance of a tk window
win = tk.Tk()


'''
Create a frame and entree options
'''
# this creates a variable to hold the value (variable) of the selected radio button
entreeResult = tk.IntVar()

# Frame with label some padding
entreeFrame = ttk.Labelframe(win, text="Entree")
entreeFrame.grid(row=1, column=1, pady=10, padx=10)

# Chicken radio button and label, value of chicken is 20
chickenRadio = ttk.Radiobutton(entreeFrame, variable=entreeResult, value=20)
chickenRadio.grid(row=1, column=1)
ttk.Label(entreeFrame, text="Chicken ($20)").grid(row=1, column=2, sticky=tk.W)

# Steak radio button and label, value of steak is 25
steakRadio = ttk.Radiobutton(entreeFrame, variable=entreeResult, value=25)
steakRadio.grid(row=2, column=1)
ttk.Label(entreeFrame, text="Steak ($25)").grid(row=2, column=2, sticky=tk.W)

# Lobster radio button and label, value of lobster is 30
lobsterRadio = ttk.Radiobutton(entreeFrame, variable=entreeResult, value=30)
lobsterRadio.grid(row=3, column=1)
ttk.Label(entreeFrame, text="Lobster ($30)").grid(row=3, column=2, sticky=tk.W)


'''     
Spinbox for the taxes 
'''
# this creates a variable to hold the value (variable) of the of the value in the spin box
taxResult = tk.IntVar()

# Frame with label some padding
taxFrame = ttk.Labelframe(win, text="Taxes")
taxFrame.grid(row=2, column=1, pady=10, padx=10)

# Spin box pretty straight forward other than it uses textvariable instead of variable !!!!
my_spinbox = tk.Spinbox(taxFrame, from_=0, to=10, width=5, justify=tk.RIGHT, textvariable=taxResult)
my_spinbox.grid(row=1, column=1, sticky=tk.W, pady=3)



'''     
Scale for setting the number of guests 
'''
# this creates a variable to hold the value (variable) of the of the value in the spin box
guestResults = tk.IntVar()

# frame with paddding for the scale
guestFrame = ttk.Labelframe(win, text="Number of guests")
guestFrame.grid(row=1, column=3, pady=10, padx=10)

# Scale that goes from 1 to 20 to enter the number of guests at the dinner
guestScale = tk.Scale(guestFrame, from_=1, to=20, var=guestResults, orient=tk.HORIZONTAL, length=100)
guestScale.grid(row=1, column=3, sticky=tk.W)



'''                    
A Label to display the results
'''
# this creates a variable to hold the value (variable) of the label
total = tk.IntVar()

totalFrame = ttk.Labelframe(win, text="Total")
totalFrame.grid(row=2, column=3, pady=10, padx=10)

# This label just shows Dinenr Cost:
simpleLabel = ttk.Label(totalFrame, text="Dinner Cost:")
simpleLabel.grid(row=1, column=1)

#This label is where the amount will go
totalLabel = ttk.Label(totalFrame, text="---", anchor="center")
totalLabel.grid(row=2, column=1)


'''                    
A calculate button
'''
my_calc_button = tk.Button(win, text="Calculate Cost", command=calculateCost)
my_calc_button.grid(row=5, column=2)

# Loop to wait for user interaction
win.mainloop()
