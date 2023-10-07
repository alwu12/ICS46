#include <iostream>
#include "LLStack.hpp"
#include <iostream>

// Note:  you are not required to implement a main() for this project.
//      Feel free to create one; it will not be accounted for in grading.
//      Be sure to use the unit testing process to test your code: that is
//      how we will be grading. 

int main()
{   
    LLStack<int> x;
    x.push(15);
    const LLStack<int> y(x);
    x.push(10);
    std::cout << x.top() << std::endl;
    std::cout << y.top() << std::endl;
    std::cout << x.size() << std::endl;
    std::cout << y.size() << std::endl;
    return 0;
}



