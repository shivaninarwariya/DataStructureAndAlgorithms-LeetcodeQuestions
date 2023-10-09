#include<bits/stdc++.h>
using namespace std;

int CountDigit(long int n){
    int count=0;
    while(n!=0){
        int temp=n%10;
        n=n/10;
        count++;
    }
    return count;
}

void CountNto1(long int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    CountNto1(n-1);
}

void fun( long int n){
    if(n==0){
        return;
    }
    fun(n/2);
    cout<<(n%2);
}

int SumOfDigit(long int n){
    if(n==0)
    return 0;

    return SumOfDigit(n/10)+n%10;
}

int ReverseInteger(long int n){
    int reverse=0;
    while(n!=0){
        if(reverse<INT_MIN/10||reverse>INT_MAX/10){return 0;}
        reverse=reverse*10 + n%10;
        n=n/10;
    }
    return reverse;
}

void SayDigit(string arr[], long int n){
    if(n==0)
    return;
    int digit=n%10;n=n/10;
    SayDigit(arr,n);
    cout<<arr[digit]<<" ";
}
// Find N Unique Integers Sum up to Zero Input: n = 5 Output: [-7,-1,1,3,4] Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
 vector<int> sumZero(int n) {
        vector<int>res(n);
        int temp;
        if(n%2==0){
            temp=n/2;
            res[n-1]=0;
        }else
            temp=(n-1)/2;
            for(int i=1;i<=temp;i++){
                res[i-1]=-1*i;
                res[i-1+temp]=i;
            }
        return res;
    }
//Rank Transform of an Array Input: arr = [40,10,20,30] Output: [4,1,2,3] Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
 vector<int> arrayRankTransform(vector<int>& arr) {
        int rank=1;
        map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        vector<int>ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans=it->second;
            int ind;
            for(int i=0;i<ans.size();i++){
                ind=ans[i];
                arr[ind]=rank;
            }
            rank++;
        }
        return arr;
    }    
//Find Lucky Integer in an Array Input: arr = [1,2,2,3,3,3] Output: 3 Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
 int findLucky(vector<int>& arr) {
       unordered_map<int,int>mp;
       int maxi=0;
       for(int i=0;i<arr.size();i++) mp[arr[i]]++;
       for(int i=0;i<arr.size();i++){
           if(mp[arr[i]]==arr[i]){
               if(arr[i]>maxi) maxi=arr[i];
           }
       }
       if(maxi!=0) return maxi;
       return -1; 
    }
//Minimum Value to Get Positive Step by Step Sum Input: nums = [-3,2,-3,4,2] Output: 5 
 int minStartValue(vector<int>& nums) {
        int ans=0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=min(ans,sum);
        }
        return -ans+1;
    }
// Reformat The String  Input: s = "a0b1c2" Output: "0a1b2c" Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
string reformat(string s) {
      string a="",d="";
        for(auto x:s)
            isalpha(x)?a.push_back(x):d.push_back(x);
        if(abs(int(a.size()-d.size()))>1)
            return "";
        bool alpha=a.size()>d.size();
        int i=0,j=0,k=0;
            while(i<s.size()){
                if(alpha){
                    s[i++]=a[j++];
                }
                else{
                    s[i++]=d[k++];
                }
                alpha=!alpha;
            }
        return s;
    }     
//Remove Duplicates from Sorted Array II Input: nums = [1,1,1,2,2,3] Output: 5, nums = [1,1,2,2,3,_] Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
//It does not matter what you leave beyond the returned k (hence they are underscores).
 int removeDuplicates(vector<int>& nums) {
      int j=0;
      for(int i=0;i<nums.size();i++){
          if(j<2 || nums[i]>nums[j-2]) nums[j++]=nums[i];
      }
      return j;
    }
// Integer to Roman Input: num = 3 Output: "III" Explanation: 3 is represented as 3 ones.
string intToRoman(int num) {
 string Roman = "";
vector<pair<int, string>> storeIntRoman = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
     for (int i = 0; i < storeIntRoman.size(); i++) {
        while (num >= storeIntRoman[i].first) {
            Roman += storeIntRoman[i].second;
            num -= storeIntRoman[i].first;
            }
        }
        return Roman;
    }
// Sum of All Odd Length Subarrays Input: arr = [1,2] Output: 3 Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
 int sumOddLengthSubarrays(vector<int>& arr) {
       int n=arr.size();
       int answer=0;
       for(int i=0;i<n;i++){
           int left=i;int right=n-i-1;
           answer+=arr[i]*(left/2+1)*(right/2+1);
           answer+=arr[i]*((left+1)/2)*((right+1)/2);
       }
       return answer;
    }  
