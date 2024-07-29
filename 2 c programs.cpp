#include <stdio.h>
#include <string.h>
int main() {
    int state = 0; 
    char str[100]; 
    printf("Enter a string: ");
    scanf("%s", str); 
    int len = strlen(str); 
    for (int i = 0; i < len; i++) {
        if (str[i] == '0') {
            if (state == 0) {
                state = 1;
            } else if (state == 1) {
                state = 1;
            } else if (state == 2) {
                state = 2;
            }
        } else if (str[i] == '1') {
            if (state == 0) {
                state = 0;
            } else if (state == 1) {
                state = 2;
            } else if (state == 2) {
                state = 2;
            }
        }
    }
    if (state == 1) {
        printf("Rejected"); 
    } else {
        printf("Accepted"); 
    }
    return 0;
}
