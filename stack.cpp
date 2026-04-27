#include<iostream>
using namespace std;
#define MAX 100
struct stack{
    int top;
    int data[MAX];
};
stack S;
void Init(stack* S){
    S -> top = 0;
}
bool Empty(stack S){
    return (S.top == 0);
}
bool Full(stack S){
    return (S.top == MAX);
}
void push(stack* S, int x){
    if (Full(*S)) cout << "Day";
    else {
        S->data[S->top] = x;
        S->top ++;
    }
}
void Pop(stack* S, int x){
    if (Empty(*S)) cout << "Rong";
    else {
        S->top --;
        S->data[S->top] = x;
    }
}
void Input(stack* S, int x){
    cin << "Nhap x: " << endl;
    while (S->top )
}

