#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i=i+2){
      printf("%d",i);
      if(i != n && i != n-1){
        printf(",");
      }
    }
}