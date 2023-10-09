#include<bits/stdc++.h>
using namespace std;

void MoveAllNegative(int arr[],int n){
    vector<int>v1;
    vector<int>v2;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            v1.push_back(arr[i]);
        }else{
            v2.push_back(arr[i]);
        }
    }
    for(int i=0;i<v1.size();i++){
        arr[i]=v1[i];
    }
    for(int i=0;i<v2.size();i++){
        arr[i+v1.size()]=v2[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void rotate(int arr[],int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
        arr[n-1]=temp;
    }
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";}
}

int doUnion(int a[], int n, int b[], int m)  {
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back(a[i]);
        }
        for(int i=0;i<m;i++){
            if(a[i]!=b[i]){
                v.push_back(b[i]);
            }
        }
        return v.size();
    }

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        long long product=1;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            product*=x;
        }
        int digit=product%10;
        if(digit==2||digit==3||digit==5){
            cout<<"YES\n";
        }
        else{
            cout<<"NO";
        }
    }
    int n;cout<<"enter the value of n: ";cin>>n;cout<<endl;
    int m;cout<<"enter the value of m: ";cin>>m;
    int a[n];int b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
   MoveAllNegative(a,n); 
   rotate(a,n);
   cout<<doUnion(a,n,b,m);
}
int fun1(int n){
    static int i=0;
    if(n>0){
        ++i;
    fun1(n-1);
    }
    return (i);
}
int fun2(int n){
    static int i=0;
    if(n>0){
        i=i+fun1(n);
        fun2(n-1);
    }
    return(i);
}
int main(){
    cout<<fun2(5);
}

/*int searchInsert(vector<int>& nums, int target) {
     int s=0;int e=nums.size();
     int mid=s+(e-s)/2;
     if(target>nums[e-1]){
        return e;
     }
     while(s<=e){
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) e=mid-1;
        else s=mid+1;
        mid=mid=s+(e-s)/2;
     }
     return s;
}
*/