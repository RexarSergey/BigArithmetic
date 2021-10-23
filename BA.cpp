#include "BA.h"


big_int::big_int(const std::string_view &number) {
    if (!big_int::is_digit(number))
        throw std::invalid_argument("It's not a number.");

    int end = 0;
    if (number[0] == '-') {
        is_negative_ = true;
        ++end;
    }

    for (size_t i = number.size(); i > end; --i) {
        this->number_.push_back((int) number[i - 1] - '0');
    }

    delete_first_zeros();
}

big_int::big_int(const big_int &number) = default;

big_int::big_int(big_int &&number) noexcept = default;

big_int::big_int() = default;

big_int::~big_int() = default;


void big_int::delete_first_zeros() {
    size_t index = number_.size();
    while (number_.size() > 1 && number_[--index] == 0)
        number_.pop_back();
}

bool big_int::is_digit(const std::string_view &str) {
    if (str[0] == '-')
        return str.substr(1, str.size() - 1).find_first_not_of("0123456789") == std::string_view::npos;
    return str.find_first_not_of("0123456789") == std::string_view::npos;
}


big_int &big_int::operator=(const big_int &that) = default;


big_int big_int::operator+() const {
    return *this;
}

big_int big_int::operator-() const {
    big_int bigInt = *this;
    bigInt.is_negative_ = !is_negative_;
    return bigInt;
}


big_int big_int::abs() const {
    big_int result(*this);
    result.is_negative_ = false;

    return result;
}


bool big_int::operator>(const big_int &that) {
    if(*this == that)
        return false;

    if(is_negative_)
        if(!that.is_negative_)
            return false;
        else
            return !(this->abs() > that.abs());
    else
        if(that.is_negative_)
            return true;

    if(this->number_.size() != that.number_.size())
        return this->number_.size() > that.number_.size();
    else{
        int i = that.number_.size() - 1;
        while(this->number_[i] == that.number_[i])
            --i;
        return this->number_[i] > that.number_[i];
    }
}

bool big_int::operator<(const big_int &that) {
    if(*this == that)
        return false;
    return !(*this > that);
}


bool big_int::operator>=(const big_int &that) {

    return (*this == that) || (*this > that);
}

bool big_int::operator<=(const big_int &that) {

    return (*this == that) || (*this < that);
}


bool big_int::operator==(const big_int &that) {
    return is_negative_ == that.is_negative_ &&
            number_ == that.number_;
}

bool big_int::operator!=(const big_int &that) {
    return !(*this == that);
}


big_int big_int::operator+(const big_int &that) {
    big_int result;

    if(is_negative_)
        if(that.is_negative_)
            result.is_negative_ = true;
        else
            return -(this->abs() - that);
    else
    if(that.is_negative_)
        return (*this - that.abs());
    else
        result.is_negative_ = false;


    result.number_ = this->abs() >= that.abs() ? number_ : that.number_;
    std::vector<int8_t> min_v = that.abs() <= this->abs() ? that.number_ : number_;

    size_t min_size = std::min(number_.size(), that.number_.size());
    size_t max_size = std::max(number_.size(), that.number_.size());

    result.number_.emplace_back(0);
    for(size_t i = min_size; i <= max_size; ++i)
        min_v.emplace_back(0);


    uint8_t next = 0;
    for (size_t i = 0; i <= max_size; ++i) {
        result.number_[i] += min_v[i] + next;
        next = result.number_[i] > 9;
        if(next)
            result.number_[i] -= 10;
    }

    result.delete_first_zeros();

    return result;
}

big_int big_int::operator-(const big_int &that) {
    big_int result;

    if(is_negative_)
        if(that.is_negative_)
            result.is_negative_ = this->abs() > that.abs();
        else
            return -(this->abs() + that.abs());
    else
        if(that.is_negative_)
            return (*this + that.abs());
        else
            result.is_negative_ = *this < that;


    result.number_ = this->abs() >= that.abs() ? number_ : that.number_;
    std::vector<int8_t> min_v = that.abs() <= this->abs() ? that.number_ : number_;

    size_t min_size = std::min(number_.size(), that.number_.size());
    size_t max_size = std::max(number_.size(), that.number_.size());

    for(size_t i = min_size; i < max_size; ++i)
        min_v.emplace_back(0);


    int next = 0;
    for (size_t i = 0; i < max_size; ++i) {
        result.number_[i] -= (min_v[i] + next);
        next = result.number_[i] < 0;
        if(next)
            result.number_[i] += 10;
    }

    result.delete_first_zeros();

    return result;
}


