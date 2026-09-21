#include "RPN.hpp"

#include <sstream>
#include <iostream>
#include <cctype>

RPN::RPN(){}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _stack = other._stack;

    return *this;
}

RPN::~RPN(){}

bool RPN::isOperator(const std::string& token) const
{
    if (token.length() != 1)
        return false;

    return (token[0] == '+'
        || token[0] == '-'
        || token[0] == '*'
        || token[0] == '/');
}

bool RPN::applyOperator(char op)
{
    if (_stack.size() < 2)
        return false;

    int right = _stack.top();
    _stack.pop();

    int left = _stack.top();
    _stack.pop();

    int result;

    if (op == '+')
        result = left + right;
    else if (op == '-')
        result = left - right;
    else if (op == '*')
        result = left * right;
    else if (op == '/')
    {
        if (right == 0)
            return false;

        result = left / right;
    }
    else
        return false;

    _stack.push(result);

    return true;
}

bool RPN::calculate(const std::string& expression)
{
    while (!_stack.empty())
        _stack.pop();

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (token.length() == 1
            && std::isdigit(static_cast<unsigned char>(token[0])))
        {
            _stack.push(token[0] - '0');
        }
        else if (isOperator(token))
        {
            if (!applyOperator(token[0]))
                return false;
        }
        else
            return false;
    }

    if (_stack.size() != 1)
        return false;

    std::cout << _stack.top() << std::endl;

    return true;
}