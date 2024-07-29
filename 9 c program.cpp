#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isAcceptedByNFA(const char* str) {
    int len = strlen(str);
    if (len < 2) {
        return false; 
    }
    if (str[0] == 'b' && str[len - 1] == 'a') {
        return true; 
    }

    return false;
}

int main() {
    char inputString[100];

    printf("Enter a string: ");
    scanf("%s", inputString);

    if (isAcceptedByNFA(inputString)) {
        printf("The string is accepted by the NFA.\n");
    } else {
        printf("The string is not accepted by the NFA.\n");
    }

    return 0;
}
