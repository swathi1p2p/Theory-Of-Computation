#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isA(const char *str, int *pos);
bool isS(const char *str, int *pos);
bool isA(const char *str, int *pos) {
    if (str[*pos] == '1') {
        (*pos)++;
        return isA(str, pos);
    }
    return true; 
}
bool isS(const char *str, int *pos) {
    int start = *pos;
    if (str[*pos] == '0') {
        (*pos)++;
        if (isS(str, pos) && str[*pos] == '0') {
            (*pos)++;
            return true;
        }
        *pos = start;
        return false;
    }
    return isA(str, pos);
}
bool isValidString(const char *str) {
    int pos = 0;
    if (isS(str, &pos) && str[pos] == '\0') {
        return true;
    }
    return false;
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (isValidString(input)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    return 0;
}
