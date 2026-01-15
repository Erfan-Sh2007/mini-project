#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void jadval(char A[10][10]);
void input_ship(char ary[10][10],int size_ship,int place[2][4]);
bool checker_star(char B[10][10]);
void shut_ship(char C[10][10],int ,int);
void moving_ship(char ARAY[10][10],int D[2][4] );
int main()
{
    string player_one;
    string player_two;

    cout <<"Enter name player number 1-->>  ";
    cin >> player_one;
    cout << "Enter name player number 2-->>  ";
    cin >> player_two;

    cout << endl;
    char map_player_number1[10][10];
    char map_player_number2[10][10];
    int place_ships_player_number1[2][4];
    int place_ships_player_number2[2][4];
    
    for(int i=0 ;i<10;i++)
        for(int j=0 ;j<10 ;j++)
        {
             map_player_number1[i][j]=48;
             map_player_number2[i][j]=48;
        }
            
      for(int i=2;i<=5 ;i++)
             input_ship(map_player_number1,i,  place_ships_player_number1);
      for(int i=2;i<=5;i++)
             input_ship(map_player_number2,i,place_ships_player_number2);

      for( int i=0;i<=3;i++)
      {
        cout << place_ships_player_number1[0][i] <<place_ships_player_number1[1][i]<< endl;
      }
       for( int i=0;i<=3;i++)
      {
        cout << place_ships_player_number2[0][i] <<place_ships_player_number2[1][i]<< endl;
      }
      int alaki=1;
     while(1)
     {
        int x;
        int y;
        char next;
       
        if(alaki==1)
        {
            cout << "Enter to start game (S/s) ";
             cin >> next;
        }
      
       
        
        cout << "                     "<< player_one<< endl;
         jadval(map_player_number1);
        cout << "Enter two integer number  for hit "<<player_two<< " map"<< endl;
        
         cin >> x >>y;
        
          while(1)
         {
            if((x>=11 || y>=11)||(x<1 ||y<1))
            {
                cout << "please Enter a number beetwen 1 until 10 \n";
                
                cin >> x >> y;
            }
            if(x<=10 && x>=1 && y<=10 && y>=1)
                break;
        
         }
        shut_ship(map_player_number2,x,y);
        


        if(checker_star(map_player_number2))
         {
            cout << "won "<<player_one<<" this game"<< endl;
                break;
         }
         else{
            cout << " Enter to go next turn(N/n) ";
         }

         cin >> next;
        cout << "\n \n \n \n \n \n \n \n \n \n";
        
        cout << "                     "<< player_two<< endl; 
        jadval(map_player_number2);
        cout << "Enter two integer number  for hit "<<player_one<< " map"<< endl;
       
        
        cin >> x >>y;
         while(1)
         {
            if((x>=11 || y>=11)||(x<1 ||y<1))
            {
                cout << "please Enter a number beetwen 1 until 10 \n";
                cin >> x >> y;
            }
            if(x<=10 && x>=1 && y<=10 && y>=1)
                break;
        
         }
        shut_ship(map_player_number1,x,y);
       

        if(checker_star(map_player_number1))
        {
            cout << "won "<< player_two<< " this game";
            break;
        }
        else{
            cout << " Enter to go next turn(N/n) ";
        
        }
        cin >>next;
        
            //   moving_ship(map_player_number1,place_ships_player_number1);
            //   moving_ship(map_player_number2,place_ships_player_number2);
        
        
        
        cout <<" \n \n \n \n \n \n \n \n \n \n";
        alaki=0;
     
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
    cout << endl;

}


   
 void input_ship(char ary[10][10],int size_ship,int place[2][4])
{
   
   int random_satr;
   int random_soton;

    srand(time(0));
    random_satr = rand() % (10)+1;
    
    random_soton = rand() % (10-size_ship+1)+1;
    int temp=1; 
   while(temp==1)
   {
         srand(time(0));
         random_satr = rand() % (10)+1;
         random_soton = rand() % (10-size_ship+1)+1;
        temp=0;
        for(int i=random_soton-2;i<=random_soton+size_ship && i<=9 &&temp==0;i++)
        {
            if(ary[random_satr-1][i]==42 && i>=0)
                temp=1;
            
            if(random_satr-2>=0 &&  ary[random_satr-2][i]==42  && i>=0)
                temp=1;

            if(ary[random_satr][i]==42 && random_satr<=9 && i>=0)
                temp=1;
        }
   }
   place[0][size_ship-2]=random_satr-1;
   place[1][size_ship-2]=random_soton-1;

   
   
  

   for(int i=0;i<size_ship;i++)
   {
       ary[random_satr-1][random_soton-1]=42;
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


void moving_ship(char ARAY[10][10],int placeship[2][4])
{
    for(int i=2;i<=5;i++)
    {
        int size_this_ship=i-2;
        int satr=placeship[0][size_this_ship-2];
        int soton=placeship[1][size_this_ship-2];

        int move=rand()%4;
        cout<< move<< endl;
       
      
      
    }
}