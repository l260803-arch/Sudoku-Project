This project is related to Programming Fundamentals course, in which we have made a basic sudoku game through basic concepts of C++.
========FEATURES========
Following are the features of this project:
There will be a 9x9 sudoku board. They will be further divided into 9 bigger boxes of small boxes.
How will it function?
When user will run the file, it will show a display in which there would be three options; easy, normal and hard.
User can select only one option at a time. When this happens, the main menu display disappears and the playing window
appears with a sudoku board. It will have dimensions of 540x540.
The user will be able to enter the numbers in each cell. But there is an important thing:
There are three main rules of sudoku:
a)The number should not be repeated in the same row.
b)The number should not be repeated in the same column.
c)The number should not be repeated in the same 3x3 box.
If either of those errors occurs, there will be an alarming sound.
Now we will discuss how our algorithm stops the sudoku solution to be completely unsolvable at the stage,
because sometimes the rules are not violated at all but it becomes unsolvable. We have made a function named copy, 
that will keep the copy of current level. If any number in the input does not match with actual solution, it will still
give alarming sound to the user. 
Now let's talk about generating random levels in sudoku. We have used a function called ShuffleSudoku, that will shuffle the given 
copy in such a way that it will keep the new level completely solvable.
When the user wins, the sudoku board disappears and the message "You Won!" is shown along with a winning sound. The restart button 
also appears in it. So when you click it, you can go to main menu again.
There are some pictures that will explain it in a better way.
Menu picture:
![Main Menu][start.PNG]
The main sudoku board:
![Sudoku Board][play.PNG]
The winning window
![Winning screen][end.PNG]
The loosing window
![Loosing Screen][loose.PNG]
======Prerequisites======
Following are the points that are required for a user to follow in order to play this:
a)The user must have a GUI operating system, such as MACOS, Windows and Linux.
b)The user must have raylib library in order to compile the project.
c)The standard compiler for C++ is MINGW, Visual Studio can be used instead of setting up MINGW in another editor, so that there 
is no need to setup compiler in an external editor.
d)There should be speakers and mouse in the device so that clicking can be done and sound effects can be heard.
======Installation Setup======
a)To install Raylib, go to the following website:
[Raylib Link][www.raylib.com]
b)To install a compiler, go to the official minGW website:
[compiler][sourceforge.net]
c)To access this project, you must visit [github.com].
======Setup on a New PC======
You have to follow each and every step of installation setup, that is how setup on a new pc is made.
======Common Troubleshoots======
If the program says that it is unable to find the raylib.h library even if you have installed it, it means that you have 
not done its setup properly.  Once set properly, it must be running.
