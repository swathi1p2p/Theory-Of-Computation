#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
int isAccepted(char *input) {
    int state = 0; // Start state
    
    for(int i = 0; i < strlen(input); i++) {
        char currentChar = input[i];
        
        switch(state) {
            case 0:
                if(currentChar == 'a')
                    state = 1;
                else
                    return FALSE;
                break;
            case 1:
                if(currentChar == 'b')
                    state = 2;
                else if(currentChar != 'a' && currentChar != 'b')
                    return FALSE;
                break;
            case 2:
                if(currentChar == 'b')
                    state = 2; 
                else if(currentChar != 'a' && currentChar != 'b')
                    return FALSE;
                break;
            default:
                return FALSE;
        }
    }
    return (state == 2);
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    if(isAccepted(input))
        printf("The string is accepted by the DFA.\n");
    else
        printf("The string is not accepted by the DFA.\n");
    return 0;
}
