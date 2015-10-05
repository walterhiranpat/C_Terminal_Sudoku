#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
      0 1 2   3 4 5   6 7 8 
00 ___________________________
01 || _ _ _ | _ _ _ | _ _ _ ||
02 || _ _ _ | _ _ _ | _ _ _ ||
03 || _ _ _ | _ _ _ | _ _ _ ||
04 ___________________________
05 || _ _ _ | _ _ _ | _ _ _ ||
06 || _ _ _ | _ _ _ | _ _ _ ||
07 || _ _ _ | _ _ _ | _ _ _ ||
08 ___________________________
09 || _ _ _ | _ _ _ | _ _ _ ||
10 || _ _ _ | _ _ _ | _ _ _ ||
11 || _ _ _ | _ _ _ | _ _ _ ||
12 ___________________________
*/
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"
//Prototype
int SUDOKUSolver(char grid[9][9]);
int lineCheck(char line[9]);

int main()
{
	int Game=1;
	while(Game==1)
	{
		//Introduction:
		char introChoice;
		int boardchoice=1;
		/*
		printf("===================================\n");
		printf("++++++++++TERMINAL SUDOKU++++++++++\n");
		printf("===================================\n");*/
		/*
		while(boardchoice==1)
		{
			char* filename;
			strcpy(filename, "game");
			printf(" Would you like to select a board\n or have computer choose for you(s/r)?:");
			scanf(" %c", &introChoice);
			if(introChoice=='s')
			{
				char numpick;
				printf("Print board number(1-10)?");
				scanf(" %c", &numpick);
				strcat(filename, numpick);
				strcat(filename, ".txt");
				if(numpick>=1 || numpick<=10)
				{
					FILE *f = fopen(filename, "r");
					if(!f){
						printf("ERROR: File %s could not be read",filename);
						return 0;
					}
					boardchoice=0;
				}
			}
			else if(introChoice=='r')
			{
				int randomnum = rand()%10+1;
				char num;
				itoa(randomnum, num, 10);
				strcat(filename, num);
				strcat(filename, ".txt");
				FILE *f = fopen(filename, "r");
				if(!f){
					printf("ERROR: File %s could not be read",filename);
					return 0;
				}
				boardchoice=0;
			}
			else
			{
				printf("Invalid input\n\n");
			}
		}
*//*
		
		char info[9][9]={
						 {'-','-','-','2','6','-','7','-','1'},
						 {'6','8','-','-','7','-','-','9','-'},
						 {'1','9','-','-','-','4','5','-','-'},
						 {'8','2','-','1','-','-','-','4','-'},
						 {'-','-','4','6','-','2','9','-','-'},
						 {'-','5','-','-','-','3','-','2','8'},
						 {'-','-','9','3','-','-','-','7','4'},
						 {'-','4','-','-','5','-','-','3','6'},
						 {'7','-','3','-','1','8','-','-','-'}
						};
		*/
		char info[9][9]={
						 {'-','3','5','2','6','9','7','8','1'},
						 {'6','8','2','5','7','1','4','9','3'},
						 {'1','9','7','8','3','4','5','6','2'},
						 {'8','2','6','1','9','5','3','4','7'},
						 {'3','7','4','6','8','2','9','1','5'},
						 {'9','5','1','7','4','3','6','2','8'},
						 {'5','1','9','3','2','6','8','7','4'},
						 {'2','4','8','9','5','7','1','3','6'},
						 {'7','6','3','4','1','8','2','5','9'}
						};
		
		char original[9][9];
		int i=0;
		int j=0;
		for (i=0;i<9;i++)
		{
			for (j=0;j<9;j++)
			{
				original[i][j]=info[i][j];
			}
		}
		int gameplay=1;
		while(gameplay==1)
		{
			int rowdisplay = 0;
			int coldisplay = 0;
			int row	= 0;
			int col = 0;
			printf("===================================\n");
			printf("++++++++++TERMINAL SUDOKU++++++++++\n");
			printf("===================================\n");
			printf("%s     0 1 2   3 4 5   6 7 8 \n", KGRN);
			while(rowdisplay<13)
			{
				switch(rowdisplay){
					case 0: case 4: case 8: case 12:
						printf("  %s___________________________\n", KGRN);
						rowdisplay++;
						break;
					case 1: case 2: case 3: case 5: case 6: case 7: case 9: case 10: case 11:
						printf("%s%d %s|| ",KGRN, row, KRED);
						coldisplay=0;
						for (col=0; col<9; col++)
						{
							if(original[row][col]!='-')
							{
								printf("%s%c ", KYEL, info[row][col]);
							}
							else
							{
								printf("%s%c ", KGRN, info[row][col]);
							}
							coldisplay++;
							if(coldisplay==3)
							{
								printf("%s|",KRED);
								coldisplay=0;
								if (col==8)
								{
									printf("%s|\n", KRED);
								}
								else
								{
									printf(" ");
								}
							}
						}
						row++;
						rowdisplay++;
						break;
				}
			}
			//Collect Player moves
			
			char inputvalue;
			int inputcheck=1;
			while(inputcheck==1)
			{
				int rowinput;
				int columninput;
				printf("\nWhat row?");
				scanf(" %d",&rowinput);
				printf("What column?");
				scanf(" %d",&columninput);
				if(rowinput>8 || rowinput<0 || columninput>8 || columninput<0)
				{
					printf("\ninvalid input\n");
					getchar();
				}
				else
				{
					if(original[rowinput][columninput]=='-')
					{
						printf("What input in [%d, %d]?", rowinput, columninput );
						scanf(" %c",&inputvalue);
						if(inputvalue=='-'||inputvalue=='1'||inputvalue=='2'||inputvalue=='3'||inputvalue=='4'||inputvalue=='5'||inputvalue=='6'||inputvalue=='7'||inputvalue=='8'||inputvalue=='9')
						{
							info[rowinput][columninput]=inputvalue;
							inputcheck=0;
						}
						else
						{
							printf("\ninvalid input\n");
							getchar();
						}
					}
				}
			}
			//Return 1 for errors else return 0 for no errors
			int SolverSolution=SUDOKUSolver(info);
			if(SolverSolution==0)
			{
				printf("\nComplete!\n");
				gameplay=0;
			}
		}
		//fclose(f);
		int completion=1;
		while(completion==1)
		{
			printf("\nWould you like to play again (Y/N)?");
			char continued;
			scanf(" %c", &continued);
			if(continued=='n' || continued=='N')
			{
				completion=0;
				Game=0;
			}
			else if(continued=='y' || continued=='Y')
			{
				completion=0;
				Game=1;
			}
			else
			{
				printf("Invalid input");
				getchar();
			}
		}
	}
	printf("\n\nQuit....\n" RESET);
	return 0;
}

