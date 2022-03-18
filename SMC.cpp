#include <iostream>
#include <stdio.h>
#include <math.h>
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

void chapter3_problem5()
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
void chapter3_programming1()
{
    int hour, minute, length;
    double cost;
    string day;
    char ch;
    cout << "Input the time the call started: ";
    cin >> hour >> ch >> minute;
    cout << "Input the length of the call in minutes: ";
    cin >> length;
    cout <<"Input the day of the week(Mu, Tu, We, Th, etc): ";
    cin >> day;
    if (day == "Sa" || day == "Su"){
        cost = length * 0.15;
        cout << "Total cost: " << cost;
    }
    else{
        if (hour >= 8 && hour <=18){
            cost = length * 0.4;
            cout << "Total cost: " << cost;
        }
        else if(hour < 8 || hour > 18){
            cost = length * 0.25;
            cout << "Total cost: " << cost;
        }
    }

}

void chapter3_programming2()
{
    int a,b,c, roots;
    while (true){
        cout << "Enter 0 to quit";
        cout << "Enter a, b, c for the equation: ";
        cin >> a >> b >> c;
        if (a == 0)
            break;
        double result1, result2;
        result1 = (-b + sqrt(pow(b,2) -4*a*c))/2;
        result2 = (-b - sqrt(pow(b,2) -4*a*c))/2;
        if (pow(b,2)-4*a*c == 0){
            cout << "only one result: " << result1 << endl;
        }
        else
            cout << "Two results: " << result1 << " " << result2;
    }
    
}
void chapter3_programming3() // Roman numerals
{
    int num, first, second ,third, fourth;
    string convert;
    cout << "Input number between 1000 and 3000: ";
    cin >> num;
    first = num / 1000;
    second = (num-first*1000) / 100;
    third = (num-first*1000 - second*100)/ 10;
    fourth = (num-first*1000 - second*100 - third*10) % 10;
    for(int i=0; i<first; i++){ // first digit.
        convert+= 'M';
    }
    if (second <=3 && second !=0){ // second digit.
        for(int i=0; i<second; i++)
        convert+= 'C';
    }
    else if (second==4){
        convert +='C';
        convert +='D';
    }
    else if (second >=5 && second <=8){
        for(int i=5; i<= second; i++){
            if (i==5)
                convert+='D';
            else
                convert+='C';
        }
    }
    else if (second ==9){
        convert += 'C';
        convert += 'M';
    }
    
    // third digit.
    if (third <=3 && third !=0){
        for(int i=0; i<third; i++)
        convert+= 'X';
    }
    if (third==4){
        convert +='X';
        convert += 'L';
    }
    
    if (third >=5 && third <=8){
        for(int i=5; i<= third; i++){
            if (i==5)
                convert+='L';
            else
                convert+='X';
        }
    }
    if (third ==9){
        convert += 'X';
        convert += 'C';
    }

    // fourth digit.
    if (fourth <=3 && fourth !=0){
        for(int i=0; i<fourth; i++)
        convert+= 'I';
    }
    if (fourth==4)
        convert +='I'+'V';
    if (fourth >=5 && fourth <=8){
        for(int i=5; i<= fourth; i++){
            if (i==0)
                convert+='V';
            else
                convert+='I';
        }
    }
    if (fourth ==9){
        convert += 'I';
        convert += 'X';
    }


    cout << convert;

}
void test()
{
    string me;
    me +='C';
    me +='D';
    me +='V';
    cout << me;
    
}
int main()
{
    chapter3_programming3();
    return 0;
}