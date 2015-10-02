// Chapter 4:  Arrays

#include <iostream>

using namespace std;

int main()
{
        int intArray[5] = { 5, 6, 7, 8, 9 };

        unsigned int index = 0;
        cout << "Index: " << index << " ";
        cout << "Value: " << intArray[index++] << endl;

        cout << "Index: " << index << endl;
        cout << "Value: " << intArray[index++] << endl;

        cout << "Index: " << index << endl;
        cout << "Value: " << intArray[index++] << endl;

        cout << "Index: " << index << endl;
        cout << "Value: " << intArray[index++] << endl;

        cout << "Index: " << index << endl;
        cout << "Value: " << intArray[index++] << endl;
        return 0;
}