int SUDOKUSolver(char grid[9][9])
{
	int row2;
	int col2;
	int row;
	int col;
	int x;
	int y;
	int overallcheck=0;

	int rowdisplay = 0;
	int coldisplay = 0;
	int rowx	= 0;
	int colx = 0;
	printf("\n\n===================================\n");
	printf("++++++++++TERMINAL SUDOKU++++++++++\n");
	printf("===================================\n");
	printf("%s     0 1 2   3 4 5   6 7 8 \n", KGRN);
	while(rowdisplay<13)
	{
		switch(rowdisplay){
			case 0: case 4: case 8: case 12:
				printf("  %s___________________________\n", KGRN);
				rowdisplay++;
				break;
			case 1: case 2: case 3: case 5: case 6: case 7: case 9: case 10: case 11:
				printf("%s%d %s|| ",KGRN, rowx, KRED);
				coldisplay=0;
				for (colx=0; colx<9; colx++)
				{
					if(grid[rowx][colx]!='-')
					{
						printf("%s%c ", KYEL, grid[rowx][colx]);
					}
					else
					{
						printf("%s%c ", KGRN, grid[rowx][colx]);
					}
					coldisplay++;
					if(coldisplay==3)
					{
						printf("%s|",KRED);
						coldisplay=0;
						if (colx==8)
						{
							printf("%s|\n", KRED);
						}
						else
						{
							printf(" ");
						}
					}
				}
				rowx++;
				rowdisplay++;
		}
	}
	//check if the grid is completed:
	for (row=0;row<9;row++)
	{
		for(col=0;col<9;col++)
		{
			if(grid[row][col]=='-')
			{
				overallcheck++;
			}
		}
	}
	//row checks:
	for (row2=0;row2<9;row2++)
	{
		char x[9] = 
		{
			grid[row2][0], grid[row2][1], 
			grid[row2][2], grid[row2][3], 
			grid[row2][4], grid[row2][5], 
			grid[row2][6], grid[row2][7],
			grid[row2][8]
		};
		int rowcheck = lineCheck(x);
		if(rowcheck==0)
		{
			printf("%srow#%d: passed\n",KCYN, row2);
		}
		else
		{
			printf("%srow#%d: failed\n",KCYN, row2);
			overallcheck++;
		}
	}
	//column checks:
	for (col2=0;col2<9;col2++)
	{
		char y[9] = 
		{
			grid[0][col2], grid[1][col2],
			grid[2][col2], grid[3][col2],
			grid[4][col2], grid[5][col2],
			grid[6][col2], grid[7][col2],
			grid[8][col2]
		};
		int colcheck = lineCheck(y);
		if(colcheck==0)
		{
			printf("%scol#%d: passed\n",KCYN, col2);
		}
		else
		{
			printf("%scol#%d: failed\n",KCYN, col2);	
			overallcheck++;		
		}
	}
	//check if each  is completed
	for (x=0;x<3;x++)
	{
		for(y=0;y<3;y++)
		{
			char block[9]=
			{
				grid[3*y  ][3*x  ], grid[3*y  ][3*x+1], grid[3*y  ][3*x+2], 
				grid[3*y+1][3*x  ], grid[3*y+1][3*x+1], grid[3*y+1][3*x+2], 
				grid[3*y+2][3*x  ], grid[3*y+2][3*x+1], grid[3*y+2][3*x+2]
			};
			int blockcheck = lineCheck(block);
			if(blockcheck==0)
			{
				printf("%sBlock[%d,%d]: passed\n",KCYN, x,y);
			}
			else
			{
				printf(
					"%sBlock[%d,%d]: failed\n",KCYN, x, y);			
				overallcheck++;
			}
		}
	}
	return overallcheck;
}

int lineCheck(char line[9])
{
	char list[9]={'1','2','3','4','5','6','7','8','9'};
	int check[9]={ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
	//check for matching
	int count=0;
	int checkcount=0;
	int i=0;
	for (i=0;i<9;i++)
	{
		switch(line[i])
		{
			case '1':
				check[0]=1;
				break;
			case '2':
				check[1]=1;
				break;
			case '3':
				check[2]=1;
				break;
			case '4':
				check[3]=1;
				break;
			case '5':
				check[4]=1;
				break;
			case '6':
				check[5]=1;
				break;
			case '7':
				check[6]=1;
				break;
			case '8':
				check[7]=1;
				break;
			case '9':
				check[8]=1;
				break;
			default:
				printf("error");
		}
	}
	for (count=0;count<9;count++)
	{
		if (check[count]==1)
		{
			checkcount++;
		}
	}
	if (checkcount==9)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}