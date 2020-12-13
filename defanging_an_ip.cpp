/*
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".
*/

#include <iostream>
#include <string>
using namespace std;

string defangIPaddr(string address)
{
    string ans;
    for (int i = 0; i < address.length(); i++)
    {
        if ((int)address[i] == (int)'.')
            ans += "[.]";
        else
            ans += address[i];
    }
    return ans;
}

int main(void)
{
    defangIPaddr("192.168.2.1.1");
    return 0;
}