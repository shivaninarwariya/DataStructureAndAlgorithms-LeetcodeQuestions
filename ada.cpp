#include<bits/stdc++.h>
using namespace std;
//square root of a number

int mySqurt(int x){
	int low=0;int high=x;int ans;
	while(low<=high){
	int mid=(low+high)/2;
	int sq=mid*mid;
    if(sq==x){
		ans=mid;
	}
	else if(sq>x){
		high=mid-1;
	}
	else if(sq<x){
		low=mid+1;
}
	}
	return ans;
}

 bool isPalindrome(string s) {
	    string st;
        for(int i=0;s[i]!='\0';i++){
			if((s[i]>='A'&&s[i]<='Z') ||(s[i]>='a'&&s[i]<='z')){
				st.push_back(s[i]);
			}
		}
		for(int i=0;st[i]!='\0';i++){
			if(st[i]>=65&&st[i]<=90){
				st[i]=st[i]+32;
			}
		}
		int start=0;int end=st.length()-1;
		while(start<end){
			if(st[start]!=st[end]){
				return false;
			}
			else{
				start++;end--;
			}
		}
		return true;
    }
  //no. of occurence of needle string in haystack string
	int strStr(string haystack, string needle){
		int count=0;
		for(int i=0;i<haystack.length();i++){
			for(int j=0;j<needle.length();j++){
				if(haystack[i+j]==needle[j]){
                  if(j==needle.length()-1)count++;
				}
			}
		}
		return count;
	}
//first and last occurence of number in an array	
	int firstoc(int arr[], int n, int x)
{
    int start=0;
    int end=n-1;
    int first=-1;
    while(start<=end)
    {
        int mid= start +(end-start)/2;
        if(arr[mid]==x)
        {
            first= mid;
            end=mid-1;
        }
        else if(arr[mid]<x)
            start= mid+1;
        else
            end= mid-1;
    }
    return first;
}
int lastoc(int arr[], int n, int x)
{
    int start=0;
    int end=n-1;
    int second=-1;
    while(start<=end)
    {
        int mid= start +(end-start)/2;
        if(arr[mid]==x)
        {
            second= mid;
            start= mid+1;
        }
        else if(arr[mid]<x)
            start= mid+1;
        else
            end= mid-1;
    }
    return second;
  }

// leetcode medium problem first and last occurance of an element in an array(vector)

int firstocc(vector<int>&nums , int target){
        int start=0,end=nums.size()-1;int first=-1;bool found=0;
        int mid=start+(end-start)/2;
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target){
                first=mid;
                end=mid-1;
                found=1;
            }
            else if(nums[mid]>target) end=mid-1;
            else if(nums[mid]<target) start=mid+1;
        }
        if(found!=1) return -1;
        return first;
    }
    int secondOcc(vector<int>&nums,int target){
        int start=0,end=nums.size()-1; int second=-1;bool found=0;
        while(start<=end){
           int mid=start+(end-start)/2;
            if(nums[mid]==target){
                second=mid;
                start=mid+1;
                found=1;
            }
            else if(nums[mid]>target) end=mid-1;
            else if(nums[mid]<target) start=mid+1;
        }
        if(found!=1) return -1;
          return second; }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        if(nums.size()==0){
            ans.push_back(-1);
             ans.push_back(-1);
        }
        else{
            int f=firstocc(nums,target);
            int s=secondOcc(nums,target);
            ans.push_back(f);
            ans.push_back(s);
        }
        return ans;
    }

//PLUS ONE Input: digits = [1,2,3] Output: [1,2,4]
  vector<int>  plusOne(vector<int>& digits) {
       int n=digits.size();
       for(int i=n-1;i>=0;i--){
           if(digits[i]<9){
               digits[i]=digits[i]+1;
               return digits;
           }else digits[i]=0;
       }
       digits.push_back(0);
       digits[0]=1;
       return digits;
    }

// Consecutive Characters Input: s = "leetcode" Output: 2
int maxPower(string s) {
        int cnt=1; int maxi=1;
        for(int i=0;i<s.length();i++){
            if(s[i]==s[i+1]){
                cnt++;
            }else{
             maxi=max(maxi,cnt);
             cnt=1;
            }
       }
        maxi=max(maxi,cnt);
       return maxi;
    }
int main(){
	/*int x;
	cout<<"enter the value of x: ";
	cin>>x;
	cout<<mySqurt(x);*/
	/*string haystack;string needle;
	cout<<"enter the value of string haystack ";
	getline(cin,haystack);
	cout<<"enter the value of string needle: ";
	getline(cin,needle);
	//cout<<isPalindrome(s);
	cout<<strStr(haystack,needle);*/
	int n;cout<<"enter the value of n :";cin>>n;
	int x;cout<<"enter the value of x: ";cin>>x;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
}

