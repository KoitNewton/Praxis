#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    
    string filename;

    cout << "输入文件名称：  " ;
    cin >> filename;

    ofstream fout(filename.c_str());
    cout << "输入文件内容： " ;
    char secret;
    cin >> secret;
    fout << secret << endl;
    fout.close();
    ifstream fin(filename.c_str());
    cout <<"这是你的文件的内容： "<< endl;
    char ch;
    while (fin.get(ch))
        cout << ch ;
    cout <<"输出结束! "<< endl;
    fin.close();
    return 0;

}