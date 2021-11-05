#include <cstring>
#include "big_int.h"

bool is_digit(const std::string_view &str) {
    if (str[0] == '-')
        return str.substr(1, str.size() - 1).find_first_not_of("0123456789") == std::string_view::npos;
    return str.find_first_not_of("0123456789") == std::string_view::npos;
}


big_int::big_int() = default;

big_int::big_int(const std::string_view& str) {
    if(!is_digit(str))
        throw std::invalid_argument("It is not a number.");

    std::memset(digits_, 0, sizeof(digits_));

    int end = 0;
    if(str[0] == '-'){
        end = 1;
        is_negative_ = true;
    }


    int index = 0;
    //Why it doesn't work with "size_t i"?
    for (int i = str.size() - 1; i >= end; --i) {
        digits_[index++] = str[i] - '0';
    }
    length_ = str.size();
}

//big_int::big_int(const big_int &bigInt) : length_(bigInt.length_), is_negative_(bigInt.is_negative_){
//    std::memset(digits_, 0, sizeof(digits_));
//    for (int i = 0; i < bigInt.length_; ++i) {
//        digits_[i] = bigInt.digits_[i];
//    }
//};

big_int::big_int(const big_int &bigInt) = default;

big_int::big_int(big_int &&bigInt)  noexcept = default;

big_int::~big_int() = default;


big_int &big_int::operator=(const big_int &that) = default;


std::string big_int::toString() {
    std::string str = "";
    for (int i = length_ - 1; i >= 0; --i)
        str += std::to_string(digits_[i]);
    if (is_negative_)
        str = '-' + str;

    return str;
}

void big_int::levelUp() {
    for (int i = length_; i >= 1; --i) {
        digits_[i] = digits_[i - 1];
    }
    if(digits_[length_])
        length_++;
}


big_int big_int::operator+() const {
    return *this;
}

big_int big_int::operator-() const {
    big_int res = *this;
    res.is_negative_ = !res.is_negative_;
    return res;
}


big_int big_int::abs() const {
    big_int res = *this;
    res.is_negative_ = true;
    return res;
}


bool big_int::operator==(const big_int &that) {
    if(is_negative_ != that.is_negative_ ||
        length_ != that.length_)
        return false;

    for (size_t i = 0; i < length_; ++i) {
        if(digits_[i] != that.digits_[i])
            return false;
    }

    return true;
}

bool big_int::operator!=(const big_int &that) {
    return !(*this == that);
}

bool big_int::operator>(const big_int &that) {
    if(is_negative_ != that.is_negative_)
        return !is_negative_;

    if(length_ != that.length_)
        return length_ > that.length_;

    for (int i = length_ - 1; i >= 0; --i) {
        if(digits_[i] != that.digits_[i])
            return digits_[i] > that.digits_[i];
    }
    return false;
}

bool big_int::operator<(const big_int &that) {
    if(is_negative_ != that.is_negative_)
        return is_negative_;

    if(length_ != that.length_)
        return length_ < that.length_;

    for (int i = length_ - 1; i >= 0; --i) {
        if(digits_[i] != that.digits_[i])
            return digits_[i] < that.digits_[i];
    }
    return false;
}

bool big_int::operator>=(const big_int &that) {
    return (*this == that) || (*this > that);
}

bool big_int::operator<=(const big_int &that) {
    return (*this == that) || (*this < that);
}


//todo: for all integral numbers and sign
big_int big_int::operator+(const int &that) {
    big_int res = *this;
    int index = 0;
    res.digits_[0] += that;

    while(res.digits_[index] >= 10){
        res.digits_[index + 1]++;
        res.digits_[index++] -= 10;
    }

    return res;
}

big_int big_int::operator+(const big_int &that) {
    big_int res;

    if(is_negative_)
        if(that.is_negative_)
            res.is_negative_ = true;
        else
            res.is_negative_ = this->abs() > that;
    else
        if(that.is_negative_)
            res.is_negative_ = *this < that.abs();
        else
            res.is_negative_ = false;

    res.length_ = std::max(length_, that.length_);

    int next = 0;
    for (size_t i = 0; i < res.length_ || next; ++i) {
        res.digits_[i] = digits_[i] + that.digits_[i] + next;
        next = res.digits_[i] >= 10;
        if(next)
            res.digits_[i] %= 10;
    }

    if(res.digits_[res.length_])
        res.length_++;

    return res;
}

big_int big_int::operator-(const big_int &that) {
    big_int res, num;

    if(this->abs() >= that.abs()){
        res = *this;
        num = that;
    }
    else{
        res = that;
        num = *this;
    }

    if(is_negative_)
        if(that.is_negative_)
            res.is_negative_ = this->abs() > that.abs();
        else
            return -(this->abs() + that);
    else
        if(that.is_negative_)
            return *this + that.abs();
        else
            res.is_negative_ = *this < that;



    for (size_t i = 0; i < res.length_; ++i) {
        res.digits_[i] -= num.digits_[i];
        if(res.digits_[i] < 0){
            res.digits_[i] += 10;
            res.digits_[i + 1]--;
        }
    }

    int new_length = res.length_;
    while(new_length && !res.digits_[new_length-1])
        new_length--;
    res.length_ = new_length;

    return res;
}

//todo: for all integral numbers and sign
big_int big_int::operator*(const int &that) {
    big_int res;
    res.length_ = length_;

    int next = 0;
    for (size_t i = 0; i < res.length_ || next; ++i) {
        res.digits_[i] = digits_[i] * that + next;
        next = res.digits_[i] / 10;
        res.digits_[i] %= 10;
    }
    while(res.digits_[res.length_])
        res.length_++;

    return res;
}

big_int big_int::operator*(const big_int &that) {
    big_int res;
    res.length_ = length_ + that.length_;
    res.is_negative_ = is_negative_ != that.is_negative_;

    for (size_t i = 0; i < length_; ++i) {
        for (size_t j = 0; j < that.length_; ++j) {
            res.digits_[i + j] += digits_[i] * that.digits_[j];
            res.digits_[i + j + 1] += res.digits_[i + j] / 10;
            res.digits_[i + j] %= 10;
        }
    }

    while(res.length_>0 && !res.digits_[res.length_ - 1])
        res.length_--;

    return res;
}

big_int big_int::operator/(const int &that) {
    big_int res;
    res.length_ = length_;

    int ost = 0;
    //size_t didn't work again
    for (int i = res.length_-1; i >= 0; --i) {
        int cur = ost * 10 + digits_[i];
        res.digits_[i] = cur / that;
        ost = cur % that;
    }

    if(!res.digits_[res.length_ - 1] && res.length_ != 1)
        res.length_--;

    return res;
}

int big_int::operator%(const int &that) {

    int ost = 0;
    //size_t didn't work again
    for (int i = length_-1; i >= 0; --i) {
        int cur = ost * 10 + digits_[i];
        ost = cur % that;
    }

    return ost;
}

big_int big_int::operator/(const big_int &that) {
    big_int res;
    big_int curV;
    big_int c(that);
    for (int i = length_ - 1; i >= 0 ; --i) {
        curV.levelUp();
        curV.digits_[0] = digits_[i];

        int x = 0;
        int l = 0;
        int r = 10;
        while(l <= r){
            int m = (l + r) >> 1;
            big_int cur = c * m;
            if(cur <= curV){
                x = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        res.digits_[i] = x;
        curV = curV - c * x;
    }

    while(res.length_ > 0 && !res.digits_[res.length_ - 1])
        res.length_--;

    return res;
}


