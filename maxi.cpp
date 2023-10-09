#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int flag=0;
        for(int j=0;j<(n-i);j++){
          if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            flag=1;
          }
        }
        if(flag==0){
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void FindingMax(int arr[],int n){
    int maxi=arr[0];
    int mini=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<mini){
            mini=arr[i];
        }
        else if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    cout<<maxi<<" "<<mini<<endl;
}

int main(){
    int n;
    cout<<"enter the no. of element :";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter the values of element:";
        cin>>arr[i];
    }
    FindingMax(arr,n);
    BubbleSort(arr ,n);
}