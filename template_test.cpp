#include <iostream>
using namespace std;

template<int num>
struct fib {
    enum {
        result = fib<num-1>::result + fib<num-2>::result
    };
};

template<>
struct fib<0> {
    enum {
        result = 1
    };
};

template<>
struct fib<1> {
    enum {
        result = 1
    };
};

template<int num>
struct TemplateCal {
    enum {
        result = TemplateCal<num - 1>::result + num
    };
};

template<>
struct TemplateCal<1> {
    enum {
        result = 1
    };
};

template<int X>
constexpr int fact()
{
    return X * fact<X - 1>();
}

template <>
constexpr int fact<0>()
{
    return 1;
}

int main() {
    cout<<fib<1>::result<<endl;
    cout<<fib<2>::result<<endl;
    cout<<fib<3>::result<<endl;
    cout<<fib<4>::result<<endl;
    cout<<fib<5>::result<<endl;
    cout<<fib<6>::result<<endl;
    ///...
    cout<<fib<20>::result<<endl;

    cout << "TemplateCal: " << TemplateCal<1>::result << endl;
    cout << "TemplateCal: " << TemplateCal<4>::result << endl;
    
    cout << "fact<5>(): " << fact<5>() << endl;

    return 0;
}




