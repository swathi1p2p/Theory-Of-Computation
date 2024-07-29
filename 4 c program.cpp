#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isInLanguage(const char* str, int start, int end) {
    if (start > end) {
        return true;
    }
    if (start == end) {
        return (str[start] == '0' || str[start] == '1'); 
    }
    if (str[start] == '0' && str[end] == '0') {
        return isInLanguage(str, start + 1, end - 1); 
    }
    if (str[start] == '1' && str[end] == '1') {
        return isInLanguage(str, start + 1, end - 1); 
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
