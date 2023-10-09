#include<bits/stdc++.h>
using namespace std;

// Reverse Words in a String Input: s = "  hello world  " Output: "world hello" Explanation: Your reversed string should not contain leading or trailing spaces.
//Input: s = "a good   example" Output: "example good a" Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 string reverseWords(string s) {
    string ans="";
    string temp="";
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]==' '){
            if(temp!=""){
            reverse(temp.begin(),temp.end());
            ans+=temp;
            ans.push_back(' ');
            temp="";
        }
        }
        else{
            temp.push_back(s[i]);
        }
    }
    reverse(temp.begin(),temp.end());
    ans+=temp;
    int n=ans.length();
    if(ans[n-1]==' ')  ans.pop_back();//to remove extra space at the end
    return ans;
    }

// Product of Array Except Self Input: nums = [1,2,3,4] Output: [24,12,8,6]
//DYNAMMIC PROGRAMMING PROBLEM 
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        ans[0]=1;
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        int right=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=right;
            right*=nums[i];
        }
        return ans;
    }

// Merge Strings Alternately Input: word1 = "abc", word2 = "pqr" Output: "apbqcr" 
 string mergeAlternately(string word1, string word2) {
       string ans="";
       int i=0; int j=0;
       while(i<word1.length() || j<word2.length()){
            if(i<word1.length()) ans+=word1[i];
            if(j<word2.length()) ans+=word2[j];
           if(i<word1.length())
           i++;
           if(j<word2.length())j++;
       }
      return ans;
    }

//Max Consecutive Ones III Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2 Output: 6 Explanation: [1,1,1,0,0,1,1,1,1,1,1]
//Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.  
int longestOnes(vector<int>& nums, int k) {
       int temp=0;int maxi=0;int zerocnt=0;
       for(int i=0;i<nums.size();i++){
           if(nums[i]==0) zerocnt++;
           while(zerocnt>k){
               if(nums[temp]==0) zerocnt--;
               temp++;
           }
           maxi=max(maxi,i-temp+1);
       }
       return maxi;
    }
// Group Anagrams Input: strs = ["eat","tea","tan","ate","nat","bat"] Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
// Pow(x, n) Input: x = 2.00000, n = -2 Output: 0.25000 Explanation: 2-2 = 1/22 = 1/4 = 0.25
 double myPow(double x, int n) {
       //x=base n=power of number 
       if(n<0){
           x=1/x;
           n=abs(n);
       }
       double res=1;
       while(n>0){
          if(n%2==0){
              x=x*x;
              n=n/2;
          }
          else{
              res=res*x;
              n--;
          }
       }
       return res;
    } 
//Find Pivot Index Input: nums = [1,7,3,6,5,6] Output: 3 Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 Right sum = nums[4] + nums[5] = 5 + 6 = 11
 int pivotIndex(vector<int>& nums) {
        vector<int>prefixsum(nums.size()+1,0);
        for(int i=0;i<nums.size();i++)
          prefixsum[i+1]=prefixsum[i]+nums[i];
        for(int i=0;i<nums.size();i++){
            int left=prefixsum[i];
            int right=prefixsum[nums.size()]-prefixsum[i+1];
            if(left==right) return i;
        } 
        return -1; 
    }
       
int main(){
    int n; cout<<"enter the value of n:";
    cin>>n;
    cout<<n;
    return 0;
}