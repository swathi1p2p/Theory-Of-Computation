#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isA(const char *str, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return false;
        }
    }
    return true;
}
bool isInLanguage(const char *str) {
    int len = strlen(str);
    if (len < 2) {
        return false;
    }
    for (int i = 0; i < len - 1; i++) {
        if (str[i] == '0' && str[i + 1] == '0') {
            if (isA(str, 0, i - 1) && isA(str, i + 2, len - 1)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    char input[100];
    printf("Enter the string: ");
    scanf("%s", input);
    if (isInLanguage(input)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    return 0;
}
