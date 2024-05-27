#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    int char_count = 0, digit_count = 0;
    
    fgets(sentence, sizeof(sentence), stdin);
    
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (isalpha(sentence[i])) {
            char_count++;
        } else if (isdigit(sentence[i])) {
            digit_count++;
        }
    }
    
    printf("%d\n", char_count);
    printf("%d", digit_count);
    
    return 0;
}
