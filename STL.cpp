#include<bits/stdc++.h>
using namespace std;

float SumOfSquare(int n){
    float s=(n*(n+1)*(2*n+1))/6;
    return s;
}

float SumOfCube(int n){
    float s=pow((n*(n+1))/2,2);
    return s;
}

vector<int> commonElement(vector<int>&arr1,int n,vector<int>&arr2){
    vector<int>ans;
    for(int i=0;i<arr1.size();i++){
        int element=arr1[i];
        for(int j=0;j<arr2.size();j++){
            if(element ==arr2[j])
            ans.push_back(element);
            break;
        }
    }
    for(auto it:ans){
        ans.pop_back();
    }
    return ans;
}

void SearchElement2DMatrix(int arr[][4],int row ,int col, int key ){
    int s=0; int e=(row*col)-1;
    int mid=(s+e)/2;
    while(s<e){
        int element=arr[mid/col][mid%col];
         if(element==key){
        cout<<"element found";
         }
         else if(element>key){
            e=mid-1;
         }else if(element<key){
            s=mid+1;
         }
         mid=(s+e)/2;
    }
}

 vector<int>  plusOne(vector<int>& digits) {
        vector<int>arr;
        int ans=0;int j=digits.size()-1;
        for(int i=0;i<digits.size();i++){
            ans=ans+digits[j-i]*pow(10,i);
        }
        int b=ans+1;
        for(int i=0;i<arr.size();i++){
            arr.push_back(b%10);
            b=b/10;
        }
        for(auto it=arr.end()-1;it>=arr.begin();it--){
           // cout<<(*it)<<" ";
            arr.push_back((*it));
        }
        return arr;
 }

void getMinMax(long long a[], int n) {
    pair<long long ,long long>ans;
       int maxi=a[0];int mini=a[0];
       for(int i=1;i<n;i++){
           if(a[i]<mini){
               mini=a[i];
           }
           else if(a[i]>maxi){
               maxi=a[i];
           }
         }
    cout<<mini<<" "<<maxi;
 }

//Sort Array by Increasing Frequency Input: nums = [1,1,2,2,2,3] Output: [3,1,1,2,2,2] Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
//If multiple values have the same frequency, sort them in decreasing order.
 static bool cmp(pair<int,int>&a,pair<int,int>&b){
        return (a.second==b.second)? a.first>b.first : a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
       if(nums.size()==1) return nums; 
       vector<int>ans;
       unordered_map<int,int>mp;
       vector<pair<int,int>>vec_freq;
       for(int i=0;i<nums.size();i++){
           mp[nums[i]]++;
       }
       for(auto it:mp) vec_freq.push_back(it);
       sort(vec_freq.begin(),vec_freq.end(),cmp);
       for(auto v:vec_freq){
           for(int i=0;i<v.second;i++)
             ans.push_back(v.first);
       }
       return ans;
    }
//Best Time to Buy and Sell Stock Input: prices = [7,1,5,3,6,4] Output: 5 GREEDY APPROACH
 int maxProfit(vector<int>& prices) {
        int lsf=INT_MAX;
        int op=0;
        int pist=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<lsf) lsf=prices[i];
            pist=prices[i]-lsf;
            if(op<pist) op=pist;
        }
        return op;
    }
//Find the Highest Altitude Input: gain = [-5,1,5,0,-7] Output: 1 Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
 int largestAltitude(vector<int>& gain) {
        int prefixsum=0;
        int ans=INT_MIN;
        for(int i=1;i<=gain.size();i++){
            prefixsum+=gain[i-1];
            ans=max(ans,prefixsum);
        }
        if(ans<0) return 0;
        return ans;
    }
//Minimum number of jumps N = 11 arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}  Output: 3 First jump from 1st element to 2nd element with value 3. Now, from here 
//we jump to 5th element with value 9,and from here we will jump to the last.
int minJumps(int arr[], int n){
        //greedy approach 
       int farthest=0;
       int jumps=0;
       int current=0;
       for(int i=0;i<n-1;i++){
           farthest=max(farthest,i+arr[i]);
           if(i==current){
               current=farthest;
               jumps++;
           }
           if(current>=n-1) return jumps;
       }
       return -1;
    }

// Minimum Size Subarray Sum Input: target = 7, nums = [2,3,1,2,4,3] Output: 2 Explanation: The subarray [4,3] has the minimal length under the problem constraint.
//window sliding approach is used in this problem
 int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;int j=0;int sum=0;
        int mini=INT_MAX;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>=target){
            sum-=nums[i];    
            mini=min(j-i+1,mini);
            i++;
            }
            j++;
        }
        if(mini==INT_MAX) return 0;
        return mini;
    }    
//Kth smallest element N = 6 arr[] = 7 10 4 3 20 15 K = 3 Output : 7 3rd smallest element in the given array is 7.
 int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int>maxH;
        for(int i=l;i<=r;i++){
            maxH.push(arr[i]);
            if(maxH.size()>k) maxH.pop();
        }
        return maxH.top();
    }
    
int main(){
   // int n;cout<<"enter the value of n: ";cin>>n;
   // cout<<SumOfSquare(n);
   // cout<<endl;
   // cout<<SumOfCube(n);
    /*vector<int>arr1;
    for(int i=0;i<6;i++){
        arr1.push_back(i);
    }
    for(auto it:arr1){
        cout<<it<<" ";
    }cout<<endl;
    vector<int>arr2;
    for(int i=3;i<9;i++){
        arr2.push_back(i);
    }
    for(auto it:arr2){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it=arr2.end()-1;it>=arr2.begin();it--){
        cout<<(*it)<<" ";
    }*/
    /*vector<vector<int>>digits;
    vector<int>subset;
    for(int i=0;i<4;i++){
        subset.push_back(i);
    }
    
    for(auto subset:digits){
        for(auto ele:subset){
            cout<<ele<<" ";
        }
    }*/
    /*digits.push_back(1);
    digits.push_back(2);
    digits.push_back(3);
    plusOne(digits);*/
    //cout<< commonElement(arr1,arr2);
   /*int row;cout<<"enter the value of row:";cin>>row;
    int col;cout<<"enter the value of column:";cin>>col;
    int arr[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }*/ 
    int n;cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    getMinMax(arr,n);
}