#include<iostream>
using namespace std;

int addition(int num_01,int num_02)
{
    return num_01 + num_02;
}
int subtraction(int num_01,int num_02)
{
    return num_01 - num_02;
}
int multiplication(int num_01,int num_02)
{
    return num_01 * num_02;
}
int division(int num_01,int num_02)
{
    return num_01 / num_02;
}

int main()
{
    cout<<endl;
    cout<<endl;

    cout<<"         Welcome to CodSoft's Calculator     "<<endl;
    cout<<endl;
    cout<<endl;
    int option;
    int num_01;
    int num_02;
do{
    cout<<"Enter the first Number: ";
    cin>>num_01;
    cout<<"Enter the second Number: ";
    cin>>num_02;
    cout<<endl;

    int i;
    cout<<"Calculator- "<<endl;
    cout<<"1.Addition(+)\n2.Subtraction(-)\n3.Multiplication(*)\n4.Division(/)"<<endl;
    cout<<"Enter the operation to be performed: ";
    cin>>i;

    switch (i)
    {
    case 1: cout<<"The addition is: "<<addition(num_01,num_02);
              
    break;

    case 2: cout<<"The subtraction is: "<<subtraction(num_01,num_02);
                   
    break;

    case 3: cout<<"The multiplication is: "<<multiplication(num_01,num_02); 
            
    break;

    case 4: cout<<"The division is: "<<division(num_01,num_02);
                 
    break;


    default: cout<<"Exit";
        break;
    }
    cout<<endl;
    cout<<"Do you want to continue (0/1)?";
    cin>>option;

    }while(option==1);

    cout<<"Thank you !!";

}


//code by Anish Patil
//for CodSoft C++ Internship
//@CodSoft