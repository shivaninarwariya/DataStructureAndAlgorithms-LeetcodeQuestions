#include<bits/stdc++.h>
using namespace std;

void LinearSearch(int arr[],int n,int key){
     for(int i=0;i<n;i++){
        if(arr[i]==key)
        cout<<"element found";
        else cout<<"not found";
     }
}

int BinarySearch(int arr[],int n,int key){
    int start=0;int end=n-1;
    int mid=(start+end)/2;
    while(start<=end){
        if(arr[mid]==key)
        return mid;
        else if(arr[mid]>key){
            end=mid-1;
        }
        else if(arr[mid]<key){
            start=mid+1;
        }
        mid=(start+end)/2;
    }
    return -1;
}

void SwapAlternate(int arr[],int n){
    for(int i=0;i<n;i+=2){
        if((i+1)<n){
        swap(arr[i],arr[i+1]);}
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;cout<<"enter the value of n: ";cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;cout<<"enter the value of key:";cin>>key;
    //LinearSearch(arr,7,key);cout<<endl;
    cout<<BinarySearch(arr,n,key);
    cout<<endl;
    SwapAlternate(arr,n);
    
}