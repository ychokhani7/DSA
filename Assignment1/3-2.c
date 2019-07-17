#include<stdio.h>
#include<stdbool.h>
// using namespace std;

bool isprime(int n){
	if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
     if (n % 2 == 0 || n % 3 == 0) 
        return false; 
	for (int i = 5; i*i <= n; i=i+6)
	{
		if(n%i==0 || n%(i+2)==0)
			return false;
		/* code */
	}
	return true;
}
void change(int *x, int *y, char s[]){
	if(s=="left")
		*y-=1;
	else if(s=="right")
		*y+=1;
	else if(s=="up")
		*x-=1;
	else
		*x+=1;
}

int main(){
	int n;
	scanf("%d", &n);
	int count = 1, x=n/2, y=n/2, k=1, r = 1, l = 2, u = 1, d = 2, prime = 2, arr[n][n], temp[n*n];
	while(count<=n*n){
		if(isprime(prime))
			temp[count++] = prime;
		prime++;
	}
	count = 1;
	
	while(count!=n*n){
		while((count!=(n*n)+1) && k<=r){
			arr[x][y] = temp[count++];
			change(&x, &y, "right");
			k++;
		}
		if(count>=n*n)
			break;
		r = r+2, k = 1;
		while(count!=n*n && k<=u){
			arr[x][y] = temp[count++];
			change(&x, &y, "up");
			k++;
		}
			// p(count);
		u = u+2, k = 1;
		while(count!=n*n && k<=l){
			arr[x][y] = temp[count++];
			change(&x, &y, "left");
			k++;
		}
		l = l+2, k = 1;
		while(count!=n*n && k<=d){
			arr[x][y] = temp[count++];
			change(&x, &y, "down");
			k++;
		}
		d = d+2, k = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		for(int j= 0;j<n; j++)
			printf("%d ", arr[i][j]);
		/* code */
		printf("\n");
	}
}