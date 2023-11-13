//Program exp3.c
//To solve Missionary and Cannibals problem using Breadth First Search
#include <stdio.h>
#include <stdlib.h>
//Definition of a STATE
struct state_node
{
    int m;
    int c;
    char b;
};
typedef struct state_node STATE;

/* Definition of Rule */
struct rule_node
{
    STATE  Left;
    STATE Right;
};
typedef struct rule_node RULES;

// Definition of Queue
STATE MyQue[50];
void INSERTQ(STATE);
STATE DELETEQ();
int EMPTYQ();
int FULLQ();

STATE SEEN[40];
int seencount = -1;
RULES RuleBase[30];

int match(STATE, STATE);
int AlreadySeen(STATE);

int i, front=-1, rear=-1;

int main() {

    STATE Initial, Goal, N, M;
    Initial.m=3; Initial.c = 3; Initial.b='L';
    Goal.m=0; Goal.c=0; Goal.b = 'R';

    printf("Program exp3.c\n");
    printf( "To solve Missionary and Cannibals problem using Breadth First Search\n");

// Rulebase is constructed manually
    RuleBase[0].Left.m=3;RuleBase[0].Left.c=3;RuleBase[0].Right.m=2;RuleBase[0].Right.c=2;RuleBase[0].Left.b='L';RuleBase[0].Right.b='R';
    RuleBase[1].Left.m=3;RuleBase[1].Left.c=3;RuleBase[1].Right.m=3;RuleBase[1].Right.c=2;RuleBase[1].Left.b='L';RuleBase[1].Right.b='R';
    RuleBase[2].Left.m=3;RuleBase[2].Left.c=3;RuleBase[2].Right.m=3;RuleBase[2].Right.c=1;RuleBase[2].Left.b='L';RuleBase[2].Right.b='R';
    RuleBase[3].Left.m=2;RuleBase[3].Left.c=2;RuleBase[3].Right.m=3;RuleBase[3].Right.c=2;RuleBase[3].Left.b='R';RuleBase[3].Right.b='L';
    RuleBase[4].Left.m=2;RuleBase[4].Left.c=2;RuleBase[4].Right.m=3;RuleBase[4].Right.c=3;RuleBase[4].Left.b='R';RuleBase[4].Right.b='L';
    RuleBase[5].Left.m=3;RuleBase[5].Left.c=2;RuleBase[5].Right.m=3;RuleBase[5].Right.c=3;RuleBase[5].Left.b='R';RuleBase[5].Right.b='L';
    RuleBase[6].Left.m=3;RuleBase[6].Left.c=1;RuleBase[6].Right.m=3;RuleBase[6].Right.c=2;RuleBase[6].Left.b='R';RuleBase[6].Right.b='L';
    RuleBase[7].Left.m=3;RuleBase[7].Left.c=1;RuleBase[7].Right.m=3;RuleBase[7].Right.c=3;RuleBase[7].Left.b='R';RuleBase[7].Right.b='L';
    RuleBase[8].Left.m=3;RuleBase[8].Left.c=2;RuleBase[8].Right.m=3;RuleBase[8].Right.c=0;RuleBase[8].Left.b='L';RuleBase[8].Right.b='R';
    RuleBase[9].Left.m=3;RuleBase[9].Left.c=2;RuleBase[9].Right.m=3;RuleBase[9].Right.c=1;RuleBase[9].Left.b='L';RuleBase[9].Right.b='R';
    RuleBase[10].Left.m=3;RuleBase[10].Left.c=0;RuleBase[10].Right.m=3;RuleBase[10].Right.c=1;RuleBase[10].Left.b='R';RuleBase[10].Right.b='L';
    RuleBase[11].Left.m=3;RuleBase[11].Left.c=0;RuleBase[11].Right.m=3;RuleBase[11].Right.c=2;RuleBase[11].Left.b='R';RuleBase[11].Right.b='L';
    RuleBase[12].Left.m=3;RuleBase[12].Left.c=1;RuleBase[12].Right.m=1;RuleBase[12].Right.c=1;RuleBase[12].Left.b='L';RuleBase[12].Right.b='R';
    RuleBase[13].Left.m=3;RuleBase[13].Left.c=1;RuleBase[13].Right.m=3;RuleBase[13].Right.c=0;RuleBase[13].Left.b='L';RuleBase[13].Right.b='R';
    RuleBase[14].Left.m=1;RuleBase[14].Left.c=1;RuleBase[14].Right.m=2;RuleBase[14].Right.c=2;RuleBase[14].Left.b='R';RuleBase[14].Right.b='L';
    RuleBase[15].Left.m=2;RuleBase[15].Left.c=2;RuleBase[15].Right.m=0;RuleBase[15].Right.c=2; RuleBase[15].Left.b='L';RuleBase[15].Right.b='R';
    RuleBase[16].Left.m=0;RuleBase[16].Left.c=2;RuleBase[16].Right.m=0;RuleBase[16].Right.c=3;RuleBase[16].Left.b='R';RuleBase[16].Right.b='L';
    RuleBase[17].Left.m=0;RuleBase[17].Left.c=3;RuleBase[17].Right.m=0;RuleBase[17].Right.c=1; RuleBase[17].Left.b='L';RuleBase[17].Right.b='R';
    RuleBase[18].Left.m=0;RuleBase[18].Left.c=1;RuleBase[18].Right.m=0;RuleBase[18].Right.c=2;RuleBase[18].Left.b='R';RuleBase[18].Right.b='L';
    RuleBase[19].Left.m=0;RuleBase[19].Left.c=2;RuleBase[19].Right.m=0;RuleBase[19].Right.c=0; RuleBase[19].Left.b='L';RuleBase[19].Right.b='R';



//BFS Algorithm
INSERTQ(Initial);
while (!EMPTYQ())
{
    N = DELETEQ();
    printf("Current STATE: m = %d,  c = %d   b = %c \n", N.m, N.c, N.b);

    if (match(N,Goal)) { printf("Success\n"); exit(0); }
    else {
        SEEN[++seencount] = N;
        for (i = 0; i <27 ; i++) {
                 if (match(N, RuleBase[i].Left)) {
                    M= RuleBase[i]. Right;
                    if (!AlreadySeen(M)) INSERTQ(M);
            }
        }
    }
    }
printf("No Solution\n");
}

int EMPTYQ() {
if (front == -1 && rear == -1) return 1;
else return 0;
}

int FULLQ() {
if (rear == 50) return 1;
else return 0;
}

void INSERTQ(STATE S) {
if(!FULLQ()) {
    MyQue[++rear]= S;
    if (front == -1) front++;
}
else printf("Queue is FULL\n");
}

STATE DELETEQ() {
STATE Temp;
if (!EMPTYQ()) {
    Temp = MyQue[front++];
    if (front > 50) { front = -1; rear = -1;}
    return Temp;
}
else printf ("Que is EMPTY\n");
}

int match(STATE L, STATE R) {
if (L.m == R.m && L.c == R.c && L.b == R.b) return 1;
else return 0;
}

int AlreadySeen(STATE S) {
int found =0;
int i;
for(i=0; i <= seencount; i++){
    if (match(S, SEEN[i])) return 1;
}
return 0;
}
