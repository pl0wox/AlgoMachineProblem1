#include <iostream>
#include <stack>
#include <string.h>
#include <algorithm>
#include <iomanip>
using namespace std;

string topostfix(string myString);
string toprefix(string myString);
int precedence(char op);

int main(){	
	
	string user_string;
	cout << "Enter Expression: ";
	cin >> user_string;
	cout << topostfix(user_string);
	cout << "\n\n================================================\n\n";
	cout << toprefix(user_string);
	return 0;
}

string topostfix(string myString){
	char myChar[myString.length()];
	strcpy(myChar, myString.c_str());
	stack<char> s_op;
	stack<char> temp;
	string print_operator = "";
	string result = "";

	cout << "Postfix" << endl;
	cout << "Expression \t\t     Operator\t\t  Operand" << endl;
	
	for(int i = 0; i < myString.length(); i++){
		if(myChar[i] != '*' && myChar[i] != '+' && myChar[i] != '-' && myChar[i] != '/' && myChar[i] != '(' && myChar[i] != ')'){	//	if operand
			result += myChar[i];

			if(s_op.empty()){	// if stack empty
				cout << setw(20) << left << myChar[i] << setw(5) << right << "" << setw(20) << right << result << endl;
			}
			else{
				while(!s_op.empty()){
					//cout << s_op.top();
					temp.push(s_op.top());
					s_op.pop();
				}
				while(!temp.empty()){
					print_operator += temp.top();
					s_op.push(temp.top());
					temp.pop();
				}
				cout << setw(20) << left << myChar[i]  << setw(5) << right << print_operator << setw(20) << right << result << endl;
				print_operator.clear();

			}

		}
		else if (myChar[i] == '(') {	 // if '('
				s_op.push(myChar[i]);
			while(!s_op.empty()){
				temp.push(s_op.top());
				s_op.pop();
			}
			while(!temp.empty()){
				print_operator += temp.top();

				s_op.push(temp.top());
				temp.pop();
			}
				cout << setw(20) << left << myChar[i] << setw(5) << right << print_operator << setw(20) << right << result << endl;
				print_operator.clear();
		}
		
		else if(myChar[i] == ')'){	// if ')'
			cout << setw(20) << left << myChar[i];

				while(s_op.top() != '('){
					result += s_op.top();
					temp.push(s_op.top());
					s_op.pop();
				}
			print_operator += s_op.top();
			s_op.pop();	// pop the opening parenthesis '('
			while(!temp.empty()){
				s_op.push(temp.top());
				print_operator += temp.top();
				temp.pop();
			}
			
			s_op.pop();	// pop the opening parenthesis '('

			cout << setw(5) << right << print_operator << setw(20) << right << result << endl;
			print_operator.clear();
		}
			
		else{	// if char is an operator
			while(!s_op.empty() && precedence(s_op.top()) >= precedence(myChar[i])){
				result += s_op.top();
				s_op.pop();
			}
			s_op.push(myChar[i]);
			
			while(!s_op.empty()){
				//cout << s_op.top();
				temp.push(s_op.top());
				//print_operator += s_op.top();
				s_op.pop();
			}
			while(!temp.empty()){
				print_operator += temp.top();

				s_op.push(temp.top());
				temp.pop();
			}
			//cout << setw(20) << left << myChar[i];
			cout << setw(20) << left << myChar[i] << setw(5) << right << print_operator << setw(20) << right << result << endl;
			print_operator.clear();
		}
	}
	
	while(!s_op.empty()){
		result += s_op.top();
		print_operator += s_op.top();
		s_op.pop();
	}	
	cout << setw(38) << "Output: " ;
	return result;
}

string toprefix(string myString){
	char myChar[myString.length()];
	strcpy(myChar, myString.c_str());
	
	stack<char> s_op;
	stack<char> temp;
	string print_operator = "";
	string result = "";
	string final_result = "";
	
	cout << "Prefix" << endl;
	cout << "Expression \t\t     Operator\t\t  Operand" << endl;
	
	for(int i = myString.length() - 1; i >= 0 ; i--){
		// if letter
		if(myChar[i] != '*' && myChar[i] != '+' && myChar[i] != '-' && myChar[i] != '/' && myChar[i] != '(' && myChar[i] !=')'){
			result += myChar[i];
			
			
				while(!s_op.empty()){
					temp.push(s_op.top());
					s_op.pop();
				}
			while(!temp.empty()){
				s_op.push(temp.top());
				print_operator += s_op.top();
				temp.pop();
			}
			
			cout << setw(20) << left << myChar[i] << setw(5) << right << print_operator << setw(20) << right << result << endl;
			print_operator.clear();
		}
		//	if operator
		
		else if(myChar[i] == ')'){	// if ')'
			s_op.push(myChar[i]);
			
			while(!s_op.empty()){
				temp.push(s_op.top());
				s_op.pop();
			}
			while(!temp.empty()){
				s_op.push(temp.top());
				print_operator += s_op.top();

				temp.pop();
			}
			cout << setw(20) << left << myChar[i] << setw(5) << right << print_operator << setw(20) << right << result << endl;
			print_operator.clear();
		}
		else if(myChar[i] == '('){	// if '('
			while(s_op.top() != ')'){
				result += s_op.top();
				s_op.pop();
				
			}
			while(!s_op.empty()){
				temp.push(s_op.top());
				s_op.pop();
			}
			while(!temp.empty()){
				print_operator += temp.top();
				s_op.push(temp.top());
				temp.pop();
			}
			s_op.pop();
			
			if(s_op.empty()){
				cout << setw(20) << left << myChar[i] << setw(5) << right << " " << setw(20) << right << result << endl;
			}
			else{
				cout << setw(20) << left << myChar[i] << setw(5) << right << print_operator << setw(20) << right << result << endl;

			}
			print_operator.clear();
		}
		else if((myChar[i] == '*' || myChar[i] == '+' || myChar[i] == '-' || myChar[i] == '/' || myChar[i] == '(' ||myChar[i] ==')')){
			while(!s_op.empty() && precedence(myChar[i]) < precedence(s_op.top())){
				result += s_op.top();
				s_op.pop();
			}

			while(!s_op.empty()){
				temp.push(s_op.top());
				s_op.pop();
			}
			while(!temp.empty()){
				print_operator += temp.top();
				s_op.push(temp.top());
				temp.pop();
			}
			s_op.push(myChar[i]);
			print_operator += myChar[i];

			cout << setw(20) << left << myChar[i] << setw(5) << right << print_operator << setw(20) << right << result << endl;
			print_operator.clear();
		}
	}
	while(!s_op.empty()){
		result += s_op.top();
		s_op.pop();
	}
	reverse(result.begin(), result.end());
	cout << setw(38) << right << "Output: ";
	return result;

}



int precedence (char op){
	if(op == '*') return 4;
	else if (op == '/') return 3;
	else if(op == '+') return 2;
	else if(op == '-') return 1;
	return 0;
}

