#include <iostream>
using namespace std;

void chapter2()
{
    int input;
    int count = 1;
    int max= 0;
    int min = 0;
    cout << "Input any number: ";
    cin >> input;
    while(input >=0){
        cout << "Input another number: ";
        cin >>input;
        if (input >= max)
        max = input;
        if (input <= min)
        min = input;
        count ++;
    }
    cout << "Number of times entered: " << count << endl;
    cout << "Max number entered: " << max << endl;
    cout << "Minimum numebr entered :" << min << endl;
}

int main()
{
    chapter2();
    return 0;
}