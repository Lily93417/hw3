#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <cstddef>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public std::vector<T>
{
public:
    Stack() = default;
    ~Stack() = default;
    bool empty() const {
      return std::vector<T>::empty();
    }
    std::size_t size() const {
      return std::vector<T>::size();
    }
    void push(const T& item) {
      std::vector<T>::push_back(item);
    }
    void pop() {  // throws std::underflow_error if empty
      if (std::vector<T>::empty()) {
        throw std::underflow_error("Stack is empty");
      }

      std::vector<T>::pop_back();
    }  
    const T& top() const { // throws std::underflow_error if empty
      if (std::vector<T>::empty()) {
        throw std::underflow_error("Stack is empty");
      }

      return std::vector<T>::back();

    }
    // Add other members only if necessary
};


#endif