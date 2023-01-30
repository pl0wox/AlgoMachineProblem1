//
//  main.cpp
//  HelloWorld
//
//  Created by Jethro Roxas on 1/5/23.
//

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <iterator>
using namespace std;

char isOperator (char ch);
int main(){

    string expression = "a+b*c+d";
    //cout << "Enter your expression: ";
    //cin >> expression;
    

    char exptochar[expression.length()];
    strcpy(exptochar, expression.c_str());
    
    stack<char> Operator_Stack;
    
    cout << endl;

    //cout << "\nPostfix\nExpression\t\tOperator\t\tOperand\n";
    return 0;
}

