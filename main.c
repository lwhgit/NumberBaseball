#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* createAnswer(int);
int random();

int main() {
	srand(time(0));
	
	int length = 0;
	
	printf("Input answer length: ");
	scanf("%d", &length);
	
	if (length > 2 && length < 10) {
		printf("Answer Length: %d\n", length);
		char* answer = createAnswer(length);
		char* input = (char*) malloc(sizeof(char) * length);
		
		while (1) {
			scanf("%s", input);
			int i = 0;
			int j = 0;
			int strike = 0;
			int ball = 0;
			
			for (i = 0;i < length;i ++) {
				for (j = 0;j < length;j ++) {
					if (input[i] == answer[j]) {
						if (i == j) {
							strike ++;
							break;
						} else {
							ball ++;
							break;
						}
					}
				}
			}
			
			if (strike == length) {
				printf("CORRECT");
				break;
			}
			
			printf("%d STRIKE, %d BALL \n", strike, ball);
		}
		
		free(answer);
		free(input);
	} else {
		printf("Wrong Number!");
		return 0;
	}
	return 0;
}

char* createAnswer(int length) {
	char base[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char* string = (char*) malloc(sizeof(char) * length + 1);
	
	int i = 0;
	for (i = 0;i < 9;i ++) {
		int dest = random();
		char tmp = base[i];
		
		base[i] = base[dest];
		base[dest] = tmp;
	}
	
	for (i = 0;i < length;i ++) {
		string[i] = base[i];
	}
	
	string[length] = 0;
	
	for (i = 0;i < length;i ++) {	//
		printf("%c ", string[i]);	// DELETE
	}								//
	
	printf("\n");
	
	string[length] = 0;

	return string;
}

int random() {
	return rand() % 9;
}
