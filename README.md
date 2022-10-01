# PasswordEncoder
A Password encoder using C++ programming language

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

features -:

2 digits = swaps the two digits (using pointers)
3 digits = swaps the digits (using pointers)
4 or more = each digit will be repleaced by the remainder when that difit is multiplied by 3 and divided by 10
EXTRA PROTECTION = if the user entered value is 8 they can enable extra protection by swapping each encoded digit with another place eg ( 1st digit with 8th digits, 2nd digits with 7th digits, 3rd digit with 6th digit)


Knowledge -: Pointers, Intermediate mathematic usage, functions


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Descripption -:

By using this program, when the user enters a integer passcode between the digit size of 2 and 8, the program encode the password. If the user enters an integer with 2 digits, the program swaps the two digits. If the entered integer is 3 digits long, the program swaps the first and the last digit. And else if the entered code is more than or equal to 4, the program will get each digit individually and replace with the remainder when that original digits is multiplied by 3 and divided by 10. After this step, the user is given to chose to enable extra protection to the entered code. This can only be enabled if the entered integer has 8 digits exactly. By this function, it will make the passcode more protection by swapping first digit and last digit, again the second digit and the seventh digit and so on. By the 3rd choice, it enables the user decode the encoded password and exit the program by reversing the expression done in the first step. 
