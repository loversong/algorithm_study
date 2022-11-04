#include <iostream>
#include <string>
#include <vector>

// Knuth-Morris-Pratt
std::vector<int> kmp_next(std::string p){
    std::vector<int> ret{0};
    int n = p.size();
    int i = 1;
    int cur = 0;
    while (i<n){
        if (p[cur]==p[i]){
            cur++;
            i++;
            ret.push_back(cur);
        }
        else if (cur>0)
            cur = ret[cur-1];
        else{
            ret.push_back(0);
            i++;
        }
    }
    return ret;
}

int kmp(std::string s, std::string p){
    int tar = 0, pos = 0;
    std::vector<int> nxt = kmp_next(p);
    while (tar<s.size()){
        if (s[tar]==p[pos]){
            tar++;
            pos++;
        }
        else if (pos>0)
            pos = nxt[pos-1];
        else
            tar++;
        if (pos==p.size())
            return pos;
    }
    return -1;
}

int main(){
    std::string s{"hello"};
    std::string p{"ll"};
    int a = kmp(s,p);
}