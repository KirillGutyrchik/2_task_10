#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

bool isNumber(const std::string& str)
{
    bool flag_sign = false;
    bool is_number = true;

    if(str[0] == '-' || str[0] == '+')
        flag_sign = true;

    std::for_each(str.begin() + flag_sign,
                  str.end(),
                  [&is_number](const char sym){
                      if(sym > '9' || sym < '0')
                          is_number = false;
                  });
    return is_number;
}


int main() {
    long long sum = 0;
    std::string str;

    std::ifstream file("file.txt");

    while (!file.eof())
    {
        file >> str;
        try
        {
            if (isNumber(str))
                sum += stoll(str);
        }
        catch(const std::out_of_range&)
        {}
    }
    std::cout << sum;
}
