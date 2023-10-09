#include<bits/stdc++.h>
using namespace std;

//selection sort(In selection sort we put smallest element of array in intial position first)
// TC(O(N^2))
void Selection_sort(int arr[],int n){
    for(int i=0;i<=(n-2);i++){
        int mini=i;
        for(int j=i;j<=(n-1);j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
            swap(arr[mini],arr[i]);
        }
    }
}

//Bubble sort(In this sort we put max element in the final pos of array)
//TC(O(N^2))
void Bubble_sort(int arr[],int n){
 for(int i=n-1;i>=0;i--){
    for(int j=0;j<=(i-1);j++){
        if(arr[j]>arr[j+1])
        swap(arr[j],arr[j+1]);
    }
  }
}

//Insertion sort

void Insertion_sort(int arr[],int n){
    for(int i=0;i<=(n-1);i++){
       int j=i;
       while(j>=0 && arr[j]>arr[j-1]){
        swap(arr[j],arr[j-1]);
        j--;
       }

    }
}

// MERGE SORT 
vector<int>  merge(int arr[],int n,int low,int mid,int high){
  int i=low,j=mid+1;
  vector<int>ans;
  while(i<=mid && j<=high){
  if(arr[i]<arr[j]){
    ans.push_back(arr[i]);
     i++;
  }
  else{
    ans.push_back(arr[j]);
    j++;
  }
 }
}

void merge_sort(int arr[],int n,int low,int high){
    if(low>=high) return;
    int mid=low+(high-low)/2;
    merge_sort(arr,n,low,mid);
    merge_sort(arr,n,mid+1,high);
    merge(arr,n,low,mid,high);
}

// ADD DIGIT IP: 38 OP: 38->3+8=11-> 1+1=2

 int addDigits(int num) {
    int sum=0;
        if(num==0) return 0;
        while(num>9){
            while(num!=0){
                int digit=num%10;
                sum+=digit;
                num=num/10;
            }
            num=sum;
            sum=0;
        }
        return num;
    }

// HAPPY NUMBERS IP: 68 OP: 68->6^2+8^2=100->1^2+0^2+0^2=1=YES IT IS HAPPY NUMBER

 int nextNumber(int n){
        int newNumber = 0;
        while(n!=0){
            int num = n%10;
            newNumber += num*num;
            n = n/10;
        }
        return newNumber;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n!=1 && !set.count(n)){
            set.insert(n);
            n = nextNumber(n);
        }
        return n==1;
    }

//UGLY NUMBER IP: 6 OP: 6->2*3(IT INCLUDE ONLY 2,3 AND 5)PRIME FACTOR

 bool isUgly(int n) {
        if(n==1) return true;
        if(n<=0) return false;
        for(int i=1;i<=n;i++){
            if(n%2==0) n=n/2;
           else if(n%3==0) n=n/3;
           else if(n%5==0) n=n/5;
           else return false;
        }
        return true;
    }

// CONTAIN DUPLICATES 
bool containsDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]>1) return true;
        }
        return false;
    }

//REMOVE DUPLICATE FROM AN ARRAY
 int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;}

// VALID ANAGRAM STRINGS
 bool isAnagram(string s, string t) {
        int hsh[26];
        for(int i=0;i<s.length();i++) hsh[s[i]-'a']++;
        for(int j=0;j<t.length();j++) hsh[t[j]-'a']--;
        for(int i=0;i<26;i++){
            if(hsh[i]!=0) return false;
        }
        return true;
 }  

// MISSING NUMBER IN AN ARRAY IN RANGE[0,N](N->SIZE OF ARRAY)
 int missingNumber(vector<int>& nums) {
         int n = nums.size() + 1;
        int total = (n * (n-1)) / 2;
        
        for (int num : nums) {
            total -= num;
        }
        
        return total;
    }

//MOVE ZEROES TO RIGHT SIDE OF AN ARRAY
 void moveZeroes(vector<int>& nums) {
        if(nums.size()==1) return ;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
            swap(nums[i],nums[cnt]);
            cnt++;
            }
        }
    }

