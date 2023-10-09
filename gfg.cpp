#include<bits/stdc++.h>
using namespace std;

void ReverseTheGroup(vector<long long>&arr,int k,int n){
    int d=ceil(float(n)/float(k));
    auto it1=arr.begin();
    auto it2=arr.begin();
    for(int i=0;i<d;i++,it1+=k){
        if((it2+k)<=arr.end()){
            it2+=k;
        }
        else{
            it2=arr.end();
        }
        reverse(it1,it2);
    }
    for(auto it=arr.begin();it!=arr.end();it++){
     cout<<(*it)<<" ";
    }

}
//Spirally traversing a matrix
 vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {  vector<int>ans;
       int row=matrix.size(); int col=matrix[0].size();
       int startingRow=0;
       int startingCol=0;
       int endingrow=r-1;
       int endingcol=c-1;
       int cnt=0;long long total=row*col;
       while(cnt<total){
           for(int i=startingCol;cnt<total && i<=endingcol;i++){
               ans.push_back(matrix[startingRow][i]);
               cnt++;
           }
           startingRow++;
           for(int i=startingRow;cnt<total && i<=endingrow;i++){
               ans.push_back(matrix[i][endingcol]);
               cnt++;
           }
           endingcol--;
           for(int i=endingcol;cnt<total && i>=startingCol;i--){
               ans.push_back(matrix[endingrow][i]);
               cnt++;
           }
           endingrow--;
           for(int i=endingrow;cnt<total && i>=startingRow;i--){
               ans.push_back(matrix[i][startingCol]);
               cnt++;
           }
           startingCol++;
       }
       return ans;
    }

//Median in a row-wise sorted Matrix
 int median(vector<vector<int>> &matrix, int R, int C){
            vector<int>ans;
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    ans.push_back(matrix[i][j]);
                } 
            }
            sort(ans.begin(),ans.end());
            int median=ans.size();
            return ans[median/2];
    }

//Row with max 1s 
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int cnt=0;int maxi=0;int index=-1;
	    for(int i=0;i<n;i++){
	        int cnt=0;
	        for(int j=0;j<m;j++){
	            if(arr[i][j]==1){
	                cnt++;
	                if(maxi<cnt){
	                    maxi=cnt;
	                    index=i;
	                }
	            }else cnt=0;
	        }
	    }
	    return index;
}

//Kth element in Matrix
int kthSmallest(int mat[][4], int n, int k)
{
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push(mat[i][j]);
            if(pq.size()>k) pq.pop();
        }
    }
    int ans=pq.top();
    return ans;
}

// MIN DISTANCE FROM C CHARACTER Input: s = "loveleetcode", c = "e" Output: [3,2,1,0,1,0,0,1,2,2,1,0]
 vector<int> shortestToChar(string s, char c){
        vector<int>ans;
        vector<int>index;
        for(int i=0;i<s.length();i++){
            if(s[i]==c) index.push_back(i);
        }
        for(int i=0;i<s.length();i++){
            int min_distance=INT_MAX;
            for(int j=0;j<index.size();j++){
                int d2=abs(i-index[j]);
                if(d2<min_distance) min_distance=d2;
            }
            ans.push_back(min_distance);
        }
        return ans;
    }

//Find Smallest Letter Greater Than Target Input: letters = ["c","f","j"], target = "a" Output: "c"
 char nextGreatestLetter(vector<char>& letters, char target) {
        int start=0; int end=letters.size()-1;
        int mid=0;
        if(letters[end]<=target) return letters[0];
        while(start<=end){
            mid=start+(end-start)/2;
            if(letters[mid]>target) end=mid-1;
            else start=mid+1;
        }
        return letters[start];
    }

//Sorted matrix N=4Mat=[[10,20,30,40],[15,25,35,45],[27,29,37,48],[32,33,39,50]]   OUTPUT:10 15 20 25  27 29 30 32 33 35 37 39 40 45 48 50
 vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int>temp;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                temp.push_back(Mat[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        int k=0;
        for(int i=0;i<N;i++){
          for(int j=0;j<N;j++){
              Mat[i][j]=temp[k++];
          }
    }
    return Mat;
    }
    
// Transpose Matrix
 vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> res(m,vector<int> (n,0)); // matrix creation
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[j][i] = matrix[i][j]; // filling the matrix in transpose form
            }
        }
        return res;
    }
//rotate matrix 2 Steps to rotate image Transpose the matrix Swap the columns
 void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        for(int i=0;i<row;i++){
            for(int j=0;j<=i;j++)
             swap(matrix[i][j],matrix[j][i]);
        }
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
//Check if One String Swap Can Make Strings Equal Input: s1 = "bank", s2 = "kanb" output=true
 bool areAlmostEqual(string s1, string s2) {
        string a=s1;
        string b=s2;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<s1.length();i++){
            if(a[i]!=b[i]) return false;
        }
        int cnt=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]) cnt++;
        }
        if(cnt==0 || cnt==2) return true;
        return false;
    }
//Maximum Ascending Subarray Sum Input: nums = [10,20,30,5,10,50] Output: 65 Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.
int maxAscendingSum(vector<int>& nums) {
       int current=nums[0];
       int maxi=nums[0];
       for(int i=1;i<nums.size();i++){
           if(nums[i]<=nums[i-1]){
               maxi=max(maxi,current);
               current=nums[i];
           }
           else current+=nums[i];
       }
       maxi=max(maxi,current);
       return maxi;
    }    

// Maximum Product of Word Lengths Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"] Output: 16
//Explanation: The two words can be "abcw", "xtfn".
 /**
    |= is bitwise OR operator...
    1 << (words[i][j]-'a') appends 0s to the end of 1...
    for ex: a becomes 1, b becomes 10, c becomes 100 and so on...
    and if our string is ab, then the w_bin we get is 1|10 which is 11.
       */    
     int maxProduct(vector<string>& words) {
       int n = words.size();
        vector<int> mask(n, 0);
        for(int i=0;i<n;++i) {
            int w_bin=0;
            for(int j=0;j<words[i].size();++j) {
                w_bin |= 1 << (words[i][j]-'a');
            }
            mask[i] = w_bin;
        }
        int res=0;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                if((mask[i]&mask[j])==0) {
                    int prod = words[i].size()*words[j].size();
                    res = max(res, prod);
                }
            }
        }
        return res;
    }
// Top K Frequent Elements Input: nums = [1,1,1,2,2,3], k = 2 Output: [1,2]
 vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        for(auto it:mp){
            pq.push(make_pair(it.second,it.first));
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            pair<int,int>temp=pq.top();
            pq.pop();
            res.push_back(temp.second);
        }
        return res;
    }     
int main(){
    vector<long long>arr{1,2,3,4,5,6};
    int k;cout<<"enter the value of k: ";cin>>k;
    ReverseTheGroup(arr,3,6);
}