#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    const char * FilePath = "C:\\Users\\abc\\Desktop\\shiyan.txt";
    if(remove(FilePath) == 0)
        cout << "File deleted successfully" << endl;
    else
        cout << "Error deleting file" << endl;


    return 0;

}


