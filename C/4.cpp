#include <stdio.h>
#include <math.h>

int main(){
    char str[100];
    int i=0,num = 0;
    printf("������Ҫת���Ķ������ַ���");
    scanf("%s",&str);
    while(str[i]!='\0'){
        num = num * 2 + (str[i] - '0');
        i++;
    }
    printf("%d", num);
}