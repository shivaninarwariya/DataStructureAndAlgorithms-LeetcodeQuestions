#include<bits/stdc++.h>
using namespace std;

int LengthOfString(string &str){
  int length=0;
  for(int i=0;str[i]!='\0';i++){
      length++;
  }
  return length;
}

void ToggleOfString(string &str){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>=65&&str[i]<=90){
        str[i]+=32;
    }else if(str[i]>='a'&&str[i]<='z'){
            str[i]-=32;
    }
 }
  for(int i=0;str[i]!='\0';i++){
        cout<<str[i];
    }
}

int  CountWord(string &str){
      int word=0;int i=str.size()-1;
      if(str[i]==' '){
        i--;
      }
      for(int i=str.size()-1;i>=0;i--){
        word++;
        if(str[i]==' '){
            break;
        }
      }
     return word-1;
}

bool ispallindrome(char a[],int n){
    int s=0;
    int e=n-1;
    if(s>=e){
        return true;
    }
    while(s<e){
        if(a[s++]==a[e--]){
            return true;
        }
    }
    return false;
}

void  ReverseTheString(char a[],int n){
    int s=0;int e=n-1;
    while(s<e){
        swap(a[s],a[e]);
        s++;e--;
    }
    cout<<"reverse string is :"<<a;
}
//REVERSE WORDS IN STRING FOR EG.INPUT :  I.LIKE.YOU.VERY.MUCH
//OUTPUT: MUCH.VERY.YOU.LIKE.I
string ReverseWords(string s){
    string ans="";
    string temp="";
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='.'){
            reverse(temp.begin(),temp.end());
            ans+=temp;
            ans.push_back('.');
            temp="";
        }
        else{
            temp.push_back(s[i]);
        }
    }
    reverse(temp.begin(),temp.end());
    ans+=temp;
    return ans;
}
//TRANSFORM OF STRING FOR EG. IP A: ABD
 //                           OP B: BAD 

 int transform (string A, string B){
    string a=A;
    string b=B;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<A.length();i++){
        if(A[i]!=B[i]) return -1;
    }
    int count=0; int j=B.length()-1;
    for(int i=a.length()-1;i>=0;i--){
      if(a[i]==b[j] && j>=0){
        j--;
      }
      else if(A[i]!=B[j]){
        count++;
      }
    }
   return count;
 }

// CHECK WHETHER THE STRINGS ARE ISOMORPHIC TO EACH OTHER
//IP: A=aab B=xxy
//OP: TRUE; 
bool areIsomorphic(string str1, string str2)
    {
        if(str1.length()!=str2.length()) return false;
       map<char ,vector<int>>mp1,mp2;
       for(int i=0;i<str1.length();i++){
        mp1[str1[i]].push_back(i);
        mp2[str2[i]].push_back(i);
        if(mp1[str1[i]]!=mp2[str2[i]]) return false;
       }
        return true;
    }
// MIN LENGTH OF STRING AFTER REMOVING SUBSTRING "AB" AND"CD"
int minLength(string s){
   stack<char>st;
       for(char c: s){
        if(!st.empty() && st.top()=='A' && c=='B') st.pop();
        else if(!st.empty() && st.top()=='C' && c=='D') st.pop();
        else st.push(c);
       }
       return st.size();
}

//LONGEST COMMON PREFIX IN STRING 

string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0) return "";
        
        string ans  = "";
        sort(begin(strs), end(strs));
        string a = strs[0];
        string b = strs[n-1];
        
        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i]){
                ans = ans + a[i];
            }
            else{
                break;
            }
        }
        
        return ans;
        
    }

//Detect Capital All letters in this word are capitals, like "USA". All letters in this word are not capitals, like "leetcode".
//Only the first letter in this word is capital, like "Google".Input: word = "USA" Output: true
 bool detectCapitalUse(string word) {
        int i=0; int uppercnt=0; int lowercnt=0;
        for(int i=0;i<word.length();i++){
            if(word[i]>=65 && word[i]<=90){
                uppercnt++;
            }else lowercnt++;
        }
        if(lowercnt==0||uppercnt==0||(uppercnt==1&&word[0]>=65 && word[0]<=90))
        return true;
        return false;
    }

//VALID PALLINDROME II Input: s = "abca" Output: true Explanation: You could delete the character 'c'.
 bool isPalindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            else{
                i++;j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;j--;
            }else
            return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
        }
        return true;
    }

// Is Subsequence Input: s = "abc", t = "ahbgdc" Output: true
 bool isSubsequence(string s, string t) {
        int i=0;int j=0;
       while(i<s.length() && j<t.length()){
           if(s[i]==t[j]){
               i++;j++;
           }
           else j++;
       }
       return (i==s.length());
    }    
    
int main(){
    string str1;
    cout<<"enter the word  in string 1:";
    getline(cin,str1);
   // string str2;
   // cout<<"enter the word  in string 2:";
   // getline(cin,str2);
    //cout<<LengthOfString(str);
    //cout<<str.length();
    //cout<<endl;
    //ToggleOfString(str);
    //cout<<endl;
    //cout<<CountWord(str);
    //cout<<endl;
    //int n;cout<<"enter the value of n:";cin>>n;
   // char a[n];
    //cin>>a;
    //cout<<ispallindrome(a,n);cout<<endl;
    //ReverseTheString(a,n);
    //cout<<ReverseWords(str1);
    //cout<<transform (str1,str2);
    cout<<minLength(str1);
}