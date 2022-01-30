
#include<iostream>
#include <ctime>


using namespace std;
 

int const size = 3;
int counter = 0;

struct Guest{
    string GuestName;
    string Guestid;
    int contactNumber;
    string checkInDate;
    int DurationOfStay;
    int GuestRank;
    bool Payment;
    Guest *next;
    Guest(){
        
        GuestName = "";
        Guestid = "";
        contactNumber = 0;
        checkInDate = "";
        DurationOfStay = 0;
        GuestRank = 0;
        Payment = false;
    }
    Guest(string name,string id,int number,string date,int duration ,int rank,bool pay){
        this->GuestName = name;
        this->Guestid = id;
        this->contactNumber = number;
        this->checkInDate = date;
        this->DurationOfStay =duration;
        this->GuestRank = rank;
        this->Payment = pay;
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
    void updateRanks();
    void displayGuests();
    void show(Guest* item);
    void CpacityReport();
    void SearchforGuest();
    void MakePayment();
    bool IsEmpty();
    bool IsFull();
};

// check in function stores quest important data
void hotel::CheckIn(){

    counter++;
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
    cout<<"\t\t\t\t|   Guest number -> "<< counter;
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
        return;
    }
    //adding the node in the end of the queue
    rear->next = temp;
    rear = temp;
    
    }else
    {
         cout<<"\t\t ===================================================\n";
        cout<<"\t\t\t\t|  opss!! the hotel is FULL     |\n";
        cout<<"\t\t ===================================================\n";
    }
}
void hotel::updateRanks()
{

    if (front != NULL)
    {    Guest *temp = front;
        for (temp = front; temp != NULL; temp = temp->next)
        {
            temp->GuestRank = temp->GuestRank - 1;
            front = temp;
        }
        
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
        //temp->next->GuestRank = temp -> GuestRank;
        temp->next = NULL;
        
        delete temp;
        counter--;
        updateRanks();
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
        if(temp->Payment ==true)
        {
            cout<<"\t\t\t\t|   PaymentStatus -> Successful ";
    	    cout<<"\n\t\t----------------------------------------------------\n";
        }else
        {
            cout<<"\t\t\t\t|   PaymentStatus -> Falied";
    	    cout<<"\n\t\t----------------------------------------------------\n";
        }

}



void hotel::displayGuests()
{   if(!IsEmpty()){
    Guest* display;
    for(display = front;display != NULL;display = display->next)
    {
    cout<<"\n";
    cout<<"\t\t ===================================================\n";
	cout<<"\t\t\t\t|   Hotel - DisplayGuests    |\n";
	show(display);
    }
    }else
    {
        cout<<"\t\t\t\t|   Hotel - DisplayGuests    |\n";
        cout<<"\t\t\t\t|   there is no guest has checkedIn recently   |\n";

    }

}

void hotel::SearchforGuest(){
    int choice;
    Guest* fetch;
    if(!IsEmpty()){
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
   }else
   {
       cout<<"\t\t\t\t|   Hotel - Search    |\n";
        cout<<"\t\t\t\t|   there is no guest has checkedIn recently |\n";
   }
}


void hotel ::MakePayment()
{
    int choose;
    cout<<"\t\t\t|   Hotel Management - Payment  |\n";
    cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t|   choose payment method ->";
    cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t|   1.credit card ";
    cout<<"\n\t\t----------------------------------------------------\n";
    cout<<"\t\t|   2.cash ";
    cout<<"\n\t\t----------------------------------------------------\n"; 
    cin >> choose;
    if(choose == 1){
        front->Payment = true;
    }else
        front->Payment = true;
}


void hotel :: CpacityReport()
{
    cout<<"\n";
    cout<<"\t\t ===================================================\n";
	cout<<"\t\t\t|   Hotel Management - CpacityReport  |\n";
	cout<<"\t\t ===================================================\n";
    if(IsEmpty()){
        cout<<"\t\t ===================================================\n";
        cout<<"\t\t\t\t|       the hotel is Empty     |\n";
        cout<<"\t\t ===================================================\n";
         cout<<"\t\t\t\t|   there is "<< size << "  Empty  Room";
    	cout<<"\n\t\t----------------------------------------------------\n";
    }else if (IsFull())
    {
        cout<<"\t\t ===================================================\n";
        cout<<"\t\t\t\t|  opss!! the hotel is FULL     |\n";
        cout<<"\t\t ===================================================\n";
    }else
    {
        cout<<"\n\t\t----------------------------------------------------\n";
        cout<<"\t\t\t\t|  we have  "<< counter << "  busy Room ";
    	cout<<"\n\t\t----------------------------------------------------\n";
        cout<<"\t\t\t\t|  we have  "<< size - counter  << "  empty room";
    	cout<<"\n\t\t----------------------------------------------------\n";
    }
}


bool hotel :: IsEmpty()
{
    if(rear == NULL && front == NULL){return true;}
    else
        return false;
}
bool hotel :: IsFull(){
    if(counter  == size )
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
    cout<<"\t\t\t\t|   4.CpacityReport";
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
            case 4: {guest.CpacityReport();}
                break;
            case 5: {guest.SearchforGuest();}
                break;
            case 6: {guest.MakePayment();}
                break;        
			default: cout << "\nThank you.. see you again.." << endl;
					 return 0;
		}
		
	} while ((choice > 0) && (choice < 7));


    return 0;
}




