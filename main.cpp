#include <iostream>
#include <functional>
#include <map>
#include "BA.h"

typedef void (*void_func)();

void sum(big_int& a, big_int& b){
    std::cout << (a+b).toString();
}
void dif(big_int& a, big_int& b){
    std::cout <<  (a-b).toString();
}
void mul(big_int& a, big_int& b){
    std::cout <<  (a*b).toString();
}

int main() {
    std::map<std::string, void_func> map;
    map["+"] = (void_func) &sum;
    map["-"] = (void_func) &dif;
    map["*"] = (void_func) &mul;


    ((void(*)(big_int, big_int)) map["*"])(big_int("99999"), big_int("9999"));

//    std::string a_str, operation, b_str;
//    std::cin >> a_str;
//    big_int a(a_str);
//
//    std::cin >> operation;
//
//    std::cin >> b_str;
//    big_int b(b_str);
//
//    ((void(*)(big_int, big_int)) map[operation])(a, b);

    return 0;
}
