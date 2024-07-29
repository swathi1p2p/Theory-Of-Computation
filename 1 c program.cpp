#include <stdio.h>
#include <string.h>
#define NUM_STATES 3
typedef enum {
    START,
    A_START,
    ACCEPT,
    REJECT
} State;
State getNextState(State currentState, char input) {
    switch (currentState) {
        case START:
            if (input == 'a') return A_START;
            break;
        case A_START:
            if (input == 'a') return A_START;
            if (input == 'b') return A_START;
            break;
        case ACCEPT:
            if (input == 'a') return A_START;
            if (input == 'b') return A_START;
            break;
        default:
            return REJECT;
    }
    return REJECT;
}
int isAccepted(const char *input) {
    State currentState = START;
    int length = strlen(input);

    for (int i = 0; i < length; ++i) {
        currentState = getNextState(currentState, input[i]);
        if (currentState == REJECT) {
            return 0;
        }
    }

    return (currentState == A_START && input[length-1] == 'a') ? 1 : 0;
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (isAccepted(input)) {
        printf("The string is accepted by the DFA.\n");
    } else {
        printf("The string is not accepted by the DFA.\n");
    }
    return 0;
}
