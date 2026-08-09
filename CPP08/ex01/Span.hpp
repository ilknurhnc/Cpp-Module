#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span
{
    private:
        unsigned int maxSize;
        std::vector<int> num;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int number);

        template <typename T>
        void addNumber(T begin, T end)
        {
            while (begin != end)
            {
                if (num.size() >= maxSize)
                    throw std::runtime_error("Span is full");

                num.push_back(*begin);
                ++begin;
            }
        }

        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};

#endif