#include<bits/stdc++.h>
using namespace std;
//subset generation 
vector<vector<int>>allsubset;

void generation(vector<int>&subset,int i,vector<int>&nums){
    if(i==nums.size()){
      allsubset.push_back(subset);
      return;
    }
    //backtracking
    //not including ith element in subset
    generation(subset,i+1,nums);
    //including ith element in subset
    subset.push_back(nums[i]);
    generation(subset,i+1,nums);
    subset.pop_back();
}

int SumOfPair(int arr[],int n){
    int j=1;int max=0;
    for(int i=0;i<n;i++){
        if((arr[i]+arr[j])>max){
            max=arr[i]+arr[j];
        }
        j++;
    }
    return max;
}
//kedane algorithm
int MaximumSumSubarray(int arr[],int n){
    int max_so_far=INT_MIN; int max_ending=0;
    for(int i=0;i<n;i++){
        max_ending+=arr[i];
        if(max_so_far<max_ending)max_so_far=max_ending;
        if(max_ending<0)max_ending=0;
    }
    return max_so_far;
}
//time complexicity O(n)
 void GivenSum(int arr[],int n,int sum){
    int i=0;int j=n-1;
    while(i<=j){
    if((arr[i]+arr[j])==sum)return;
    if((arr[i]+arr[j])<sum)i++;
    if((arr[i]+arr[j])>sum)j--;
   }
 }

 void prefixSum(int arr[],int n){
    int sum[n];
    int maxi1=INT_MIN;
    int mini1=INT_MAX;
    int maxi2=arr[1];int mini2=arr[1];
    for(int i=1;i<n;i++){
        sum[0]=arr[0];
        sum[i]=sum[i-1]+arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<sum[i]<<" ";
    }
    for(int i=0;i<n;i++){
        if(sum[i]<mini1){
         mini1=sum[i];
        }
         else if(sum[i]>maxi1){
            maxi1=sum[i];
        }
    }cout<<endl;
    cout<<maxi1<<" "<<mini1<<" "<<endl;
    for(int i=2;i<n;i++){
        if(arr[i]<mini2){
            mini2=arr[i];
        }else if(arr[i]>maxi2){
            maxi2=arr[i];
        }
    }
    cout<<maxi2<<" "<<mini2<<" "<<endl;
    vector<int>ans(3);
    ans[0]=maxi2-mini2;
    ans[1]=maxi1-mini2;
    ans[2]=maxi2-mini1;
    for(int i=0;i<3;i++){
        cout<<ans[i]<<" ";
    }
 }

//Merge Without Extra Space HARD PROBLEM
 void merge(long long arr1[], long long arr2[], int n, int m) 
 { 
          int i=n-1; int j=0;
          while(i>=0 && j<m){
              if(arr1[i]>arr2[j]) swap(arr1[i],arr2[j]);
              i--;j++;
          }
          sort(arr1,arr1+n);
          sort(arr2,arr2+m);
} 

//Count pairs with given sum
 int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int>mp;
        int cnt=0;
        for(int i=0;i<n;i++){
            int diff=k-arr[i];
            if(mp.find(diff)!=mp.end()) cnt+=mp[diff];
            mp[arr[i]]++;
        }
        return cnt;
}   

//Alternate positive and negative numbers Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2} output: 9 -2 4 -1 5 -5 0 -3 2
void rearrange(int arr[], int n) {
  vector<int>pos;
  vector<int>neg;
  for(int i=0;i<n;i++){
      if(arr[i]>=0) pos.push_back(arr[i]);
      else neg.push_back(arr[i]);
	  }
	 
  int j=0;int k=0; int i=0;
  while(j<pos.size() && k<neg.size()){
   if(i%2==0) arr[i++]=pos[j++];
     else arr[i++]=neg[k++];
	      
	  }
  while(j<pos.size()){
	     arr[i++]=pos[j++];
	  }
  while(k<neg.size()){
	     arr[i++]=neg[k++];
	  }
}

//Three way partitioning A[] = {1, 2, 3, 3, 4} [a, b] = [1, 2] output=1(range <a kept in left side and range>b kept in right side by keeping two pointer)
 void threeWayPartition(vector<int>& array,int a, int b)
    {   
        int s=0;int e=array.size()-1;
        for(int i=0;i<array.size();i++){
            if(array[i]<a){
                swap(array[s],array[i]);
                s++;
            }
        }
        for(int i=array.size()-1;i>=s;i--){
            if(array[i]>b){
                swap(array[e],array[i]);
                e--;
            }
        }
        return;
    }

