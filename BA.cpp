#include "BA.h"


big_int::big_int(const std::string_view &number) {
    if(!big_int::is_digit(number))
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

const std::vector<uint8_t> &big_int::getNumber() const {
    return number_;
}

bool big_int::isNegative() const {
    return is_negative_;
}


