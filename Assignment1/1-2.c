#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool checkmax(int j, int mini, int n, int arr[n][n]){
	int max = arr[0][j];
	for (int w = 0; w < n; ++w)
	{
		if(arr[w][j] > max)
			max = arr[w][j];
		/* code */
	}
	return (max == mini);
}

int main(){
	int n, count = 0;
	scanf("%d", &n);
	int arr[n][n];
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &arr[i][j]);
			/* code */
		}
		/* code */
	}

	for (int i = 0; i < n; ++i)
	{
		int mini = arr[i][0], in;
		for (int j = 0; j < n; ++j)
		{
			/* code */
			if(mini>arr[i][j])
				mini = arr[i][j];
		}
		for (int j = 0; j < n; ++j)
		{
			if(mini == arr[i][j]){
				if(checkmax(j, mini, n, arr)==1)
				{
					printf("%d,%d: %d\n", i, j, mini);
					count++;
				}
			}
		}
		
	}
	if(count == 0)
		printf("No saddle points");

	
}
