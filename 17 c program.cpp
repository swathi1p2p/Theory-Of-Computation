#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool parseA(const char *str, int *index);
bool parseS(const char *str, int *index);
bool parseS(const char *str, int *index) {
    int start = *index;
    if (str[*index] == 'a') {
        (*index)++;
        if (parseA(str, index)) {
            if (str[*index] == 'b') {
                (*index)++;
                return true;
            }
        }
    }
    *index = start;
    return false;
}
bool parseA(const char *str, int *index) {
    int start = *index;
    if (str[*index] == 'a') {
        (*index)++;
        if (parseA(str, index)) {
            return true;
        }
        *index = start;
    }
    if (str[*index] == 'b') {
        (*index)++;
        if (parseA(str, index)) {
            return true;
        }
        *index = start;
    }
    return true;
}
bool checkString(const char *str) {
    int index = 0;
    if (parseS(str, &index)) {
        return str[index] == '\0';
    }
    return false;
}
int main() {
    const char *testStrings[] = {
        "aab",
        "aaab",
        "ab",
        "aabb",
        "aaaabbbb",
        "a",
        "b",
        "aa",
        "bb",
        ""
    };
    int numTests = sizeof(testStrings) / sizeof(testStrings[0]);
    
    for (int i = 0; i < numTests; i++) {
        if (checkString(testStrings[i])) {
            printf("The string \"%s\" is in the language.\n", testStrings[i]);
        } else {
            printf("The string \"%s\" is NOT in the language.\n", testStrings[i]);
        }
    }
    
    return 0;
}
