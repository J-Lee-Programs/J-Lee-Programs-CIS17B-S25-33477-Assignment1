# J-Lee-Programs-CIS17B-S25-33477-Assignment1
This bank system is for CIS-17B. The overall system contains a class with three private variables and three member functions.
The private member variables are accessed through the constructor, of which the default variables are 0 and blank.

For this program to work, the user must input integer numbers as an option for the switch cases. Anything that isn't an integer
will cause the program to run an infinite loop, of which I cannot implement an error for. Same thing for deposits and withdrawls, except that decimals are allowed.

The program will also prompt you to create an account before anything else, warning the user through the try-catch block, and it will deny you from inputing data into the class.
Once you create an account, the account cannot be created again. The private variable accountNumber uses a fixed RNG (Random Number Generator) that reads back to the user their account.

The independent functions serve as clarifiers, reading back to the user the requested ammount. The display function gets the balance and also reads it back.

In this instruction set, I will describe the actions in this program.

User Prompt > User input > Account creation (All other options will NOT take data, display balance displays no values.) > Deposit/Withdraw/Display/Exit

Deposit:  Takes user input > passes it through readback and member function > member function verifies account and passes data.

Withdraw: Takes user input > passes it through readback and member function > member function verifies account and passes data.

Display: Calls member function and retrieves balance, display passes that and reads back to user.



*Author's notes: Unable to implement preventative measures regarding numerical inputs in required areas.
Variables set as member functions unnecessary, will not change for time constraints and needless change. 
