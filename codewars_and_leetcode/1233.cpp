#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
using namespace std;
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans = {folder[0]};
        for (int i = 1; i < folder.size(); ++i) {
            if (int pre = ans.end()[-1].size(); !(pre < folder[i].size() && ans.end()[-1] == folder[i].substr(0, pre) && folder[i][pre] == '/')) {
                ans.push_back(folder[i]);
            }
        }
        cout << "After manipulation:\n";
        for (int i = 0; i < folder.size(); ++i) {
            cout << folder[i] << endl;
        }
        return ans;
    }
};

// I feel confused about this class solution because it goes wrong in my code.
int main() {
    string str[] = {"/a", "/a/b", "/c/d", "/c/d/e","/c/f"};
    vector<string> folder (str,str+5);
    cout << "At beginning:\n";
    for (int i = 0; i < folder.size(); ++i) {
        cout << folder[i] << endl;
    }
    Solution a;
    a.removeSubfolders(folder);

}

