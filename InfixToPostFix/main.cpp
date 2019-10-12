#include <iostream>
#include <cstring>

using namespace std;
#define SIZE 100
char stack[SIZE];
int top = -1;

bool isOperand(char c);
int getOpeatorPrecedence(char c);
bool isOperator(char c);
int main()
{
    char infix[100], postfix[100];
    // Precedence in Infix
    // Precedence in Stack
    int j = 0, Pi, Ps;
    cout << "Enter Your Expression: " << endl;
   cin >> infix;
    int len = strlen(infix);
    for(int i = 0; i < len; i++){
        for(int x = 0; x <= top; x++){
            cout << stack[x] << endl;
        }
        cout << "--------------" << endl;

        if(isOperand(infix[i])){
            postfix[j++] = infix[i];
        }else if(isOperator(infix[i])){
            // Until Stack is Not Empty
            while(true){
                if (top == -1)
                    break;
                Pi = getOpeatorPrecedence(infix[i]);
                Ps = getOpeatorPrecedence(stack[top]);

                if (Pi <= Ps){
                    postfix[j++] = stack[top--];
                }else{
                    break;
                }
            }
            // PUSH INTO STACK
            stack[++top] = infix[i];
        }else if(infix[i] == '('){
            stack[++top] = infix[i];
        }else if(infix[i] == ')'){
            while(top > -1 && stack[top] != '('){
                postfix[j++] = stack[top--];
            }
            postfix[j] = stack[top--];
        }
    }
    while(top > -1){
        postfix[j++] = stack[top--];
    }
    cout << "PostFix Expression is " << endl;
    for (int i = 0; i < j; i++){
        cout << postfix[i] << " ";
    }
}
bool isOperand(char c){
    if(c >= 0 && c <= 9) return true;
    if(c >= 'a' && c <= 'z') return true;
    if(c >= 'A' && c <= 'Z') return true;
    return false;
}

bool isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

int getOpeatorPrecedence(char ch){
    int Precedence = -1;

    if (ch == '+' || ch == '-'){
        Precedence = 1;
    }else if(ch == '*' || ch == '/' || ch == '%'){
        Precedence = 2;
    }else if(ch == '^'){
        Precedence = 3;
    }else{
        Precedence = 0;
    }
    return Precedence;
}
