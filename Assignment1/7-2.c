#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* reverse(char *s){
	char *temp;
	temp = malloc(sizeof(char)*50);
	int i=0, w=0, n = strlen(s);
    while (i<n) { 
       if(s[i]==' '){
       	temp[w] = s[i];
       	i++, w++;
       }
       else{
       	int k=0, j;
       	while(s[i]!=' ' && i<n){
       		k++, i++;
       	}
       	j = i-1;
       	while(k){
      		temp[w] = s[j];
      		j--, k--, w++;
      	}
       }
    }
    return temp; 
}
char* encode(char *s){
	int i = 0, j=0, n = strlen(s), x;
	while(s[i]==' '){
		i++;
	}
	x = s[i]+3;
	if(x>122)
		x = x-26;
	s[i] = x;
	while(i < n)
	{
		int temp = 0;
		while(temp<2){
			if(s[i+1]!=' ')
				temp++;
			i++;
		}
		if(s[i]!=' ' && i<n){
			
			int x = s[i]+3;
			if(x>122)
				x = x-26;
			s[i] = x;
			
		}
	}
	char *temp = reverse(s);
	return temp;
}

char* decode(char s[]){
	s = reverse(s);
	int i = 0, j=0, n = strlen(s), x;
	while(s[i]==' '){
		i++;
	}
	x = s[i]-3;
	if(x<97)
		x = 26+x;
	s[i] = x;
	while(i < n)
	{
		int temp = 0;
		while(temp<2){
			if(s[i+1]!=' ')
				temp++;
			i++;
		}
		if(s[i]!=' ' && i<n){
			
			int x = s[i]-3;
			if(x<97)
				x = 26+x;
			s[i] = x;
			
		}
	}
	return s;
}

int main(){
	char *s;
	s = malloc(sizeof(char)*50);
  	scanf("%[^\n]", s);
  	s = encode(s);
	// s = decode(s);
	printf("%s\n", s);
	// decode(s);
  	


	
}