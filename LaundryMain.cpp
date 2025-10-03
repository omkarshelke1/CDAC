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
        this->msg = msg;
    }

    const char* what() const noexcept override
    {
        return msg.c_str();
    }
};

class Laundry
{
    protected:
    int id;
    string cname;
    int quantity;
    public:
    Laundry(){

    }
    Laundry(int id,string cname,int quantity)
    {
        this->id=id;
        this->cname=cname;
        this->quantity=quantity;
    }

    virtual void display()
    {
        cout<<"ID: "<<id<<"Customer name: "<<cname<<" Quantity: "<<quantity<<endl;
    }

    virtual void starch()=0;

};

class RegularLaundry : public Laundry
{
    private:
        int IronPrice = 10;
        int shirts;
    public:
    RegularLaundry()
    {

    }
    RegularLaundry(int id,string cname,int quantity,int shirts) : Laundry(id,cname,quantity)
    {
        this->shirts = shirts;
    }

    void display()
    {
        Laundry::display();
        cout<<" IronPrice : "<<IronPrice<<" Shirts:"<<shirts<<endl;
    }

    void price()
    {
        cout<<"Total Bill = "<<quantity * IronPrice<<endl;
    }

    void starch()
    {
        cout<<"Starch successfull of Regular Laundry !!!"<<endl;
    }
};

class DryCleaning : public Laundry
{
    private:
        int DCPrice = 40;
        int pants;
    public:
    DryCleaning()
    {

    }
    DryCleaning(int id,string cname,int quantity,int pants) : Laundry(id,cname,quantity)
    {
        this->pants = pants;
    }

    void display()
    {
        Laundry::display();
        cout<<" DCPrice : "<<DCPrice<<" Pants:"<<pants<<endl;
    }

    void price()
    {
        if(quantity > 10){
            cout<<"Total Discounted Bill = "<<quantity * DCPrice * 0.80<<endl;
    
        }
        else{
            cout<<"Total Bill = "<<quantity * DCPrice<<endl;
    
        }
    }

    void starch()
    {
        cout<<"Starch successfull of Dry Cleaning!!!"<<endl;
    }
        
};

int main()
{
    int ch;
    int id=1;
    string cname;
    int quantity;
    int shirts,pants;
    vector<Laundry*> v;
    Laundry* laundry;
    do
    {
        cout<<"\n1.Add Regular Laundry\n2.Add Dry Cleaning\n3.Display all\n4.Show bills\n5.View starch\n6.Exit\n";
        cin>>ch;
        try
        {
            switch (ch)
            {
            case 1:{
                cout<<"Enter name:";
                cin.ignore();
                getline(cin,cname);
                cout<<"Enter quantity:";
                cin>>quantity;
                if(quantity < 1)
                {
                    throw MyException("Quantity should be positive !!!");
                }
                cout<<"No of shirts:";
                cin>>shirts;
                if(shirts > quantity)
                {
                    throw MyException("No of shirts cannot be more than the quantity !!!");
                }
                laundry = new RegularLaundry(id,cname,quantity,shirts);
                v.push_back(laundry);
                cout<<"Item added !!!";
                id++;
            }
                
                break;
            case 2:{
                cout<<"Enter name:";
                cin.ignore();
                getline(cin,cname);
                cout<<"Enter quantity:";
                cin>>quantity;
                if(quantity < 1)
                {
                    throw MyException("Quantity should be positive !!!");
                }
                cout<<"No of pants:";
                cin>>pants;
                if(pants > quantity)
                {
                    throw MyException("No of pants cannot be more than the quantity !!!");
                }
                laundry = new DryCleaning(id,cname,quantity,pants);
                v.push_back(laundry);
                cout<<"Item added !!!";
                id++;
            }
                
                break;
            case 3:{
                if(id == 1)
                {
                    throw MyException("No items added yet to display !!!");
                }
                for(auto i:v)
                {
                    i->display();
                }
            }
            break;

            case 4:{
                for(auto i:v)
                {
                    if(typeid(*i)==typeid(RegularLaundry))
                    {
                        RegularLaundry* rl = dynamic_cast<RegularLaundry*>(i);
                        if(rl)
                        {
                            rl->price();
                        } 
                    }
                    else if(typeid(*i)==typeid(DryCleaning))
                    {
                        DryCleaning* dc = dynamic_cast<DryCleaning*>(i);
                        if(dc){
                            dc->price();
                        } 
                    }
                }
            }
            break;

            case 5:{
                for(auto i:v)
                {
                    i->starch();
                }
            }
            break;
            
            case 6:
                cout<<"Exited !!!"<<endl;
                break;

            default:
                cout<<"Enter valid choice !!!"<<endl;
                break;
            }
        }
        catch(exception& e)
        {
            cout << e.what() << '\n';
        }
        
    } while (ch !=6);
    

}