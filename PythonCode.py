import re #imports regular expression operation
import string #provides the ability to do complex variable substitutions and value formatting
import os #provides a portable way of using operating system
from datetime import date #imports date

#definition to produce a list then a dictionary that counts the number of repeated items
def itemsSoldList():
    os.system('cls') #clears the output on the screen
    item_list = [] #initializes an empty list
    item_dic = {} #intializes an empty dictionary

    today = date.today() #obtains the current date

    #loop to check for errors when opening a file
    while True: 
        try:
            f = open("itemsSold.txt", "r")
            break
        except IOError:
            print("Could not Open file.")

    #iterates through the file and appends to the empty list striping the newlines
    for line in f:
        item_list.append(line.strip())
    

    print(" Items Sold on", today)
    print('=========================')
    print("Item           Number Sold")
    print("-------------------------")

    #iterates over the list and sets the items as keys and the number of items as values
    for items in item_list:
        item_dic[items] = item_list.count(items)

    # sorts the dictionary by value in reverse order
    sorted_item_dic = sorted(item_dic.items(), key =lambda x:x[1], reverse = True)

    #iterates through the dictionary and displays the formatted keys and values
    for key, value in sorted_item_dic:  
        print(f"{key:<15}{value:>6}")

    print("_________________________")
    f.close() #closes the file

    #definition to obtain user input to search for a specific key in the dictionary and return its value
def itemsSearch(userItemSearch):
    #os.system('cls')
    item_list = []
    item_dic = {}

    print("     Item Frequency")
    print('=========================')
    print("Item           Number Sold")
    print("-------------------------")

    while True:
        try:
            f = open("itemsSold.txt", "r")
            break
        except IOError:
            print("Could not Open file.")

    #places the user input obtained in C++ into a new Python variable and captalizes the first letter
    user_input = userItemSearch
    user_input = user_input.capitalize()

    for line in f:
        item_list.append(line.strip())

    for items in item_list:
        item_dic[items] = item_list.count(items)
    f.close()
    
    #returns the interger value from the dictionary of the user searched key
    return item_dic[user_input]

    
    
#definitions to create a .dat file and populate it with the key:value from the item sold list
def itemsHistograms():
    os.system('cls')
    item_list = []
    item_dic = {}

    while True:
        try:
            f = open("itemsSold.txt", "r")
            break
        except IOError:
            print("Could not Open file.")

    for line in f:
        item_list.append(line.strip())

    for items in item_list:
        item_dic[items] = item_list.count(items)
    
    sorted_item_dic = sorted(item_dic.items(), key =lambda x:x[1], reverse = True)

    #creates a .dat file and populates it with the key:value from the dictionary produced in the previous lines
    with open('frequency.dat', 'w') as f:
        for key, value in sorted_item_dic:
            f.write(f"{key:<15}{value:>6}\n")

    f.close()
