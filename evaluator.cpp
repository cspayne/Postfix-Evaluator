#include "evaluator.h"
#include <stack>
#include <string>
#include <iostream>
#include <cmath>
#include <sstream>
using std::stack; 

double Evaluate(const string& postfix, bool& error){
	//Start with an empty stack.  We scan P from left to right.
	stack<double> myStack; 
	string toPush = ""; 
	int inStack = 0; 
	
	for(size_t i = 0; i < postfix.size(); i++){
		if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '/' || postfix[i] == '*'
			|| postfix[i] == '^'){
			if (inStack < 2){
				error = 1; 
				return error; 
			}
			double a,b, retval = 0; 
			a = myStack.top();  
			myStack.pop();
		 	b = myStack.top(); 
			myStack.pop();
			if (postfix[i] == '+'){
				retval = b + a; 
			}
			if (postfix[i] == '-'){
				retval = b - a; 
			} 	
			if (postfix[i] == '/'){
				retval = b / a; 
			}
			if (postfix[i] == '*'){
				retval = b * a; 
			}
			else if (postfix[i] == '^'){
				retval = pow(b, a); 
			}
			myStack.push(retval); 	
		}
		else if (postfix[i] == ' '){
			if (toPush != ""){
			double forStack = stod(toPush); 	
			myStack.push(forStack); 
			inStack++; 
			toPush = ""; 
			}
		}
		else if (postfix[i] == '0' || postfix[i] == '1' || postfix[i] == '2' || postfix[i] == '3' || postfix[i] == '4' || postfix[i] == '5' 
			|| postfix[i] == '6' || postfix[i] == '7' || postfix[i] == '8' || postfix[i] == '9' || postfix[i] == '.'){
			toPush = toPush + postfix[i]; 
		}
		else {
			error = 1; 
			return error; 
		}
		}
    double toReturn = myStack.top(); 
    myStack.pop(); 
    error = 0; 
    return toReturn; 
}

