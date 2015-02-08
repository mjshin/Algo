
#include <stdio.h>
#include <iostream>
#include <string>

#define MAX_SIZE 5

using namespace std;

typedef struct {

  int cy;
  int cx;
} coord;


coord foundResult[10][10];
int solutionIndex = 0;
int orderIndex = 0;
char *targetWord = "YES";

const int dy[8] = { -1, 0, 1, -1, 0, 1,  -1, 1};
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
char board[MAX_SIZE][MAX_SIZE] = { 'N', 'N', 'N', 'N', 'S',
                                   'N', 'E', 'E', 'E', 'S',
                                   'N', 'E', 'Y', 'E', 'N',
                                   'N', 'E', 'E', 'E', 'N',
                                   'S', 'N', 'N', 'N', 'N'};

bool hasWord(int, int, int, int, const string&);
bool inRange(int, int);
void printBoard();


void init()
{

  memset(foundResult, 0, sizeof(foundResult));

  solutionIndex = 0;
  orderIndex = 0;
}

void printBoard()
{
  for (int y = 0; y < MAX_SIZE; y++)
  {
    for ( int x = 0; x < MAX_SIZE; x++)
      cout << board[y][x] << " ";

    cout << endl;

  }
}


void printSolution()
{

  for (int i = 0; i <= solutionIndex - 1; i++)
  {
    for (int j = 0 ; j < strlen(targetWord); j++ )
      printf("[%d:%d] ", foundResult[i][j].cy, foundResult[i][j].cx);

    printf("\n");
  }

}


bool hasWord(int prev_y, int prev_x, int y, int x, char  *word) {

  printf("%s : [%d, %d] %s \n", __FUNCTION__, y, x, word);

  if (!inRange(y, x))
  {
    //printf("Out of Range \n");
    return false;
  }

  if (board[y][x] != word[0])
  {
      printf("Does not match \n");
      return false;
  }

  //foundResult[solutionIndex][orderIndex].cy = y;
  //foundResult[solutionIndex][orderIndex].cx = x;
  //orderIndex++;


  if (strlen(word) == 1)
  {

    return true;
  }

  ++word;

  for (int direction = 0; direction < 8; ++direction) {
     int nextY = y + dy[direction];
     int nextX = x + dx[direction];



     if (hasWord(y, x, nextY, nextX, word))
     {
        foundResult[solutionIndex][orderIndex].cy = nextY;
        foundResult[solutionIndex][orderIndex].cx = nextX;
        orderIndex++;
        return true;
      }
  }

  return false;
}


bool inRange(int y, int x)
{
  if (y < 0)
    return false;

  if (y >= MAX_SIZE)
    return false;

  if (x < 0)
    return false;

  if (y >= MAX_SIZE)
    return false;

    return true;
}


int main(int argc, char **argv)
{

//  printBoard();
//  char *word = "YES";

  init();

  for (int y = 0; y < MAX_SIZE; y++)
  {
    for (int x = 0; x < MAX_SIZE; x++)
    {
        if (hasWord(y, x, y, x, targetWord))
        {
            foundResult[solutionIndex][orderIndex].cy = y;
            foundResult[solutionIndex][orderIndex].cx = x;
            solutionIndex++;
            cout<<"Found !!" << endl;

        }
    }
  }

  printSolution();
}
