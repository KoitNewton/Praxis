#include "iostream"
#include "string"
#include "iterator"
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        int right = s.size();     
        int left = 0;
        int start = 0;
        int end = 0;
        while(left < right) {         
            while(s[left] != ' '&& left < right) {
                left++;
            }
        
            end = left-1;

            while((start<=start+(end-start)/2)&&(start<end)) {          
                swap(s[start], s[end]);
                start++;
                end--;
            }
            end = left;
            left++;
            start=end+1;
        } 
        return s;
    }

};

int main() {
    string a ="Hello World,I love you!";
    Solution obj;
    obj.reverseWords(a);
    cout <<"a="  << a;


    return 0;

}