// Interesting start to the text adventure page

#include <iostream>
#include <string>

using namespace std;

int main()
{
        cout << "Welcome to Text Adventure!" << endl << endl;
        cout << "What is your name?" << endl << endl;
        string playerName;
        cin >> playerName;

        cout << endl << "Hello " << playerName << endl;

        return 0;
}
