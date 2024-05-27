#include <stdio.h>

    int main() {
      int x;
      scanf("%d",&x);
      for(int i=1;i<=x;i++){
        for(int j=i;j<x;j++){
          printf(" ");
        }
        for(int j=1;j<=i;j++){
          printf("*");
        }
        for(int j=1;j<=i-1;j++){
          printf("*");
        }        
      printf("\n");  
      }
  }
