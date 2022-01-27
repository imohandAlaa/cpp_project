
#include<iostream>
#include <ctime>


using namespace std;
 

int const size = 20;
int counter;

struct Guest{

    string GuestName;
    string Guestid;
    int contactNumber;
    string checkInDate;
    int DurationOfStay;
    Guest *next;
    Guest(){
        GuestName = "";
        Guestid = "";
        contactNumber = 0;
        checkInDate = "";
        DurationOfStay = 0;
    }
    Guest(string name,string id,int number,string date,int duration ){
        this->GuestName = name;
        this->Guestid = id;
        this->contactNumber = number;
        this->checkInDate = date;
        this->DurationOfStay =duration;

    }

};
 
class hotel{
    public:
    Guest *front,*rear;
    hotel(){front=rear=NULL;}
    void CheckIn();
    void CheckOut();
    void displayQuests();
    void checkCpacity();
    void SearchforGuest();
    void makePayment();
    void IsEmpty();
    void IsFull();
    void destroyQueue();
    ~hotel();
};

// check in function stores quest important data
void hotel::CheckIn(){
    string name;
    string id;
    int number;
    string date;
    int duration;
    Guest* temp = new Guest();

    

    cout<<"\n";
    	cout<<"\t\t ===================================================\n";
	cout<<"\t\t\t\t|   Hotel - CheckIn    |\n";
	cout<<"\t\t ===================================================\n\n\n";
    cout<<"\t\t\t\t|   GuestName ->";
	cin>>name;
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   GuestId ->";
	cin>>id;
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   ContactNumber ->";
	cin>>number;
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   CheckInDate ->";
	cin>>date;
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   DurationOfStay ->";
	cin>>duration;
    	cout<<"\n\t\t----------------------------------------------------\n";

    temp->GuestName = name;
    temp->Guestid = id;
    temp->contactNumber = number;
    temp->checkInDate = date;
    temp->DurationOfStay = duration;


    //in case if the queue is empty
    if (rear == NULL) 
    {
        front = rear = temp;
        return;
    }

    //adding the node in the end of the queue
    rear->next = temp;
    rear = temp;
    


}

int main(){



}









