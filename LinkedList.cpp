#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
    Node(){
        this->next=NULL;
    }
};
void insertAtHead(Node* &head ,int d){
    //create new node
    Node* newTemp=new Node(d);
    newTemp->next=head;
    head=newTemp;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
//REVERSE A LINKED LIST
Node* reverse(Node*&head){
    if(head==NULL || head->next==NULL) return head;
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

//DETECT A LOOP IN LINKED LIST
 bool detectLoop(Node* head)
    {
       if(head==NULL || head->next==NULL) return false;
       map<Node*,bool>visited;
       Node* temp=head;
       while(temp!=NULL){
           if(visited[temp]==true) return true;
           else visited[temp]=true;
           temp=temp->next;
       }
       return false;
    }

//MIDDLE ELEMENT OF LINKED LIST
 Node* middleNode(Node* head) {
        if(head==NULL || head->next==NULL) return head;
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL) fast=fast->next;
            slow=slow->next;
        }
        return slow;
 }

//CHECK WHETHER LL IS CIRCULAR OR NOT
bool isCircular(Node *head)
{
   if(head==NULL) return NULL;
   Node* temp=head->next;
   while(temp!=NULL && temp!=head){
       temp=temp->next;
   }
   if(temp==head) return true;
   return false;
}

// PALLINDROME LL 
    bool isPalindrome(Node* head) {
        if(head==NULL) return true;
        if(head->next==NULL) return true;
        Node* prev=NULL;
        Node* curr=head;
        Node* forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        Node* newll=prev;
        while(newll!=NULL && head!=NULL){
            if(newll->data!=head->data) return false;
            else {
              newll=newll->next;
              head=head->next;
            }
        }
        return true;
        } 

//Find the first node of loop in linked list
 int findFirstNode(Node* head)
    {
        Node* temp=head;
        map<Node*,bool>visited;
        while(temp!=NULL){
            if(visited[temp]==true){
                int d=temp->data;
                return d;
            }
            else {
                visited[temp]=true;
                temp=temp->next;
        }
    }
    return -1;}

//Remove duplicate element from sorted Linked List
Node *removeDuplicates(Node *head)
{
   if(head==NULL || head->next==NULL) return head;
   Node* curr=head;
   while(curr !=NULL){
      if(curr->next!=NULL && curr->data==curr->next->data){
         Node* next_next=curr->next->next;
         Node* toBeDeleted=curr->next;
         delete(toBeDeleted);
         curr->next=next_next;
      }
      else curr=curr->next;
   }
   return head;
}

//Given a linked list of 0s, 1s and 2s, sort it
 Node* segregate(Node *head) {
        
      int zerocnt=0;
      int onecnt=0;
      int twocnt=0;
      Node* temp=head;
      while(temp!=NULL){
          if(temp->data==0) zerocnt++;
          if(temp->data==1) onecnt++;
          if(temp->data==2) twocnt++;
          temp=temp->next;
      }
      temp=head;
      while(temp!=NULL){
          if(zerocnt!=0) {temp->data=0; zerocnt--;}
         else if(onecnt!=0)  {temp->data=1; onecnt--;}
         else if(twocnt!=0)  {temp->data=2;  twocnt--;}
          temp=temp->next;
      }
          return head;
}

//REVERSE A LINKED LIST IN GROUPS
  Node *reverse ( Node *head, int k)
    { 
       if(head==NULL) return NULL;
       Node *prev=NULL;
       Node *curr=head;
       Node *forward=NULL;
       int cnt=0;
       while(curr!=NULL && cnt<k){
           forward=curr->next;
           curr->next=prev;
           prev=curr;
           curr=forward;
            cnt++;
          }
          if(forward!=NULL){
              head->next=reverse(forward,k);
          }
        return prev;   
    }

// Remove Linked List Elements Input: head = [1,2,6,3,4,5,6], val = 6 Output: [1,2,3,4,5]
 Node* removeElements(Node* head, int val) {
       if(head==nullptr) return head;
        while(head!=nullptr && head->data==val){
            head = head->next;
        }
        Node* curr = head;
        Node* prev = nullptr;
        while(curr!=nullptr){
            if(curr->data==val){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                prev = curr;
                curr = curr->next;        
            }
        }
        return head;
    } 
