#include<iostream>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Do not modify main
// This function takes as input an integer num
// It should return required output.	  
string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
                 "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                 "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string power[] = {"", "Thousand", "Million", "Billion", "Trillion"};

string f2(int n, int floor)
{
    if(n == 0){
        return "";
    }

    string rres = f2(n / 10, floor + 1);

    if(floor == 0)
    {
        int smalln = n / 10;

        if(smalln % 10 <= 1){
            string s = ones[(smalln%10)*10 + n%10];
            rres += " " + s;
        } else {
            string s = ones[n%10];
            rres += " " + s;
        }
    }
    else if(floor == 1)
    {
        if(n%10 > 1){
            string s = tens[n%10];
            rres += " " + s;
        }
    }
    else
    {
        if(n > 0)
        {
            string s = ones[n];
            s += " Hundred";
            rres += s;
        }
    }
    return rres;
}

string f1(int n, int floor)
{
    if(n == 0)
    {
        return "";
    }

    string rres = f1(n / 1000, floor + 1);

    string f2res = f2(n % 1000, 0);

    // int smalln = n / 1000;

    // cout << "smalln " << smalln%10 << endl;
    // cout << floor << " " << f2res << " " << endl;
    if(n % 10 != 0 || (n / 10) % 10 != 0)
        rres += f2res + " " + power[floor] + " ";
    else
        rres += f2res + power[floor] + " ";

    return rres;
}

string numberToWords(int num) {
    //Write your code here
    if(num == 0){
        return "Zero";
    }

    if(num >= 1 && num <= 19){
        return ones[num];
    }

    if(num >= 20 && num <= 99){
        return tens[num/10] + " " + ones[num%10];
    }

    return f1(num, 0);
}

int main(int argc, char** argv){
    int num;
    cin>>num;
    cout<<numberToWords(num);

    // cout << f2(num, 0) << endl;
}