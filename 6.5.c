#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int count_vowels_with_pointer(char *str);

int main(){
    char sentence[MAX_SIZE];
    int vowel_count;

    printf("Enter a senrence: ");
    if (fgets(sentence, MAX_SIZE, stdin) == NULL) {
        return 1;
    }

    sentence[strcspn(sentence, "\n")] = '\0';

    vowel_count = count_vowels_with_pointer(sentence);

    printf("\n--- STRING ANALYSIS REPORT ---\n");
    printf("Input String: \"%s\"\n", sentence);
    printf("Total Vowel Count: %d\n", vowel_count);

    return 0;
}

int count_vowels_with_pointer(char *str){
    int count = 0;

    while (*str != '\0'){
        char c = *str;

        if(c == 'a' || c == 'e' || c == 'i' ||
           c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' ||
           c == 'O' || c == 'U') {
            count++;
        }
        
        str++;
    }

    return count;
}