//WORD PATTERN FOR EG=Input: pattern = "abba", s = "dog cat cat dog"
//                    Output: true  
 bool wordPattern(string pattern, string s) {
    //stringstream function is used to split the string word wise

      stringstream str(s);
      string word;
      vector<string>words;
      while(str>>word){
          words.push_back(word);
      }
      if(pattern.size()!=words.size()) return false;
      map<char,string>charToString;
      map<string,char>stringToChar;
      for(int i=0;i<pattern.length();i++){
          if(charToString.find(pattern[i])==charToString.end()&&
          stringToChar.find(words[i])==stringToChar.end()){
              charToString[pattern[i]]=words[i];
              stringToChar[words[i]]=pattern[i];
          }
          else if(charToString[pattern[i]]!=words[i]) return false;
      }
      return true;
    } 

// INTERSECTION OF TWO ARRAYS
 vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int i=0;int j=0;
        int n=nums1.size();
        int m=nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<n && j<m){
            if(i>0 && nums1[i]==nums1[i-1]){
                i++; continue;
            }
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++;j++;
            }
            else if(nums1[i]>nums2[j]){
              j++;
            }
            else i++;
        }
        return ans;}

// countbits ip: 2 op: [0,1,1] 2->10=1+0==1;
 vector<int> countBits(int n) {
        vector<int>ans(n+1);
        ans[0]=0;
        for(int i=1;i<=n;i++){
            ans[i]=ans[i/2]+i%2;
        }
        return ans;
    }

// DIFFERENCE IN STRING IP S="abcd" t="abcde" OP "e";
 char findTheDifference(string s, string t) {
        int sSum=0;int tSum=0;
        for(int i=0;i<s.length();i++){
            sSum+=s[i];
        }
        for(int i=0;i<t.length();i++){
            tSum+=t[i];
        }
        char ans=(tSum-sSum);
        return ans;
    }
 //Find All Numbers Disappeared in an Array Input: nums = [4,3,2,7,8,2,3,1] output: [5,6]
  vector<int> findDisappearedNumbers(vector<int>& nums) {
         unordered_map<int, int> mp;
        for(int i=0 ; i<nums.size() ; i++)
        {
            mp[i+1]++;
            mp[nums[i]]++;
        }
        nums.clear();
        for( auto it:mp)
        {
            if(it.second==1)
            {
                nums.push_back(it.first);
            }
        }
        return nums;}
//Max Consecutive Ones Input: nums = [1,1,0,1,1,1] Output: 3
 int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
                maxi=max(maxi,cnt);
            }
            else cnt=0;
        }
        return maxi;
    }
//  Next Greater Element I
 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int j=0;int i=0;
       while(j<nums2.size() || i<nums1.size()){
           if(nums1[i]!=nums2[j]) j++;
           else if(nums1[i]==nums2[j]) {
               if(nums1[i]<nums2[j+1]){
                 ans.push_back(nums2[j+1]);
                 i++;j=0;}
               else ans.push_back(-1);
           }
       }
       return ans;
    }

// REVERSE THE STRING BY K
 void reverse(string &s,int l,int r){
        for(size_t i=l,j=r;i<j;i++,j--) swap(s[i],s[j]);
    }
    string reverseStr(string s, int k) {
        bool flag=true;
        for(int i=0;i<s.length();i++){
            if(flag){
                if(i+k-1 >=s.length()) reverse(s,i,s.length()-1);
                else reverse(s,i,i+k-1);
                flag=false;
            }
            else flag=true;
        }
        return s;
    }
// ANOTHER WAY TO CODE SAME PROBLEM
 string reverseStr(string s, int k) {
        for(int i = 0 ; i < s.size() ; i=i+(2*k)){
            int st = i;
            int e = i+k-1;
            if(e>=s.size()){
                e = s.size()-1;
            }
            while(st<e){
                swap(s[st++],s[e--]);
            }
         }
        return s;
       
    }            
//Sum of Middle Elements of two sorted arrays N = 5 Ar1[] = {1, 2, 4, 6, 10} Ar2[] = {4, 5, 6, 9, 12} Output: 11
//Explanation: The merged array looks like {1,2,4,4,5,6,6,9,10,12}. Sum of middle elements is 11 (5 + 6).
int findMidSum(int ar1[], int ar2[], int n) {
         int arr[n+n];
           int i=0;
           int j=0;
           int k=0;
           while(i<n && j<n)
           {
               if(ar1[i]<=ar2[j])
                   arr[k++]=ar1[i++];
               else  arr[k++]=ar2[j++];
           }
           while(i<n)
          {
              arr[k++]=ar1[i++];
          }
          while(j<n)
          {
              arr[k++]=ar2[j++];
          }
           int s=0;
           int e=(n+n)-1;
           int mid=s+(e-s)/2;
           int sum=0;
           sum=arr[mid]+arr[mid+1];
           
           return sum;
    }
