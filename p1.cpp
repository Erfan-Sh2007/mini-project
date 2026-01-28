#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void jadval(char A[10][10]);
void input_ship(char ary[10][10],int size_ship);
bool checker_star(char B[10][10]);
void shut_ship(char C[10][10],int ,int);

int main()
{
    string player_one;
    string player_two;

    cout <<"Enter name player number 1-->>  ";
    cin >> player_one;
    cout << "Enter name player number 2-->>  ";
    cin >> player_two;
    char map_player_number1[10][10];
    char map_player_number2[10][10];
    
    for(int i=0 ;i<10;i++)
        for(int j=0 ;j<10 ;j++)
        {
             map_player_number1[i][j]=48;
             map_player_number2[i][j]=48;
        }
            
      for(int i=2;i<=5 ;i++)
             input_ship(map_player_number1,i);
      for(int i=2;i<=5;i++)
             input_ship(map_player_number2,i);

     
     while(1)
     {
        int x;
        int y;

        cout <<"turn player number one :  ";
        cout << "          "<< player_one<< endl;
        cout << "Enter two integer number  for hit "<<player_two<< "map"<< endl;
         jadval(map_player_number1);
         cout << endl;
         cin >> x >>y;
    
        shut_ship(map_player_number2,x,y);

        if(checker_star(map_player_number2))
         {
            cout << "won "<<player_one<<" this game"<< endl;
                break;
         }

         cout << endl<<endl<<endl;
        cout <<"turn player number two :  ";
        cout << "          "<< player_two<< endl;
        cout << "Enter two integer number  for hit "<<player_one<< " map"<< endl;
        jadval(map_player_number2);
        cout << endl;
        cin >> x >>y;
        shut_ship(map_player_number1,x,y);

        if(checker_star(map_player_number1))
        {
            cout << "won "<< player_two<< " this game";
            break;
        }
        cout <<endl << endl<< endl;
     
     }
    
         
    
   
   
    return 0;
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
                if(A[i-1][k-1]==48)
                {
                    cout <<"   ";
                
                }
                else{
                     if(k!=11)
                     {
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
            }
            cout << endl<<"    ";
        }
    }

}

void input_ship(char ary[10][10],int size_ship)
{
   
   int random_satr;
   int random_soton;

    srand(time(0));
    random_satr = rand() % (10)+1;
    srand(time(0));
    random_soton = rand() % (10-size_ship+1)+1;
   while(1)
   {
         srand(time(0));
         random_satr = rand() % (10)+1;
         random_soton = rand() % (10-size_ship+1)+1;
         int alaki=0; 
         for(int i=0 ;i<10;i++)
         {
            if(ary[random_satr-1][i] == 42)
            {
                alaki=1;
            }

            if(random_satr<=9 &&  random_soton+i-1<=(size_ship+random_soton +2))
            {
                if((ary[random_satr][random_soton+i-1]==42)&&(ary[random_satr][random_soton+i-2]==42))
                {
                    alaki=1;
                }
            }

            if(random_satr-2>=0 && (random_soton+i-1)<=(random_soton+size_ship +2))
            {
                if(ary[random_satr-2][random_soton+i-1]==42)
                {
                    alaki=1;
                }
            }

         }
         if(alaki==0)
         {
            break;
         }
      
   }
   char setare='*';
   cout <<random_satr<<" "<< random_soton<< endl;

   for(int i=0;i<size_ship;i++)
   {
       ary[random_satr-1][random_soton-1]=setare;
       random_soton++;

   }
}


bool checker_star(char B[10][10])   //checker : do there  is star in array?
{
    for(int i=0 ;i<10;i++)
    {
        for(int j=0 ;j<10 ;j++)
        {
            if(B[i][j]==42)         // 42 is star ascii code.
            {
                return false;
            }
        }
    }

    return true;
}


void shut_ship(char C[10][10],int sat,int sot)
{

    if(C[sat-1][sot-1]==42)                     // 42 is star ascii code.
    {
        C[sat-1][sot-1]=35;                    //35 is sharp ascii code.

        cout << "shut was secesfull"<< endl;

    }
    else{
        cout << "shut wasnot secesfull"<< endl;
    }
    

}


