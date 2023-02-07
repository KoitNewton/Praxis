using namespace std;
#include <cmath>
bool narcissistic( int value ){
  //Code away
  int weishu = 1;
  int temp = value;
  int temp_1 = value;
  while(temp>=10){
      temp /= 10;
      weishu++;
  }
  //cout<<weishu;
  int sum=0;
  for(int i=1;i<=weishu;i++){
    sum = sum + pow(value%10,weishu);
    value /= 10;    
  }

  return sum==temp_1;
  
  
}