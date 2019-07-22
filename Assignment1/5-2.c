#include<stdio.h>
#include<stdlib.h>
#define print(x) printf("%d", x)
typedef struct node
{
	int data;
	struct node* next;
} node;

int l, arr[10];

void search(node *head, int n, int arr[]){
	node* temp = head;
	l = 0;
	int j=1;
	while(temp!=NULL){
		if(temp->data==n){
			arr[l] = j;
			l++;
		}
		j++;
		temp = temp->next;
	}
}

void delete(node** head, int n){
	search(*head, n, arr);
	
	node* prev = *head;
	node* curr;
	int i = 1;
	while(i<l){
		int j = arr[i];
		node* temp = *head;
		j--;
		while(j-- && temp->next!=NULL){
			prev = temp;
			temp = temp->next;
		}
		if(temp == NULL) return;
		// curr = temp;
		prev->next = temp->next;
		free(temp);
		i++;
	}
}
void push(node** head, int new){
	node* newn = (node*)malloc(sizeof(node));
	node* last = *head;
	newn->data = new;
	newn->next = NULL;
	
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

void swap(node *head, int num){
	node* temp = head;
	
	while(temp->next!=NULL && temp->data!=num){
		temp = temp->next;
	}
	if(temp->next == NULL) return;
	int x = temp->data;
	temp->data = temp->next->data;
	temp->next->data = x;
	return;
}

void printlist(node* head){
	
	while(head!=NULL){
		print(head->data);
		if(head->next!=NULL) printf("->");
		head = head->next;
	}
	// printf("\n");
}

int main(){
	node *head = NULL;
	char tmp = ' ';
	int x, k;
	//scan till new line
	while(tmp!='\n'){
		scanf("%d", &x);
		scanf("%c", &tmp);
		push(&head, x);
	}
	scanf("%d", &k);
	search(head, k, arr);
	for (int i = 0; i < l; ++i)
	{
		printf("%d ", arr[i]);
		/* code */
	}
	printf("\n");
	delete(&head, k);
	printlist(head);
	printf("\n");
	swap(head, 2);
	printlist(head);
	printf("\n");
	print(l);
	
}