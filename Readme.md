2023-2024 Semester 2 ENGG1340 Group project Group 112

Group Members:
Au Shun To 3036270493
Chan Sin Chi 3036224224
Law Pak Chun 3036225345
Lei Yiu Long 3036225993
Tse Fai 3036227020

First, type "make clean" to clean all .o file.
Second, type "make game" to creat new .o file.
Last, type "./game" to enter the game.

Welcome to the GRAND CASINO. 
Please first create a new account or log in to your account according to the instruction.

Now you can choose a game to test your luck!
There are 4 games to play with, including (1)Blackjack, (2)Roulette, (3)Slot Machine and (4)Soccer.
Input a game number(1-4) and you will be directed to the corresponding betting menu.
Input (5) for viewing your balance.

The game rules are as follows:
----------------------------------------------------------------------------------------------------------------------------------------
#1 Blackjack
Objective: 
To get highest total value of cards but not exceeding 21.

Card value:
(A = 1 or 11), (2-10 = card value), (J,Q,K = 10)

Instruction:
For each round, Enter "N" to start a new game or "Q" to quit the game.
In the game, There are three choices: 
1.Hit:      Get one more card
2.Stand:    Stop getting card                             (the game will stop immediately and see the result)
3.Double:   Double the bet amount and get one more card   (the game will stop immediately and see the result)

Wining cases:
1.Blackjack:    The first 2 cards meets the value of 21.                    (Reward: bet*2)
2.Dragon:       Hold 5 cards and the total value of cards not exceeding 21. (Reward: bet*3)
3.High card:    Your total value of cards is higher than that of dealer.    (Reward: bet)

Losing cases:
1.Your total value of cards is lower than or equal to that of dealer (except Blackjack,Dragon cases). (Pay: bet)

----------------------------------------------------------------------------------------------------------------------------------------
#2 Roulette
Objective:
To get the right bet which the ball rolled to.

Instruction:
For each round, Enter "N" to start a new game or "Q" to quit the game.
In each game, there are serveral option for betting:
1.Single Number:    Bet for one single numbers
2.Row:              Bet for each row of numbers
3.12 numbers:       Bet for first, second or thrid 12 numbers
4.Even and Odd:     Bet for even or odd
5.Colour:           Bet for red and black Colour
Enter "0" for finish placing the bet

Betting Odds:
1.Single Number:    Bet*35
2.Row:              Bet*2
3.12 numbers:       Bet*2
4.Even and Odd:     Bet*1
5.Colour:           Bet*1
----------------------------------------------------------------------------------------------------------------------------------------
#3 Slot Machine
Objective:
To get the same 3 symbols in a row, either vertically or diagonally.

Instruction:
For each round, Enter "N" to start a new game or "Q" to quit the game.
After starting a new game, player may choose the amount of their bet.
They may bet ranging from 1 dollar, to the whole balance that the player has.
The system will keep checking until the player has made a valid bet.
The Slot Machine will then spin automatically. 
There are 2 cases:
1. If 3 slots in any of the 3 rows or diagonals matches with the same number, you win 999 times your bet!!!
2. However, if there are no matches in any of the 3 rows or diagonals, you lose your bet.

The Slot Machine game has a nature and potential of low cost and low winning rate, but it has a extremely high returing and repay rate!!!
So say no more! Don't wait! Come quickly and try your luck!
----------------------------------------------------------------------------------------------------------------------------------------
#4 Soccer
Objective:
To get a card that the card number within the two frame.

Instruction:
For each round, Enter "N" to start a new game or "Q" to quit the game.
In each game, you can not bit more than one third of your balance since you may be lose 3 times of your bet!!!
Next, you will receive two card, which are the frames.
Press Enter to get your card.
There are 4 cases:
1. Your card is within two frame, then you goal!!! (You win 1 time of your bet)
2. Your card is out of two frame, then you not goal. (You lose your bet)
3. Your card is same as one of the frame (You lose 2 times of your bet)
4. Two frame are the same, you can choose your card is bigger or smaller than the frame.
   If your choice is correct, then you win!!(You win 2 times of your bet)
   If your choice is wrong, you lose but you only lose 1 time of your bet.
   However!!! If your card is same as the frame, which mean 3 cards are the same, you will lose 3 times of your bet!!!
   Be careful!!
