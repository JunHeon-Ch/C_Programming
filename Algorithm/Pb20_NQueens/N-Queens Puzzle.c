/*
* YOO SUHWA
* December 4, 2016
* N-Queens Puzzle
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>

int col[30], count=0;
int promising(int);
void queen(int n);
void main()
{
	int i,n;
	while(1){
		count = 0;
		printf("n = ");
		scanf("%d",&n);
		queen(n);
		printf("count = %d\n",count);
	}
}
void queen(int n)
{
	int k = 1;
	col[k] = 0;
	while(k != 0)
	{
		col[k] = col[k]+1;
		while( (col[k]<=n) && !promising(k) )
			col[k]++;
		if(col[k] <= n)
		{
			if(k == n)
				count++;
			else
			{
				k++;
				col[k] = 0;
			}
		}
		else
			k--;
	}
}
int promising(int pos)
{
	int i;
	for(i = 1;i < pos; i++)
	{
		if((col[i] == col[pos]) || ((abs(col[i]-col[pos]) == abs(i-pos))))
			return 0;
	}
	return 1;
}