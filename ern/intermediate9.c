#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool isArmstrong(int num) {
    int originalNum, remainder, n = 0, result = 0;
    originalNum = num;

   
    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = num;

  
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }

    
    return result == num;
}

int main() {
    int num;

    scanf("%d", &num);
    
    if (isArmstrong(num))
        printf("true");
    else
        printf("false");
    return 0;
}
