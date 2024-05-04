#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main(){
    char x;
    char vowels[5]={'a','e','i','o','u'};
    scanf("%c",&x);
    bool vowel=false;
    for(int i=0;i<5;i++){
      if(vowels[i]==x){
        vowel=true;
      }
    }
    if(vowel){
      printf("vowel");
    }
    else{
      printf("consonant");
    }
}