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


