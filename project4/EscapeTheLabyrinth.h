#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

/* Change this constant to contain your full first and last name (middle is ok too).
 *
 * WARNING: Once you've set set this constant and started exploring your maze,
 * do NOT edit the value of kYourName. Changing kYourName will change which
 * maze you get back, which might invalidate all your hard work!
 */
const string kYourName = "Roshan Dhimal";

/* Change these constants to contain the paths out of your mazes. */
const string kPathOutOfRegularMaze = "ESSWSEEENNWNSEN";   // regular path
const string kPathOutOfTwistyMaze = "EWSSWWWWNWNE";  // tisted path

bool isPathToFreedom(MazeCell *start, const string& moves) {
  int mSize = moves.size();
  set<string> checkin;
  // if the start if null
  if (start == nullptr) {
    return false;
  }
  //loops till the size
  for (int i = 0; i < mSize; i++) {
    // if found in the front
    if (start->whatsHere  == "Potion" || start->whatsHere  == "Spellbook" || start->whatsHere  == "Wand") {
      checkin.insert(start->whatsHere);
    }
    if(moves[i] == 'W') {
      start = start->west;
    }
    else if (moves[i] == 'E') {
      start = start->east;
    }
    else if (moves[i] == 'N') {
      start = start->north;
    }
    else if (moves[i] == 'S') {
      start = start->south;
    } else return false;
    // if the path inside is empty
    if (start == nullptr) {
      return false;
    }
    // if not empty inserts inside the set
    if (start != nullptr) {
      if (start->whatsHere  == "Potion" || start->whatsHere  == "Spellbook" || start->whatsHere  == "Wand")
        checkin.insert(start->whatsHere);
    } else break;
   }
   // if found in the set of inserted elements
  return checkin.size() == 3;
}
