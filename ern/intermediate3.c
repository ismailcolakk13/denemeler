#include <stdio.h>
int main()
{
    char input[50];
    char comp;
    fgets(input,sizeof(input),stdin);
    scanf(" %c",&comp);
    int count=0;
    for(int i=0;i<sizeof(input)/sizeof(input[0]);i++){
        if(input[i]==comp){
            count++;
        }
      }
    printf("%d",count);
}