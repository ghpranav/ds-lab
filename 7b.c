#include<stdio.h>
int fibonacci(int n) {
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return (fibonacci(n-1) + fibonacci(n-2));
}

int main() {
	int i, n;
	printf("Enter number: ");
	scanf("%d", &n);
	for(i=0; i<n; i++)
		printf("%d \t", fibonacci(i));
	printf("\n");
	return 0;
}
