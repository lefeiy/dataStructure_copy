#include<iostream>

using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;
//typedef int ElemType;
typedef int KeyType;
typedef int InfoType;

typedef struct ElemType{
    KeyType key;
    InfoType otherinfo;
} ElemType; //the element being looked up

typedef struct {
    ElemType *R;
    int length;
} SSTable;
//Function declaration
void Create_Bin(SSTable &ST,int n);
void Traverse_Bin(const SSTable ST);
int Search_Bin(SSTable ST, KeyType key);

int main()
{
    SSTable a;
    Create_Bin(a,11);
    Traverse_Bin(a);
    Search_Bin(a,27);
    Search_Bin(a,65);

    return 0;
}


void Create_Bin(SSTable &ST,int n)
{
    cout<<"please enter "<<n<<" elements";
    ST.length=n;
    for (int i=1;i<=n;i++)
    {
       cin>> ST.R[i].key;
    }
}

void Traverse_Bin(const SSTable ST)
{
    for (int i=1;i<=ST.length;i++)
    {
        cout<<ST.R[i].key<<"  ";
    }
    cout<<endl;
}

int Search_Bin(SSTable ST, KeyType key)
{
    int low = 1;
    int high = ST.length;
    int mid ;
    int times = 0;
    while (low <=high)
    {
        times++;
        mid = (low +high)/2;
        if (key == ST.R[mid].key) {cout<<"found!!!"<<"the target is"<<ST.R[mid].key<<endl; return mid;}
        else if (key < ST.R[mid].key) {
            cout<<"It's "<<times<<"th time the value is :"<<ST.R[mid].key<<endl;
            high = mid-1;
        }
        else {cout<<"It's "<<times<<"th time the value is :"<<ST.R[mid].key<<endl;low = mid +1;}
    }
    return 0;
}
void Destroy_Bin(SSTable &ST)
{
    for (int i = 1;i<=ST.length;i++)
    {
        delete [] ST.R;
    }
    ST.length = 0;
}
/*
5
16
20
27
30
36
44
55
60
67
71

*/