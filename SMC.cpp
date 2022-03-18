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

void chapter3_problem1()
{
    char user1, user2;
    while(true){
        cout << "Enter x to quit" << endl;
        cout << "user1's turn: ";
        cin >> user1;
        if (user1 == 'X' || user1 == 'x')
            break;
        cout << "user2's turn: ";
        cin >> user2;
        if (user2 == 'X' || user2 == 'x')
            break;
        if ((user1 == 'P' || user1 == 'p')){
            if((user2 == 'S' || user2 == 's')){
                cout << "user2 wins";
            }
            else if(user2=='R' || user2=='r'){
                cout << "user1 wins";
            }
            else{
                cout << "nobody wins";
            }
        }
        else if((user1 == 'S' || user1 == 'S')){
            if((user2 == 'S' || user2 == 's')){
                cout << "nobody wins";
            }
            else if(user2=='R' || user2=='r'){
                cout << "user2 wins";
            }
            else{
                cout << "user1 wins";
            }
        }
        else if((user1 == 'R' || user1 == 'r')){
            if((user2 == 'S' || user2 == 's')){
                cout << "user1 wins";
            }
            else if(user2=='R' || user2=='r'){
                cout << "nobody wins";
            }
            else{
                cout << "user2 wins";
            }
        }
    }
}

void chapter3_problem2()
{
    double interest, total, min, balance;
    while(true){
        cout << "Enter 0 to quit" << endl;
        cout << "Input the account balance: ";
        cin >> balance;
    
        if (balance == 0 || balance == 0)
            break;
        if (balance >= 1000){
            interest = 1000*0.015 + (balance - 1000) *0.01;
            total = balance + interest;
            if(10 >= balance*0.01)
                min = 10;
            else
                min = total*0.01;
            cout << "Interest: " << interest << "\n"
                 << "Total Amount: " << total << "\n"
                 << "Minimum Payment due: " << min << "\n";
        }
        else{
            interest = balance*0.015;
            total = balance + interest;
            if (total <= 10)
                min = total;
            else
                min = total *0.01;
            cout << "Interest: " << interest << "\n"
                 << "Total Amount: " << total << "\n"
                 << "Minimum Payment due: " << min << "\n";
        }
    }
}

void chapter3_problem3()
{
    bool me;
    for(int i =3; i<=100; i++){
        me = true;
        for(int n =2; n<= i-1; n++){
            if (i%n == 0)
                me = false;
        }
        if (me == true)
            cout << i << " ";
    }
}
void test()
{
    int n =5;
    while (--n > 0){
        if (n==2)
        break;
        cout << n << " ";
    }
    cout << "End of Loop.";
    
}
int main()
{
    chapter3_problem3();
    return 0;
}