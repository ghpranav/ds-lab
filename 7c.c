#include<stdio.h>

void toh(int n, char from, char to, char aux) {
	if(n == 1) {
		printf("Move disk 1 from rod %c to %c\n", from, to);
		return;
	}
	toh(n-1, from, aux, to);
	printf("Move disk %d from rod %c to %c\n", n, from, to);
	toh(n-1, aux, to, from);
}

int main() {
	int n;
	printf("Enter number of disks: ");
	scanf("%d", &n);
	toh(n, 'A', 'C', 'B');
	return 0;
}
