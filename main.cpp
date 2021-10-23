#include "BA.h"

int main() {
    big_int a("1000");
    big_int b("1");

    big_int c = a-b;

    std::cout << ((a-b) == big_int("999"));

    return 0;
}
