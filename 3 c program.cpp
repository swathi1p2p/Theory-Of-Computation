#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isInLanguage(const char* str, int start, int end) {
    if (start >= end) {
        return false;
    }
    if (str[start] == '0' && str[end] == '1') {
        for (int i = start + 1; i < end; i++) {
            if (str[i] != '0' && str[i] != '1') {
                return false; 
            }  }
        return true; 
    }
    return false; 
}
int main() {
    char inputString[100];
    printf("Enter a string: ");
    scanf("%s", inputString);
    int len = strlen(inputString);
    if (isInLanguage(inputString, 0, len - 1)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    return 0;
}
