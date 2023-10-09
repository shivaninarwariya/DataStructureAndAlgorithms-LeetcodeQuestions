#include<bits/stdc++.h>
using namespace std;

int CountOneBit(int n){
    int count=0;
    while(n!=0){
    if(n&1){
        count++;
    }
    n=n>>1;
}
return count;
}

int binary(int n){
    int ans=0;
    int i=0;
    while(n!=0){
        int bit=n&1;
        ans=bit*(pow(10,i))+ans;
        n=n>>1;
        i++;

    }
    return ans;
}

int negative(int &n){
    int temp=~n;
    return temp;
}

void PowerOfTwo(int n){
    if((n&(n-1))==0){
        cout<<" power of 2";
    }
    else{
        cout<<"  not a power of 2";
    }
}
// SUM OF NUMBERS WHICH IS DIVISIBLE BY 3 5 7 
 int sumOfMultiples(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            if(i%3==0 || i%5==0 || i%7==0){
             sum+=i;
            }
        }
        return sum;
    }

//Non Repeating Numbers N = 2 arr[] = {1, 2, 3, 2, 1, 4} OUTPUT:  3 4 Return in increasing order.
 vector<int> singleNumber(vector<int> nums) 
    {
       map<int,int>mp;
       vector<int>ans;
       for(int i=0;i<nums.size();i++) mp[nums[i]]++;
       for(int i=0;i<nums.size();i++){
           if(mp[nums[i]]==1) ans.push_back(nums[i]);
       }
       sort(ans.begin(),ans.end());
       return ans;
    }  

//Bit Difference Input: A = 10, B = 20 Output: 4 EXPLAINATION: A  = 01010 B  = 10100
 int countBitsFlip(int a, int b){
        int Xor=a^b;
        int cnt=0;
        while(Xor!=0){
            int bit=Xor&1;
            if(bit) cnt++;
            Xor=Xor>>1;
        }
        return cnt;
    }

//Copy Set Bits in Range X = 44, Y = 3 Output: 47 Explaination: Binary represenation of 44 and 3 is 101100 and
//11. So in the range 1 to 5 there  are two set bits. If those are set in 44 it will become 101111 which is 47.
//OR operator is used to set bit ans AND operator is used to unset the bits
int setSetBit(int x, int y, int l, int r){
        int mask=0;
        for(int i=l;i<=r;i++){
            mask=mask | y&(1<<(i-1));
        }
        return x| mask;
    }    

//Count Common Words With One Occurrence Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"] Output: 2
// the number of strings that appear exactly once in each of the two arrays.
 int countWords(vector<string>& words1, vector<string>& words2) {
        int cnt=0;
       unordered_map<string,int>mp1,mp2;
       for(auto it1:words1) mp1[it1]++;
       for(auto it2:words2) mp2[it2]++;
       for(auto it:words1){
           if(mp1[it]==1 && mp2[it]==1) cnt++;
       }
       return cnt;
    }

//. Positions of Large Groups Input: s = "abcdddeeeeaabbbcd" Output: [[3,5],[6,9],[12,14]] Explanation: The large groups are "ddd", "eeee", and "bbb".
vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        for (int i = 0, j = 0; i < s.size(); i = j) {
            while (j < s.size() && s[j] == s[i]) ++j;
            if (j - i >= 3)
                res.push_back({i, j - 1});
        }
        return res; 
    }

//Sort Characters By Frequency  Input: s = "tree" Output: "eert"sort it in decreasing order based on the frequency of the characters.
//'e' appears twice while 'r' and 't' both appear once.so 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.   
 string frequencySort(string s) {
        string ans="";
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++) mp[s[i]]++;
        priority_queue<pair<int,char>>qu;
        for(auto it:mp) qu.push({it.second,it.first});
        while(!qu.empty()){
            int cnt=qu.top().first;
            while(cnt--) ans+=qu.top().second;
            qu.pop();        
            }
        return ans;    
    }

//Unique Number of Occurrences Input: arr = [1,2,2,1,1,3] Output: true Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
 bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        set<int>s1;
        set<int>s2;
        for(int i=0;i<arr.size();i++) {
            mp[arr[i]]++;
            s1.insert(arr[i]);
        }
        for(auto it:mp){
            s2.insert(it.second);
        }
        return s1.size()==s2.size();
    }

//Duplicate Zeros Input: arr = [1,0,2,3,0,4,5,0] Output: [1,0,0,2,3,0,0,4] Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
 void duplicateZeros(vector<int>& arr) {
       vector<int>ans(arr.begin(),arr.end());
       int i=0;
       for(int j=0;j<ans.size() && i<ans.size();j++){
           if(ans[j]==0){
               arr[i]=0;
               if(i+1<ans.size()) arr[i+1]=0;
               i+=2;
           }else{
               arr[i]=ans[j];
               i++;
           }
       } 
    }

//Maximum Number of Balloons Input: text = "loonbalxballpoon" Output: 2
 int maxNumberOfBalloons(string text) {
      int b=0, a=0, l2=0, o2=0, n=0;  
        for(int i=0;i<text.size();i++){
            if(text[i]=='b') b++;
            else if(text[i]=='a') a++;
            else if(text[i]=='l') l2++;
            else if(text[i]=='o') o2++;
            else if(text[i]=='n') n++;
        }
        l2=l2/2;  o2=o2/2;  //both occours 2 times in the balloon
        int ans=min({b, a, l2, o2, n}); // min occourence of the char would be the solution
        return ans;
    }  

//Element Appearing More Than 25% In Sorted Array  Input: arr = [1,2,2,6,6,6,6,7,10] Output: 6
int findSpecialInteger(vector<int>& arr) {
        int n=ceil(arr.size()*1/4);
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]]++;
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]]>n) return arr[i];
        }
        return -1;
    }

//Maximum Count of Positive Integer and Negative Integer Input: nums = [-3,-2,-1,0,0,1,2] Output: 3 Explanation: There are 2 positive integers and 3 negative integers. The maximum count among them is 3.
 int maximumCount(vector<int>& nums) {
        int pos=0;int neg=0;int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) pos++;
            else if(nums[i]<0) neg++;
            maxi=max(pos,neg);
        }
        return maxi;
    }

// Find the Difference of Two Arrays Input: nums1 = [1,2,3], nums2 = [2,4,6] Output: [[1,3],[4,6]] explaination answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
//answer[1] is a list of all distinct integers in nums2 which are not present in nums1. 
 vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        unordered_set<int>s1,s2;
        vector<int>res1;
        unordered_map<int,int>mp1,mp2;
        for(int i=0;i<nums1.size();i++) mp1[nums1[i]]++;
        for(int i=0;i<nums2.size();i++) mp2[nums2[i]]++;
        for(int i=0;i<nums1.size();i++){
            if(mp2.find(nums1[i])==mp2.end()) s1.insert(nums1[i]);
        }
        for(auto i:s1) res1.push_back(i);
        ans.push_back(res1);
        vector<int>res2;
        for(int i=0;i<nums2.size();i++){
            if(mp1.find(nums2[i])==mp1.end()) s2.insert(nums2[i]);
        }
        for(auto i:s2) res2.push_back(i);
        ans.push_back(res2);
        return ans;
    }                          
int main(){
    int n;
    cout<<"enter the value of n:";cin>>n;
    //cout<<binary(n);
   PowerOfTwo(n);cout<<endl;
    cout<<CountOneBit(n);

}