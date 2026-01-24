class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int i=0; 

        while(i<s1.size()){
            if(s1[i]==s2[i]) i++;
            else {
                swap(s1[i],s1[i+2]);
                i++;
            }
        }
        if(s1!=s2) return false;
        else return true;
    }
};