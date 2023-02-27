#ifndef STACK_H
#define STACK_H


#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
public:
    Stack(){}
    ~Stack(){}

    bool empty() const{
        return data.empty();
    }
    size_t size() const{
        return data.size();
    }
    void push(const T& item){
        data.push_back(item);
    }
    void pop(){  // throws std::underflow_error if empty
        if(empty()){
            throw std::underflow_error("Empty stack");
        }
        data.pop_back();
    }
    const T& top() const{ // throws std::underflow_error if empty
        if(empty()){
            throw std::underflow_error("Empty stack");
        }
        return data.back();
    }
    // Add other members only if necessary
    std::vector<T> data;
};


#endif