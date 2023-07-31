#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
long length = 1000;
 
int list1[200000];
int list2[200000];
 
void read()
{
    ifstream fin("random.dat", ios::binary);
    for (long i = 0; i < length; i++)
    {
        fin.read((char*)&list1[i], sizeof(int));
        fin.read((char*)&list2[i], sizeof(int));
    }
    fin.close();
}
 
void bubbleSort()
{
    int temp;
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
    
}
 
void insertionSort()
{
    int temp;
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
}
 

 
int main()
{
	
	ofstream fout("random.dat", ios::binary);
	ofstream a("random.txt",ios::out);
    
    srand(time(NULL)); 
    int r;
    for (size_t i = 0; i < length; i++)
    {
        r = (rand()%100);
        fout.write((char*)&r, sizeof(r));
        a<<r<<endl;
    }
 
    fout.close();
    
    double t1, t2;
 
    for (length = 1000; length <= 200000; )
    {
        cout << "\nLength\t: " << length << '\n';
 
        read();
        t1 = clock();
        insertionSort(); 
        t2 = clock();
        cout << "Bubble Sort\t: " << (t2 - t1)/CLOCKS_PER_SEC << " sec\n";
 
        read();
        t1 = clock();
        bubbleSort();
        t2 = clock();
        cout << "Insertion Sort\t: " << (t2 - t1)/CLOCKS_PER_SEC<< " sec\n";
 
       
        switch (length)
        {
        case 1000 :
            length = 5000;
            break;
        case 5000 :
            length = 10000;
            break;
        case 10000 :
            length = 50000;
            break;
        case 50000 :
            length = 100000;
            break;
        case 100000 :
            length = 200000;
        case 200000 :
            length = 200001;cout<<"\n done";
            break;

        }
    }
 
    return 0;
}
