#include <iostream>
#include "big_int.h"

int main() {

    big_int a("122");
    big_int b("11");

    std::cout << (a/b).toString();

    return 0;
}
