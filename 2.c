#include<stdio.h>
#include<stdlib.h>

int flag = 0;

struct stud{
  char name[10];
  int reg_no, m[3];
  float avg;
};

void read(struct stud *p, int n) {
	int i;
	struct stud *s = p;
	for(i=0; i<n; i++, s++) {
		printf("Enter details of student %d:\n", i+1);
		printf("Enter name: ");
		scanf("%s", s->name);
		printf("Enter reg no: ");
		scanf("%d", &s->reg_no);
		printf("Enter marks 1: ");
		scanf("%d", &s->m[0]);
		printf("Enter marks 2: ");
		scanf("%d", &s->m[1]);
		printf("Enter marks 3: ");
		scanf("%d", &s->m[2]);
		s->avg = 0;
	}
	flag = 1;
}

void print(struct stud *p, int n) {
	int i;
	struct stud *s = p;
	if(flag == 1) {
		for(i=0; i<n; i++, s++) {
			printf("\nDetails of student %d:\n", i+1);
			printf("Name: %s\n", s->name);
			printf("Reg no: %d\n", s->reg_no);
			printf("Marks 1: %d\n", s->m[0]);
			printf("Marks 2: %d\n", s->m[1]);
			printf("Marks 3: %d\n", s->m[2]);
			printf("Avg: %f\n", s->avg);
		}
	} else printf("Details not yet read\n");
}

void avg(struct stud *p, int n) {
	int i, m1, m2, m3;
	struct stud *s = p;
	if(flag == 1) {
		for(i=0; i<n; i++, s++) {
			m1 = s->m[0] > s->m[1] ? (s->m[0] > s->m[2] ? s->m[0] : s->m[2]) : (s->m[1] > s->m[2] ? s->m[1] : s->m[2]);
			m3 = s->m[0] < s->m[1] ? (s->m[0] < s->m[1] ? s->m[0] : s->m[2]) : (s->m[1] < s->m[2] ? s->m[1] : s->m[2]);
				if( s->m[i]<=m1 && s->m[i]>=m3)
					m2 =  s->m[i];	
			s->avg = (m1+m2)/2;
			printf("Average of Student %d = %d\n", i=1, s->avg);
		}
	}
		
	/*printf("Average of top 2 marks of\n");
	for(i=0; i<n; i++, s++) {
		m1 = m2 = s->m[0];
		for(j=1; j<3; j++) {
			if(s->m[j] > m1) {
				m2 = m1;
				m1 = s->m[j];
			}
			else if(s->m[j] > m2 && s->m[j] != m1)
				m2 = s->m[j];
		}
		printf("Student %d: %d\n", i+1, (m1+m2)/2);
	}*/
}

int main() {
  int n, choice;
  struct stud *p;
  printf("Enter number of students: ");
  scanf("%d", &n);
  p = (struct stud*)malloc(n*sizeof(struct stud));
  while(1) {
    printf("\nChoose an option:\n");
    printf("1. Read info\n");
    printf("2. Display info\n");
    printf("3. Calculate avg\n");
    printf("4. Exit\n");
    printf("Enter the option: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1: read(p, n);
      		  break;
      case 2: print(p, n);
      		  break;
      case 3: avg(p, n);
      		  break;
      case 4: exit(0);
      default: printf("Invalid option entered\n");
    }
  }
  return 0;
}

