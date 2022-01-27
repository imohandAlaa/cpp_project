
#include<iostream>
#include <ctime>


using namespace std;
 

struct Guest{
    
    string GuestName;
    int contactNumber;
    string Guestid;
    string checkInDate;
    int DurationOfStay;
    Guest *next;
};
 
class hotel{
    public:
    Guest *front,*rear;
    hotel(){front=rear=NULL;}
    void CheckIn(int n);
    void CheckOut();
    void displayQuests();
    void checkCpacity();
    void SearchforGuest();
    void makePayment();
    void IsEmpty();
    void IsFull();
    ~hotel();
};
 






int main(){



}










