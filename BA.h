#ifndef BIGARITHMETIC_BA_H
#define BIGARITHMETIC_BA_H

#include <iostream>
#include <vector>

class big_int{
public:
    explicit big_int(const std::string_view &number);
    big_int(const big_int &number);
    big_int(big_int &&number) noexcept ;
    big_int();
    ~big_int();

    big_int& operator=(const big_int &that);

    big_int operator+() const;
    big_int operator-() const;

    bool operator>(const big_int &that);
    bool operator<(const big_int &that);

    bool operator>=(const big_int &that);
    bool operator<=(const big_int &that);

    bool operator==(const big_int &that);
    bool operator!=(const big_int &that);


    big_int operator+(const big_int &that);

private:
    std::vector<uint8_t> number_;
    bool is_negative_ = false;

    void delete_first_zeros();
    bool is_digit(const std::string_view &str);
};


#endif //BIGARITHMETIC_BA_H
