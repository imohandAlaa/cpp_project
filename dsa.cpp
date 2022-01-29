
#include<iostream>
#include <ctime>


using namespace std;
 

int const size = 3;
int counter = 1;

struct Guest{
    string GuestName;
    string Guestid;
    int contactNumber;
    string checkInDate;
    int DurationOfStay;
    int GuestRank;
    Guest *next;
    Guest(){
        
        GuestName = "";
        Guestid = "";
        contactNumber = 0;
        checkInDate = "";
        DurationOfStay = 0;
        GuestRank = 0;
        
    }
    Guest(string name,string id,int number,string date,int duration ,int rank){
        this->GuestName = name;
        this->Guestid = id;
        this->contactNumber = number;
        this->checkInDate = date;
        this->DurationOfStay =duration;
        this->GuestRank = rank;
    }
};
 
class hotel{
    public:
    Guest *front,*rear;
    void creatqueue(){
        front = NULL;
        rear = NULL;
    };
    void CheckIn();
    void CheckOut();
    void displayGuests();
    void show(Guest* item);
    void CpacityReport();
    void SearchforGuest();
    void MakePayment();
    bool IsEmpty();
    bool IsFull();
    void destroyQueue();
   // ~hotel();
};

// check in function stores quest important data
void hotel::CheckIn(){
    
    if(!IsFull()){
    string name;
    string id;
    int number;
    string date;
    int duration;
    Guest* temp = new Guest();
    
    cout<<"\n";
    cout<<"\t\t ===================================================\n";
	cout<<"\t\t\t\t|   Hotel - CheckIn    |\n";
	cout<<"\t\t ===================================================\n";
    cout<<"\t\t\t\t|   Guest number -> "<<counter;
    cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   GuestName ->";
	cin >> name;
    cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   GuestId ->";
	cin >> id;
    cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   ContactNumber ->";
	cin >> number;
    cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   CheckInDate ->";
	cin >> date;
    cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   DurationOfStay ->";
	cin >> duration;
    cout<<"\n\t\t----------------------------------------------------\n\n\n";

    temp->GuestName = name;
    temp->Guestid = id;
    temp->contactNumber = number;
    temp->checkInDate = date;
    temp->DurationOfStay = duration;
    temp->GuestRank = counter;
    //in case if the queue is empty
    if (front == NULL) 
    {
        front = rear = temp;
        counter++;
        return;
    }
    //adding the node in the end of the queue
    rear->next = temp;
    rear = temp;
    counter++;
    }else
    {
         cout<<"\t\t ===================================================\n";
        cout<<"\t\t\t\t|  opss!! the hotel is FULL     |\n";
        cout<<"\t\t ===================================================\n";
    }
}

void hotel::CheckOut()
{
    if(!IsEmpty())
    {
        Guest* temp = front;
        cout<<"\n";
        cout<<"\t\t ===================================================\n";
        cout<<"\t\t\t\t|   Hotel - CheckOut    |\n";
        cout<<"\t\t ===================================================\n";
        show(front);
        temp = front;
        front = front->next;
        temp->next = NULL;
        delete temp;

    }else
    {
         cout<<"\t\t ===================================================\n";
        cout<<"\t\t\t\t|  opss!! the hotel is empty     |\n";
        cout<<"\t\t ===================================================\n";
       
    }
}


void hotel:: show(Guest *item)
{
    Guest *temp = item;
    cout<<"\n";
	cout<<"\t\t ===================================================\n";
    cout<<"\t\t\t\t|   GuestRank ->"<<temp->GuestRank;
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   GuestName ->"<<temp->GuestName;
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   GuestId ->"<<temp->Guestid;
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   ContactNumber ->"<<temp->contactNumber;
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   CheckInDate ->"<<temp->checkInDate;
    	cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   DurationOfStay ->"<<temp->DurationOfStay;
    	cout<<"\n\t\t----------------------------------------------------\n";

}



void hotel::displayGuests()
{
    int counter2 = 1;
    Guest* display;
    for(display = front;display != NULL;display = display->next)
    {
    cout<<"\n";
    cout<<"\t\t ===================================================\n";
	cout<<"\t\t\t\t|   Hotel - DisplayGuests    |\n";
	show(display);
    counter2++;
    }

}

void hotel::SearchforGuest(){
    int choice;
    Guest* fetch;
    
    cout<<"\n";
    cout<<"\t\t ===================================================\n";
	cout<<"\t\t\t\t|   Hotel - SearchforGuest    |\n";
	cout<<"\t\t ===================================================\n\n\n";
    cout<<"\t\t\t\t|   Search by";
    cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   ->1.GuestName ";
    cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t|   ->2.GuestId ";
    cout<<"\n\t\t----------------------------------------------------\n";
    cin >> choice;

    if(choice == 1)
    {
        string Name;
        cout<<"\t\t\t\t|    Enter GuestName -> ";
        cin >> Name;
    	cout<<"\n\t\t----------------------------------------------------\n";
        for(fetch = front;fetch !=NULL;fetch = fetch->next)
        {
            if(fetch->GuestName == Name)
            {
                cout<<"\n";
    	        cout<<"\t\t ===================================================\n";
	            cout<<"\t\t\t\t|   Guest is found Successfully   |\n";
	            show(fetch);

            }else
            {
                cout<<"\n";
    	        cout<<"\t\t ===================================================\n";
	            cout<<"\t\t\t\t|   Guest is not found    |\n";
                cout<<"\t\t ===================================================\n\n\n";
            }
        }
        

    }else
    {
        string ID;
        cout<<"\t\t\t\t|    Enter GuestID -> ";
        cin >> ID;
    	cout<<"\n\t\t----------------------------------------------------\n";
        for(fetch = front;fetch !=NULL;fetch = fetch->next)
        {
            if(fetch->Guestid == ID)
            {
                cout<<"\n";
    	        cout<<"\t\t ===================================================\n";
	            cout<<"\t\t\t\t|   Guest is found Successfully   |\n";
	            show(fetch);

            }else
            {
                cout<<"\n";
    	        cout<<"\t\t ===================================================\n";
	            cout<<"\t\t\t\t|   Guest is not found Successfully   |\n";
                cout<<"\t\t ===================================================\n\n\n";
            }

        }
    }

}


void hotel :: CpacityReport()
{
    


}


bool hotel :: IsEmpty()
{
    if(rear == NULL && front == NULL){return true;}
    else
        return false;
}
bool hotel :: IsFull(){
    if(counter  == size + 1)
        return true;
    else
        return false;    
}

void dispMenu()
{
    
	cout<<"\n";
    	cout<<"\t\t ===================================================\n";
	cout<<"\t\t\t\t|   Hotel Management   |\n";
	cout<<"\t\t ===================================================\n";
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
    cout<<"\t\t\t\t|   Enter your choice [1-6]: ";
    	cout<<"\n\t\t----------------------------------------------------\n\n\n";     

}
int main(){

    hotel guest;
    guest.creatqueue();
    int choice;
do
{
		dispMenu();
		
		cin >> choice;
		cin.ignore();
		
		switch(choice)
		{
			case 1: {guest.CheckIn();}
                break;
            case 2: {guest.CheckOut();}
                break;
            case 3: {guest.displayGuests();}
                break;
            case 4: {guest.SearchforGuest();}
                break;
			default: cout << "\nThank you.. see you again.." << endl;
					 return 0;
		}
		
	} while ((choice > 0) && (choice < 5));


    return 0;
}



    











