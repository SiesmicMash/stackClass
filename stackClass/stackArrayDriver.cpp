//
//  stackArrayDriver.cpp
//  stackClass
//
//  Created by Usaid Ali Syed on 2025-02-11.
//

#include <iostream>
#include <string>
#include <cctype>
#include "ArrayStack.hpp"


//Include the source (.cpp) files
#include "ArrayStack.cpp"

using namespace std;
/*

void stackTester(StackInterface<string>* stackPtr){
    
    string items[] = {"zero", "one", "two", "three", "four", "five"};
    cout << "Empty: " << stackPtr->isEmpty() << endl;
    for (int i = 0; i < 6; i++)
    {
        cout<<"Pushing " << items[i] << endl;
        bool success = stackPtr->push(items[i]);
        if (!success)
            cout << "Failed to push " << items[i] << " onto the stack." << endl;
    }

    cout << "Empty?: " << stackPtr->isEmpty() << endl;

    for (int i = 0; i < 5; i++) { // NEEDS TO BE 5 TO AVOID ASSERT ERROR

        cout << "Loop " << i << endl;
        cout << "peek1: " << stackPtr->peek() << endl;
        cout << "pop: " << stackPtr->pop() << endl;
        cout << "Empty: " << stackPtr->isEmpty() << endl;
    }
    cout << "Empty: " << stackPtr->isEmpty() << endl;
    cout << "pop an empty stack: " << endl;
    cout << "pop: " << stackPtr->pop() << endl; // nothing to pop!

    cout << "peek into an empty stack (should fail): " << endl;
    cout << "peek: " << stackPtr->peek() << endl; // nothing to peek!
}


int main(){
    StackInterface<string>* stackPtr = new ArrayStack<string>();
    cout << "Testing the Array-Based Stack:" <<endl;
    stackTester(stackPtr);
    delete stackPtr;

    system("Pause");
    return 0;
}

*/

//Balanced Brace Checker Implementation

bool balancedBraceChecker(const string& s) {
    ArrayStack<char> stackObj;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{') {
            stackObj.push(s[i]);
        } else if (s[i] == '}') {
            if (!stackObj.isEmpty()) {
                stackObj.pop();
            }
            else {
                return false;
            }
        }
    }
    if (stackObj.isEmpty()) {
        return true;
    }
    else {
        return false;
    }
}

//Is special Palindrome implementation

bool isSpecialPallindrome(string& s) {
    ArrayStack<char> stackObj;
    int i = 0;

    while (i < s.length() && s[i] != '$') {
        stackObj.push(s[i]);
        i++;
    }
    
    i++;
    
    while (i < s.length()) {
        if (stackObj.isEmpty()) {
            return false;
        }
        
        else if(s[i] != stackObj.peek()) {
            return false;
        }
        
        else {
            stackObj.pop();
            i++;
        }
    }
    
    return stackObj.isEmpty();
}

bool isSpecialPallindrome2(string& s) {
    
    if (s == "") {              // special case
        return false;
    }
    
    ArrayStack<char>  stackObj;
    
    int i=0;
    for (; i<s.length(); i++) {
        
        if(s[i] == '$') {
            break;
        }
        
        else {
            stackObj.push(s[i]);
        }
        
    }
    i++;
    
    for (; i<s.length(); i++) {
        
        if (stackObj.isEmpty()) {
            return false;
        }
        
        else if(stackObj.peek() != s[i]) {
            return false;
        }
        
        else {
            stackObj.pop();
        }
    }
    return stackObj.isEmpty();
}

//alanced String implementation

// AAAAABBBBBB

bool isBalancedString(string &s) {

    ArrayStack<char> stackObj;
    bool flag = false;
    int i = 0;
    
    while (i < s.length()) {
        if (s[i] == 'A')
        {
            if (!flag)
                stackObj.push(s[i]);
            else
                return false;
        }
        else if (s[i] == 'B')
        {
            if (!flag)
                flag = true;
            if (stackObj.isEmpty())
                return false;
            else
                stackObj.pop();
        }
        else
            return false;
        i++;
    }
    return stackObj.isEmpty();
}

/*
if (s[i] == 'A' && !flag) {
    stackObj.push(s[i]);
    i++;
}
else if (s[i] == 'B' && !flag)
{
    flag = true;
}
else if(s[i] == 'B' && flag) {
    
    if(stackObj.isEmpty()) {
        return false;
    }
    
    else if (stackObj.peek() != 'A') {
        stackObj.pop();
    }
    
}
else  {
    return false;
}


i++;
 */

//Check if a given string is a postfix expression

bool isDigit(const char ch)
{
    return ch >= '0' && ch <= '9';
}
int eval(const int a, const int b, const char ch)
{
    assert(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
    int result = 0;
    switch (ch)
    {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            assert(b != 0);
            result = a / b;
            break;
        case '%':
            assert(b != 0);
            result = a % b;
    }
    return result;
}

int evalPostFixExpression(string& s) {
    ArrayStack<int> stackObj;
    for (int i = 0; i < s.length(); i++)
    {
        if (isDigit(s[i]))
            stackObj.push(s[i] - '0');
        else
        {
            assert(!stackObj.isEmpty());
            int b = stackObj.peek();
            stackObj.pop();
            
            assert(!stackObj.isEmpty());
            int a = stackObj.peek();
            stackObj.pop();
            
            int c = eval(a, b, s[i]);
            stackObj.push(c);
        }
    }
    assert(!stackObj.isEmpty());
    int result = stackObj.peek();
    stackObj.pop();
    assert(stackObj.isEmpty());
    return result;
}
    
    
    /*
    ArrayStack<int> stackObj;
    int x = 0, y = 0;
    int result = 0;
    for (int i = 0; i< s.length(); i++) {
        
        if (isdigit(s[i])) {
            stackObj.push(s[i] - '0');
        }
        
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] != '/') {
            
            if (stackObj.isEmpty()) {
                return false;
            }
            
            x = stackObj.peek();
            stackObj.pop();
            
            if (stackObj.isEmpty()) {
                return false;
            }
            
            y = stackObj.peek();
            stackObj.pop();
            
            switch (s[i]) {
                case '+':
                    result = y + x;
                    break;
                    
                case '-':
                    result = y - x;
                    break;
                    
                case '*':
                    result = y * x;
                    break;
                    
                case '/':
                    if (x == 0) {
                        return false;
                    } else{
                        result = y/x;
                    }
                    break;
            }
            stackObj.push(result);
        }
    }
    if (stackObj.pop() == stackObj.isEmpty()) {
        return true;
    }
    else {
        return false;
    }
    */


/*
int main() {
    string s;
    
    cout << "Please enter a balanced expression";
    cin >> s;
    
    if (isBalancedString(s)) {
        cout << "The string is a balanced expression" << endl;
    }
    else {
        cout << "The string is not a balanced expression" << endl;
    }
    
    return 0;
}*/


int main() {
    string s;
    
    cout << "Please enter a postfix expression";
    cin >> s;
    
    
    
    int result = evalPostFixExpression(s);
    cout << "The postfix is evaluated to " << result << endl;
    
    return 0;
    
}

