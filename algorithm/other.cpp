#include <iostream>
#include <string>
#include <vector>

int longest_palindrome_expand(const std::string& s, int left, int right){
    while (left>=0 && right<s.size() && s[left]==s[right]){
        --left;
        ++right;
    }
    return (right-left-2)/2;
}

std::string longest_palindrome(std::string s){
    int start = 0, end = -1;
    std::string t = "#";
    std::string ret;
    for (char c: s){
        t += c;
        t += '#';
    }
    t += '#';
    s = t;
    std::vector<int> arm_len;
    int right = -1, j = -1;
    for (int i=0;i<s.size();++i){
        int cur_arm_len;
        if (right>=i){
            int i_sym = j*2-i;
            int min_arm_len = (std::min)(arm_len[i_sym], right-i);
            cur_arm_len = longest_palidrome_expand(s, i-min_arm_len, i+min_arm_len);
        }
        else
            cur_arm_len = longest_palidrome_expand(s, i, i);
        arm_len.push_back(cur_arm_len);
        if (i+cur_arm_len>right){
            j = i;
            right = i + cur_arm_len;
        }
        if (cur_arm_len*2+1>end-start){
            start = i - cur_arm_len;
            end = i + cur_arm_len;
        }
    }
    for (int i=start;i<end;++i){
        if (s[i]!='#')
            ret += s[i];
    }
    return ret;
}

int main(){
    // Longest Palindrome
    std::string s{"asdfasdssdsag"};
    std::cout << s << std::endl;
    std::cout << longest_palindrome(s) << std::endl;

    return 0;
}