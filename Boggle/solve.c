
#include <iostream>
#include <string>

#define MAX_SIZE 5


const int dy[8] = { -1, 0, 1, -1, 0, 1,  -1, 1};
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };


bool hasWord(int, int, const string&);
bool inRange(int, int);

bool hasWord(int y, int x, const string& word) {


  if (!inRange(y, x)) return false;

  if (board[y][x] != word[0])) return false;

  if (word.size() == 1) return false;

  for (int direction = 0; direction < 8; ++direction) {
     int nextY = y + dy[direction];
     int nextX = x + dx[direction];

     if (hasWord(nextY, nextX, word.substring(1)))
        return true;
  }

  return false;
}


bool inRange(int y, int x)
(
  if (y < 0)
    return false;

  if (y >= MAX_SIZE)
    return false;

  if (x < 0)
    return false;

  if (y >= MAX_SIZE)
    return false;

    return true;
)



int main(int argc, char **argv)
{

  for (int y = 0; y < MAX_SIZE; y++)
    for (int x = 0; x < MAX_SIZE; x++)
    {
        if (!hasWord(y, x, "YES"))
          break;
        else
        {
            cout<<"Found !!" << endl;
            break;
        }
    }
}
