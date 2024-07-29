#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isAcceptedByNFA(const char* input);
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    if (isAcceptedByNFA(input)) {
        printf("The string '%s' is accepted by the NFA.\n", input);
    } else {
        printf("The string '%s' is not accepted by the NFA.\n", input);
    }
    return 0;
}
bool isAcceptedByNFA(const char* input) {
    int len = strlen(input);
    if (len < 4) {
        return false;
    }
    if (input[0] == '0' && input[1] == '0' && input[len - 2] == '1' && input[len - 1] == '1') {
        return true;
    }
    return false;
}
