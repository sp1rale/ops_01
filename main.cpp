#include <iostream>

using namespace std;

class CharStack {
private:
    char* stackArray;
    int maxSize;
    int top;

public:
    CharStack(int size) : maxSize(size), top(-1) {
        stackArray = new char[maxSize];
    }

    ~CharStack() {
        delete[] stackArray;
    }

    void push(char c) {
        if (top < maxSize - 1) {
            stackArray[++top] = c;
            cout << "Pushed: " << c << endl;
        }
        else {
           cerr << "Stack overflow. Unable to push." << endl;
        }
    }

    void pop() {
        if (!isEmpty()) {
            cout << "Popped: " << stackArray[top--] << endl;
        }
        else {
            cerr << "Stack is empty. Unable to pop." << endl;
        }
    }

    int size() const {
        return top + 1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == maxSize - 1;
    }

    void clear() {
        top = -1;
        cout << "Stack cleared." << endl;
    }

    char peek() const {
        if (!isEmpty()) {
            return stackArray[top];
        }
        else {
            cerr << "Stack is empty. Unable to peek." << endl;
            return '\0'; 
        }
    }
};

int main() {
    CharStack charStack(5);

    charStack.push('A');
    charStack.push('B');
    charStack.push('C');

    cout << "Stack size: " << charStack.size() << endl;
    cout << "Top element: " << charStack.peek() << endl;

    charStack.pop();
    charStack.pop();

    cout << "Is stack empty? " << (charStack.isEmpty() ? "Yes" : "No") << endl;

    charStack.clear();

    cout << "Is stack full? " << (charStack.isFull() ? "Yes" : "No") << endl;

    return 0;
}

