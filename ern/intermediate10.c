#include <stdio.h>

void printPascalTriangle(int rows) {
    int coef = 1;

    for(int i = 0; i < rows; i++) {
 
        for(int space = 1; space <= rows-i; space++)
            printf(" ");

        for(int j = 0; j <= i; j++) {
       
            if (j == 0 || i == 0)
                coef = 1;
            else {
                
                coef = coef * (i - j + 1);
                coef = coef / j;
            }

            printf("%d", coef);
            if(j!=i){
              printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int rows;
    scanf("%d", &rows);
    printPascalTriangle(rows);
    return 0;
}