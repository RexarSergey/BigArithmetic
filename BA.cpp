#include "BA.h"

big_int::big_int(const std::vector<int> &number, bool sign) : number(number), is_negative(sign) {
    delete_first_zeros();
}

big_int::big_int(const std::string &number)
{
    if(number.empty() || (number.size() == 1 && number[0] == '-')){
        this->number.push_back(0);
        return;
    }

    int end = 0;
    if(number[0] == '-') {
        is_negative = true;
        ++end;
    }

    for (long long i = number.size(); i > end; --i) {
        this->number.push_back((int)number[i - 1] - '0');
    }

    delete_first_zeros();
}

big_int::big_int(const big_int &number) : number(number.number), is_negative(number.is_negative) {}

big_int::big_int() {}

big_int::~big_int() {}


std::ostream &operator<<(std::ostream &out, const big_int &bi) {
    std::string str_out = "";
    for(const int& elem : bi.number)
        str_out = std::to_string(elem) + str_out;
    if(bi.is_negative)
        str_out = '-' + str_out;

    out << str_out;

    return out;
}

std::istream &operator>>(std::istream &in, big_int &bi) {
    std::string number;

    in >> number;
    while(!big_int::is_digit(number)){
        std::cout << "Incorrect number. Try again\n>> ";
        in >> number;
    }
    bi = big_int(number);

    return in;
}


void big_int::delete_first_zeros()
{
    int index = number.size();
    while(number.size() > 1 && number[--index] == 0)
        number.pop_back();
}


big_int &big_int::operator=(const big_int &that) {
    if(*this == that)
        return *this;

    this->number = that.number;
    this->is_negative = that.is_negative;
    return *this;
}

const big_int &operator+(const big_int &a) {
    return a;
}

const big_int operator-(const big_int &a) {
    return big_int(a.number, !a.is_negative);
}


const big_int operator+(const big_int &a, const big_int &b) {
    if(a < b)
        return b + a;

    if(a.is_negative){
        if(b.is_negative) return -((-a) + (-b));
        else
            return -((-a) + b);
    }
    else
        if(b.is_negative)
            return a - (-b);

    std::vector<int> result(a.number);
    int next = 0;
    for (int i = 0; i < b.number.size(); ++i) {
        result[i] += b.number[i] + next;
        next = result[i] > 9;
        if(next)
            result[i] -= 10;
    }

    for (int i = b.number.size(); i < result.size(); ++i) {
        result[i] += next;
        next = result[i] > 9;
        if(next)
            result[i] -= 10;
        else
            break;
    }

    if(next)
        result.push_back(1);

    return big_int(result, false);
}

const big_int operator-(const big_int &a, const big_int &b) {
    if(a < b)
        return -(b - a);

    if(a.is_negative)
        if(b.is_negative)
            return -((-a) - (-b));
        else
            return -((-a) - b);
    else
        if(b.is_negative)
            return a + (-b);

    std::vector<int> result(a.number);
    int next = 0;
    for (int i = 0; i < b.number.size(); ++i) {
        result[i] -= (b.number[i] + next);
        next = result[i] < 0;
        if(next)
            result[i] += 10;
    }

    for (int i = b.number.size(); i < result.size(); ++i) {
        result[i] -= next;
        next = result[i] < 0;
        if(next)
            result[i] += 10;
        else
            break;
    }

    return big_int(result, false);
}


bool operator>(const big_int &a, const big_int &b) {
    if(a == b)
        return false;

    if(a.is_negative){
        if(!b.is_negative)
            return false;
        else
            return !((-a) > (-b));
    }
    else{
        if(b.is_negative)
            return true;
        else{
            if(a.number.size() != b.number.size())
                return a.number.size() > b.number.size();
            else{
                int i = 0;
                while(a.number[i] == b.number[i])
                    ++i;
                return a.number[i] > b.number[i];
            }
        }
    }
}

bool operator<(const big_int &a, const big_int &b) {
    if(a == b)
        return false;
    return !(a > b);
}


bool operator>=(const big_int &a, const big_int &b) {
    return (a > b) || (a == b);
}

bool operator<=(const big_int &a, const big_int &b) {
    return (a < b) || (a == b);
}


bool operator==(const big_int &a, const big_int &b) {
    return a.number == b.number &&
            a.is_negative == b.is_negative;
}

bool operator!=(const big_int &a, const big_int &b) {
    return !(a == b);
}

bool big_int::is_digit(const std::string &str) {
    if(str[0] == '-')
        return str.substr(1, str.size() - 1).find_first_not_of("0123456789") == std::string::npos;
    return str.find_first_not_of("0123456789") == std::string::npos;
}

const std::vector<std::string> big_int::str_bool_op({">", "<", ">=", "<=", "==", "!="});

const std::vector<std::string> big_int::str_int_op({"+", "-"});

