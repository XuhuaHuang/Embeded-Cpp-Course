/**
 * @file template_notes.cpp
 * @author Xuhua Huang
 * @brief Notes on template. Used as a quick reference guide.
 * @version 0.1
 * @date 2022-02-04
 * Last updated on Dec 02, 2022
 * 
 * "Lift algorithms and data structures from concrete examples
 * to their most general and abastract form." - Bjarne Stroustrup
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <stdlib.h>
#include <type_traits>
#include <vector>

#ifndef BUILD_COMPARE(TYPE)
#define BUILD_COMPARE(TYPE)                             \
    int cmp_ ## TYPE(const void* va, const void* vb)    \
    {                                                   \
        TYPE const* pa = static_cast<TYPE const*>(va);  \
        TYPE const* pb = static_cast<TYPE const*>(vb);  \
                                                        \
        if (*pa < *pb)          return -1;              \
        else if (*pa == *pb)    return 0;               \
        else                    return 1;               \
    }
#endif

BUILD_COMPARE(float)
BUILD_COMPARE(double)

/* ------------------ */
/* Function Templates */
/* ------------------ */
template<typename T>
T const& min(T const& a, T const& b) {
    return (a < b) ? a : b;
}

/* --------------- */
/* Class Templates */
/* --------------- */
template<typename T, size_t N>
struct array {
    /*...*/
};

/* ------------------------------ */
/* Variable Templates since C++14 */
/* ------------------------------ */
template<typename T>
inline constexpr T pi = T(3.14159265359L);
// compile-time constant
// require a type that is convertible from long double
// double my_pi = pi<double>;

template<typename T>
T circular_area(T r) {
    return pi<T> * r * r;
}

// wrapper around is_arithmetic from <type_trait> library
template<typename T>
inline constexpr size_t is_arithmetic_v = std::is_arithmetic<T>::value;

/* ---------------------------- */
/* Lambda Templates since C++20 */
/* ---------------------------- */
auto multiply = []<typename T>(T a, T b) -> T {
    return a * b;
};

/* ----------------------- */
/* Define a Stack template */
/* ----------------------- */
template<typename T>
class Stack {
private:
    std::vector<T> m_data;
    
    // inline static member since C++17
    // in-place definition using inline
    inline static int m_count = 0;

public:
    // template type deduction dependent -> typename keyword is required
    using const_iterator = typename std::vector<T>::const_iterator;

    const_iterator begin() const;
    const_iterator end() const;
    bool is_empty() const;

    T const& top() const;

    void pop();
    void push(const T& t);
    Stack push_all_from(const Stack& stack);
    Stack();
};

template<class T>
auto Stack<T>::begin() const -> const_iterator {
    return m_data.crbegin();
    // std::vector::crbegin() to return the end of the vector
    // i.e. top of the stack
}

/* -------------------------------------------- */
/* Explicit Partial Specialization for Pointers */
/* -------------------------------------------- */
template<typename T>
class Stack<T*> {
private:
    std::vector<T*> m_data;
    inline static int m_count = 0;

public:
    using const_iterator = typename std::vector<T*>::const_iterator;

    Stack() = default;

    const_iterator begin() const;
    const_iterator end() const;
    bool is_empty() const { return m_data.empty(); }

    /* Specialized function */
    T* top() const;
    T* pop();

    void push(const T& t);
    void push(T* t) {
        m_data.push_back(t);
    }

    Stack push_all_from(const Stack& stack);

    Stack(T* pt) {
        if (pt!=nullptr)
            this->m_data.push_back(pt);
    }
};

template<typename T>
T* Stack<T*>::top() const {
    if (!is_empty())
        return m_data.back();
    return nullptr;
}

template<typename T>
T* Stack<T*>::pop() {
    if (!is_empty()) {
        T* tmp = m_data.back();
        m_data.pop_back();
        return tmp;
    }
    return nullptr;
}

int main(void) {
    Stack<typename std::string*> pstrstack{};

    std::string* greetings = new std::string("Hello, world");
    pstrstack.push(greetings);
    std::cout << static_cast<std::string>(*pstrstack.pop()) << "\n";

    delete pstrstack.pop();

    std::cin.get();
    return 0;
}
