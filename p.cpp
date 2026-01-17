#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void jadval(char A[10][10]);
void input_ship(char ary[10][10],int place[2][5]);
bool checker_star(char B[10][10]);
void shut_ship(char C[10][10]);
void moving_ship(char ARAY[10][10],int D[2][5] );
void scan_area(char ARA[10][10]);
void repair_ship(char Map_player[10][10]);
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
    int place_ships_player_number1[2][5];
    int place_ships_player_number2[2][5];
    int using_repair_player_number1=3;
    int using_repair_player_number2=3;
    int using_scan_area_player_number1=1;
    int using_scan_area_player_number2=1;
    
    for(int i=0 ;i<10;i++)
        for(int j=0 ;j<10 ;j++)
        {
             map_player_number1[i][j]=48;
             map_player_number2[i][j]=48;
        }
            
      
     input_ship(map_player_number1,place_ships_player_number1);
      
     input_ship(map_player_number2,place_ships_player_number2);

    //   for( int i=0;i<=4;i++)
    //   {
    //     cout << place_ships_player_number1[0][i] <<place_ships_player_number1[1][i]<< endl;
    //   }
    //    for( int i=0;i<=4;i++)
    //   {
    //     cout << place_ships_player_number2[0][i] <<place_ships_player_number2[1][i]<< endl;
    //   }
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
      
         int choose;
         cout << "What do you want to do    1: simple shut    2: Scan Area   3: Repair  ";
         cin >>choose;
         while(1)
         {
            if(choose>=1 && choose <=3)
            {
                break;
            }
            else{
                cout << " Enter a corcect number : ";
                cin >> choose;
            }

         }
         
        switch(choose)
        {
            

        case 1:
         
            shut_ship(map_player_number2);
            
            break;
        case 2 :
            if(using_scan_area_player_number1==1)
            {
                  scan_area(map_player_number2);
                  using_scan_area_player_number1--;
            }
            else{

                cout << "you used scan !! "<<endl << endl;
                shut_ship(map_player_number2);
          break;

        case 3:
        
            if(using_repair_player_number1>=1)
            {
                repair_ship(map_player_number1);
                using_repair_player_number1--;

            }
            else{

               cout << "you used all of repair "<< endl;
                shut_ship(map_player_number2);
            }
            
         break;

        default:
            break;
        }  
       
        


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
       
        cout << "What do you want to do   1: simlpe shut   2: Scan Area   3: Repair   ";
        cin >> choose;
           while(1)
         {
            if(choose>=1 && choose <=3)
            {
                break;
            }
            else{
                cout << " Enter a corcect number : ";
                cin >> choose;
            }

         }
    switch (choose)
       {
       case 1:

          
            shut_ship(map_player_number1);
        
          break;
        
        case 2:
            if (using_scan_area_player_number2==1)
            {
                 scan_area(map_player_number1);
                 using_scan_area_player_number2--;
            }
            else{
                
                cout << "you used scan !! "<<endl << endl;
               
                shut_ship(map_player_number1);
            }
           
         break;

        case 3:
            if(using_repair_player_number2>=1)
            {
                  repair_ship(map_player_number2);
                  using_repair_player_number2--;
            }
            else{
                cout << "you used all of repair "<< endl << endl;
                
                shut_ship(map_player_number1);
            }
          

         break;

       default:
        break;
       }

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


   
 void input_ship(char ary[10][10],int place[2][5])
{
    int size_ship=2;
   for( int k=0; k<5 ;k++)
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
                for(int i = random_soton-1 ; i < random_soton+size_ship  && temp == 0 ; i++ )
                {
                    if(ary[random_satr-1][i]==42)
                    {
                          temp=1;
                    }
                }
                    
                          
                    
            }
            place[0][k]=random_satr-1;
            place[1][k]=random_soton-1;

            for(int i=0;i<size_ship;i++)
            {
                ary[random_satr-1][random_soton-1]=42;
                random_soton++;

            }
            if(k!=1)            // FOR INPUT TWO SHIP WHIT SIZE 3
            {
                  size_ship++;

            }
        
          
      
           
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


void shut_ship(char C[10][10])
{
    int sat;
    int sot;
    cout << "Enter two integer number  for attak ";

     cin >> sat >>sot;
     while(1)
      {
              
        if((sat<11 && sot<11)&&(sat>=1 && sot>=1))
         {
             break;
         }
         else{
                 cout << "please Enter a number beetwen 1 until 10 \n";
                    cin >> sat >> sot;
            }
     }

    if(C[sat-1][sot-1]==42)                     // 42 is star ascii code.
    {
        C[sat-1][sot-1]=35;                    //35 is sharp ascii code.

        cout << "shut was secesfull"<< endl;

    }
    else{
        cout << "shut wasnot secesfull"<< endl;
    }   
}


void moving_ship(char ARAY[10][10],int placeship[2][5])
{
    int size_this_ship=2;
    for(int i=0;i<=4;i++)
    {
       
        int satr=placeship[0][i];
        int soton=placeship[1][i];

        int move=rand()%4;
        cout<< move<< endl;
        
        if(move==0)   //right
        {
            if(ARAY[satr][soton+size_this_ship+1]!=35 && ARAY[satr][soton+size_this_ship+1]!=42 && (soton+size_this_ship+1<=9))
            {
                  for(int k=soton +size_this_ship ;k>=soton;k--)
                  {
                    if(ARAY[satr][k]==42)
                        ARAY[satr][k+1]=42;

                    if(ARAY[satr][k]==35)
                        ARAY[satr][k+1]=35;
                  }
                  ARAY[satr][soton]=48;

                  placeship[1][i]++;
            }
            else{
                 for(int k=soton ;k<=soton+size_this_ship;k++)
                  {
                    if(ARAY[satr][k]==42)
                        ARAY[satr][k-1]=42;

                    if(ARAY[satr][k]==35)
                        ARAY[satr][k-1]=35;
                  }
                  ARAY[satr][soton+size_this_ship]=48;

                  placeship[1][i]--;
            }


        }
        if(move==1)         //left
        {
            if(ARAY[satr][soton-1]!=35 && ARAY[satr][soton-1]!=42 && soton-1>=0)
            {
                for(int k=soton ;k<=soton+size_this_ship ;k++)
                {
                    if(ARAY[satr][k]==42)
                        ARAY[satr][k-1]=42;

                    if(ARAY[satr][k]==35)
                        ARAY[satr][k-1]=35;
                }
                ARAY[satr][soton+size_this_ship]=48;

                placeship[1][i]--;
            }
            else{
                  for(int k=soton +size_this_ship ;k>=soton;k--)
                  {
                    if(ARAY[satr][k]==42)
                        ARAY[satr][k+1]=42;

                    if(ARAY[satr][k]==35)
                        ARAY[satr][k+1]=35;
                  }
                  ARAY[satr][soton]=48;

                  placeship[1][i]++;
            }
        }

        if(move==2)         //up
        {
            int temp_up=1;
            if(satr-1>=0)
            {
                for(int j=soton ;j<=soton +size_this_ship ;j++)
                {
                    if(ARAY[satr-1][j]==42 ||ARAY[satr-1][j]==35)
                        temp_up=0;
                }
            }
            else{
                temp_up=0;
            }
               
              

            if(temp_up==1)
            {
                for(int k=soton ;k<=soton +size_this_ship; k++)
                {
                    if(ARAY[satr][k]==42)
                         ARAY[satr-1][k]=42;
                
                    if(ARAY[satr][k]==35)
                         ARAY[satr-1][k]=35;
                         
                    ARAY[satr][k]=48;
                }
                placeship[0][i]--;
            }
            else{
                int temp_down=1;
                if(satr+1<=9)
                {
                    for(int j=soton ;j<=soton +size_this_ship;j++)
                    {
                        if(ARAY[satr+1][j]==42 || ARAY[satr][j]==35)
                            temp_down=0;
                    }
                }
                else{
                    temp_down=0;
                }


                if(temp_down==1)
                {
                    for(int k=soton ;k<=soton +size_this_ship; k++)
                    {
                        if(ARAY[satr][k]==42)
                            ARAY[satr+1][k]=42;

                        if(ARAY[satr][k]==35)
                            ARAY[satr+1][k]=35;
                            
                        ARAY[satr][k]=48;
                    }
                    placeship[0][i]++;

                }
                

                }
         }

         if(move==3)
         {  
                int temp_down=1;
                if(satr+1<=9)
                {
                   
                   for(int j=soton ;j<=soton +size_this_ship && temp_down==1 ;j++)
                    {
                        if(ARAY[satr+1][j]==42 ||ARAY[satr+1][j]==35)
                               temp_down=0;
                     }
                }
                else{
                    temp_down=0;
                }
                 

              if(temp_down==1)
              {
                for(int k=soton ;k<=soton +size_this_ship  ;k++)
                {
                    if(ARAY[satr][k]==42)
                        ARAY[satr+1][k]=42;
                     
                    
                      
                    if(ARAY[satr][k]==35)
                        ARAY[satr+1][k]=35;

                     ARAY[satr][k]=48;

                }
              }
              else {

                 int temp_up=1;
                 if(satr-1>=0)
                 {
                    for(int j=soton ;j<=soton +size_this_ship && temp_up==1 ;j++)
                    {
                      if(ARAY[satr-1][j]==42 ||ARAY[satr-1][j]==35)
                            temp_up=0;
                    }
                 }
                 else{
                    temp_up=0;
                 }
              
                 if(temp_up==1)
                 {
                      for(int k=soton ;k<=soton +size_this_ship; k++)
                        {
                              if(ARAY[satr][k]==42)
                                  ARAY[satr-1][k]=42;
                
                              if(ARAY[satr][k]==35)
                                  ARAY[satr-1][k]=35;
                         
                              ARAY[satr][k]=48;
                        }
                        placeship[0][i]--;
            
                 }
               
              }
                
            }
           
            cout <<"size: " <<size_this_ship<<endl;
            if(i!=1)
             {
                size_this_ship++;
             }
         }
    
     
    
}

void scan_area(char ARA[10][10])
{
    int x1;
    int y1;
    int x2;
    int y2;
    cout << "Enter Addres top left : ";
    cin >> x1 >> y1;
    while(1)
    {
        if(x1<=7 && y1 <=7)
            break;
        else{

            cout << "Please Enter a number between 1 and 7 ";
            cin >> x1 >> y1;
        }
    }
   
    cout << "Enter addres under right : ";
    cin >> x2 >> y2;
    while(1)
    {
        if((x1+3)==x2 && (y1+3)==y2)
            break;

        else{
            cout << "Enter a crrect number for under right : ";
            cin >>x2 >> y2;
        }
    }
    int temp=0;
    for(int i=x1; i<=x2  ;i++)
    {
        for(int j=y1;j<=y2 ;j++)
        {
            if(ARA[i-1][j-1]==42 || ARA[i-1][j-1]==35)
            {
                temp=1;
            }
                 
        }
    }
    if(temp==1)
    {
        cout << "Ship Detected !!! "<< endl;

    }
    else if(temp==0){
        cout << "No Ship In Area !!! " << endl;
    }
    
}


void repair_ship(char Map_player[10][10] )
{
    int satr_map;
    int soton_map;

    cout << "Enter an Addres : ";
    cin >>satr_map>> soton_map;

    while(1)
    {
         if(satr_map<=0 || soton_map<=0 || satr_map>10 || soton_map>10)
         {
            cout << "Enter addres beetwen 1 and 10 :" ;
            cin >> satr_map >> soton_map;


         }
         else{
            break;
         }
    }

    while(1)
    {
        if( Map_player[satr_map-1][soton_map-1]!=35)
        {
            if(Map_player[satr_map-1][soton_map-1]==42)
            {
                cout << "this addres unHit(undamage) Enter another : ";
                cin >> satr_map >> soton_map;
            }
            if(Map_player[satr_map-1][soton_map-1]==48)
            {
                cout << "tehre is no ship in addres Enter another : ";
                cin >> satr_map >> soton_map;
            }
        }
        else{
           break;
        }
    }

    if(Map_player[satr_map-1][soton_map-1]==35)
    {
        Map_player[satr_map-1][soton_map-1]=42;
        cout << "Repaired ";
    }
    
   
   
}