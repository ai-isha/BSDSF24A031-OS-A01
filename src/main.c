// File: src/main.c
#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");
    char str1[100] = "Operating ";
    const char* str2 = "Systems";
    char dest[100];

    // Test mystrlen
    printf("Length of '%s': %d\n", str2, mystrlen(str2));

    // Test mystrcpy
    mystrcpy(dest, str2);
    printf("Copied string: %s\n", dest);

    // Test mystrncpy (copy only 3 characters)
    mystrncpy(dest, "University", 3);
    dest[3] = '\0'; // Nul character add karna zaroori hai
    printf("Strncpy (3 chars): %s\n", dest);

    // Test mystrcat
    mystrcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    printf("\n--- Testing File Functions ---\n");
    
    // Testing ke liye ek temporary file banate hain
    FILE *temp = fopen("test.txt", "w+");
    if (temp != NULL) {
        fputs("Hello world\nThis is OS assignment\nTesting grep function in OS\n", temp);
        
        int lines, words, chars;
        // Test wordCount
        if (wordCount(temp, &lines, &words, &chars) == 0) {
            printf("File stats - Lines: %d, Words: %d, Chars: %d\n", lines, words, chars);
        }

        // Test mygrep (OS lafz ko dhoondhte hain)
        char** matches;
        int match_count = mygrep(temp, "OS", &matches);
        printf("Found 'OS' %d times. Matches:\n", match_count);
        for (int i = 0; i < match_count; i++) {
            printf("Match %d: %s", i + 1, matches[i]);
            free(matches[i]); // Memory free karna zaroori hai
        }
        free(matches);
        
        fclose(temp);
        remove("test.txt"); // Test ke baad file delete kar dete hain
    } else {
        printf("Error creating test file.\n");
    }

    return 0;
}
