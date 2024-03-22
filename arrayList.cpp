/*Array Representation of List ADT*/
#include<iostream>
using namespace std;
class Array_List
{
public:
    int n=5;
    int num[5];
    int no_of_ele=0;
    Array_List()
    {
        for(int i=0;i<n;i++)
            num[i]=0;
    }
    int IsFull()
    {
        if(no_of_ele==n)
            return 1;
        else
            return 0;
    }
    int IsEmpty()
    {
        if(no_of_ele==0)
            return 1;
        else
            return 0;
    }
    void insertAtBeginning()
    {
        int data;
        cin>>data;
        if(IsEmpty())//empty list => create list
        {
            num[0]=data;
            no_of_ele++;
        }
        else
        {
            if(IsFull())
            {
                cout<<"Insertion not Possible, List is Full"<<endl;
            }
            else
            {
                for(int i=no_of_ele;i>0;i--)
                {
                    num[i]=num[i-1];
                }
                num[0]=data;
                no_of_ele++;
            }
        }
    }
    void insertAtEnd()
    {
        int data;
        cin>>data;
        if(IsFull())
        {
                cout<<"Insertion not Possible, List is Full"<<endl;
        }
        else
        {
            num[no_of_ele]=data;
            no_of_ele++;
        }
    }
    void insertAtMiddle()
    {
        int data, index;
        cin>>data>>index;
        if(IsFull())
        {
                cout<<"Insertion not Possible, List is Full"<<endl;
        }
        else
        {
                for(int i=no_of_ele;i>index;i--)
                {
                    num[i]=num[i-1];
                }
                num[index]=data;
                no_of_ele++;
        }

    }
    void deleteAtEnd()
    {
        if(IsEmpty())
       {
           cout<<"Deletion not Possible, List is Empty"<<endl;
       }
       else
       {
           num[no_of_ele]=0;
           no_of_ele--;
       }
    }
    void deleteAtBeginning()
    {
       if(IsEmpty())
       {
           cout<<"Deletion not Possible, List is Empty"<<endl;
       }
       else
       {
           for(int i=0;i<no_of_ele-1;i++)
           {
                num[i]=num[i+1];
           }
           no_of_ele--;
           num[no_of_ele]=0;
       }
    }
    void deleteAtMiddle()
    {
        int index;
        cin>>index;
        if(IsEmpty())
       {
           cout<<"Deletion not Possible, List is Empty"<<endl;
       }
       else
       {
           for(int i=index;i<no_of_ele-1;i++)
           {
                num[i]=num[i+1];
           }
           no_of_ele--;
           num[no_of_ele]=0;
       }
    }
    void print()
    {
        cout<<"List Elements are"<<endl;
        for(int i=0;i<no_of_ele;i++)
            cout<<num[i]<<" ";
        cout<<endl;

    }
};
int main()
{
    Array_List obj;
    obj.insertAtBeginning();
    obj.print();
    obj.insertAtEnd();
    obj.insertAtBeginning();
    obj.print();
    obj.insertAtMiddle();
    obj.print();
    obj.insertAtEnd();
    obj.print();
    obj.insertAtEnd();
    obj.print();
    obj.deleteAtBeginning();
    obj.print();
    obj.deleteAtEnd();
    obj.print();
    obj.deleteAtMiddle();
    obj.print();
    obj.deleteAtBeginning();
    obj.print();
    obj.deleteAtEnd();
    obj.print();
    obj.deleteAtBeginning();
    obj.print();
    obj.deleteAtEnd();
    obj.print();
    obj.insertAtBeginning();
    obj.print();
    obj.insertAtEnd();
    obj.print();
    return 0;
}

