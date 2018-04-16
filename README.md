# A Game for the AVR - Written in C
The purpose of this assignment is to recreate the memory game you created in assembler. This time using C as the programming language and Test Driven Development (TDD) as the development process. You can find the description of the game at the end of this document.

## Requirements

### Analysis and Design
You must create a domain model (UML class diagram). This should form the basis for structuring your solution using abstract data types.

### Test
All functions and data types should be unit tested. Work in iterations where you: 
1. write a test
1. run the test and see that it fails
1. write the code that satisfies the test
1. repeat

### Implementation
Implement the game in C. The code should be well-structured preferably using abstract data types.

## Practical Information
### Definition of Done
The game should be demonstrated for me on class and your implementation code handed in on github. See section below for details on how to hand in on github.

All group members should have participated actively in producing code and thus it should be possible to find all group members in the git commit history.

### Deadline 
1st of May by the end of the lesson (11.50am)

### Github
Before starting to commit any code, this repository should be forked to the github account of a group member. This forked repository is where you are going to create your Atmel Studio project and commit your assembler code. Eventually you can "Hand in" by creating a pull request. This will enable me to see your code and provide you comments on your project.

If you are unsure of the details, ask me or a fellow student og go watch a video (like this: https://www.youtube.com/watch?v=_NrSWLQsDL4) or read the documentation.

## Description of the Game

The game is a turn-based memory game. The player will at the beginning of a turn be presented with a sequence of flashes on the leds that the player must then try to remember and input correctly on the buttons. If input correctly the round is won and the game continues, if not, the game is lost and restarted. Gradually the difficulty increases (the sequence getting longer).

* The UI of the game must be implemented with 8 leds
* User input must be implemented using 8 switches
* The user should get feedback from the game when a game is started (and restarted) and when a round is won.
* The sequence of flashes represents a sequence of numbers from 0 to 7. The sequence can contain the same numbers multiple times. 