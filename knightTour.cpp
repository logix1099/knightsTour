#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

  struct info{
  		int nummoves;
  		bool taken;
  		int movenum;
  	};
  	
bool vaildmove(int imove,int jmove);
info nextmove(int &a, int &b, info **board);
int n;
int m;

int main(int argc, char* argv[])
{
	
	if (argc < 3)
	{
		cout<<"forgot a n or m value"<<endl;
		return 0;
	}
	else if (argc > 2)
	{
  		 n=atoi(argv[1]);
  		 m=atoi(argv[2]);
	}
  	if (n < m)
  	{
  		int temp = n;
  		n = m;
  		m = temp;
  	}
  	int a = 1;
  	int b = 1;	
 	int maxsquare = (n * m);
  	int movecount = 1;
  	int nextsquare;  	
  	info** board = new info*[n];
  	for (int i=1;i<=n;i++)
  	{
  		board[i] = new info[m];
  		for(int j=1;j<=m; j++)
  		{
			board[i][j].nummoves = 0;
  			board[i][j].taken = false; 			
  		}
  	}
  	
  	for (int i = 1; i <= n; i++)
  	{
  		for (int j = 1; j <= m; j++)
  		{
  			if (vaildmove(i+1,j-2))
  			{

  				board[i][j].nummoves++;
  			}
  			if (vaildmove(i+1,j+2))
  			{
  				board[i][j].nummoves++;
  			}
  			if (vaildmove(i+2,j-1))
  			{
  				board[i][j].nummoves++;
  			}
  			if (vaildmove(i+2,j+1))
  			{
  				board[i][j].nummoves++;
  			}
  			if (vaildmove(i-1,j+2))
  			{
  				board[i][j].nummoves++;
  			}
  			if (vaildmove(i-1,j-2))
  			{
  				board[i][j].nummoves++;
  			}
  			if (vaildmove(i-2,j+1))
  			{
  				board[i][j].nummoves++;
  			}
  			if (vaildmove(i-2,j-1))
  			{
  				board[i][j].nummoves++;
  			}
  		}
  	}
	for(int i = 1; i <= n; i++)
  	{
  		cout<<i;
	  	for(int j = 1; j <= m; j++)
		{
			cout<<"     "<<j<<" "<<board[i][j].nummoves;
		}
		cout<<endl;
  	}
	int currentnummoves;
	
  	while (movecount <= maxsquare)
  	{
  		
		currentnummoves = board[a][b].nummoves;	
  		if ((movecount == maxsquare) && ((a == 3 && b == 2) || (a == 2 && b==3)))
  		{
  			cout<<"complete path"<<endl;
  			return 0;
  			
  		}
		else if (currentnummoves == 0)
		{
			cout<<"no knights tour"<<endl;
			return 0;
		}
		else{
			nextmove(a, b, board);
			board[a][b].taken = true;
			cout<<a<<" "<<b<<endl;
			movecount++;
			}
			
  	} 	
}

