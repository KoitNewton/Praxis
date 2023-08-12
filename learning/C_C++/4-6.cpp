#include<iostream>
int main() {
    using namespace std;
    cout << "What year was your house built?\n";
    int year;
    (cin >> year).get();  // "or (cin >>year).get(ch)" written in C++ Primer Plus but it does not work in this code 
    cout << "What is its street address?\n";
    char address[80];
    cin.getline(address,80);
    cout << "Year built: " << year <<endl;
    cout << "Street address: " << address <<endl;
    cout << "Done!" <<endl;
    return 0;


}