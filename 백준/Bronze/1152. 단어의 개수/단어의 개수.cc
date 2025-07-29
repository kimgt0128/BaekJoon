#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#define MAX 1000000

int countword(char* a) {
    char* ptr = a;// 문자열 리스트 a를 가리키는 포인터 선언
    int count = 0;//개수변수 선언
    char x = NULL;

    for (ptr = a; ptr < ptr + MAX; ptr++) {
        if (*ptr == NULL) { x = *(ptr-1); break; }
        else if (isspace(*ptr)) { count += 1; }//공백이 중간에 한번 나올때마다 count + 1
    }
    if (!isspace(x)) { count += 1; }//마지막 문자 확인: 마지막 입력이 공백이 아니면 count + 1
    if (isspace(a[0])) { count -= 1; }//공백으로 시작하면 count유지
            
    return count;//Enter키가 공백이므로 하나 제거
}

int main(void){

        char a[MAX];

    scanf("%[^\n]s", a);
    printf("%d", countword(a));
    return 0;
}