#include <stdio.h>
#include <string.h>
int main()
{
    char inp[100];
    int count[256];
    scanf("%s",inp);
    for(int i=0;i<strlen(inp);i++){
        char c = inp[i];
        if(c!=' '){
            count[c]++;
        }
    }

    char uniqueChar=' ';
    for(int i=0;i<strlen(inp);i++){
        char c = inp[i];
        if(count[c]==1&&c!=' '){
            uniqueChar=c;
            break;
        }
    }
    printf("%c",uniqueChar);
    return 0;
}