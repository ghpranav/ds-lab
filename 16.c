// To implement doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
} *head;

struct node *insert(int pos) {
    struct node *temp, *cur;
    int i;
    cur = head;

    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Error allocating memory!\n");
        return NULL;
    }

    printf("Enter the element: ");
    scanf("%d", &temp->data);

    if (pos == 1) {
        temp->next = head;
        temp->prev = NULL;
        head = temp;
        return temp;
    }

    for (i = 1; i < pos - 1; i++, cur = cur->next);
    temp->next = cur->next;
    temp->prev = cur;
    cur->next = temp;
    if(temp->next != NULL) {
	    cur = temp->next;
    	cur->prev = temp;
    }
    return temp;
}

void delete (int pos) {
    struct node *temp, *cur;
    int i;
    cur = head;

    if (pos == 1) {
        head = head->next;
        head->prev = NULL;
        free(cur);
        return;
    }

    for (i = 1; i < pos - 1; i++, cur = cur->next);
    temp = cur->next;
    cur->next = temp->next;
    cur = cur->next;
    cur->prev = temp->prev;
    free(temp);
    return;
}

void search_key() {
    struct node *cur;
    int i = 1, key;
    cur = head;
    printf("Enter search key: ");
    scanf("%d", &key);
    while (cur != NULL)
    {
        if (cur->data == key)
        {
            printf("Key found at position %d\n", i);
            return;
        }
        cur = cur->next;
        i++;
    }
    printf("Key not found\n");
    return;
}

void search_pos(int pos) {
    struct node *cur;
    int i;
    cur = head;
    for (i = 1; i < pos; i++, cur = cur->next);
    printf("Element: %d\n", cur->data);
    return;
}

void display() {
    struct node *temp;
    printf("\nYour list:\n");
    temp = head;
    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d\t", temp->data);
    return;
}

int main() {
    struct node *cur;
    int i, n, pos, choice;
    head = (struct node *)malloc(sizeof(struct node));

    printf("Enter number of elements: ");
    scanf("%d", &n);
    if(n == 0) {
		printf("Empty list!");
		exit(0);
	}
    for (i = 1; i <= n; i++)
        cur = insert(i);
    cur->next = NULL;
    display();

    while (1) {
        cur = head;
        printf("\n1. Insert an element at front\n");
        printf("2. Insert an element at rear end\n");
        printf("3. Insert an element at specified position\n");
        printf("4. Delete an element\n");
        printf("5. Search by key\n");
        printf("6. Search by position\n");
        printf("7. Exit\n");
        printf("Enter the option: ");
        scanf("%d", &choice);
        switch (choice) {

        case 1:
            cur = insert(1);
            n++;
            display();
            break;

        case 2:
            cur = insert(n + 1);
            cur->next = NULL;
            n++;
            display();
            break;

        case 3:
            printf("Enter the position: ");
            scanf("%d", &pos);
            if (pos <= n + 1) {
                cur = insert(pos);
                if(pos == n + 1)
                	cur->next = NULL;
                n++;
                display();
            }
            else
                goto error;
            break;

        case 4:
            printf("Enter the position: ");
            scanf("%d", &pos);
            if (pos <= n) {
                delete (pos);
                n--;
                display();
            }
            else
                goto error;
            break;
        
        case 5:
            search_key();
            break;

        case 6:
            printf("Enter the position: ");
            scanf("%d", &pos);
            if (pos <= n)
                search_pos(pos);
            else
                goto error;
            break;

        case 7:
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