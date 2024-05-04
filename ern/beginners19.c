#include <stdio.h>
#include <stdbool.h>
int main()
{
  int num;
  scanf("%d",&num);
  bool isprime=true;
  for(int i=2;i<num;i++){
    if(num%i==0){
      isprime=false;
    }
  }
  if(isprime&&num!=1){
    printf("yes");
  }
  else{
    printf("no");
  }
}