//Subarray with 0 sum Input:5          Output: YES Explanation: 2, -3, 1 is the subarray with sum 0.
//                          4 2 -3 1 6   
//This code uses an unordered map to keep track of the cumulative sum at each index. It iterates through the array, updating the sum and checking if the sum exist
//s in the map. If the sum already exists in the map, it means there is a subarray with a sum of zero.                    
 bool subArrayExists(int arr[], int n)
    {
      unordered_map<int,int>mp;
      int sum=0;
      for(int i=0;i<n;i++){
          sum+=arr[i];
          mp[sum]++;
          if(mp[sum]>=2 || sum==0) return true;
      }
      return false;
    } 
//Maximum Product Subarray Arr[] = {6, -3, -10, 0, 2} output: 180([6, -3, -10] which gives product as 180)
long long maxProduct(vector<int> arr, int n) {
	    long long product=1;
	    long long maxi=arr[0];
	    for(int i=0;i<n;i++){
	        if(arr[i]==0) product=1;
	        product*=arr[i];
	        maxi=max(maxi,product);
	    }
	    product=1;
	    for(int i=n-1;i>=0;i--){
	        product*=arr[i];
	        maxi=max(maxi,product);
	        if(arr[i]==0) product=1;
	    }
	    return maxi;
	}  

//Minimum Swaps to Sort 
int binary(vector<int>&nums,int k){
        int s=0;int e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==k) return mid;
            else if(nums[mid]>k) e=mid-1;
            else s=mid+1;
        }
    }
	int minSwaps(vector<int>&nums)
	{
	    vector<int>ans;
	    for(int i=0;i<nums.size();i++) ans.push_back(nums[i]);
	    sort(nums.begin(),nums.end());
	    int cnt=0;
	    for(int i=0;i<nums.size();i++){
	        if(nums[i]!=ans[i]){
	            int ind=binary(nums,ans[i]);
	            swap(ans[i],ans[ind]);
	            cnt++; i--;
	        }
	    }
	    return cnt;
	}
//Zero Sum Subarrays arr[] = {0,0,5,5,0,0} Output: 6 Explanation: The 6 subarrays are [0], [0], [0], [0], [0,0], and [0,0].
 long long int findSubarray(vector<long long int> &arr, int n ) {
        long long int cnt=0;
        long long int sum=0;
        unordered_map<long long int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp.find(sum)!=mp.end()) cnt+=mp[sum];
            mp[sum]++;
        }
        return cnt;
    }
//Find Pair Given Difference L = 6, N = 78 arr[] = {5, 20, 3, 2, 5, 80} Output: 1 Explanation: (2, 80) have difference of 78.
//BINARY SEARCH APPROACH
bool binarysearch(int arr[],int start,int end,int target){
    int low=start;int high=end;
    int mid=start+(end-start)/2;
    while(low<=high){
        if(arr[mid]==target) return true;
        else if(target>arr[mid]) low=mid+1;
        else high=mid-1;
        mid=low+(high-low)/2;
    }
    return false;
}

bool findPair(int arr[], int size, int n){
    sort(arr,arr+size);
    for(int i=0;i<size;i++){
        int target=n+arr[i];
        if(target>arr[size-1]) continue;
        else {
            if(binarysearch(arr,i+1,size-1,target)) return true;
        }
    }
    return false;
}  
// Replace All ?'s to Avoid Consecutive Repeating Characters Input: s = "?zs" Output: "azs"
 string modifyString(string s) {
       int n=s.length();
       for(int i=0;i<n;i++){
           if(s[i]=='?'){
               for(char j='a';j<='z';j++){
                   if(i-1>=0 && j==s[i-1]) continue;
                   if(i+1<n && j==s[i+1]) continue;
                   s[i]=j;
                   break;
               }
           }
       }
       return s;
    }
// Search in Rotated Sorted Array II Input: nums = [2,5,6,0,0,1,2], target = 0 Output: true
 bool search(vector<int>& nums, int target) {
        int start=0;int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]==nums[start] && nums[mid]==nums[end]){
                start++;end--;
            }
            else if(nums[mid]>=nums[start]){
                if(target>=nums[start] && target<nums[mid]) end=mid-1;
                else start=mid+1;
            }
            else if(nums[mid]<=nums[end]){
                if(target>nums[mid] && target<=nums[end]) start=mid+1;
                else end=mid-1;
            }
        }
        return false;
    }    

