#ifndef BIGARITHMETIC_BIG_INT_H
#define BIGARITHMETIC_BIG_INT_H

#include <iostream>
#include <string>

const int max_len = 20;

struct big_int {

    big_int();
    explicit big_int(const std::string_view& str);
    big_int(const big_int& bigInt);
    big_int(big_int&& bigInt) noexcept;
    ~big_int();

    big_int& operator=(const big_int &that);

    std::string toString();
    void levelUp();

    big_int operator+() const;
    big_int operator-() const;

    big_int abs() const;

    bool operator==(const big_int &that);
    bool operator!=(const big_int &that);
    bool operator>(const big_int &that);
    bool operator<(const big_int &that);
    bool operator>=(const big_int &that);
    bool operator<=(const big_int &that);

    big_int operator+(const int &that);
    big_int operator+(const big_int &that);
    big_int operator-(const big_int &that);
    big_int operator*(const int &that);
    big_int operator*(const big_int &that);
    big_int operator/(const int &that);
    int operator%(const int &that);
    big_int operator/(const big_int &that);

private:
    int length_ = 0;
    //todo:change into dynamic
    int digits_[max_len];
    bool is_negative_ = false;
};


#endif //BIGARITHMETIC_BIG_INT_H
