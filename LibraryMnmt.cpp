#include<iostream>
#include<vector>
using namespace std;
class Item
{
    private:
    int id;
    string title;
    string author;

    public:
     Item(){

    }
    Item(int id,string title,string author)
    {
        this->id=id;
        this->title=title;
        this->author=author;
    }

    virtual void display()
    {
        cout<<"ID: "<<id<<" Title: "<<title<<" Author: "<<author;
    }

    virtual void accept()
    {
        cout<<"Enter id,title,author:";
        cin>>id>>title>>author;
    }
    virtual void getFine()=0; 

};

class Book : public Item
{
    private:
    int pages;
    public:
    Book(){

    }
    Book(int id,string title,string author,int pages):Item(id,title,author)
    {
        this->pages = pages;
    }

     void display()
    {
        Item::display();
        cout<<" Pages:" <<pages;
    }

      void accept()
    {
        Item::accept();
        cout<<"Enter pages:";
        cin>>pages;
    }

    void getFine()
    {
        int days;
        cout<<"Enter no of days you are late:";
        cin>>days;
        cout<<"Fine = "<<days*5;
    }
};

class Magzine : public Item
{
    private:
    int duration;
    public:
    Magzine(){

    }
    Magzine(int id,string title,string author,int duration):Item(id,title,author)
    {
        this->duration = duration;
    }

     void display()
    {
        Item::display();
        cout<<" Duration: "<<duration;
    }

      void accept()
    {
        Item::accept();
        cout<<"Enter duration in min:";
        cin>>duration;
    }

    void getFine()
    {
        int days;
        cout<<"Enter no of days you are late:";
        cin>>days;
        cout<<"Fine = "<<days*10;
    }
};
class DVD : public Item
{
    private:
    int issueno;
    public:
    DVD(){

    }
    DVD(int id,string title,string author,int issueno):Item(id,title,author)
    {
        this->issueno = issueno;
    }

     void display()
    {
        Item::display();
        cout<<"Issue No: "<<issueno;
    }

      void accept()
    {
        Item::accept();
        cout<<"Enter Issueno:";
        cin>>issueno;
    }

    void getFine()
    {
        int days;
        cout<<"Enter no of days you are late:";
        cin>>days;
        cout<<"Fine = "<<days*15;
    }
};

int main()
{
    vector<Item*> library;
    Item *i = nullptr;
    int ch;
    do{
        cout<<"\nEnter choice:\n1.Add Book \n2.Add Magzine \n3.Add DVD \n4.Display \n0.Exit\n";
        cin>>ch;
        switch (ch)
        {
        case 1:
            i = new Book();
            i->accept();
            library.push_back(i);
            cout<<"Book added successfully !!!";
            break;

        case 2:
            i = new Magzine();
            i->accept();
            library.push_back(i);
            cout<<"Magzine added successfully !!!";
            
            break;

        case 3:
            i = new DVD();
            i->accept();
            library.push_back(i);
            cout<<"Magzine added successfully !!!";
            break;

        case 4:
            for(auto item : library)
            {
                item->display();
            }
            break;
        case 0:
            cout<<"Exiting !!!";
            break;
        default:
        cout<<"\nEnter valid choice !!!";
            break;
        }
    }while(ch!=0);
}
