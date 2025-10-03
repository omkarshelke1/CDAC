#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;

class MyException : public exception
{
    private:
    string msg;
    public:
    MyException(string msg)
    {
        this->msg=msg;
    }

    const char* what() const noexcept override
    {
        return msg.c_str();
    }
};
class Room
{
    protected:
        int roomno;
        string roomType;
        double price;
        int days;

    public:
    Room(int roomno,string roomType,double price,int days)
    {
        this->roomno = roomno;
        this->roomType = roomType;
        this->price=price;
        this->days=days;
    }

       virtual void display()
       {
        cout<<"Room no:"<<roomno<<" Room type:" << roomType<<" Price:"<<price<<" Days:"<<days<<endl;
       } 
    virtual void calculateBill() = 0;

};

class StandardRoom : public Room
{
    private:
        string amenities;
    public:
        StandardRoom(int roomno,string roomType,double price,int days,string amenities):Room(roomno,roomType,price,days)
        {
            this->amenities=amenities;
        }

        void display()
       {
        Room::display();
        cout<<"Amenities:"<<amenities<<endl;
       } 

       void calculateBill()
       {
        cout<<"\nTotal Bill of standard room no "<<roomno<<": "<<days*price;
       }

       void specialAmenities()
       {
        cout<<"Special amenities of standard room:free-wifi, hot water \n";
       }


};

class DeluxeRoom : public Room
{
    private:
        string specialSerivce;
    public:
        DeluxeRoom(int roomno,string roomType,double price,int days,string specialSerivce):Room(roomno,roomType,price,days)
        {
            this->specialSerivce=specialSerivce;
        }

        void display()
       {
        Room::display();
        cout<<"Special Serivce:"<<specialSerivce<<endl;
       } 

       void calculateBill()
       {
        cout<<"\nTotal Bill of standard room no "<<roomno<<": "<<days*price;
       }

       void specialSerivceAvl()
       {
        cout<<"Special amenities of deluxe room:break-fast included, ac room \n";
       }


};

int main()
{
    int ch,count=0;
    int roomno;
    string roomType;
    double price;
    int days;
    string amenities,specialService;

    vector<Room*> v;
    Room *r;
    do
    {
        cout<<"\n\n1.Add standard room \n2.Add deluxe room \n3.Display and Calculate Bill\n4.Special methods\n5.Exit\n";
        cin>>ch;
        try
        {
            switch(ch)
            {
                case 1:{
                    cout<<"\nEnter roomno:";
                    cin>>roomno;
                    cout<<"Enter price:";
                    cin>>price;
                    cout<<"Enter no of days:";
                    cin>>days;
                    if(days < 1)
                    {
                        throw MyException("No of days should be positive !!!");
                    }
                    cout<<"Enter amenities:";
                    cin.ignore();
                    getline(cin,amenities);
                    r = new StandardRoom(roomno,"Standard Room",price,days,amenities);
                    v.push_back(r);
                    count++;
                    cout<<"Added successfully !!!"<<endl;
                }
                break;

                case 2:{
                    cout<<"\nEnter roomno:";
                    cin>>roomno;
                    cout<<"Enter price:";
                    cin>>price;
                    cout<<"Enter no of days:";
                    cin>>days;
                    if(days < 1)
                    {
                        throw MyException("No of days should be positive !!!");
                    }
                    cout<<"Enter special service:";
                    cin.ignore();
                    getline(cin,specialService);
                    r = new DeluxeRoom(roomno,"Deluxe Room",price,days,specialService);
                    v.push_back(r);
                    count++;
                    cout<<"Added successfully !!!\n";

                }
                break;

                case 3:{
                    if(count==0)
                    {
                        throw MyException("No rooms added yet!!!");
                    }
                    for(auto i:v)
                    {
                        i->display();
                        i->calculateBill();
                    }
                }
                break;

                case 4:{
                    for(auto i:v)
                    {
                        if(typeid(*i)==typeid(StandardRoom))
                        {
                            StandardRoom* sr = dynamic_cast<StandardRoom*>(i);
                            if(sr)
                            {
                                sr->specialAmenities();
                            }
                        }
                        else if(typeid(*i)==typeid(DeluxeRoom))
                        {
                            DeluxeRoom* dr = dynamic_cast<DeluxeRoom*>(i);
                            if(dr)
                            {
                                dr->specialSerivceAvl();
                            }
                        }
                    }
                }
                break;
                case 5:
                    cout<<"\nExiting!!!";
                    break;
                default:
                    cout<<"Enter valid choice !!!";

            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    } while (ch!=5);
    
}