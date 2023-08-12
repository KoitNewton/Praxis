#include <iostream>
#include <string>
#include <cstring>
int main(){
    using namespace std;
    char charr1 [20];
    char charr2 [20] = "jaguar";
    string str1;
    string str2 = "panther";

    char first_date [] = {"Le Chapon Dodu"};
    char second_date[] {"The Elegant Plate"};
    string third_date = {"The Bread Bowl"};
    string fourth_date {"Hank's Fine Eats"};


    // cout <<"Enter a kind of feline: ";
    // cin >> charr1;
    // cout << "Enter another kind of  feline: ";
    // cin >> str1;
    // cout << "Here are some felines:\n";
    // cout << charr1 << " " << charr2 << " "
    //      << str1 << " " << str2 // use cout for output
    //      << endl;
    str1 = second_date + third_date + fourth_date;
    cout << "The fifth letter in" << second_date << " is " << second_date[4] << endl;
    cout << "The fifth letter in" << third_date << " is "  << third_date[4] << endl;
    cout << str1 <<endl;
    strcpy(charr1,charr2);
    int len1 = str1.length();
    int len2 = strlen(charr2);
    cout << len1 << " " << len2 << endl;

    return 0;


}


/// i prefer the string than C-style code