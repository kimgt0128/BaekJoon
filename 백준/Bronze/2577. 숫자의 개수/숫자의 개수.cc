#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#define NUMBER 10 
#define MAX 10
int number[NUMBER] = { 0, };//숫자들의 개수를 세는 함수: index를 숫자로, 값들을 숫자의 개수로 활용

int main(void) {

	char s[MAX];
	unsigned int result = 1;
	int x;
	int index;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &x);
		result *= x;
	}
	sprintf(s, "%d", result);
	for (int i = 0; i < MAX; i++) {
		if (s[i] == NULL) { break; }
		else {
			index = s[i] - '0';//number의 index를 구할때 아스키 코드값을 이용하여 숫자 구하기
			number[index] += 1;
		}
	}
	//배열 출력
	for (int i = 0; i < NUMBER; i++) {
		printf("%d\n", number[i]);
		}
	return 0;
}
