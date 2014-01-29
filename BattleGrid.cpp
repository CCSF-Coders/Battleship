/* Craig Persiko
   CIS 110B - Programming in C++
   Fall 2001

   BattleGrid.cpp

   BattleGrid class implementation source file

   Implementation of sample class to demonstrate class 
   design principles.
*/

#include <iostream>
using namespace std;
#include <time.h>      // used to seed random number generator
#include "BattleGrid.h"

/* Constructor: initializes grids, hides ship */
BattleGrid::BattleGrid()
{
  int x, y, shipDirection, shipTop, shipLeft;
  time_t dummyTime;

  srand(time(&dummyTime));

  missileCount = hitCount = 0;

  // initialize display grid and ship grid
  for (x = 0; x < WIDTH; x++)
    for (y = 0; y < HEIGHT; y++)
    {
      viewGrid[x][y] = '_';
      shipGrid[x][y] = false;
    }

  // initialize position of ship
  shipDirection = rand() % 2;  // 0 or 1
  if (shipDirection == 0) // Horizontal
  {
    shipTop = rand() % HEIGHT;
    shipLeft = rand() % (WIDTH - SHIP_LENGTH);
    for (x = shipLeft; x < (shipLeft + SHIP_LENGTH); x++)
      shipGrid[x][shipTop] = true;
  }
  else // shipDirection is Vertical
  {
    shipTop = rand() % (HEIGHT - SHIP_LENGTH);
    shipLeft = rand() % WIDTH;
    for (y = shipTop; y < (shipTop + SHIP_LENGTH); y++)
      shipGrid[shipLeft][y] = true;
  }

}

/* outputGrid: displays viewGrid for user */
void BattleGrid::outputGrid()
{
  int x, y;

  // Output column labels line:
  cout << " ";
  for (x = 0; x < WIDTH; x++)
    cout << " " << x + 1;
  cout << endl;
  
  // Output grid contents and row labels:
  for (y = 0; y < HEIGHT; y++)
  {
    cout << y + 1 << " "; // output row number
    for (x = 0; x < WIDTH; x++)
    {
      cout << viewGrid[x][y];  // grid contents
      if (x < WIDTH - 1) 
        cout << "|"; // output line after all but last values     
    }
    cout << endl;
  }

  cout << "\nMissile Count: " << missileCount << endl;
}

/* testCell: tests specified cell to see if it hits ship.
   returns:
     hit if battleship has been hit, but not fully revealed
     miss if battleship was missed
     final_hit if last cell of battleship has just been revealed
*/
hitOrMiss BattleGrid::testCell(int x, int y)
{
  missileCount++;

  //  check range - make sure x and y are in the grid 
  // (don't access memory out of range!)
  if (x < 1 || y < 1 || x > WIDTH || y > HEIGHT)
    return miss;

  // translate from 1-based coordinates to 0-based
  x--; y--;

  if (shipGrid[x][y]) // hit
  {
    hitCount++;
    viewGrid[x][y] = 'X';
    if (hitCount == SHIP_LENGTH)
      return final_hit;
    else
      return hit;
  }
  else // miss
  {
    viewGrid[x][y] = 'O';
    return miss;
  }
}