#include <stdio.h>
#include <stdbool.h>
#define STATES 3
void epsilonClosure(int nfa[STATES][STATES], int closure[STATES][STATES], int state) {
    closure[state][state] = 1;
    for (int i = 0; i < STATES; i++) {
        if (nfa[state][i] == 1 && closure[state][i] == 0) {
            closure[state][i] = 1;
            epsilonClosure(nfa, closure, i);
        }
    }
}
void findEpsilonClosure(int nfa[STATES][STATES], int closure[STATES][STATES]) {
    for (int i = 0; i < STATES; i++) {
        for (int j = 0; j < STATES; j++) {
            closure[i][j] = 0;
        }
    }
    for (int i = 0; i < STATES; i++) {
        epsilonClosure(nfa, closure, i);
    }
}
void printClosure(int closure[STATES][STATES]) {
    for (int i = 0; i < STATES; i++) {
        printf("e-closure of state %d: { ", i);
        for (int j = 0; j < STATES; j++) {
            if (closure[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("}\n");
    }
}
int main() {
    int nfa[STATES][STATES] = {
        {1, 1, 0}, 
        {0, 0, 1},
        {0, 0, 0}  
    };

    int closure[STATES][STATES];
    findEpsilonClosure(nfa, closure);
    printClosure(closure);
    return 0;
}
