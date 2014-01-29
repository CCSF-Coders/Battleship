/* Craig Persiko
   CIS 110B - Programming in C++
   Fall 2001

   battleship.cpp

   Battleship program main driver file

   Sample program to demonstrate class 
   design principles.
*/

#include <iostream>
using namespace std;
#include "BattleGrid.h"


int main()
{
  BattleGrid board;
  int x, y;
  hitOrMiss testResult;

  do
  {
    board.outputGrid();
    cout << "Enter Cell Coordinates: ";
    cin >> x >> y;
    testResult = board.testCell(x, y);
  }while(testResult != final_hit);
  
  board.outputGrid();
  cout << "Game Over!\n";

  return 0;
}