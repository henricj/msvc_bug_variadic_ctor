// TemplatePack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <type_traits>

// Argument check pilfered from https://stackoverflow.com/a/39659128

class Test1 final {
public:
    template<typename... Parameters, class Enable = std::enable_if_t<(... && std::is_convertible_v<Parameters, int>)>>
    Test1(Parameters&&... parameters)
    { }
};

class Test2 final {
public:
    template<typename... Parameters>
    Test2(Parameters&&... parameters)
    { }
};


Test1* f(int c)
{
    auto test = new Test1(c);

    return test;
}

Test2* g(int c)
{
    auto test = new Test2(c);

    return test;
}

int main()
{
    volatile auto arg = 123;
    volatile auto x = f(arg);
    volatile auto y = g(arg);

    return 0;
}

