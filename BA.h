#ifndef BIGARITHMETIC_BA_H
#define BIGARITHMETIC_BA_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

class big_int{
public:
    big_int(const std::vector<int> &number, bool sign);
    big_int(const std::string &number);
    big_int(const big_int &number);
    big_int();
    ~big_int();

    friend std::ostream& operator<<(std::ostream &out, const big_int &bi);
    friend std::istream & operator>>(std::istream &in, big_int &bi);

    big_int& operator=(const big_int &that);

    friend const big_int& operator+(const big_int &a);
    friend const big_int operator-(const big_int &a);

    friend const big_int operator+(const big_int &a, const big_int &b);
    friend const big_int operator-(const big_int &a, const big_int &b);
    friend const big_int operator*(const big_int &a, const big_int &b);

    friend bool operator>(const big_int &a, const big_int &b);
    friend bool operator<(const big_int &a, const big_int &b);

    friend bool operator>=(const big_int &a, const big_int &b);
    friend bool operator<=(const big_int &a, const big_int &b);

    friend bool operator==(const big_int &a, const big_int &b);
    friend bool operator!=(const big_int &a, const big_int &b);

    static const std::vector<std::string> str_bool_op;
    static const std::vector<std::string> str_int_op;

//    static std::map<std::string, void (*)(big_int, big_int)> functions_map;
private:
    std::vector<int> number;
    bool is_negative = false;

    void delete_first_zeros();
    static bool is_digit(const std::string &str);
};


#endif //BIGARITHMETIC_BA_H
