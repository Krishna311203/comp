#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 50
#define MAX_PRODUCTIONS 30
#define MAX_RULE_LENGTH 30

char NT[10], T[10];
int nt, t, top = 0;
char s[MAX_CHARS];
char l[10][10], tr[MAX_PRODUCTIONS][MAX_PRODUCTIONS];
char pr[MAX_PRODUCTIONS][MAX_RULE_LENGTH];

int searchnt(char a) {
    int i;
    for (i = 0; i < nt; i++) {
        if (NT[i] == a)
            return i;
    }
    return -1;
}

int searchter(char a) {
    int i;
    for (i = 0; i < t; i++) {
        if (T[i] == a)
            return i;
    }
    return -1;
}

void push(char a) {
    s[top] = a;
    top++;
}

char pop() {
    top--;
    return s[top];
}

void installl(int a, int b) {
    if (l[a][b] == 'f') {
        l[a][b] = 't';
        push(T[b]);
        push(NT[a]);
    }
}

void installt(int a, int b) {
    if (tr[a][b] == 'f') {
        tr[a][b] = 't';
        push(T[b]);
        push(NT[a]);
    }
}

int main() {
    int i, j, k, s, n;
    char b, c;
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions one by one\n");
    for (i = 0; i < n; i++)
        scanf("%s", pr[i]);
    nt = 0;
    t = 0;
    for (i = 0; i < n; i++) {
        if (searchnt(pr[i][0]) == -1)
            NT[nt++] = pr[i][0];
    }
    for (i = 0; i < n; i++) {
        for (j = 3; j < strlen(pr[i]); j++) {
            if (searchnt(pr[i][j]) == -1) {
                if (searchter(pr[i][j]) == -1)
                    T[t++] = pr[i][j];
            }
        }
    }
    for (i = 0; i < nt; i++) {
        for (j = 0; j < t; j++)
            l[i][j] = 'f';
    }
    for (i = 0; i < nt; i++) {
        for (j = 0; j < t; j++)
            tr[i][j] = 'f';
    }
    for (i = 0; i < nt; i++) {
        for (j = 0; j < n; j++) {
            if (NT[searchnt(pr[j][0])] == NT[i]) {
                if (searchter(pr[j][3]) != -1)
                    installl(searchnt(pr[j][0]), searchter(pr[j][3]));
                else {
                    for (k = 3; k < strlen(pr[j]); k++) {
                        if (searchnt(pr[j][k]) == -1) {
                            installl(searchnt(pr[j][0]), searchter(pr[j][k]));
                            break;
                        }
                    }
                }
            }
        }
    }
    while (top != 0) {
        b = pop();
        c = pop();
        for (s = 0; s < n; s++) {
            if (pr[s][3] == b)
                installl(searchnt(pr[s][0]), searchter(c));
        }
    }
    for (i = 0; i < nt; i++) {
        printf("Leading[%c]\t{", NT[i]);
        for (j = 0; j < t; j++) {
            if (l[i][j] == 't')
                printf("%c, ", T[j]);
        }
        printf("}\n");
    }

    top = 0;
    for (i = 0; i < nt; i++) {
        for (j = 0; j < n; j++) {
            if (NT[searchnt(pr[j][0])] == NT[i]) {
                if (searchter(pr[j][strlen(pr[j]) - 1]) != -1)
                    installt(searchnt(pr[j][0]), searchter(pr[j][strlen(pr[j]) - 1]));
                else {
                    for (k = (strlen(pr[j]) - 1); k >= 3; k--) {
                        if (searchnt(pr[j][k]) == -1) {
                            installt(searchnt(pr[j][0]), searchter(pr[j][k]));
                            break;
                        }
                    }
                }
            }
        }
    }
    while (top != 0) {
        b = pop();
        c = pop();
        for (s = 0; s < n; s++) {
            if (pr[s][3] == b)
                installt(searchnt(pr[s][0]), searchter(c));
        }
    }
    for (i = 0; i < nt; i++) {
        printf("Trailing[%c]\t{", NT[i]);
        for (j = 0; j < t; j++) {
            if (tr[i][j] == 't')
                printf("%c, ", T[j]);
        }
        printf("}\n");
    }
    return 0;
}