#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isAcceptedByNFA(const char *str) {
    int length = strlen(str);
    if (length == 0) {
        return false;
    }
    if (str[0] == 'b' && str[length - 1] == 'a') {
        return true;
    }
    return false;
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%99s", input);
    if (isAcceptedByNFA(input)) {
        printf("The string is accepted by the NFA.\n");
    } else {
        printf("The string is not accepted by the NFA.\n");
    }

    return 0;
}
