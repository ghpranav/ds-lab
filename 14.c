//To implement ordered linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head;

struct node *insert(int order)
{
    struct node *temp, *cur;
    int i;
    cur = head;

    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Error allocating memory!\n");
        return NULL;
    }

    printf("Enter the element: ");
    scanf("%d", &temp->data);

    if (head == NULL)
    {
        head = temp;
        head->next = NULL;
        return head;
    }
    
    /*for (cur = head; cur != NULL; cur = cur->next) {
    	if( (cur->next->data > temp->data) || (cur->next == NULL) )  {
    		temp->next = cur->next;
    		cur->next = temp;
    		break;
    	}
    } */
    
    if(order == 1) {
		if (temp->data < head->data) {
			temp->next = head;
			head = temp;
			return head;
		}
	
		while((cur->next != NULL) && (cur->next->data < temp->data))
			cur = cur->next;
		temp->next = cur->next;
		cur->next = temp;
		return temp;
    }
    
    if (temp->data > head->data) {
    	temp->next = head;
    	head = temp;
    	return head;
    }
	
    while((cur->next != NULL) && (cur->next->data > temp->data))
    	cur = cur->next;
    temp->next = cur->next;
	cur->next = temp;
    return temp;
}


void delete (int pos)
{
    struct node *temp, *cur;
    int i;
    cur = head;

    if (pos == 1)
    {
        head = head->next;
        free(cur);
        return;
    }

    for (i = 1; i < pos - 1; i++, cur = cur->next);
    temp = cur->next;
    cur->next = temp->next;
    free(temp);
}

int concat(int order, int len)
{
    struct node *cur;
    int i, n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if(n == 0) {
		printf("Empty list!");
		return;
	}
    for (i = len + 1; i <= (n + len); i++)
        if(order == 1)
			cur = insert(1);
		else cur = insert(0);
    return (n + len);
}

void search_key()
{
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

void search_pos(int pos)
{
    struct node *cur;
    int i;
    cur = head;
    for (i = 1; i < pos; i++, cur = cur->next);
    printf("Element: %d\n", cur->data);
}

void display(void)
{
    struct node *temp;
    printf("\nYour list:\n");
    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d\t", temp->data);
    return;
}

int main(void)
{
    struct node *cur;
    int i, n, pos, choice, order;
    head = NULL;
    
	printf("\nChoose the order:\n");
	printf("1. Ascending\n");
	printf("2. Dscending\n");
	printf("Enter the option: ");
	scanf("%d", &order);
	if(order != 1 && order != 2) {
		printf("Invalid choice\n");
		exit(0);
	}
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if(n == 0) {
		printf("Empty list!");
		exit(0);
	}
    for (i = 1; i <= n; i++)
        if(order == 1)
			cur = insert(1);
		else cur = insert(0);
    display();

    while (1) {
        cur = head;
        printf("\n1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Search by key\n");
        printf("4. Search by position\n");
        printf("5. Concatenate another list\n");
        printf("6. Exit\n");
        printf("Enter the option: ");
        scanf("%d", &choice);
        switch (choice) {

        case 1:
        	if(order == 1)
	            cur = insert(1);
	        else cur = insert(0);
            n++;
            display();
            break;

        case 2:
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
        
        case 3:
            search_key();
            break;

        case 4:
            printf("Enter the position: ");
            scanf("%d", &pos);
            if (pos <= n)
                search_pos(pos);
            else
                goto error;
            break;
            
        case 5:
        	if(order == 1)
	            n = concat(1, n);
	        else n = concat(0, n);
            display();
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