//ADD ONE TO LINKED LIST
 Node*rev(Node*head){
      Node*prev=NULL;
      Node*curr=head;
      Node* nxt;
      while(curr)
      {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
      }
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
       if(head==NULL) return head;
       
       int carry=0;
       head=rev(head);
       Node*temp=head;
       
       int sum=temp->data+1;
       int digit=sum%10;
       carry=sum/10;
       
       Node* newNode=new Node(digit);
       Node* ansHead=newNode;
       Node* ansTail=newNode;
       temp=temp->next;
       
       while(temp){
           sum=carry+temp->data;
           digit=sum%10;
           carry=sum/10;
           
           Node* newNode=new Node(digit);
            ansTail->next=newNode;
            ansTail=newNode;
           temp=temp->next;
       }
       while(carry){
           int sum=carry;
           int digit=sum%10;
           carry=sum/10;
           Node* newNode=new Node(digit);
           ansTail->next=newNode;
           ansTail=newNode;
       }
       ansHead=rev(ansHead);
       return ansHead;
    }       

//// Delete the Middle Node of a Linked List Input: head = [1,3,4,7,1,2,6] Output: [1,3,4,1,2,6]
int length(Node* head){
        Node* temp = head;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    Node* deleteMiddle(Node* head) {
        if(head==NULL || head->next==NULL) return NULL;
        int n = length(head);
        int t = n/2;
        Node* temp = head;
        for(int i=0;i<t;i++){
            if(i==t-1){
                Node* todelete = temp->next;
                temp->next=temp->next->next;
                delete todelete;
            }
            temp=temp->next;
        }
        return head;
    }
// Intersection of Two Linked Lists Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
//Output: Intersected at '8'
 int length(Node *head){
        int cnt=0;
        Node *temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    Node *getIntersectionNode(Node *headA, Node *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        int lenA=length(headA),lenB=length(headB);
        if(lenA>lenB){
            while(lenA>lenB){
                headA=headA->next;
                lenA--;
            }
        }
        if(lenB>lenA){
            while(lenB>lenA){
                headB=headB->next;
                lenB--;
            }
        }
        while(headA && headB){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    } 

// Remove Nth Node From End of List  Remove Nth Node From End of List Output: [1,2,3,5]
Node* removeNthFromEnd(Node* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        int cnt=0;
        Node* curr=head;
        while(curr!=NULL){
            cnt++;
            curr=curr->next;
        }
        if((cnt-n)==0){
            head=head->next;
            return head;
        }
        Node* temp=head;
        Node* slow=head;
        for(int i=0;i<(cnt-n);i++){
            slow=temp;
            temp=temp->next;
        }
        slow->next=temp->next;
        return head;
    }   
    
// Odd Even Linked List Input: head = [1,2,3,4,5] Output: [2,3,6,7,1,5,4]
  Node* oddEvenList(Node* head) {
        if(head == NULL) return head;
        Node* ptr1 = head;
        Node* ptr2 = head->next;
        Node* temp = head->next;

        while(ptr1 and ptr2 and ptr1->next != NULL and ptr2->next != NULL){
            ptr1->next = ptr1->next->next;
            ptr1 = ptr1->next;
            
            ptr2->next = ptr2->next->next;
            ptr2 = ptr2->next;
           
        }
        ptr1->next = temp;
        return head;
    } 
// Maximum Twin Sum of a Linked List Input: head = [5,4,2,1] Output: 6
 int pairSum(Node* head) {
        int i,j,k,c=0;
        Node*s,*f;
        s=head;
        f=head;
        vector<int>v;

        while(f and f->next){
            v.push_back(s->data);
            s=s->next;
            f=f->next->next;

        }

        for(i=v.size()-1;i>=0;i--){
            v[i]+=s->data;
            s=s->next;
            if(!s)
            break;
        }
        for(i=0;i<v.size();i++){
            c=max(c,v[i]);
        }
        return c;
        
    } 
//Swap Nodes in Pairs Input: head = [1,2,3,4] Output: [2,1,4,3]
 Node* swapPairs(Node* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        Node* dummy=new Node();
        Node*prev=dummy;
        Node* curr=head;
        while(curr!=NULL && curr->next!=NULL){
            prev->next=curr->next;
            curr->next=prev->next->next;
            prev->next->next=curr;
            prev=curr;
            curr=curr->next;
        }
        return dummy->next;
    }              
int main(){
    Node* newNode=new Node(10);
    cout<<newNode->data<<" ";
    Node* head=newNode;
    insertAtHead(head,12);
    print(head);
}