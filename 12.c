//To implement singly linked list

#include<stdio.h>
#include<stdlib.h>

int flag = 0;
struct node {
	int data;
	struct node *next;
};

struct node* insert_node(struct node *head, int pos) {
	struct node *temp, *cur;
	int i;
	cur = head;

	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL) {
		printf("Error allocating memory!\n");
		return NULL;
	}

	printf("Enter the element: ");
	scanf("%d", &temp->data);

	if(pos == 1) {
		if(flag == 0) {
			head = temp;
			temp->next = NULL;
			flag =1;
			return temp;
		}
		else {
		return temp;
		}
	}
	else if(pos == 2) {
		temp->next = NULL;
		head->next = temp;
		return temp;
	}

	for(i=1; i<pos-1; i++, cur=cur->next);
	temp->next = cur->next;
	cur->next = temp;
	return cur->next;
}

struct node* delete_node(struct node *head, int pos) {

}

struct node* reverse(struct node *head) {

}

int search_key(int key) {

}

int search_pos(int pos) {

}

void display(struct node *head) {
	struct node *temp;
	printf("\nYour list:\n");
	for(temp=head; temp!=NULL; temp=temp->next)
		printf("%d\t", temp->data);
	free(temp);
	return;
}

int main() {
	struct node *cur, *head;
	int i, n, pos, choice;
	head = (struct node*)malloc(sizeof(struct node));

	printf("Enter number of elements: ");
	scanf("%d", &n);
	head = insert_node(head, 1);
	for(i=2; i<=n; i++)
		cur = insert_node(head, i);
	cur->next = NULL;
	display(head);

	while(1) {
		cur = head;
		printf("\n1. Insert an element\n");
		printf("2. Delete an element\n");
		printf("3. Reverse the list\n");
		printf("4. Concatenate two lists\n");
		printf("5. Search\n");
		printf("6. Exit\n");
		printf("Enter the option: ");
		scanf("%d", &choice);
		switch(choice) {

		case 1:
			printf("\nInsert an element at\n");
			printf("1. Front\n");
			printf("2. Rear\n");
			printf("3. Specified position\n");
			scanf("%d", &choice);
			if(choice == 1) {
				cur = insert_node(head, 1);
				n++;
				display(head);
			}
			else if(choice == 2) {
				cur = insert_node(head, n);
				cur->next = NULL;
				n++;
				display(head);
			}
			else if(choice == 3) {
				printf("Enter the position: ");
				scanf("%d", &pos);
				if(pos < n) {
					cur = insert_node(head, pos);
					n++;
					display(head);
				}
				else
					goto error;
			}
			else goto error;
			break;

		case 2:
			printf("\nDelete element at\n");
			printf("1. Front\n");
			printf("2. Rear\n");
			printf("3. Specified position\n");
			scanf("%d", &choice);
			if(choice == 1) {
				cur = delete_node(head, 1);
				n--;
			}
			else if(choice == 2) {
				cur = delete_node(head, n);
				n--;
			}
			else if(choice == 2) {
				scanf("%d", &pos);
				cur = delete_node(head, pos);
				n--;
			}
			else goto error;
			break;

		case 6:
			exit(0);
			break;

		default:
			error:
				printf("Invalid option entered\n");
				break;
		}
	}
	return 0;
}
