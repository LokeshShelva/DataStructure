#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

void print(struct Node* head){
    while(head->next != NULL){
        head = head->next;
        printf("%d\t",head->data);
    }
}

struct Node* insert_first(struct Node* head, int k){
    struct Node* temp = (struct Node* )malloc(sizeof(struct Node));
    struct Node* first = head->next;
    temp->next = head->next;
    first->prev = temp;
    head->next = temp;
    temp->data = k;
    return head;
}

void insert_last(struct Node* head, int k){
	struct Node* temp = head->next;
	struct Node* New = (struct Node* )malloc(sizeof(struct Node));
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = New;
	New->next = NULL;
	New->prev = temp;
	New->data = k;
}

struct Node* remove_first(struct Node* head, int *k){
	struct Node* temp = head->next;
	struct Node* sec = temp->next;
	head->next = temp->next;
	sec->prev = head;
	*k = temp->data;
	free(temp);
}

void remove_last(struct Node* head, int *k){
	struct Node* prev;
	while(head->next != NULL){
		head = head->next;
	}
	prev = head->prev;
	prev->next = NULL;
	*k = head->data;
	free(head);
}

void insert(struct Node* head, int k, int n){
	struct Node* temp = (struct Node* )malloc(sizeof(struct Node));
	struct Node* prev;
	int N = 0;
	while(N < n){
		head = head->next;
		N++;
	}
	prev = head->prev;
	temp->next = head;
	temp->prev = head->prev;
	prev->next = temp;
	head->prev = temp;
	temp->data = k;
}

void remove_(struct Node* head, int *k, int n){
	int N = 0;
	struct Node* prev;
	struct Node* next;
	while(N < n){
		head = head->next;
		N++;
	}
	prev = head->prev;
	next = head->next;
	prev->next = next;
	next->prev = prev;
	*k = head->data;
	free(head);
}

void main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    int k, x = 0, n, c;

    head->prev = NULL;
    head->next = first;
    first->data = 1;
    first->prev = head;
    first->next = second;
    second->data = 2;
    second->prev = first;
    second->next = third;
    third->data = 3;
    third->prev = second;
    third->next = NULL;

   while(x == 0){
		printf("\n1.Insert in front\n2.Insert at end\n3.Insert in nth position\n");
		printf("\n4.Remove in front\n5.Remove at end\n6.Remove in nth position\t7.Exit\n");
    	printf("\nEnter your choice: ");
   		scanf("%d",&c);
   		
    	switch(c){
    		case 1:
    		
    			printf("Enter the element:");
    			scanf("%d",&k);
    			head = insert_first(head,k);
    			printf("\nThe list is:\n");
    			print(head);
    			printf("\n");
   				break;
   				
   			case 2:
   				printf("Enter the element:");
    			scanf("%d",&k);
    			insert_last(head,k);
    			printf("\nThe list is:\n");
    			print(head);
    			printf("\n");
    			break;	
	
			case 3:
				printf("Enter the element:");
    			scanf("%d",&k);
    			printf("Enter the position: ");
    			scanf("%d",&n);
  				insert(head,k,n);
    			printf("\nThe list is:\n");
    			print(head);
    			printf("\n");
    			break;	
			
			case 4:
				head = remove_first(head,&k);
    			printf("The removed element is: %d\n",k);
    			printf("\nThe list is:\n");
    			print(head);
    			printf("\n");
    			break;	
			
			case 5:
				remove_last(head,&k);
    			printf("The removed element is: %d\n",k);
    			printf("\nThe list is:\n");
    			print(head);
    			printf("\n");
    			break;	
				
			case 6:
			   	printf("\nEnter the position: ");
    			scanf("%d",&n);
    			remove_(head,&k,n);
    			printf("\nThe list is:\n");
    			print(head);
    			printf("\n");
    			break;
				
			case 7:
				x = 1;
				break;	
			}
		}
}