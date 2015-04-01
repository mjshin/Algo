/* 
 * File:   main.c
 * Author: myungjoonshin
 *
 * Created on 2015년 4월 1일 (수), 오후 8:52
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH   20
#define MAX_HEIGHT  20


void doProcess();

char board[MAX_HEIGHT][MAX_WIDTH];
int  nTestCase;
int  nWidth;
int  nHeight;


/*
 * 
 */
int main(int argc, char** argv) {

    FILE *fp;
    char buffer[1024];
    int  i, j; 
    char *token = NULL;
    char delimeter[] = " ";
            
            
            
    fp  = fopen("input.txt", "rb");
    if (fp == NULL)
    {
        printf("File not found \n");
        return (EXIT_FAILURE);
    }
    
    i = 0; 
    j = 0;
    
    memset(board, 0, sizeof(board));
    
    for (i = 0; !feof(fp); i++)
    {
        fgets(buffer, sizeof(buffer), fp);
                //puts(buffer);
        if (i == 0)
        {
            nTestCase = atoi(buffer);
            continue;
        }
        if (strchr(buffer, ' ') != NULL)
        {
            nHeight = atoi(strtok(buffer, delimeter));
            nWidth = atoi(strtok(NULL, delimeter));
            
            //printf("nTestCase = %d Width = %d Height = %d \n", nTestCase, nWidth, nHeight);
            continue;
            
        }
        strncpy(board[j], buffer, strlen(buffer));
        j++;
        
        if (j == nHeight)
        {
            doProcess();
            
        }
        
    }
    
    return (EXIT_SUCCESS);
}

void doProcess()
{
    
    int i, j;
    
    for (i = 0; i <nHeight; i++)
    {
        for (j = 0; j < nWidth; j++)
            printf("%c", board[i][j]);
    
        printf("\n");
    }
           
}