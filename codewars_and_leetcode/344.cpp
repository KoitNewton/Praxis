class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size();
        while (left < right/2) {
            swap(s[left], s[right-left-1]);
            left++;
        }
    }
};