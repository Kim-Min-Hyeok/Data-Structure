/*On my honor, I pledge that I have neither received nor provided
improper assistance in the completion of this programming assignment.
Signed: 김민혁*/
// infix.cpp :
//
// The program evaluates a given infix expression which is fully parenthesized.
// It uses Dijkstra's two-stack algorithm. For simplicity of coding, however,
// the expression is to be fully parenthesized.
// For example:
//   ((3 - 1 ) * 5) + 4
//   2 * ((34 - 4) * 2)
//   1 + (((12 * 2) / 4) - 1)
//
// Author: idebtor@gmail.com
// 2020.04.05	created and assert() added
// 2020.04.08	for testing purpose, the basic stack with member functions added
//
#include <iostream>
#include <cassert>
// #include <stack>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#if 1
/////////////////////////////////////////////////////////////////////////////////
// a basic stack functinality only provided for pedagogical purpose
// To use STL stack, just comment out this section and inclucde <stack> above.
#include <vector>
template <typename T>
struct stack {
	vector<T> item;

	bool empty() const {
		return item.empty();
	}
	auto size() const {
		return item.size();
	}
	void push(T const& data) {
		item.push_back(data);
	}
	void pop() {
		if (item.empty())
			throw out_of_range("stack<>::pop(): pop stack");
		item.pop_back();
	}
	T top() const {
		if (item.empty())
			throw out_of_range("stack<>::top(): top stack");
		return item.back();
	}
};
///////////////////////////////////////////////////////////////////////
#endif

// Stay tuned since we are going to use C++ Template to make them into
// one or a generic function.
template <typename T>
void printStack(stack<T> s) {
	stack<T> temp;
	while(!s.empty()){
		temp.push(s.top());
		s.pop();
	}
	while(!temp.empty()){
		cout << temp.top();
		s.push(temp.top());
		temp.pop();
	}
}

// performs arithmetic operations.
int apply_op(int a, int b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	case '^': int power=1;
						for(int i=b; i>0; i--) power*=a;
						return power;
	}
	cout << "Unsupported operator encountered: " << op << endl;
	return 0;
}

// there is a bug ...
int compute(stack<int>& va_stack, stack<char>& op_stack) {
	int right  = va_stack.top(); va_stack.pop();
	int left = va_stack.top(); va_stack.pop();
	char op = op_stack.top(); op_stack.pop();
	int answer = apply_op(left, right, op);
	DPRINT(cout << " va/op_stack.pop: " << left << op << right << " = " << answer << endl;);
	return answer;
}
int precedence(int op) {
	if (op == '(') return 0;
  if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	if (op == '^') return 3;
	else return 4;
}

// returns value of expression after evaluation.
int evaluate(string token) {
	DPRINT(cout << ">evaluate: token=" << token << endl;);
	stack<int>  va_stack;                 // stack to store operands or values
	stack<char> op_stack;                 // stack to store operators.

	for (int i = 0; i < token.length(); i++) {
		DPRINT(cout << " token[" << i << "]=" << token[i] << endl;);

		// current token is a whitespace or an opening brace, skip it.
		if (token[i] == ' ') continue;
		else if(token[i] == '(') {
			op_stack.push(token[i]);
 			DPRINT(cout << " op_stack.push: " << token[i] << endl;);
		}
		// current token is a value(or operand), push it to va_stack.
		else if(isdigit(token[i])) {
			int va = 0;
			// add the code to handle multi-digits val
						while(isdigit(token[i]))
            {
            va = va * 10 + (int)(token[i] - '0');
                i++;
            }
            i--;

            //push the element in the stack
            va_stack.push(va);
			DPRINT(cout << " va_stack.push: " << va << endl;);
		} // closing brace encountered; compute it and push the result to va_stack.
		else if (token[i] == ')') {
			while(op_stack.top()!='('){
			int answer = compute(va_stack, op_stack);
			va_stack.push(answer);
			DPRINT(cout << " va_stack.push: " << answer << endl;);
			}
			op_stack.pop();
		}
		else { // current token is an operator; push it to op_stack.
			char thisOp = token[i];
			while(!op_stack.empty()&&precedence(op_stack.top())>=precedence(thisOp)){
			int answer = compute(va_stack, op_stack);
			va_stack.push(answer);
		  }
			op_stack.push(thisOp);
			DPRINT(cout << " op_stack.push: " << thisOp << endl;);
		}
	}

	DPRINT(cout << "Token is cleared. Now, check two stacks:" << endl;);
	DPRINT(printStack(va_stack);  cout << endl;);
	DPRINT(printStack(op_stack);  cout << endl;);

	// The whole expression has been parsed at this point,
	// apply remaining op_stack to remaining va_stack.
	while (!op_stack.empty()) {
		int answer = compute(va_stack, op_stack);
		va_stack.push(answer);
	}

	// use two post-conditions for assertion
	cout << "your code here to check two post-conditions\n";


	assert(va_stack.size()==1);
	assert(op_stack.size()==0);

	// va_stack top contains the result, return it.
	DPRINT(cout << "<evaluate" << endl;);
	return va_stack.top();
}