//Common elements n1 = 6; A = {1, 5, 10, 20, 40, 80} n2 = 5; B = {6, 7, 20, 80, 100} n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
//output=20 80
vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            map<int,int>mp;
            vector<int>ans;
           for(int i=0;i<n1;i++){
               if(mp[A[i]]==1) continue;
               else mp[A[i]]=1;
           }
           for(int i=0;i<n2;i++){
               if(mp[B[i]]==1) mp[B[i]]++;
               else if(mp[B[i]]==2) continue;
           }
           for(int i=0;i<n3;i++){
               if(mp[C[i]]==2) mp[C[i]]++;
           }
           for(auto it=mp.begin();it!=mp.end();it++){
               if(it->second==3) ans.push_back(it->first);
           }
           return ans;
        }

// 1-bit and 2-bit Characters The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).
//Input: bits = [1,1,1,0] Output: false Explanation: The only way to decode it is two-bit character and two-bit character.So the last character is not one-bit character.
 bool isOneBitCharacter(vector<int>& bits) {
       if(bits.size()==1){
           if(bits[0]==0) return true;
           else return false;
       }
       int i=0;
       while(i<bits.size()){
           if(i==bits.size()-1){
               if(bits[i]==0) return true;
               else return false;
           }else if(i<bits.size() && (i+1)<bits.size()){
               if(bits[i]==1 && bits[i+1]==0) i=i+2;
               else if(bits[i]==1 && bits[i+1]==1) i=i+2;
               else i++;
           }
       }
       return false;
    }
// old approach     
string binary(int n){
        int ans=0;int i=0;
        while(n!=0){
            int bit=n&1;
            ans=(bit*pow(10,i))+ans;
            n=n>>1;i++;
        }
        string str="";
        str.push_back(ans);
        return str;
    }
    bool hasAlternatingBits(int n) {
        string ans=binary(n);
        bool res;
        for(int i=0;i<ans.length();i++){
            if(ans[i]==0 && ans[i+1]==1) res=true;
            else if(ans[i]==1 && ans[i+1]==0) res=true;
            else res=false; 
        }
        return res;
    } 
// Binary Number with Alternating Bits Input: n = 11 Output: false Explanation: The binary representation of 11 is: 1011.    
// new and correct approach
 bool hasAlternatingBits(int n) {
        vector<int>ans;
        int temp=0;
        while(n>0){
            if(n==1){
                ans.push_back(1);
                break;
            }
           temp=n%2;
           ans.push_back(temp);
           n=n/2;
        }
        for(int i=1;i<ans.size();i++){
            if(ans[i]==ans[i-1]){
                return false;
            }
        }
     return true; } 
// new technique bit manipulation same above question solution
bool hasAlternatingBits(int n) {
        long x = n>>1;
        x = x ^ n;
        x = x & (x+1);
        return (x == 0);
    }  

//power of two
 bool isPowerofTwo(long long n){
        
         if(n==0) return false;
         if(n==1) return true;
         while(n>1){
             if(n%2!=0) return false;
             n=n/2;
         }
        return true;
    }             
//Rotate Array Input: nums = [1,2,3,4,5,6,7], k = 3 Output: [5,6,7,1,2,3,4]
//1.first reverse the numbers form index 0 to n-k; ->4321 567
//2.reverse the k elements from the last ->4321 765
//3.now reverse the whole nums; ->5671234 Done Answer is here !!!!
 void rotate(vector<int>& nums, int k) {
       k=k%nums.size();
       reverse(nums.begin(),nums.begin()+(nums.size()-k));
       reverse(nums.begin()+(nums.size()-k),nums.end());
       reverse(nums.begin(),nums.end()); 
    }

// Count Primes Input: n = 10 Output: 4 Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 int countPrimes(int n) {
      if(n==0 || n==1) return 0;
      //sieve of eratosthenes
        int cnt=0;
        vector<bool>prime(n+1,true);
        prime[0]=prime[1]=0;
        for(int i=2;i<n;i++){
            if(prime[i]){
                cnt++;
                for(int j=2*i;j<n;j=j+i)
                prime[j]=false;
            }
        }
        return cnt;
    }
int main(){
    int n;cout<<"enter the value of n :";cin>>n;
   /* vector<int>nums(n);
    for(int i=0;i<nums.size();i++){
        cin>>nums[i];
    }
    vector<int>empty;
    generation(empty,0,nums);
    for(auto subset:allsubset){
        for(auto ele:subset){
            cout<<ele<<" ";
        }
        cout<<endl;
    }*/
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    prefixSum(arr,n);
}