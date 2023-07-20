#include <iostream>

using namespace std;

template <typename T>
int binary_search_array(const T& key, const T data[], int n) {
        // key -- The number you search for    
        // data[]-- The sequential array from small to big which the key might be in  
        // n -- The length of the array
    if ( n<= 0)
        return 0;  //absolutly if the array had no data, return 0
    
    int low = 0;
    int high = n -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;
    
        if(key < data[mid])
            high = mid - 1;
        else if (data[mid] < key)
            low = mid + 1;
        else
            return mid;

    }

    return n;
}


int main() {

    int A[5] = {1,2,3,4,5};
    cout << binary_search_array(2,A,5) << endl;
    cout << binary_search_array(0,A,5) << endl;
    cout << binary_search_array(2,A,0) << endl;
    cout << binary_search_array(2,A+2,3) << endl;

    return 0;
}