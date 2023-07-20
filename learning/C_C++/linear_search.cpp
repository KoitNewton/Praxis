#include <iostream>
#include <vector>
#include <string>

using namespace std;

//----------------------------------------------------------------
template <typename T>
int linear_search_array(const T& key,const T data[],int n){

    for(int i=0;i<n;++i)
        if (data[i]==key)
            return i;
    return n;

}
//Linear search for array elements above the note
//----------------------------------------------------------------


//----------------------------------------------------------------
template <typename T>
size_t linear_search_vector(const T& key,const vector<T>& data){

    for (size_t i=0;i<data.size();++i)
        if (data[i]==key)
            return i;
    return data.size();
    

}

//Linear search for vector elements above the note
//----------------------------------------------------------------




//----------------------------------------------------------------
template <typename T, typename IR>
IR linear_search_iterator(const T& key,IR left, IR right){
    while (left != right && *left != key)
        ++left;
    return left;

}
//Lineaer search for iterator elements
//----------------------------------------------------------------

int main(){
    const int m = 1000;
    int n = 5;
    int A[m] = {3,2,1,4,5};
    vector<string> V {"RSA","Apple","Miao","Urai","C"};
    cout << linear_search_array(1,A,n) <<endl;
    string key = "Apple";
    cout << linear_search_vector(key,V) << endl;
    key = "Algorithm";
    auto iter = linear_search_iterator(key,V.begin(),V.end());
    if(iter == V.end())
        cout << "Not Found!" <<endl;
    else
        cout << *iter << endl;

}






