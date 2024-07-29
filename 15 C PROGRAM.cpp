#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STATES 100
typedef struct Node {
    int state;
    struct Node* next;
} Node;
typedef struct {
    Node* epsilonTransitions[MAX_STATES];
    int numStates;
} NFA;
void initializeNFA(NFA* nfa, int numStates) {
    nfa->numStates = numStates;
    for (int i = 0; i < numStates; i++) {
        nfa->epsilonTransitions[i] = NULL;
    }
}
void addEpsilonTransition(NFA* nfa, int fromState, int toState) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->state = toState;
    newNode->next = nfa->epsilonTransitions[fromState];
    nfa->epsilonTransitions[fromState] = newNode;
}
void printEpsilonClosure(bool epsilonClosure[MAX_STATES][MAX_STATES], int numStates) {
    for (int i = 0; i < numStates; i++) {
        printf("e-closure(q%d) = { ", i);
        for (int j = 0; j < numStates; j++) {
            if (epsilonClosure[i][j]) {
                printf("q%d ", j);
            }
        }
        printf("}\n");
    }
}
void computeEpsilonClosure(NFA* nfa, bool epsilonClosure[MAX_STATES][MAX_STATES]) {
    for (int i = 0; i < nfa->numStates; i++) {
        for (int j = 0; j < nfa->numStates; j++) {
            epsilonClosure[i][j] = false;
        }
    }
    for (int i = 0; i < nfa->numStates; i++) {
        epsilonClosure[i][i] = true;
    }
    for (int i = 0; i < nfa->numStates; i++) {
        bool visited[MAX_STATES] = { false };
        int queue[MAX_STATES];
        int front = 0, rear = 0;
        queue[rear++] = i;
        visited[i] = true;
        while (front < rear) {
            int state = queue[front++];
            for (Node* node = nfa->epsilonTransitions[state]; node != NULL; node = node->next) {
                int nextState = node->state;
                if (!visited[nextState]) {
                    visited[nextState] = true;
                    queue[rear++] = nextState;
                    epsilonClosure[i][nextState] = true;
                }
            }
        }
    }
}
int main() {
    NFA nfa;
    int numStates = 4;
    initializeNFA(&nfa, numStates);
    addEpsilonTransition(&nfa, 0, 1);
    addEpsilonTransition(&nfa, 1, 2);
    addEpsilonTransition(&nfa, 2, 3);
    addEpsilonTransition(&nfa, 1, 3);
    bool epsilonClosure[MAX_STATES][MAX_STATES];
    computeEpsilonClosure(&nfa, epsilonClosure);
    printEpsilonClosure(epsilonClosure, numStates);
    for (int i = 0; i < numStates; i++) {
        Node* current = nfa.epsilonTransitions[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    return 0;
}