bool vaildmove(int imove, int jmove)
{
	if (imove <= n && jmove <= m && imove >= 1 && jmove >= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
info nextmove(int &a, int &b, info **board)
{
	int minmove = 9;
	int move = 0;
	info nextsquare;
			cout<<"in nextmove"<<endl;
			
			if ((vaildmove(a+1,b-2))&&(board[a+1][b-2].taken == false))
  			{
  		
  				if (board[a+1][b-2].nummoves < minmove)
  				{
  						
  					minmove = board[a+1][b-2].nummoves;

  					//cout<<square.nummoves<<endl;
  					//nextsquare = board[a+1][b-2];
  					
  					//cout<<square.nummoves<<endl;
  					move = 1;
  					
  				}
//  			else if (board[a+1][b-2].nummoves==minmove)
//  			{
////  			minmove=tiebreak(a+1, b-2);
//  			}
				if (board[a+1][b-2].nummoves > 0)
				board[a+1][b-2].nummoves--;
  			}
  			if ((vaildmove(a+1,b+2))&&(board[a+1][b+2].taken == false))
  			{
  				if (board[a+1][b+2].nummoves < minmove)
  				{
  					minmove = board[a+1][b+2].nummoves;

  					//nextsquare = board[a+1][b+2];
  					
  					move = 2;
  				}
  				else if (board[a+1][b+2].nummoves == minmove)
  				{
  					//minmove=tiebreak(a+1, b+2);
  				}
  				if (board[a+1][b+2].nummoves > 0)
  				board[a+1][b+2].nummoves--;
  			}
  			if ((vaildmove(a+2,b-1))&&(board[a+2][b-1].taken == false))
  			{
  				if (board[a+2][b-1].nummoves < minmove)
  				{
  					minmove = board[a+2][b-1].nummoves;

  					//nextsquare = board[a+2][b-1];
  					
  					move = 3;
  				}
  				else if (board[a+2][b-1].nummoves == minmove)
  				{
  				//	minmove=tiebreak(a+2, b-1);
  				}
  				if (board[a+2][b-1].nummoves > 0)
  				board[a+2][b-1].nummoves--;
  			}
  			if ((vaildmove(a+2,b+1))&&(board[a+2][b+1].taken == false))
  			{
  				if (board[a+2][b+1].nummoves < minmove)
  				{
  					minmove = board[a+2][b+1].nummoves;

  					//nextsquare = board[a+2][b+1];
  					
  					move = 4;
  				}
  				
  				else if (board[a+2][b+1].nummoves == minmove)
  				{
  			//		minmove=tiebreak(a+2, b+1);
  				}
  				if (board[a+2][b+1].nummoves > 0)
  				board[a+2][b+1].nummoves--;
  			}
  			if ((vaildmove(a-1,b+2))&&(board[a-1][b+2].taken == false))
  			{
  				if (board[a-1][b+2].nummoves < minmove)
  				{
  					minmove = board[a-1][b+2].nummoves;

  					//nextsquare = board[a-1][b+2];
  					
  					move = 5;
  				}
  				else if (board[a-1][b+2].nummoves == minmove)
  				{
  			//		minmove=tiebreak(a-1, b+2);
  				}
  				if (board[a-1][b+2].nummoves > 0)
  				board[a-1][b+2].nummoves--;
  			}
  			if ((vaildmove(a-1,b-2))&&(board[a-1][b-2].taken == false))
  			{
  				if (board[a-1][b-2].nummoves<minmove)
  				{
  					minmove = board[a-1][b-2].nummoves;

  					//nextsquare = board[a-1][b-2];
  					
  					move = 6;
  				}
  				else if (board[a-1][b-2].nummoves == minmove)
  				{
  		//			minmove=tiebreak(a-1, b-2);
  				}
  				if (board[a-1][b-2].nummoves > 0)
  				board[a-1][b-2].nummoves--;
  			}
  			if ((vaildmove(a-2,b+1))&&(board[a-2][b+1].taken == false))
  			{
  				if (board[a-2][b+1].nummoves < minmove)
  				{
  					minmove = board[a-2][b+1].nummoves;

  					//nextsquare = board[a-2][b+1];
  					
  					move = 7;
  				}
  				else if (board[a-2][b+1].nummoves == minmove)
  				{
  	//				minmove=tiebreak(a-2, b+1);
  				}
  				if (board[a-2][b+1].nummoves > 0)
  				{
  				board[a-2][b+1].nummoves--;
  				}
  			}
  			if ((vaildmove(a-2,b-1))&&(board[a-2][b+1].taken == false))
  			{
  				if (board[a-2][b-1].nummoves < minmove)
  				{
  					minmove = board[a-2][b-1].nummoves;

  					//nextsquare = board[a-2][b-1];
  					
  					move = 8;
  				}
  				else if (board[a-2][b-1].nummoves == minmove)
  				{
  //					minmove=tiebreak(a-2, b-1);
  				}
  				if(board[a-2][b-1].nummoves > 0)
  				{
  				board[a-2][b-1].nummoves--;
  				}
  			}
  			cout<<a<<" "<<b<<endl;
  			
  			if (move == 1)
  			{
  				a=a+1;
  				b=b-2;
  			}
  			if (move == 2)
  			{
  				a=a+1;
  				b=b+2;
  				
  			}
  			if (move == 3)
  			{
  				a=a+2;
  				b=b-1;
  			}
  			if (move == 4)
  			{
  				a=a+2;
  				b=b+1;
  			}
  			if (move == 5)
  			{
  				a=a-1;
  				b=b+2;
  			}
  			if (move == 6)
  			{
  				a=a-1;
  				b=b-2;
  			}
  			if (move == 7)
  			{
  				a=a-2;
  				b=b+1;
  			}
  			if (move == 8)
  			{
  				a=a-2;
  				b=b-1;
  			}
  			return board[a][b];
}
//tiebreak(minmove, )
