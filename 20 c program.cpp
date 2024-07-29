#include <stdio.h>
#include <string.h>
int checkCFG(const char *str, int index) {
    if (str[index] == '\0') {
        return 1;
    }
    if (str[index] == 'a' || str[index] == 'b') {
        return checkCFG(str, index + 1);
    }
    return 0;
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (checkCFG(str, 0)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    return 0;
}
