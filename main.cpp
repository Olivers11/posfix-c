#include <stack>
#include <iostream>
using namespace std;

char operators[7] = {'+', '-', '*', '/', '(', ')', '^'};

int priority(char ch){
  if(ch == '+' || ch == '-'){
    return 1;
  }
  else if(ch == '*' || ch == '/'){
    return 2;
  }
  else if(ch == '^'){
    return 3;
  }
  return 0;
}


bool isOP(char ch){
  for(char c : operators){
    if(c == ch)return true;
  }
  return false;
}

string infixToPosfix(string expression){
  string output = "";
  stack<char> stack;
  for(char ch: expression){
    if(!isOP(ch)){
      output += ch;
    }
    else if (ch == '('){
      stack.push(ch);
    }
    else if(ch == ')'){
      while(stack.top() != '('){
	output += stack.top();
	stack.pop();
      }
      stack.pop();
    }
    else{
      while(!stack.empty() && priority(ch) <= priority(stack.top())){
	output += stack.top();
	stack.pop();
      }
      stack.push(ch);
    }
  }
  while(!stack.empty()){
    output += stack.top();
    stack.pop();
  }
  return output;
}


int main(){
  string input;
  cout << "Enter a expression: ";
  cin >> input;
  string result = infixToPosfix(input);
  cout << "Result: " << result << endl;
}
