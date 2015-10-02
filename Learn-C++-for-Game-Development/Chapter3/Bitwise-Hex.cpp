// Chapter 3 Bit manipulation example

#include <iostream>

using namespace std;

int main()
{
        unsigned int first = 0x0F;
        unsigned int second = 0x18;
        unsigned int anded = first & second;

        cout << hex << showbase;
        cout << first << endl;
        cout << second << endl;
        cout << anded << endl;

        return 0;
}
