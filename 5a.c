// To convert infix to postfix expression

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	int *arr, top;
	unsigned capacity;
} Stack;

Stack* initialise(int len) {
	Stack *stack;
	
	stack = (Stack*)malloc(sizeof(Stack));
	if(!stack)
		return;
	
	stack->arr = (int*)malloc(len*sizeof(int));
	if(!stack->arr)
		return;
	stack->top = -1;
	stack->capacity = len;
	return stack;
}

int isEmpty(Stack *stack) {
	return (stack->top == -1);
}

int isFull(Stack *stack) {
	return (stack->top == stack->capacity-1);
}

char top(Stack *stack) {
	return stack->arr[stack->top];
}

void push(char op, Stack *stack) {
	if(!isFull(stack))
		stack->arr[++stack->top] = op;
}

char pop(Stack *stack) {
	if(!isEmpty(stack))
		return stack->arr[stack->top--];
}

char isOperand(char ch) {
	return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}

int prec(char ch) {
	switch(ch) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}

int infixToPostfix(char* exp) {
	int i, k;
	Stack *stack;
	
	stack = initialise(strlen(exp));
	if(!stack)
		return -1;
	
	for(i=0, k=-1; exp[i]; i++) {
		if(isOperand(exp[i]))
			exp[++k] = exp[i];
			
		else if(exp[i] == '(')
			push(exp[i], stack);
			
		else if(exp[i] == ')') {
			while(!isEmpty(stack) && top(stack) != '(')
				exp[++k] = pop(stack);
			if(!isEmpty(stack) && top(stack) != '(')		//Unbalanced expression
				return -1;
			else
				pop(stack);
		}
		
		else {
			while(!isEmpty(stack) && prec(exp[i]) <= prec(top(stack)))
				exp[++k] = pop(stack);
			push(exp[i], stack);
		}
	}
	
	while(!isEmpty(stack))
		exp[++k] = pop(stack);
		
	exp[++k] = '\0';
	printf("%s\n", exp);
}

int main() {
	char exp[100];
	
	printf("Enter infix expression: ");
	scanf("%s", exp);
	infixToPostfix(exp);
	
	return 0;
}
