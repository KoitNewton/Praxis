#include "iostream"
using namespace std;

int main(){
    
    int sum = 0;
    int dividend = 0;
    cin >> dividend;  // your dividend or the denominator
    int half = dividend/2 +1;
    //cout << half<<endl; 
    for(int i=1; i<= half; i++){
        
        if((dividend%i)==0){
            if((dividend/i)>i)
                sum = dividend/i + i + sum;
            else if((dividend/i)==i)
                sum = i + sum;            
        }

    }

    cout<<sum<<endl;

    return 0;
}