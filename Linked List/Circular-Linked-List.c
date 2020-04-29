#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void print(struct Node* head){
    struct Node* temp = head->next;
    while(temp->next != head->next){    
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("%d\t",temp->data);
}

struct Node* insert_first(struct Node* head, int k){
    struct Node* temp = (struct Node* )malloc(sizeof(struct Node));
    struct Node* last;

    temp->next = head->next;
    if(head->next == NULL){
        head->next = temp;
        temp->next = temp;
        temp->data = k;
        return head;
    }
    temp->next = head->next;
    temp->data = k;
    head->next = temp;
    last = temp->next;
    while(last->next != temp->next){
        last = last->next;
    }
    last->next = temp;
    return head;
}

void insert_last(struct Node* head, int k){
    struct Node* temp = (struct Node* )malloc(sizeof(struct Node));
    struct Node* last = head->next;
    while(last->next != head->next){
        last = last->next;
    }
    temp->next = last->next;
    last->next = temp;
    temp->data = k;
}

struct Node* remove_first(struct Node* head, int *k){
    struct Node* first = head->next;
    struct Node* last = head->next;

    while(last->next != head->next){
        last = last->next;
    }
    head->next = first->next;
    last->next = first->next;
    *k = first->data;
    free(first);
    return head;
}

void remove_last(struct Node* head, int *k){
    struct Node* last = head->next;
    struct Node* prev;

    while(last->next != head->next){
        prev = last;
        last = last->next;
    }

    prev->next = last->next;
    *k = last->data;
    free(last);
}

void insert(struct Node* head, int k, int n){
    int N = 0;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* prev;
    while(N < n){
        prev = head;
        head = head->next;
        N++;
    }
    temp->next = prev->next;
    prev->next = temp;
    temp->data = k;
}

void remove_(struct Node* head, int *k, int n){
    int N = 0;
    struct Node* prev;
    while(N < n){
        prev = head;
        head = head->next;
        N++;
    }
    prev->next = head->next;
    *k = head->data;
    free(head);
}

void main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    int k,n,c,ch,x = 0, y = 0;

    head->next = first;
    first->data = 1;
    first->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = first;

	while(x == 0){
		y = 0;
		printf("1.Insert\t2.Remove\n3.Exit");
    	printf("\nEnter your choice: ");
   		scanf("%d",&c);
   		
    	switch(c){
    		case 1:
    			while(y == 0){
    				printf("\n1.Insert in front\n2.Insert at end\n3.Insert in nth position\n4.Back\n");
    				printf("\nEnter your choice:");
    				scanf("%d",&ch);
    				
    				switch(ch){
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
    						y = 1;
    						break;
					}
				}
				break;
				
			
			case 2:
				while(y == 0){
    				printf("\n1.Remove in front\n2.Remove at end\n3.Remove in nth position\n4.Back\n");
    				printf("\nEnter your choice:");
    				scanf("%d",&ch);
    				
    				switch(ch){
    					case 1:
    						head = remove_first(head,&k);
    						printf("The removed element is: %d\n",k);
    						printf("\nThe list is:\n");
    						print(head);
    						printf("\n");
    						break;
    					
    					case 2:  				
    						remove_last(head,&k);
    						printf("The removed element is: %d\n",k);
    						printf("\nThe list is:\n");
    						print(head);
    						printf("\n");
    						break;
    						
    					case 3:
    						printf("\nEnter the position: ");
    						scanf("%d",&n);
    						remove_(head,&k,n);
    						printf("\nThe list is:\n");
    						print(head);
    						printf("\n");
    						break;
    						
    					case 4:
    						y = 1;
    						break;
					}
				}
				break;
				
			case 3:
				x = 1;
				break;
		}
	}
}