#include "BA.h"

int main() {
    big_int a("-1234567891011");
    big_int b("-123456789");

    std::cout << ((a+b) == big_int("-1234691347800"));

    return 0;
}
