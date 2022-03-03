//Dabin Jang
//djang12@bu.edu

//Part A (pseudo code)
/*
char grid[height][width]
for i = 0 to  (height-1)                //this block will populate a grid of blanks of height by width 
    for j = 0 to (width-1) 
        grid[i][j] = ' '


for i = 0 to N                         //this block will populate grid of x's column by column with 2 x's 
    for j = i to (i+1)                 //the x's will follow a linear pattern as shown by homework problem 
        grid[j][i] = 'x'


if N is odd                            //this block will populate grid with o's following same pattern as hw problem
    grid[N][N+2] = 'o'
    grid[N+2][N+2] = 'o'
else                                   //if N is even
    grid[N+1][N+1] = 'o'
*/

//Part B
#include <iostream>
#include <string>

using namespace std;

int main(int argv, char **argc)
{
    char grid[10][10];
    int N = stoi(argc[1]); //Convert char into int. Now we can use N to run the program.

    //below is to populate the 10x10 grid with '.'
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            grid[i][j] = '.';
        }
    }

    //used to populate grid with X's
    for (int i = 0; i <= N; i++)
    {
        for (int j = i; j <= i + 1; j++)
        {
            grid[j][i] = 'x';
        }
    }

    //used to populate grid with O's
    if (N % 2 != 0)
    {
        grid[N][N + 2] = 'o';
        grid[N + 2][N + 2] = 'o';
    }
    else
    {
        grid[N + 1][N + 1] = 'o';
    }

    //used to print out grid
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j <= 9; j++)
        {
            cout << " " << grid[i][j] << " ";
        }
        cout << endl;
    }
}
