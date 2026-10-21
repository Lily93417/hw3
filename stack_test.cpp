#include <iostream>
#include <string>
#include "stack.h"

int main()
{
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Size: " << s.size() << std::endl;
    std::cout << "Top: " << s.top() << std::endl;

    s.pop();

    std::cout << "Top after pop: " << s.top() << std::endl;

    Stack<std::string> words;
    words.push("hello");
    words.push("world");

    std::cout << "String top: " << words.top() << std::endl;

    Stack<int> emptyStack;

    try {
        emptyStack.pop();
    } catch (const std::underflow_error& e) {
        std::cout << "Caught error: " << e.what() << std::endl;
    }

    return 0;
}