#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 100
int stack[SIZE];
int top = -1;
bool isOperand(char ch);
bool isOperator(char ch);
int getValue(char ch);
int getResult(int value1,int value2,char ch);
int main()
{
    char postFix[100];
    cout << "Enter a Valid PostFix Expression" << endl;
    cin >> postFix;
    int len = strlen(postFix);
    for(int i = 0; i < len; i++){
        cout << "--------------" << endl;
        cout << "Values in Stack" << endl;
        for(int x = 0; x <= top; x++){
            cout << stack[x] << endl;
        }
        cout << "--------------" << endl;
        if(isOperand(postFix[i])){
              int value = 0;
              value = getValue(postFix[i]);
              stack[++top] = value;
        }else if(isOperator(postFix[i])){
            int Ro = stack[top--];
            int Lo = stack[top--];
            int Result = getResult(Lo,Ro,postFix[i]);
            if (top < 0){
                stack[++top] = Result;
            }else{
                int temp = stack[top--];
                stack[++top] = getResult(temp,Result,postFix[++i]);
            }
        }
    }
    cout << "Result = " << stack[top] << endl;
}

int getResult(int value1,int value2,char ch){
    int result;
    switch (ch){
        case '+':
            result = value1 + value2;
            break;
        case '-':
            result = value1 - value2;
            break;
        case '*':
            result = value1 * value2;
            break;
        case '/':
            result = value1 / value2;
            break;
    }
    return result;
}

int getValue(char ch){
    int value;
    cout << "Enter value of " << ch << ": ";
    cin >> value;
    return value;
}

bool isOperand(char ch){
    if(ch >= 'a' && ch <= 'z') return true;
    if(ch >= 'A' && ch <= 'Z') return true;
    if(ch >= 0 && ch <= 9) return true;
    return false;
}

bool isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    return false;
}
