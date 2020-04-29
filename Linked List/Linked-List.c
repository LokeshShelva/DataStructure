#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void print(struct Node* n){
    while(n->next != NULL){
        n = n->next;
        printf("%d\t",n->data);
    }
}

struct Node* insert_first(struct Node* head, int k){
    struct Node* temp = (struct Node* )malloc(sizeof(struct Node));

    if(head->next == NULL){
       
        temp->data = k;
        temp->next = NULL;
        head->next = temp;
        return head;
    }

    temp->data = k;
    temp->next = head->next;
    head->next = temp;
    return head; 
}

void insert_last(struct Node* head, int k){
    struct Node* temp = (struct Node* )malloc(sizeof(struct Node));

    if(head->next == NULL){
       
        head->next = temp;
        temp->data = k;
        temp->next = NULL;
    
    }else{

        while(head->next!=NULL){
            head = head->next;
        }
        temp->data = k;
        head->next = temp;
        temp->next = NULL;
    }
}

struct Node* remove_first(struct Node* head, int *k){
    struct Node* temp = head->next;

    if(head->next == NULL){
        printf("List empty");
        return head;
    }

    *k = temp->data;
    head->next = temp->next;
    free(temp);
    return head;
}

void remove_last(struct Node* head, int *k){
    struct Node* temp = NULL;
    if(head->next == NULL){
        
        printf("The list is empty.");

    }else{
        
        while(head->next != NULL){
            temp = head;
            head = head->next;
        }
        *k = head->data;
        temp->next = NULL;
        free(head);
    }
}

void insert(struct Node* head, int k, int n){
    struct Node* prev = (struct Node* )malloc(sizeof(struct Node));
    struct Node* temp = (struct Node* )malloc(sizeof(struct Node));

    int N = 0;
    if(n == 0){
        free(prev);
        free(temp);
        exit(0);
    }
    while(N < n){
        prev = head;
        head = head->next;
        N++;
    }
    temp->data = k;
    temp->next = prev->next;
    prev->next = temp;
}

int remove_(struct Node* head, int *k, int n){
    struct Node* prev = (struct Node* )malloc(sizeof(struct Node));
    int N = 0;
    while(N < n){
        prev = head;
        head = head->next;
        N++;
    }
    *k = head->data;
    prev->next = head->next;
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
