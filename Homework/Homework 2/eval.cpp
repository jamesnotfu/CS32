#include <iostream>
#include <stack>
#include <string>
using namespace std;

// helper functions for evaluate
bool convertToPostfix(string infix, string& postfix);
char next(string s, size_t k);

int evaluate(string infix, string& postfix, bool& result){
    // Evaluates a boolean expression
    //   If infix is a syntactically valid infix boolean expression,
    //   then set postfix to the postfix form of that expression, set
    //   result to the value of the expression, and return zero.
    if (convertToPostfix(infix, postfix)){
        stack<bool> operand;
        for (size_t i = 0; i < postfix.size(); i++){
            if (postfix[i] == 'T' || postfix[i] == 'F'){
                switch(postfix[i]){
                    case 'T':
                        operand.push(true);
                        break;
                    case 'F':
                        operand.push(false);
                        break;
                }
            }
            else if (postfix[i] == '&' || postfix[i] == '|') {
                bool operand2 = operand.top();
                operand.pop();
                bool operand1 = operand.top();
                operand.pop();
                switch(postfix[i]){
                    case '&':
                        operand.push(operand1 & operand2);
                        break;
                    case '|':
                        operand.push(operand1 | operand2);
                        break;
                }
            }
            else {
                bool operand1 = operand.top();
                operand.pop();
                operand.push(!operand1);
            }
        }
        result = operand.top();
        return 0;
    }
    //   If infix is not a syntactically valid expression, return 1; in
    //   that case, postfix may or may not be changed, but result must
    //   be unchanged.
    return 1;
}


char next(string s, size_t i){
    // determine if there is a next character by iterating i, otherwise exit and return '0' char
    i++;
    while (i < s.size() && s[i] == ' '){
        i++;
    }
    // no next character or blank
    if (i == s.size()){
        return '0';
    }
    // return next character
    return s[i];
}


bool convertToPostfix(string infix, string& postfix){
    postfix = "";
    stack<char> oper;
    // stack to hold/handle operators
    stack<char> operand;
    // stack to hold/handle parentheses
    stack<char> parentheses;
    for (size_t i = 0; i < infix.size(); i++){
        switch(infix[i]){
            case 'T':
            case 'F': {
                operand.push(infix[i]);
                char n = next(infix, i);
                if (n == '&' || n == '|' || n == ')' || n == '0'){
                    postfix += infix[i];
                    break;
                }
                return false;
            }
            case '!':
            case '(': {
                if (infix[i] == '('){
                    parentheses.push(infix[i]);
                }
                char n = next(infix, i);
                if (n == 'T' || n == 'F' || n == '(' || n == '!'){
                    oper.push(infix[i]);
                    break;
                }
                return false;
            }
            case ')': {
                if (parentheses.empty()){
                    return false;
                }
                else {
                    parentheses.pop();
                }
                char n = next(infix, i);
                if (n == '&' || n == '|' || n == '0' || n == ')'){
                    while(oper.top() != '('){
                        postfix += oper.top();
                        oper.pop();
                    }
                    oper.pop();
                    break;
                }
                return false;
            }
                
            case '&':
            case '|': {
                char n = next(infix, i);
                if (n == 'T' || n == 'F' || n == '(' || n == '!'){
                    while (!oper.empty() && oper.top() != '(' && infix[i] != '!' && (infix[i] == '|' || (infix[i] == '&' && oper.top() != '|')))
                    {
                        postfix += oper.top();
                        oper.pop();
                    }
                    oper.push(infix[i]);
                    break;
                }
                return false;
            }
            case ' ':{
                break;
            }
            default:
                return false;
                break;
        }
        
    }
    
    while (!oper.empty()){
        postfix += oper.top();
        oper.pop();
    }
    
    if (operand.empty() || parentheses.size() > 0){
        return false;
    }
    
    return true;
}

//int main()
//{
//    string pf;
//    bool answer;
//    assert(evaluate("T| F", pf, answer) == 0  &&  pf == "TF|"  &&  answer);
//    assert(evaluate("T|", pf, answer) == 1);
//    assert(evaluate("F F", pf, answer) == 1);
//    assert(evaluate("TF", pf, answer) == 1);
//    assert(evaluate("()", pf, answer) == 1);
//    assert(evaluate("()T", pf, answer) == 1);
//    assert(evaluate("T(F|T)", pf, answer) == 1);
//    assert(evaluate("T(&T)", pf, answer) == 1);
//    assert(evaluate("(T&(F|F)", pf, answer) == 1);
//    assert(evaluate("T+F", pf, answer) == 1);
//    assert(evaluate("", pf, answer) == 1);
//    assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0
//                           &&  pf == "FF!TF&&|"  &&  !answer);
//    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
//    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
//    cout << "Passed all tests" << endl;
//}