----------------------------------------------------------------------------------------------------------------------------------------
We have a earning system as well!

When your balance is under 100, we will automatically direct you to a mini game when you input the game number.
If you are bankrupted, you are forced to play this mini game.
If you still have some dollars, you can choose to attempt this game or not.

The mini game is a very simple word typing game.
What you need to do is to input all the words displayed on the screen. 
There will be 3 levels for this game, you can get 10 in level1, 100 in level2, 1000 in level3 respectively.
You should be reminded not to use copy and paste.

When you have finished, simply enter 'q' to quit the game and you can check your rank on the ranking list!
----------------------------------------------------------------------------------------------------------------------------------------
#List of Features implemented in the code
1. 
1. Login system
- To create and store individual player usernames, passwords and balance in txt files
- To allow players to create unique accounts and track their progress

2. Ranking system
- To retrieve player username and balance data, compare the balance of different players and append into a linked list in descending order
- Allow players to compete with each other

3. Earning system
- To allow players earn back money when they are bankrupted
- Players no need to open a new account when they dont have money so that they can play as long as they want
 
4. Animation
- By using usleep function, texts are printed with time delay
- Animation in Slot Machine

----------------------------------------------------------------------------------------------------------------------------------------
#Code requirement we included:

# requirement 1 (Generation of random game sets or events)

As we make the games of Grand Casino, the events of drawing cards, Slot Machine are random events.
We use the code "srand()" in (Blackjack, Roulette and Slot Machine games) to initial the random in order to generate random cards and number in Slot Machine.
Thus, the requirment of generation of random game sets or events is fufilled.

# requirement 2 (Data structures for storing game status (e.g., arrays, STL containers))

In Slot Machine, 2D arrays is used to store the random numbers and show the interface of Slot Machine.
Several arrays is used in the game to store the game status including the card sets and the random numbers of Slot Machine.
Thus, the requirement of data structures for storing game status can be fulfilled.

# requirement 3 (Dynamic memory management (e.g., dynamic arrays, linked lists, STL containers))

In "Blackjack.cpp", dynamic arrays are used to store the card sets of dealers and players. The card sets are deleted and renew for each game, thus the dynamic arrays will be deleted in the end of the loop and renew in new loop.
In "Roulette.cpp", dynamic array is used to store the betting of the players. The betting is deleted and renew each game, thus the dynamic array will be deleted in the end of the loop and renew in new loop.
In "ranking.cpp", the ranking system used linked list to store the information of all the players and place it in descending order.
Thus, the requirement of dynamic memory management.

# requirement 4 (File input/output (e.g., for loading/saving game status))

In login system, user can create an new account with a password and write them in user_name.txt. The game will also read user_name.txt to get existed username and password to ensure the account and be loged in.
In the player balance system, the balance and username of player will be written into the txt file Money.txt when there is a change of balance. Money.txt will be read and get the balance amount and username by the program when player want to display their balance.
Thus, the requirement of input/output can be fulfilled.

# requirement 5 (Program codes in multiple files (recall separate compilation)) 

In the main function, it has included all the files to combine all the game function such as different library and .h files.
Therefore, we can call the functions in other .cpp files. This allows the job distribution and top-down approach in game development. Each members can modify their module of program individually.
We also included a Makefile to make different .o files and then combine them with the main.cpp to ensure every functions in the directory can work in the main function.
Thus, the requirement of program codes in multiple files is fulfilled.

# requirement 6 (Proper indentation and naming styles)

The names of the variables is related to the type of variables and the usage of the variable, e.g. the variable "balance" is used to store the balances of players in integer types.
The names of the functions show the task the function does. The subfunction is also named by the task of the function. For exmaple, "blackjackgame" function is used to perform the game of Blackjack, "roulettegame" function is used to perform the game of Roulette.
Thus, the requirement of Proper indentation and naming styles is fulfilled.

# requirement 7 (In-code documentation)

Serveral comments is provided for each functions and structure.
Thus, the requirement of in-code documentation in filled.
