#include<bits/stdc++.h>
using namespace std;

 bool isPalindrome(int x) {
    if(x<0) return false;
        int reverse=0;
        int n=x;
        while(n!=0){
            int temp=n%10;
            reverse=reverse*10+temp;
            n=n/10;
        }
        if(reverse==x){
            return true;
        }
        else{
            return false;
        }
 }  
    //     int i=0,j=count-1;
    //    while(i<j){
    //     if(i==j){
    //     return true;}
    //    else{
    //    i++;j--;}
    //    }
        // return false;
    void TwoSum(int arr[],int n,int target){
    int j=1;
    vector<int>temp;
    for(int i=0;i<n;i++){
        if(arr[i]+arr[j]==target){
          temp.push_back(i);
          temp.push_back(j);
        }
        else{
            j++;
        }
    }
    for(auto it:temp){
        cout<<it<<" ";
    }
}
class Solution{
    public:

vector<int> twoSum(vector<int> &nums,int target){
    int j=1;
    vector<int>temp;
    for(int i=0;i<nums.size();i++){
        if(nums[i]+nums[j]==target){
          temp.push_back(i);
          temp.push_back(j);
        }
        else{
            j++;
        }
    }
    return temp;
}
};

// Backspace String Compare Input: s = "ab#c", t = "ad#c" Output: true Explanation: Both s and t become "ac".
 bool backspaceCompare(string s, string t) {
      string s1="";
      string t1="";
      int cnt=0;
      for(int i=s.length()-1;i>=0;i--){
          if(s[i]=='#') cnt++;
          else{
              if(cnt>0) cnt--;
              else s1+=s[i];
          }
      }
      cnt=0;
      for(int i=t.length()-1;i>=0;i--){
          if(t[i]=='#') cnt++;
          else{
              if(cnt>0) cnt--;
              else t1+=t[i];
          }
      }
      return (s1==t1);
    }

// Buddy Strings Input: s = "ab", goal = "ba" Output: true Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
 bool buddyStrings(string s, string goal) {
        unordered_map<char, int> mp;
        for(int i=0;i<s.length();i++) mp[s[i]] = i;
        for(int i=0;i<goal.length();i++){
            if(mp.find(goal[i]) == mp.end()) return false;
            if(mp[goal[i]] != i){
                swap(s[i], s[mp[goal[i]]]);
                if(s == goal) return true;
                swap(s[i], s[mp[goal[i]]]);
            }
        }
        return false;
    }

 //Reverse Only Letters Input: s = "a-bC-dEf-ghIj" Output: "j-Ih-gfE-dCba"   All the characters that are not English letters remain in the same position.
//All the English letters (lowercase or uppercase) should be reversed.(two pointer approach)
string reverseOnlyLetters(string s) {
       int i=0; int j=s.length()-1;
       while(i<j){
           if(!isalpha(s[i])) {
               i++;continue;}
            if(!isalpha(s[j])){
                j--;continue;
            }
            swap(s[i],s[j]);
            i++;j--;   
       }
       return s;
    }

//Find Common Characters Input: words = ["bella","label","roller"] Output: ["e","l","l"]
 vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        vector<int>minFreq(26,INT_MAX);
        for(auto &word:words){
            vector<int>freq(26,0);
            for(char c:word) freq[c-'a']++;
            for(int i=0;i<26;i++){
                minFreq[i]=min(minFreq[i],freq[i]);
            }
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<minFreq[i];j++) ans.push_back(string(1,i+'a'));
        }
        return ans;
    }

//Monotonic Array Input: nums = [1,2,2,3] Output: true
 bool isMonotonic(vector<int>& nums) {
     int n=nums.size();
     int last=nums[n-1];
     if(last > nums[0]){
         for(int i=1;i<nums.size();i++){
             if(nums[i-1] > nums[i])
                 return false;
         }
     }
          if(last < nums[0]){
         for(int i=1;i<nums.size();i++){
             if(nums[i-1] < nums[i])
                 return false;
         }
     }
          if(last == nums[0]){
         for(int i=1;i<nums.size();i++){
             if(nums[i-1] != nums[i]) {
                 return false;
         }
     }
        return true;
    } 
 }

// Sort Array By Parity Input: nums = [3,1,2,4] Output: [2,4,3,1]  move all the even integers at the beginning of the array followed by all the odd integers.        
 vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
            ans.push_back(nums[i]);
        }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
            ans.push_back(nums[i]);
        }
    }
    return ans;
    }

