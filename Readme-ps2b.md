# PS2a: Sokoban

## Contact
Name: Arthea Valderrama
Section: 202
Time to Complete: > 7 hours


## Description
This project adds the gameplay mechanics for the Sokoban game. It enables the player to move and push crates into designated target. It also displays a victory screen, and resets the game upon pressing 'r'. This is my final draft of the Sokoban game, and it fully works. 

### Features
I decided to refresh the player state when it moves according to direction. I added this feature because I felt it necessary to include as it moves. 

### Memory
I did not use a smart pointer, but I did use a unique pointer to to hold the Matrix class object. This Matrix class object stores the game state in a char matrix.  

### Lambdas
I used std::find to sort through my vector of crates in my move function to see if there is a wall behind it. The target is the beyond vector, which calculates the ground beyond the position of the crate. Another instance of using std::find is in my isWon function, iterating through the target areas to see if it matches with the location of the crates. 

### Issues
I am not aware of any issues my program has, but I still have problems with SFML segmentation faulting on my computer due to software. 

### Extra Credit
I included the character changing states as it is moving for extra credit. 

## Acknowledgements
I went to the professor's office hours, I read through https://en.cppreference.com/w/cpp, I was very active in asking for help in the discord group chat. Additionally, I referenced a matrix class used from class, but changed it into a char matrix.

I obtained the victory image from here: https://aimbotjpegforfortnite.blogspot.com/2020/10/fortnite-win-maker.html
