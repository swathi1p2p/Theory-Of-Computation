#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool S();
bool A();
const char *input;
int pos;
bool S() {
    int start_pos = pos;
    if (A() && input[pos] == 'a' && pos++ && A() && input[pos] == 'a' && pos++ && A() && input[pos] == 'A') {
        return true;
    }
    pos = start_pos;
    return false;
}
bool A() {
    if (input[pos] == 'a' || input[pos] == 'b') {
        pos++;
        return A();
    }
    return true; 
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    input = str;
    pos = 0;
    if (S() && input[pos] == '\0') {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    return 0;
}
