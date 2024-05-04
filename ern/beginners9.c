#include <stdio.h>
int main()
{
  int numbers[3];
  int largest;
  scanf("%d",&numbers[0]);
  scanf("%d",&numbers[1]);
  scanf("%d",&numbers[2]);
  largest=numbers[0];
  for(int i=0;i<3;i++){
    if(numbers[i]>largest){
      largest=numbers[i];
    }
  }
  printf("%d",largest);
}