// File: src/myfilefunctions.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/myfilefunctions.h"

// File ke andar lines, words aur characters count karne ka function
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (file == NULL) return -1; // Agar file open nahi hui toh fail ho jaye
    
    *lines = 0; 
    *words = 0; 
    *chars = 0;
    
    int in_word = 0;
    int ch;
    
    rewind(file); // File ko shuru se read karna start karein
    
    // File ke end (EOF) tak ek ek character read karein
    while ((ch = fgetc(file)) != EOF) {
        (*chars)++;
        
        if (ch == '\n') {
            (*lines)++;
        }
        
        // Agar space ya newline aaye, matlab word khatam ho gaya
        if (isspace(ch)) {
            in_word = 0;
        } else if (in_word == 0) {
            // Agar naya character aaye aur hum word mein nahi the, toh word count badhayein
            in_word = 1;
            (*words)++;
        }
    }
    return 0; // Success
}

// File mein ek makhsoos lafz (search_str) dhoondhne ka function
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (fp == NULL || search_str == NULL || matches == NULL) return -1;
    
    char buffer[1024]; // Ek line ko store karne ke liye buffer
    int count = 0;
    int capacity = 10;
    
    // Memory allocate karein matches store karne ke liye
    *matches = malloc(capacity * sizeof(char*));
    if (*matches == NULL) return -1;
    
    rewind(fp);
    
    // Jab tak file mein lines bachi hain, unko read karein
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // strstr function check karta hai ke string ke andar doosri string maujood hai ya nahi
        if (strstr(buffer, search_str) != NULL) {
            // Agar jagah kam par jaye toh memory barhayein (realloc)
            if (count >= capacity) {
                capacity *= 2;
                *matches = realloc(*matches, capacity * sizeof(char*));
            }
            
            // Line ki copy bana kar array mein store karein
            char* line_copy = malloc(strlen(buffer) + 1);
            strcpy(line_copy, buffer);
            (*matches)[count] = line_copy;
            count++;
        }
    }
    return count; // Jitni dafa lafz mila, woh ginti wapas karein
}
