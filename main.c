#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#endif

#include <stdio.h>
#include <ctype.h>

int main() {
	int c; //current simbol from the stream
	int first = 1; //flag of the first letter in the word
	int letter1 = 0; //first letter of the word
	int counter = 0; //word counter

	int endFlag = 1; //a flag that stops the application

	//a global cycle that prevents the program from endting without the user's desire
	do {	
		//a cycle for reading characters from a stream associated with the keyboard
		printf("Please type down your words:\n");
		while ((c = toupper(getchar())) != EOF){
			if (c == ' ' || c == '.' || c == '\n' || c == ',') {
				//separator found
				first = 1;
			}
			else {
				//letter found
				if (first == 1) {
					first = 0;
					letter1 = c;
				}
				else {
					//comparing not the first letter to the first one
					if (letter1 == c) {
						counter++;
						letter1 = 0;
					}
					else {
						letter1 = 0;
					}
				}
			}
		}
		printf("The amount of words: %d\n", counter);
		first = 0;
		letter1 = 0;
		counter = 0;

		//suggesting to user to run program again or exit.
		printf("\nPlease choose from the following:\n\t1 - Count again.\n\t2 - Exit.\n");
		scanf("%d", &endFlag);
		switch (endFlag) {
			case 1: endFlag = 1; break;
			case 2: endFlag = 0; break;
			default: printf("Incorrect answer. The program will be closed."); endFlag = 0; break;
		}
	}while (endFlag); //if flag is 0, then exiting out of cycle 
	return 0;
}