#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char firstNonRepeatedChar(char *str) {
    int count[256] = {0}; 

    
    for (int i = 0; str[i]; i++) {
        if (!isspace(str[i])) 
            count[str[i]]++;
    }


    for (int i = 0; str[i]; i++) {
        if (!isspace(str[i]) && count[str[i]] == 1)
            return str[i];
    }
    
    return '\0'; 
}

int main() {
    char str[MAX_SIZE];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 

    char result = firstNonRepeatedChar(str);

        printf("%c", result);


    return 0;
}
