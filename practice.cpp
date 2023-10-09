#include<bits/stdc++.h>
using namespace std;
// only reverse the vowel in the string 

string reverseVowels(string s) {
        int start=0; int end=s.length()-1;
        while(start<=end){
            if((s[start]=='a'|| s[start]=='e'|| s[start]=='i'|| s[start]=='o'|| s[start]=='u' ||s[start]=='A'|| s[start]=='E'||s[start]=='I' ||s[start]=='O' || s[start]=='U')) {
                if( (s[end]=='a'|| s[end]=='e'|| s[end]=='i'|| s[end]=='o'|| s[end]=='u' ||s[end]=='A'|| s[end]=='E'||s[end]=='I' ||s[end]=='O' || s[end]=='U') ){
                swap(s[start],s[end]);
                start++; end--;
                }  
            else{
                end--;
            }
            }    
            else{
                start++;
            }
        }
        return s;
      }
//BALAMCED PARANTHESIS PROBLEM
 bool ispar(string x){ 
       stack<char>st;
       for(int i=0;i<x.length();i++){
           char ch=x[i];
           if(x[i]=='[' || x[i]=='{' || x[i]=='(') st.push(x[i]);
           else{
               if(!st.empty()){
                  char tp=st.top();
                  if((ch==']'&& tp=='[') || (ch=='}'&& tp=='{') || (ch==')'&& tp=='(')) st.pop();
                  else return false;
               }
               else {return false;}
           }  
       }
         if (st.empty())
        return true ;
        return false ;
    }
//ROMAN TO DECIMAL CONVERSION PROBLEM SOLUTION
 int romanToDecimal(string &str) {
         map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int sum=0;
        for(int i=0;i<str.length();i++){
            if(mp[str[i]]<mp[str[i+1]]) sum-=mp[str[i]];
            else sum+=mp[str[i]];
        }
        return sum;
    }
    
// MAXIMISE THE ARRAY AND RETURN THE MAX SUM IN AN ARRAY BY REPLACING MAX ELEMENT TO M+1;
int maximizeSum(vector<int>& nums, int k) {
    int maxi=nums[0]; int sum=0;
    for(int i=0;i<nums.size();i++){
        if(maxi<nums[i]) {maxi=nums[i];}
    }
    for(int i=0;i<k;i++){
    sum+=maxi;
    nums.push_back(maxi+1);
    maxi+=1;
    }
   return sum;
}
//DISTINCT DIFFERENCE ARRAY SUM (duplicate values are not allowed)
vector<int> distinctDifferenceArray(vector<int>& nums) {
     vector<int>diff(nums.size());
       int ind; set<int>s;
       for(int i=0;i<nums.size();i++){
           int left=0;int right=0;
           for(int j=0;j<=i;j++){
               s.insert(nums[j]);
           }
           left=s.size(); s.clear();
           for(int k=i+1;k<nums.size();k++){
               s.insert(nums[k]);
           }
           right=s.size(); s.clear();
           diff[ind++]=left-right;
       }
      return diff;
}
// LEFTSUM AND RIGHT SUM OF AN ARRAY
//abs() library is used for modulus 
vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>leftsum(nums.size(),0);
        vector<int>rightsum(nums.size(),0);
        vector<int>ans(nums.size());
        for(int i=1;i<=(nums.size()-1);i++){
            leftsum[i]=leftsum[i-1]+nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--){
            rightsum[i]=rightsum[i+1]+nums[i+1];
        }
        for(int i=0;i<nums.size();i++){
        ans[i]=(abs(leftsum[i]-rightsum[i]));
        }
        return ans;
    }

// Majority Element II Input: nums = [3,2,3] Output: [3] EXPLAINATION: find all elements that appear more than ⌊ n/3 ⌋ times.
//MEDIUM LEVEL PROBLEM
 vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        unordered_set<int>s;
        int n=floor(nums.size()/3);
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]>n) s.insert(nums[i]);
        }
        for(auto it=s.begin();it!=s.end();it++){
            ans.push_back(*it);
        }
        return ans;
    } 

//Majority Element Input: nums = [2,2,1,1,1,2,2] Output: 2 explaination: The majority element is the element that appears more than ⌊n / 2⌋ times.
//EASY LEVEL PROBLEM 
int MajorityElement(vector<int>& nums){
        unordered_map<int,int>mp;
        int n=floor(nums.size()/2);
        int ans;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        for(int i=0;i<nums.size();i++){
           if(mp[nums[i]]>n){
               ans=nums[i];
               break;
           }
        }
        return ans;
    }

// clever method
// Most Frequent Even Element Input: nums = [0,1,2,2,4,4,1] Output: 2 Explanation:The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.We return the smallest one, which is 2.
    int mostFrequentEven(vector<int>& A) {
        //For Runtime allocation in place of using array of size 10^5
        unordered_map<int,int> mp;
        int val=1e6,freq=0;
        for(auto i:A){
            //if even element
            if(i%2==0){
                //increase frequency in map
                mp[i]++;
                //Update smallest with greatest frequency
                if(mp[i]>freq or mp[i]==freq and i<val){
                    val=i;
                    freq=mp[i];
                }
            }
        }
        return freq==0? -1 : val;
    }
//same above problem have different solution
int MostFrequentEven(vector<int>& nums) { 
     int ans=-1;
     vector<int>findmax;
     vector<int>even;
     unordered_map<int,int>mp;
     for(int i=0;i<nums.size();i++){
         if(nums[i]%2==0) mp[nums[i]]++;
     }
     int max=0;
     for(auto it:mp){
         findmax.push_back(it.second);
     }
     if(findmax.size()==0) return ans;
     sort(findmax.begin(),findmax.end());
     max=findmax[findmax.size()-1];
     for(auto it:mp){
         if(it.second==max) even.push_back(it.first);
     } 
     sort(even.begin(),even.end());
     if(even.size()>=1) return even[0];
     else return ans;
    }    


 int main(){
   // string x;
    //getline(cin,x);
    //cout<<ispar(x);
    vector<int>nums(3,5);
    int k;cout<<"enter the value of k: ";cin>>k;
    cout<<maximizeSum(nums,k);
 }   