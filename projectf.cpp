#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class comparisons {
int length;
void selection();
void bubblesort();
void insertion();
void menu();
void option1();
void option2();
    int *list1,*list2,*list3;
public:

comparisons() {
menu();}

};

void comparisons:: option2() {
float ch;
cout<<"comparison between insertion and selection sort using array of 1 lakh elements of various degree of sortedness:";
cout<<"enter the degree of sortedness in % \n";
cin>>ch;

srand(time(NULL));
    int r;
    length=100000;
    list3= new int[length];
list2= new int[length];

    for (int i = 0; i < 100000; i++)
    {
if (i<= (ch*1000))
list3[i]=list2[i]=i;
else
        {r = (rand()%100);
        list3[i]=list2[i]=r;}
       
    }
    cout<<endl<<endl;
    insertion();
    selection();

}

void comparisons:: option1() {
cout<<"enter the no of elements to generate in the array: ";
cin>>length;
list1= new int[length];
list2= new int[length];
list3= new int[length];
 int num;
cout<<"\nHow many sets of results do you want to obtain? "; cin>>num;
for(int i=0;i<num;i++) {
srand(time(NULL));
    int r;
    for (int i = 0; i < length; i++)
    {

        {r = (rand()%100);
        list1[i]=list2[i]=list3[i]=r;}
     }  
       insertion();selection();bubblesort();cout<<endl;
   
  }
 
}






void comparisons:: selection() {
int i,j,loc,temp,min;
int n = length;
double t1 = clock();


    for(i=0;i<n-1;i++)
    {
        min=list3[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(min>list3[j])
            {
                min=list3[j];
                loc=j;
            }
        }
 
        temp=list3[i];
        list3[i]=list3[loc];
        list3[loc]=temp;
    }
        double  t2 = clock();
        cout << "selection Sort\t: " << (t2 - t1)/CLOCKS_PER_SEC<< " sec\n";
 
 }

 

void comparisons::bubblesort()
{
    int temp;
   
    double t1 = clock();
    for(long i = 0; i < length; i++)
    {
        for(long j = 0; j < length-i-1; j++)
        {
            if (list1[j] > list1[j+1])
            {
                temp        = list1[j];
                list1[j]     = list1[j+1];
                list1[j+1]   = temp;
            }
        }
    }
     double t2 = clock();
     cout<< "bubble Sort\t: " << (t2 - t1)/CLOCKS_PER_SEC<< " sec\n";
   
}
 
void comparisons:: insertion()
{
    int temp; double t1 = clock();

 
    for(long i = 1; i < length; i++)
    {
        temp = list2[i];
        long j;
        for(j = i-1; j >= 0 && list2[j] > temp; j--)
        {
            list2[j+1] = list2[j];
        }
        list2[j+1] = temp;
    }
double t2 = clock();
     cout<< "Insertion Sort\t: " << (t2 - t1)/CLOCKS_PER_SEC<< " sec\n";
}

void comparisons:: menu() {
int ch;
do {
cout<<"\n\n\nEnter the choice: \n1. Comparison between 3 sorts \n2.Between insertion and selection based on degree of sortedness.\n0.exit\n";

cin>>ch;
switch(ch)
{
case 1: option1();break;
   case 2: option2();break;

}
}while(ch);
}


int main()
{
cout<<"\t\tTIME COMPARISON BETWEEN DIFFERENT SORTING TECHNIQUES\n";
comparisons z;
return 0;      
 }
