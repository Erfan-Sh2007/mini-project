#include <iostream>
using namespace std;

void jadval(int ,int,char);


int main()
{
    char s='*';
   jadval(1,1,s);
    
}


void jadval(int m,int n,char func)
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
                if(m==i &&n==k&& func=='*')
                {
                    cout <<" "<<"*"<<" ";
                }
                if(m==i &&n==k&& func=='#')
                {
                    cout <<" "<<"#"<<" ";
                }

                else{
                    cout <<"   ";
                }
            }
            cout << endl<<"    ";
        }
    }

}