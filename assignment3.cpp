#include <iostream>
#include <string>
using namespace std;
string num_to_Digit(int number)
{
    if (number == 0)
    {
        return "zero";
    }
    string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                     "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                     "seventeen", "eighteen", "nineteen"};
    string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    if (number < 20)
    {
        return ones[number];
    }
    if (number < 100)
    {
        return tens[number / 10] + (number % 10 == 0 ? "" : "-" + ones[number % 10]);
    }
    if (number < 1000)
    {
        return ones[number / 100] + " hundred" + (number % 100 == 0 ? "" : " " + num_to_Digit(number % 100));
    }
    if (number < 10000)
    {
        return num_to_Digit(number / 1000) + " thousand" + (number % 1000 == 0 ? "" : " " + num_to_Digit(number % 1000));
    }

    return "Invalid input";
}
int main()
{
    int n;
    cout << "Enter a number \n";
    cin >> n;
    cout << num_to_Digit(n);
    return 0;
}
