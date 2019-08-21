#include<stdio.h>
#include<stdlib.h>

int flag = 0;

struct time{
  int hr, min ,sec;
};

void read(struct time *t1) {
  printf("Enter hour:\n");
  scanf("%d", &t1->hr);
  printf("Enter min:\n");
  scanf("%d", &t1->min);
  printf("Enter sec:\n");
  scanf("%d", &t1->sec);
  flag=1;
}

void print(struct time *t1) {
  if(flag==1) {
    printf("Hour = %d\n", t1->hr);
    printf("Min = %d\n", t1->min);
    printf("Sec = %d\n", t1->sec);
  }
  else {
    printf("Time not yet read\n");
  }
}

void update(struct time *t1) {
  if(flag==1) {
  	if(t1->sec == 59) {
  	  t1->sec = 0;
  	  if(t1->min == 59) {
  	    t1->min = 0;
  	    if(t1->hr == 23) {
  	      t1->hr = 0;
  	    }
  	    else t1->hr++;
  	  }
  	  else t1->min++;
  	}
  	else t1->sec++;
    printf("Hour = %d\n", t1->hr);
    printf("Min = %d\n", t1->min);
    printf("Sec = %d\n", t1->sec);
  }
  else {
    printf("Time not yet read\n");
  }
}

void add(struct time *t1) {
  if(flag==1) {
    struct time t2;
    read(&t2);
    t1->hr += t2.hr;
    t1->min += t2.min;
    t1->sec += t2.sec;
    if(t1->sec >= 60) {
      t1->min++;
      t1->sec = (60-t1->sec);
      if(t1->min >= 60) {
        t1->hr++;
        t1->min = (60-t1->min);
        if(t1->hr >= 24) {
          t1->hr = (24-t1->hr);
        }
      }
    }
    printf("Hour = %d\n", t1->hr);
    printf("Min = %d\n", t1->min);
    printf("Sec = %d\n", t1->sec);
  }
  else {
    printf("Initial time not yet read\n");
  }
}



int main() {
  struct time t1;
  int choice;
  while(1) {
    printf("\nChoose an option:\n");
    printf("1. Read time\n");
    printf("2. Print time\n");
    printf("3. Update time\n");
    printf("4. Add time\n");
    printf("5. Exit\n");
    printf("Enter the option: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1: read(&t1);
      		  break;
      case 2: print(&t1);
      		  break;
      case 3: update(&t1);
      		  break;
      case 4: add(&t1);
      		  break;
      case 5: exit(0);
      default: printf("Invalid option entered\n");
    }
  }
  return 0;
}

