
#include<iostream>
#include <ctime>


using namespace std;
 

int const size = 20;
int counter = 20;

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
    void displayGuests();
    void checkCpacity();
    void SearchforGuest();
    void MakePayment();
    void IsEmpty();
    bool IsFull();
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

   // counter++;

}

void hotel::CheckOut(){

    //if(IsEmpty){}
    //first guest checkedin will checkout first
    Guest* temp = new Guest();

    cout<<"\n";
    	cout<<"\t\t ===================================================\n";
	cout<<"\t\t\t\t|   Hotel - CheckOut    |\n";
	cout<<"\t\t ===================================================\n\n\n";
    cout<<"\t\t\t\t|   GuestName ->"<<front->GuestName;
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   GuestId ->"<<front->Guestid;
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   ContactNumber ->"<<front->contactNumber;
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   CheckInDate ->"<<front->checkInDate;
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   DurationOfStay ->"<<front->DurationOfStay;
    	cout<<"\n\t\t----------------------------------------------------\n";




    temp = front;
    front = front->next;
    temp->next = NULL;

    delete temp;
    


}




void hotel::IsEmpty(){}

/*
bool hotel::IsFull(){

    return bool(counter == size);
}
*/

void dispMenu()
{
	
	cout<<"\n";
    	cout<<"\t\t ===================================================\n";
	cout<<"\t\t\t\t|   Hotel Management   |\n";
	cout<<"\t\t ===================================================\n\n\n";
    cout<<"\t\t\t\t|   1.CheckIn";
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   2.CheckOut";
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   3.displayGuests";
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   4.checkCpacity";
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   5.SearchforGuest";
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   6.MakePayment";
    	cout<<"\n\t\t----------------------------------------------------\n"; 
    cout<<"\n\n\t\t\t\t|   Enter your choice [1-6]: ";
    	cout<<"\n\t\t----------------------------------------------------\n";     
}
int main(){
    
    dispMenu();
    

}