// Shuffle the Array Input: nums = [2,5,1,3,4,7], n = 3 Output: [2,3,5,4,1,7]  Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
 vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        int i=0;int j=0;
        while(j<n){
            j++;
        }
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
            if(j<nums.size()){
                ans.push_back(nums[j]);
                j++;
            }
        }
        return ans;
    }

//Running Sum of 1d Array Input: nums = [1,2,3,4] Output: [1,3,6,10] Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
vector<int> runningSum(vector<int>& nums) {
        //question based on prefix sum
        int presum=0;
        for(int i=0;i<nums.size();i++){
          presum+=nums[i];
          nums[i]=presum;
        }
        return nums;
    }
//Get Maximum in Generated Array Input: n = 7 Output: 3 explaination: nums[0] = 0 nums[1] = 1 nums[2 * i] = nums[i] when 2 <= 2 * i <= n nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
//DP BASED PROBLEM
 int getMaximumGenerated(int n) {
        if (n < 2) return n;
        vector<int> dp(n+1);
        int m = INT_MIN;
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (i % 2) dp[i] = dp[i / 2] + dp[i / 2 + 1];
            else dp[i] = dp[i / 2];
            m = max(dp[i], m);
        }
        return m;
    }  
//Three Consecutive Odds Input: arr = [1,2,34,3,4,5,7,23,12] Output: true Explanation: [5,7,23] are three consecutive odds.
 bool threeConsecutiveOdds(vector<int>& arr) {
        bool ans=false;
        int i=0;int j=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2!=0){
                if((j+1)<arr.size()){
                if(arr[j]%2!=0 && arr[j+1]%2!=0) {
                     ans =true;
                     break;}
                }
            }
            j++;
        }
        if(ans==true) return true;
        return false;
    }
// Kth Missing Positive Number Input: arr = [2,3,4,7,11], k = 5 Output: 9 Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
int findKthPositive(vector<int>& arr, int k) {
       int cnt=0;
       int i=0;int j=1;
       while(cnt!=k){
           if(i<arr.size() && arr[i]==j) i++;
           else cnt++;
           if(cnt==k) return j;
           j++;
       }
       return 0;
    }
//Make The String Great Input: s = "leEeetcode" Output: "leetcode" Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
string makeGood(string s) {
        stack<char> t;
        t.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(t.empty()!=true && t.top()+32==s[i])
                t.pop();
            else if(t.empty()!=true && t.top()==s[i]+32)
                t.pop();
            else
                t.push(s[i]);
        }
        s="";
        while(t.empty()!=true)
        {
            s.push_back(t.top());
            t.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
//Maximum Number of Vowels in a Substring of Given Length Input: s = "abciiidef", k = 3 Output: 3 Explanation: The substring "iii" contains 3 vowel letters.
 bool check(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int ans=0;
        int count=0;
        for(int i=0;i<k;i++){
            if(check(s[i]))count++;
        }
        ans=count;
        int i=0,j=k;
        while(j<s.size()){
            if(check(s[j]))count++;
            if(check(s[i]))count--;
            ans=max(ans,count);
            j++;
            i++;
        }
        return ans;
    }
// Set Matrix Zeroes
  void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int>ump;
        unordered_map<int,int>mp;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    ump[i]=1;
                    mp[j]=1;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(ump[i] || mp[j]){
                    matrix[i][j]=0;
                }
            }
        }
  
    } 
//Detect Pattern of Length M Repeated K or More Times Input: arr = [1,2,1,2,1,1,1,3], m = 2, k = 2 Output: trueExplanation: The pattern (1,2) of length 2 is repeated 2 consecutive times. Another valid pattern (2,1) is also repeated 2 times.
 bool containsPattern(vector<int>& arr, int m, int k) {
        int cnt=0;
        for(int i=0;(i+m)<arr.size();i++){
            if(arr[i]!=arr[i+m]) cnt=0;
            cnt+=(arr[i]==arr[i+m]);
            if(cnt==(k-1)*m) return true;
        }
      return false;
    }                                      
int main(){
    long int n;
    cout<<"enter the value of n:";
    cin>>n;
    cout<<CountDigit(n);
    cout<<endl;
    fun(n);cout<<endl;
    CountNto1(n);cout<<endl;
    cout<<SumOfDigit(n);cout<<endl;
    cout<<ReverseInteger(n);cout<<endl;
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    //int nt;cout<<"enter the value of nt:";cin>>nt;
    SayDigit(arr,n);
    return 0;
}