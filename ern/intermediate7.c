#include <stdio.h>
#include <string.h>
#include <ctype.h>

void capitalize(char *str) {
    if (*str >= 'a' && *str <= 'z') {
        *str = toupper(*str);
    }
}

int main() {
    char email[100];
    

    scanf("%s", email);

    char *username = strtok(email, "@");
    char *domain = strtok(NULL, "@");
    
    capitalize(username);
    capitalize(domain);
    int i;
    for (i = 0; domain[i] != '\0'; i++) {
        if (domain[i] == '.') {
            break; 
        }
    }

  
    printf("Hi %s, Welcome to ", username);

    for (int j = 0; j < i; j++) {
        printf("%c", domain[j]);
    }
    

    return 0;
}
