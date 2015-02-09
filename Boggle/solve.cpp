
#include <stdio.h>
#include <iostream>
#include <string>
#include "solve.h"



using namespace std;

coord foundResult[10][10];
int solutionIndex = 0;
int orderIndex = 0;
char *targetWord = (char *)"YES";


const int dy[8] = { -1, 0, 1, -1, 0, 1,  -1, 1};
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };


int main(int argc, char **argv)
{

  coord footprint[MAX_SIZE];

  init();


  memset (footprint, 0, sizeof (footprint));

  for (int y = 0; y < MAX_SIZE; y++)
  {
    for (int x = 0; x < MAX_SIZE; x++)
    {
        printf("Searching the work from (%d, %d) \n", y, x); 
        hasWord(y, x, targetWord, footprint, 0);
    }
  }

  printSolution();
}



RESULT hasWord(int y, int x, char  *word, coord *footprint, int depth) {

  //printf("%s : [%d, %d] %s \n", __FUNCTION__, y, x, word);

  RESULT res;
  coord current;


  if (!inRange(y, x))
  {
    //printf("Out of Range \n");
    return R_FAIL;
  }

  if (board[y][x] != word[0])
  {
      //printf("Does not match \n");
      return R_FAIL;
  }

  /* Keep the footprint */
  footprint[depth].cy = y;
  footprint[depth].cx = x;
  ++depth;

  /* Completely found the word */
  if (strlen(word) == 1)
  {
      return R_FOUND;
  }

  /* move to next substring */
  ++word;

  for (int direction = 0; direction < 8; ++direction) {
     int nextY = y + dy[direction];
     int nextX = x + dx[direction];


     res = hasWord(nextY, nextX, word, footprint, depth);

     switch (res)
    {
      case R_FAIL :

        break;

      case R_PROGRESS :

        break;

      case R_FOUND :
        /* save the footprint */
        current.cy = nextY;
        current.cx = nextX;
        saveFootPrint(footprint, depth, current);

        solutionIndex++;

        break;

    }

  }

  return R_FAIL;
}


void saveFootPrint(coord *past, int depth, coord current)
{
  int k;

  printf("%s \n", __FUNCTION__);

  for (k = 0; k < depth; k++)
  {
    foundResult[solutionIndex][k].cy = past[k].cy;
    foundResult[solutionIndex][k].cx = past[k].cx;
  }
  foundResult[solutionIndex][k].cy = current.cy;
  foundResult[solutionIndex][k].cx = current.cx;


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



void printBoard()
{
  for (int y = 0; y < MAX_SIZE; y++)
  {
    for ( int x = 0; x < MAX_SIZE; x++)
      cout << board[y][x] << " ";

    cout << endl;

  }
}

void init()
{

  memset(foundResult, 0, sizeof(foundResult));

  solutionIndex = 0;
  orderIndex = 0;
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
