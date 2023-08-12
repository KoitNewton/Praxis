#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(){
    // char charr[20];
    // string str;
    // cout << "The length of the charr before input is " <<strlen(charr)<<endl;//In the book it says 27 ,but the real outcome is 0
    // cout << "The length of the str before input is " <<str.size()<<endl;

    // cout << "Enter a line of text: \n";
    // cin.getline(charr,20);
    // cout << "Enter another line: \n";
    // getline(cin,str);
    // cout << "The length of the charr after input is " <<strlen(charr)<<endl; 
    // cout << "The length of the str after input is " <<str.size()<<endl;

    wchar_t title[] = L"Chief Astrogator";
    cout << R"(Jim "King" Tutt uses "\n" instead of endl.)" << '\n';
    //      here "R" means "raw string" which its characters are themselves not for transferred meaning like '\n' just print the '\n'
    //  on the screen not for chaning the line 
    cout << R"+*("(Who would't?)",she whispered.)+*" <<endl;
    cout << title << endl;
    return 0;


}