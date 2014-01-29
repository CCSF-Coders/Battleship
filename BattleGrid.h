/* Craig Persiko
   CIS 110B - Programming in C++
   Fall 2001

   BattleGrid.h

   BattleGrid class header file

   Declaration of sample class to demonstrate class 
   design principles.
*/

const int SHIP_LENGTH = 4;  // one-dimensional size of ship
const int WIDTH = 5;  // Grid width: must be >= SHIP_LENGTH
const int HEIGHT = 5;  // Grid height: must be >= SHIP_LENGTH

enum hitOrMiss { hit, miss, final_hit };

class BattleGrid
{
  public: 
    /* Constructor: initializes grids, hides ship */
    BattleGrid();
    
    /* outputGrid: displays viewGrid for user */
    void outputGrid();

    /* testCell: tests specified cell to see if it hits ship.
    returns:
      hit if battleship has been hit, but not fully revealed
      miss if battleship was missed
      final_hit if last cell of battleship has just been revealed
    */
    hitOrMiss testCell(int x, int y);

  private:
    char viewGrid[WIDTH][HEIGHT];
    // viewGrid contains '_' for unknown, 'X' for hit, 'O' for miss
    bool shipGrid[WIDTH][HEIGHT]; 
    // shipGrid contains false for "no ship here", 
    // true for "ship is here"
    int missileCount;
    // missileCount is how many cells tested
    int hitCount;
     // hitCount is how many times ship has been hit
};