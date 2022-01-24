//Implementation of Queue using Linked List
//hi man
#include<iostream>
#include <ctime>


using namespace std;
 
struct Node{
    
    string GuestName;
    int contactNumber;
    string Guestid;
    string checkInDate;
    int DurationOfStay;
    Node *next;
};
 
class Queue{
    public:
    Node *front,*rear;
    Queue(){front=rear=NULL;}
 
    void CheckIn(int n);
    void CheckOut();
    void displayQuests();
    void checkCpacity();
    void SearchforGuest();
    void IsEmpty();
    void IsFull();
    ~Queue();
};
 
void Queue::insert(int n){
    Node *temp=new Node;
    if(temp==NULL){
        cout<<"Overflow"<<endl;
        return;
    }
    temp->data=n;
    temp->next=NULL;
 
    //for first node
    if(front==NULL){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
    cout<<n<<" has been inserted successfully."<<endl;
}
 
void Queue::display(){
    if(front==NULL){
        cout<<"Underflow."<<endl;
        return;
    }
    Node *temp=front;
    //will check until NULL is not found
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
 
void Queue :: deleteitem()
    {
    if (front==NULL){
        cout<<"underflow"<<endl;
        return;
    }
     
    cout<<front->data<<" is being deleted "<<endl;
    if(front==rear)//if only one node is there
        front=rear=NULL;
    else
        front=front->next;
}
 
Queue ::~Queue()
{
    while(front!=NULL)
    {
        Node *temp=front;
        front=front->next;
        delete temp;
    }
    rear=NULL;
}
 
 
int main(){

    /*
    time_t ttime = time(0);
    
    char* dt = ctime(&ttime);
    cout << "The current local date and time is: " << dt << endl;
    */
    Queue Q;
  
    Q.display();
 
    Q.insert(10);
    Q.insert(24);
    Q.insert(28);
    Q.insert(32);
    Q.insert(30);
     
    Q.display();
     
    Q.deleteitem();
    Q.deleteitem();
    Q.deleteitem();
    Q.deleteitem();
    Q.deleteitem();
     
    return 0;
}
