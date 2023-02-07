#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_no(void);
void clr(void);
void bulb_lighted(int times, char status);

extern int j = 0;

main(void) {
    int num = 0,score = 0,c = 0 , key = 0; 
    clr();
    for (j=0; j < 5; ++j) { //for loop that loops the game 3 times

    num = rand_no() % 6;
    if (num <= 0) {
       ++num;
    }
    putchar('\n');
    bulb_lighted(5,'n');
    printf("\nWhich bulb will light:\n");
           
   while ((c=getchar()) != '\n') {
    c = c - '0';/* To minus the value of C to make it neutral to char numbers and show their actual value like 49-48 = 1 and 49 is char value of 1*/
    for (int i=1; i<6; ++i) {
        if (num == i) {
		bulb_lighted(1,'y');
        }
        else {
		bulb_lighted(1,'n');

        }
    }
    if (c == num) {
	       printf("That is correct!\n");
               ++score;
	}

    else {
        printf("\nThat is wrong. The number %i will light.\n",num);
	}

    }
   }
printf("Your score is %i out of %i\n", score, j);

}
int rand_no(void) {
    int rand_no;

    srand(time(0));
    rand_no = rand();

    return rand_no;
}

void clr(void) {
  for (int i=0; i<100; ++i) {
	printf("\n");		
}
  printf("\033[%i;%iH", 0, 0); //moves cursor to the start of screen
}
void bulb_lighted(int times, char status) {
	for (int i=0; i<times; ++i) {
		if (status == 'y') {
		   putchar('+');
      		   putchar('O');
                   putchar(' ');
		}
		else if (status == 'n') {
		   putchar('O');
            	   putchar(' ');
		}
	}
}

