#include <iostream>
using namespace std;

void jadval(char A[10][10]);


int main()
{
    char star='*';
    char sharp='#';
   char arr[10][10]={};
   
   jadval(arr);
    
}


void jadval(char A[10][10])
{
 cout << "  ";
    for(int i=1;i<=10;i++)
        cout << "   "<<i;
    cout << endl<<"    ";

    for(int i=1;i<=11;i++)
    {
    
        for ( int j=1 ; j<=10;j++)
        {
            cout <<"---"<< " ";
        }
        if(i!=11)
        {
            if(i!=10)
               cout <<endl << i<<"  ";
            else{cout <<endl <<i <<" ";}

            for(int k=1;k<=11;k++)
            {
                cout << "|";
                if(A[i-1][k-1]==0)
                {
                    cout <<"   ";
                
                }
                else{

                    if(A[i-1][k-1]=='*')
                    {
                        cout <<" "<<"*"<<" ";
                    }
                    else if(A[i-1][k-1]=='#')
                    {
                        cout << " "<<"#"<<" ";
                    }
                }
            }
            cout << endl<<"    ";
        }
    }

}