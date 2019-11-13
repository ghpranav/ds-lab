// To implement ordinary queue

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int front, rear;
	int *arr;
	unsigned max;
} Queue;

Queue* init(int len) {
	Queue* temp;
	temp = (Queue*)malloc(sizeof(Queue));
	if(!temp)
		return 0;
	
	temp->max = len;
	temp->front = temp->rear = -1;
	
	temp->arr = (int*)malloc(len*sizeof(int));
	if(!temp->arr)
		return 0;
	
	return temp;
}

int isFull(Queue *q) {
	if(q->rear == q->max - 1)
		return 1;
	return 0;
}

int isEmpty(Queue *q) {
	if(q->front == -1)
		return 1;
	return 0;
}

void enqueue(Queue *q, int x) {
	if(isFull(q)) {
		printf("Queue full\n");
		return;
	}
	
	if(isEmpty(q))
		q->front++;
	
	q->rear++;
	q->arr[q->rear] = x;
}

int dequeue(Queue *q) {
	int temp;
	if(isEmpty(q)) {
		printf("Queue empty\n");
		return;
	}
	temp = q->arr[q->front];
	
	if(q->rear == q->front) {
		q->front = q->rear = -1;
	}
	else q->front++;
	
	return(temp);
}

void print(Queue *q) {
	int i;
	printf("\n");
	
	if(isEmpty(q)) {
		printf("Empty queue\n");
		return;
	}
	
	for(i = q->front; i <= q->rear; i++)
		printf("%d\t", q->arr[i]);
	printf("\n");
}

int main() {
	int choice;
	Queue *q;
	
	printf("Enter the size of queue: ");
	scanf("%d", &choice);
	q = init(choice);
	
	while(1) {
		printf("\nMenu\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("Enter the element: ");
				scanf("%d", &choice);
				enqueue(q, choice);
				print(q);
				break;
			
			case 2:
				choice = dequeue(q);
				print(q);
				break;
			
			case 3:
				exit(0);
			
			default:
				printf("Invalid choice!\n");
		}		
	}
	return 0;
}
