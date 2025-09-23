class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.size(),n2=version2.size();
        int i=0,j=0;
        int num1=0,num2=0;
        while(i<n1 && j<n2){
            string s1="",s2="";
            while(i<n1 && version1[i]!='.') s1+=version1[i++];
            while(j<n2 && version2[j]!='.') s2+=version2[j++];
            num1=stoi(s1),num2=stoi(s2);
            if(num1 > num2) return 1;
            if(num2 > num1) return -1;
            i++;
            j++;
        }
        num2=0;
        while(i<n1){
            string s1="";
            while(i<n1 && version1[i]!='.') s1+=version1[i++];
            // cout<<s1<<" ";
            num1=stoi(s1);
            if(num1 > num2) return 1;
            i++;
        }
        num1=0;
        while(j<n2){
            string s2="";
            while(j<n2 && version2[j]!='.') s2+=version2[j++];
            num2=stoi(s2);
            if(num2>num1) return -1;
            j++;
        }
        return 0;
    }
};