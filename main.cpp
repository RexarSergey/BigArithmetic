#include "BA.h"

int main() {
    std::string operation;
    big_int a;
    big_int b;

    std::cout << "Print first number.\n>> ";
    std::cin >> a;

    std::cout << "Print operation(+, -, *, >, <, >=, <=, ==, !=).\n>> ";
    std::cin >> operation;
    while(std::find(big_int::str_bool_op.begin(), big_int::str_bool_op.end(), operation) == big_int::str_bool_op.end() &&
            std::find(big_int::str_int_op.begin(), big_int::str_int_op.end(), operation) == big_int::str_int_op.end()){
        std::cout << "Incorrect operation.\nYou can use only these operations: +, -, >, <, >=, <=, ==, !=.\n>> ";
        std::cin >> operation;
    }

    std::cout << "Print second number.\n>> ";
    std::cin >> b;

    big_int::functions_map[operation](a, b);
//    if(operation == "+")
//            std::cout << (a + b);
//    else
//        if(operation == "-")
//            std::cout << (a - b);
//    else
//        if(operation == "*")
//            std::cout << (a * b);
//    else
//        if(operation == ">")
//            std::cout << ((a > b) ? "True" : "False");
//    else
//        if(operation == "<")
//            std::cout << ((a < b) ? "True" : "False");
//    else
//        if(operation == ">=")
//            std::cout << ((a >= b) ? "True" : "False");
//    else
//        if(operation == "<=")
//            std::cout << ((a <= b) ? "True" : "False");
//    else
//        if(operation == "==")
//            std::cout << ((a == b) ? "True" : "False");
//    else
//        if(operation == "!=")
//            std::cout << ((a != b) ? "True" : "False");

    return 0;
}