// Sort Array By Parity II Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.
//Input: nums = [4,2,5,7] Output: [4,5,2,7] Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
 vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>even;
        vector<int>odd;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) even.push_back(nums[i]);
            else if(nums[i]%2!=0) odd.push_back(nums[i]);
        }
        int j=0; int k=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
             res.push_back(even[j]);
              if(j<even.size()) j++;}
            else{
             res.push_back(odd[k]);
             if(k<odd.size()) k++;
             }
        }
        return res;
    }

// Flipping an Image Input: image = [[1,1,0],[1,0,1],[0,0,0]] Output: [[1,0,0],[0,1,0],[1,1,1]] Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
//Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
 void reverse(vector<int> &arr) {
        int mid = arr.size() / 2;
        for (int i = 0; i < mid; i++)
            swap(arr[i], arr[arr.size()-1-i]);
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto &row: image) {
            reverse(row);
            for (auto &val: row)
                val = val == 1 ? 0 : 1;
        }
        return image;
    }  

// N-Repeated Element in Size 2N Array nums.length == 2 * n. Exactly one element of nums is repeated n times.
//Input: nums = [1,2,3,3] Output: 3
 int repeatedNTimes(vector<int>& nums) {
        int size=nums.size();
        int n=size/2;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==n) return nums[i];
        }
        return -1;
    }

// Add to Array-Form of Integer Input: num = [1,2,0,0], k = 34 Output: [1,2,3,4] Explanation: 1200 + 34 = 1234
 vector<int> addToArrayForm(vector<int>& num, int k) {
       vector<int>ans;
       vector<int>temp;
       int carry=0;
       while(k>0){
           temp.push_back(k%10);
           k=k/10;
       }
       reverse(temp.begin(),temp.end());
       int i=num.size()-1;int j=temp.size()-1;
       while(i>=0 || j>=0){
           int sum=carry;
           if(i>=0) sum+=num[i--];
           if(j>=0) sum+=temp[j--];
           carry=sum/10;
           ans.push_back(sum%10);
       }
       if(carry){
           ans.push_back(carry);
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }

// Remove All Adjacent Duplicates In String Input: s = "abbaca" Output: "ca"
 string removeDuplicates(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            if(!ans.empty() && ans.back()==s[i]) ans.pop_back();
            else ans.push_back(s[i]);
        }
        return ans;
    }

// Occurrences After Bigram Input: text = "alice is a good girl she is a good student", first = "a", second = "good" Output: ["girl","student"]  
 vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        vector<string> ans;
        string str = "";
        text = text + " ";
        for(int i = 0 ; i < text.length() ; i++){
            if(text[i] != ' ')
                str = str + text[i];
            else{
                words.push_back(str);
                str = "";
            }
        }
        for(int i = 0 ; i < words.size()-2 ; i++){
            if(words[i]==first && words[i+1]==second)
                ans.push_back(words[i+2]);
        }
        return ans;
 }

// Find Words That Can Be Formed by Characters Input: words = ["cat","bt","hat","tree"], chars = "atach" Output: 6
//Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
 bool check(vector<int>arr1,vector<int>arr2){
            for(int i=0;i<26;i++){
                if(arr1[i]<arr2[i]) return false;
            }
            return true;
        }
        int countCharacters(vector<string>& words, string chars) {
        int sum = 0;
        vector<int> arr1(26,0);
        for(int i = 0 ; i < chars.size() ; i++)
            arr1[chars[i]-'a']++;
        
        for(int i = 0 ; i < words.size() ; i++){
            vector<int> arr2(26,0);
            for(int j = 0 ; j < words[i].size() ; j++){
                string m = words[i];
                arr2[m[j]-'a']++;
            }
            
            bool p = check(arr1 , arr2);
            if(p){
                sum = sum + words[i].size();
            }
        }
        return sum;
    }  

//Find Missing And Repeating N = 2 Arr[] = {2, 2} Output: 2 1 Explanation: Repeating number is 2 and smallest positive missing number is 1 
vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int i=0;int a=0; int b=0;
        for(i=0;i<arr.size();i++) mp[arr[i]]++;
        for(i=1;i<=n;i++){
            if(mp[i]==0) a=i;
            if(mp[i]>=2) b=i;
        }
        ans.push_back(b);
        ans.push_back(a);
        return ans;
    }   

    
int main(){
    /*int n;cout<<"enter the value of n";cin>>n;
    int sum=0;int product =1;
        while(n!=0){
            product=product*n%10;
            sum=sum+n%10;
            n=n/10;
        }
        int diff=(product-sum);
        cout<< diff;*/
       // cout<<isPalindrome(10);
       int n; cout<<"enter the value of n: ";cin>>n;
       int arr[n];
       for(int i=0;i<n;i++){
        cin>>arr[i];
       }
       int target;cout<<"enter the value of target: ";cin>>target;
       TwoSum(arr,n,target);
    }
