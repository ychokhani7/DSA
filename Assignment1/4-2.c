#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define print(x) printf("%d", x)


typedef struct node{
	int data;
	struct node* next;
	struct node* prev;
} node;

//track last node added to circular linked list
node* circularlast;

//Find Kth node from the end
int knode(node* head, int k, char *s){
	int l = 0;
	node* temp = head;
	if(strcmp(s, "single") == 0 || strcmp(s, "double") == 0 ){
		while(temp!=NULL){
			temp = temp->next;
			l++;
		}
		if(k>l)
			return -1;
		temp = head;
		for (int i = 1; i < l-k; ++i)
		{
			temp = temp->next;
			/* code */
		}
	}
	else{
		while(temp!=circularlast){
			temp = temp->next;
			l++;
		}
		l++;
		temp = head;
		k = k%l;
		for (int i = 1; i < l-k+1; ++i)
		{
			temp = temp->next;
			/* code */
		}

	}
	return temp->data;
}



void push(node** head, int new, char *s){
	node* newn = (node*)malloc(sizeof(node));
	node* last = *head;
	newn->data = new;
	newn->next = NULL;
		
	if(strcmp(s, "single")==0){
		
		if(*head == NULL){
			*head = newn;
			return;
		}
		while(last->next!=NULL){
			last = last->next;
		}
		last->next = newn;
		return;
	}
	else if(strcmp(s, "double")==0){
				

		if(*head == NULL){
			*head = newn;
			newn->prev = NULL;
			return;
		}
		while(last->next!=NULL){
			last = last->next;
		}
		last->next = newn;
		newn->prev = last;
		return;
	}
	else if(strcmp(s, "circular")==0){
			
		if(*head == NULL){
			*head = newn;
			newn->next = newn;
			circularlast = newn;
			return;
		}
		while(last!=circularlast){
			last = last->next;
		}
		newn->next = last->next;
		last->next = newn;
		last = newn;
		circularlast = last;

	}
}
void printlist(node* head, char *s){
	if(strcmp(s, "circular")==0){
		while(head!=NULL && head!=circularlast){
		printf("%d->", head->data);
		head = head->next;
		}
		print(circularlast->data);
	}
	else{
		while(head->next!=NULL){
			printf("%d->", head->data);
			head = head->next;
		}
		print(head->data);
	}
}

int main(){
	node* head = NULL;
	char *s;
	//To know the type of linked list
	scanf("%[^\n]", s);
	char tmp = ' ';
	int x, k;
	//scan till new line
	while(tmp!='\n'){
		scanf("%d", &x);
		scanf("%c", &tmp);
		push(&head, x, s);
	}
	scanf("%d", &k);
	int ans = knode(head, k, s);
	if(ans == -1)
		printf("Value of k has exceeded the limit\n");
	else
		printf("%d\n", ans);
	printlist(head, s);
	
}