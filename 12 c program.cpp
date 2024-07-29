#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool simulateDFA(const char *str) {
    int len = strlen(str);
    if (len < 2 || str[0] != 'b' || str[len - 1] != 'b') {
        return false;
    }
    return true;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (simulateDFA(input)) {
        printf("The string belongs to the language represented by the DFA.\n");
    } else {
        printf("The string does not belong to the language represented by the DFA.\n");
    }

    return 0;
}
