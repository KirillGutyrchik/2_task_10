#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

bool isNumber(const std::string& str)
{
    if(str.empty())
        return false;

    return std::all_of(str.begin() + (str[0] == '-' || str[0] == '+'),
                str.end(),
                [](const char sym){
                    return std::isdigit(sym);
    });
}


int main() {
    long long sum = 0;
    std::string str;

    std::ifstream file("file.txt");

    while (!file.eof())
    {
        file >> str;
        if (isNumber(str))
            sum += stoll(str);
    }
    std::cout << sum;
}
