#pragma once
#include <string>
#include <iostream>

class bigint
{
private:
    std::string num;

    void remove_zeros()
    {
        size_t pos = num.find_first_not_of('0');
        if (pos == std::string::npos)
            num = "0";
        else if (pos > 0)
            num.erase(0, pos);
    }

    // conversion manuelle string -> int (C++98)
    static int to_int(const std::string& s)
    {
        int result = 0;
        for (size_t i = 0; i < s.size(); ++i)
            result = result * 10 + (s[i] - '0');
        return result;
    }

public:
    /* =========================
       Constructeurs
       ========================= */

    bigint() : num("0") {}

    bigint(const std::string& n) : num(n)
    {
        remove_zeros();
    }

    bigint(unsigned int n)
    {
        if (n == 0)
        {
            num = "0";
            return;
        }

        while (n > 0)
        {
            num.insert(num.begin(), char('0' + (n % 10)));
            n /= 10;
        }
    }

    /* =========================
       Addition
       ========================= */

    bigint operator+(const bigint& oth) const
    {
        std::string a = num;
        std::string b = oth.num;
        std::string result;

        // alignement des tailles
        while (a.size() < b.size()) a.insert(a.begin(), '0');
        while (b.size() < a.size()) b.insert(b.begin(), '0');

        int carry = 0;
        for (int i = (int)a.size() - 1; i >= 0; --i)
        {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            carry = sum / 10;
            result.insert(result.begin(), char('0' + (sum % 10)));
        }

        if (carry)
            result.insert(result.begin(), char('0' + carry));

        return bigint(result);
    }

    bigint& operator+=(const bigint& oth)
    {
        *this = *this + oth;
        return *this;
    }

    /* =========================
       Incrémentation
       ========================= */

    bigint& operator++()
    {
        *this += bigint(1);
        return *this;
    }

    bigint operator++(int)
    {
        bigint tmp(*this);
        ++(*this);
        return tmp;
    }

    /* =========================
       Décalage base 10
       ========================= */

    bigint operator<<(int shift) const
    {
        if (num == "0")
            return *this;

        bigint res(*this);
        while (shift-- > 0)
            res.num.push_back('0');
        return res;
    }

    bigint operator>>(int shift) const
    {
        if (shift <= 0)
            return *this;

        if ((size_t)shift >= num.size())
            return bigint("0");

        bigint res(num.substr(0, num.size() - shift));
        res.remove_zeros();
        return res;
    }

    bigint& operator<<=(int shift)
    {
        *this = *this << shift;
        return *this;
    }

    bigint& operator>>=(int shift)
    {
        *this = *this >> shift;
        return *this;
    }

    bigint& operator>>=(const bigint& oth)
    {
        int shift = to_int(oth.num);
        *this = *this >> shift;
        return *this;
    }

    /* =========================
       Comparaisons
       ========================= */

    bool operator<(const bigint& oth) const
    {
        if (num.size() != oth.num.size())
            return num.size() < oth.num.size();
        return num < oth.num;
    }

    bool operator>(const bigint& oth) const { return oth < *this; }
    bool operator<=(const bigint& oth) const { return !(*this > oth); }
    bool operator>=(const bigint& oth) const { return !(*this < oth); }
    bool operator==(const bigint& oth) const { return num == oth.num; }
    bool operator!=(const bigint& oth) const { return !(*this == oth); }

    /* =========================
       Affichage
       ========================= */

    friend std::ostream& operator<<(std::ostream& os, const bigint& b)
    {
        os << b.num;
        return os;
    }
};
