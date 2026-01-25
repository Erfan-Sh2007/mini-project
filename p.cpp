#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void jadval(char A[10][10]);                        // print map game
void input_ship(char ary[10][10],int place[3][5]);  // input ships randomly
bool checker_star(char B[10][10]);                  // check for exist star
void shut_ship(char C[10][10]);                     // shuting
void move_right(char R[10][10], int place_r[3][5], int andis_r);    
void move_left(char L[10][10], int place_l[3][5], int andis_l); 
void move_up(char U[10][10], int place_u[3][5],int andis_u); 
void move_down(char D[10][10], int place_d[3][5],int andis_d );        
void scan_area(char ARA[10][10]);                   // scan an area for exist ships
void repair_ship(char Map_player[10][10]);          // repiar ships 

int main()
{
    string player_one;
    string player_two;

   
    char map_player_number1[10][10];
    char map_player_number2[10][10];
    int place_size_ships_player_number1[3][5];
    int place_size_ships_player_number2[3][5];
    int using_repair_player_number1=3;
    int using_repair_player_number2=3;
    int using_scan_area_player_number1=1;
    int using_scan_area_player_number2=1;
    int result;

    for(int i=0 ;i<10 ;i++)
    {
        for( int j=0; j<10 ;j++)
        {
            map_player_number1[i][j]=48;            // 48 is ascii code zero
            map_player_number2[i][j]=48;            // 48 is ascii code zero
        }
    }
    

    cout <<"Enter name player number 1-->>  ";
    cin >> player_one;
  
    input_ship(map_player_number1,place_size_ships_player_number1);

    cout << "Enter name player number 2-->>  ";
    cin >> player_two;

    input_ship(map_player_number2,place_size_ships_player_number2);

   
    srand(time(0));
    
     while(1)
    {

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
       int temp_using_repair=0;
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
            }
          break;

         case 3:
                       
                  for(int satr=0 ;satr<10 && temp_using_repair==0;satr++)
                      for( int  soton=0 ;soton <10 &&temp_using_repair==0; soton++)
                          if(map_player_number1[satr][soton]==35)
                              temp_using_repair=1;

                  if(temp_using_repair==1)
                  {
                      if(using_repair_player_number1>=1)
                        {
                            repair_ship(map_player_number1);
                            using_repair_player_number1--;

                        }
                        else{

                             cout << "you used all of repair "<< endl;
                               shut_ship(map_player_number2);
                           }
                   
                  }
                  else{
                        cout << "there is no any hit "<< endl;
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
         for(int ship_number=0 ;ship_number<=4 ;ship_number++)
         {
            result= rand()%4;
            switch (result)
            {
            case 0:
                move_right(map_player_number2,place_size_ships_player_number2, ship_number);
                cout << "R : "<<ship_number<< endl;
                break;
            case 1:
                move_left(map_player_number2, place_size_ships_player_number2, ship_number);
                cout << "L : "<< ship_number << endl;
                break;
            case 2:
                move_up(map_player_number2,place_size_ships_player_number2,ship_number);
                cout << "U : "<< ship_number << endl;
                break;
            case 3:
                move_down(map_player_number2,place_size_ships_player_number2, ship_number);
                cout << "D : "<< ship_number << endl;
                break;

            default:
                break;
            }
        }
        
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
         temp_using_repair=0;
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
         
                  
                    for(int satr=0 ;satr<10 && temp_using_repair==0;satr++)
                         for( int  soton=0 ;soton <10 &&temp_using_repair==0; soton++)
                            if(map_player_number2[satr][soton]==35)
                                temp_using_repair=1;

                    if(temp_using_repair==1)
                    {
                        if(using_repair_player_number2>=1)
                        {
                            repair_ship(map_player_number2);
                            using_repair_player_number2--;
                        }
                        else{
                            cout << "you used all of repair "<< endl << endl;
                                
                            shut_ship(map_player_number1);
                        }
                    }
                    else{
                            cout << "there is no any hit "<< endl;
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
  
         for(int ship_number=0 ;ship_number<=4 ;ship_number++)
         {
            result= rand()%4;
            switch (result)
            {
            case 0:
                move_right(map_player_number1,place_size_ships_player_number1, ship_number);
                cout << "R : "<< ship_number<< endl;
                break;
            case 1:
                move_left(map_player_number1, place_size_ships_player_number1, ship_number);
                cout << "L : "<< ship_number << endl;
                break;
            case 2:
                move_up(map_player_number1,place_size_ships_player_number1,ship_number);
                cout << "U : "<< ship_number << endl;
                break;
            case 3:
                move_down(map_player_number1,place_size_ships_player_number1, ship_number);
                cout << "D : "<< ship_number << endl;
                break;

            default:
                break;
            }
        }
     
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
                if(A[i-1][k-1]=='0')
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


   
 void input_ship(char ary[10][10],int place[3][5])
{
    int size_ship=2;
    
      srand(time(0));
   for( int k=0; k<5 ;k++)
   {
     int random_satr;
     int random_soton;
           
                int temp=1; 
            while(temp==1)
            {
                
                random_satr = rand() % (10)+1;
                random_soton = rand() % (10-size_ship+1)+1;

                temp=0;
                for(int i = random_soton-1 ; i < random_soton+size_ship  && temp == 0 ; i++ )
                {
                    if(ary[random_satr-1][i]=='*')
                    {
                          temp=1;
                    }
                }
                    
                          
                    
            }
            place[0][k]=random_satr-1;
            place[1][k]=random_soton-1;
            place[2][k]=size_ship;
            // cout <<" "<<random_satr<< " "<<random_soton;
            

            for(int i=0;i<size_ship;i++)
            {
                ary[random_satr-1][random_soton-1]='*';
                random_soton++;

            }
            if(k!=1)            // FOR INPUT TWO SHIP WHIT SIZE 3
            {
                  size_ship++;

            }
        
          
    //    cout << endl;
           
     }
    

}


bool checker_star(char B[10][10])   //checker : do there  is star in array?
{
    for(int i=0 ;i<10;i++)
    {
        for(int j=0 ;j<10 ;j++)
        {
            if(B[i][j]=='*')         // 42 is star ascii code.
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
    else 
    {
        cout << "shut wasnot secesfull"<< endl;
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
                    if(ARA[i-1][j-1]=='*' || ARA[i-1][j-1]=='#')
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


void repair_ship(char Map_player[10][10])
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
        if( Map_player[satr_map-1][soton_map-1]!='#')
        {
            if(Map_player[satr_map-1][soton_map-1]=='*')
            {
                cout << "this addres unHit(undamage) Enter another : ";
                cin >> satr_map >> soton_map;
            }
            if(Map_player[satr_map-1][soton_map-1]=='0')
            {
                cout << "tehre is no ship in addres Enter another : ";
                cin >> satr_map >> soton_map;
            }
        }
        else{
           break;
        }
    }

    if(Map_player[satr_map-1][soton_map-1]=='#')
    {
        Map_player[satr_map-1][soton_map-1]='*';
        cout << "Repaired "<<endl;
    }
    
   
   
}

void move_right(char R[10][10] ,int place[3][5], int andis)
{
    int temp_r=1;
    int temp_moving=0;
    int satr_r=place[0][andis];
    int soton_r=place[1][andis];
    int size_r=place[2][andis];
    for(int j=soton_r ; j <=soton_r+size_r ;j++)
    {
        if(R[satr_r][j]=='*')
            temp_moving=1;
    }
    if(temp_moving==1)
{ 
        if(soton_r+size_r+1<=10)
        {
            if(R[satr_r][soton_r+size_r+1]=='*' || R[satr_r][soton_r+size_r+1]=='#')
                temp_r=0;

        }
       else{
           temp_r=0;
          }


    if(temp_r==1)
    {
        for(int j=soton_r+size_r+1 ;j>=soton_r ;j--)
        {
            if(R[satr_r][j]=='*')
                R[satr_r][j+1]='*';

            if(R[satr_r][j]=='#')
                R[satr_r][j+1]='#';
        }
        place[1][andis]++;
        R[satr_r][soton_r]='0';
    }
    else{
        int temp_l=1;
      if(soton_r-1>=0)
       {
         if(R[satr_r][soton_r-1]=='*' || R[satr_r][soton_r-1]=='#')
            temp_l=0;

       }
       else{
           temp_l=0;
       }

       if(temp_l==1)
       {
        for(int j=soton_r ;j<=soton_r+size_r ;j++)
            {
                    if(R[satr_r][j]=='*')   
                        R[satr_r][j-1]='*';

                    if(R[satr_r][j]=='#')
                        R[satr_r][j-1]='#';
            }
            place[1][andis]--;
            R[satr_r][soton_r+size_r-1]='0';
       }
            

    }
  }
}

void move_left(char L[10][10], int place_l[3][5], int andis_l)
{   
    int temp_moving=0;
    int temp_l=1;
    int satr_l=place_l[0][andis_l];
    int soton_l=place_l[1][andis_l];
    int size_l=place_l[2][andis_l];
     for(int j=soton_l ; j <=soton_l+size_l ;j++)
    {
        if(L[satr_l][j]=='*')
            temp_moving=1;
    }
  if(temp_moving==1)
   {
    if(soton_l-1>=0)
    {
        if(L[satr_l][soton_l-1]=='*' || L[satr_l][soton_l-1]=='#')
            temp_l=0;
    }
    else{
        temp_l=0;
    }


    if(temp_l==1)
    {
         for(int j=soton_l ;j<=soton_l+size_l-1 ;j++)
            {
                    if(L[satr_l][j]=='*')   
                        L[satr_l][j-1]='*';

                    if(L[satr_l][j]=='#')
                        L[satr_l][j-1]='#';
            }
            place_l[1][andis_l]--;
            L[satr_l][soton_l-1+size_l]='0';
    }
    else{
        int temp_r=1;
        if(soton_l+size_l+1<=10)
        {
            if(L[satr_l][soton_l+size_l+1]=='*' || L[satr_l][soton_l]=='#')
                temp_r=0;   
        }
        else{
            temp_r=0;
        }

         if(temp_r==1)
         {  
            for(int j=soton_l+size_l ;j>=soton_l ;j--)
            {
               if(L[satr_l][j]=='*')
                  L[satr_l][j+1]='*';

               if(L[satr_l][j]=='#')
                  L[satr_l][j+1]='#';
            }
              place_l[1][andis_l]++;
              L[satr_l][soton_l]='0';
         }
                
    }
 }
}


void move_up(char U[10][10], int place_u[3][5],int andis_u)
{      
    int temp_moving=0;
    int temp_up=1;
    int satr_u=place_u[0][andis_u];
    int soton_u=place_u[1][andis_u];
    int size_u=place_u[2][andis_u];
    for(int j=soton_u ; j <=soton_u+size_u ;j++)
    {
        if(U[satr_u][j]=='*')
            temp_moving=1;
    }
   if(temp_moving==1)
   {
    if(satr_u-1>=0)
     {
       for(int j=soton_u ;j<soton_u +size_u ;j++)
        {
             if(U[satr_u-1][j]=='*' || U[satr_u-1][j]=='#')
                    temp_up=0;
        }
     }
    else{
            temp_up=0;
    
        }
                    
        if(temp_up==1)
            {
                
               for(int k=soton_u ;k<size_u+soton_u; k++)
                  {
                    if(U[satr_u][k]=='*')
                      U[satr_u-1][k]='*';
                        
                    if(U[satr_u][k]=='#')
                       U[satr_u-1][k]='#';
                    
                  }
                  for( int t=soton_u ;t<soton_u+size_u ;t++)
                          U[satr_u][t]='0';

                  place_u[0][andis_u]--;
            }
         else{
             int temp_down_1=1;
             if(satr_u+1<=9)
              {
                   for(int j=soton_u ;j<soton_u +size_u;j++)
                     {
                         if(U[satr_u+1][j]=='*' || U[satr_u+1][j]=='#')
                             temp_down_1=0;
                     }
              }
              else{
                temp_down_1=0;
              }
              if(temp_down_1==1)
              {
                for(int k=soton_u ;k<soton_u +size_u; k++)
                 {
                     if(U[satr_u][k]=='*')
                       U[satr_u+1][k]='*';

                     if(U[satr_u][k]=='#')
                        U[satr_u+1][k]='#';
                                        
                       U[satr_u][k]='0';
                 }
                    place_u[0][andis_u]++;

              }
           }
   }        
}

void move_down(char D[10][10], int place_d[3][5],int andis_d )
{
    int temp_moving=0;
     int temp_down=1;
     int satr_d=place_d[0][andis_d];
     int soton_d=place_d[1][andis_d];
     int size_d=place_d[2][andis_d];
   for(int j=soton_d ; j <soton_d+size_d ;j++)
    {
        if(D[satr_d][j]=='*')
            temp_moving=1;
    }
if(temp_moving==1)
{
  if(satr_d+1<=9)
  { 
    for(int j=soton_d ;j<soton_d +size_d && temp_down==1 ;j++)
     {
        if(D[satr_d+1][j]=='*' ||D[satr_d+1][j]=='#')
                 temp_down=0;
     }
  }
  else{
      temp_down=0;
  }
                        

 if(temp_down==1)
 {
    for(int k=soton_d ;k<soton_d +size_d  ;k++)
     {
         if(D[satr_d][k]=='*')
            D[satr_d+1][k]='*';
                    
         if(D[satr_d][k]=='#')
           D[satr_d+1][k]='#';

         D[satr_d][k]='0';

     }
         place_d[0][andis_d]++;
 }
 else {

      int temp_up2=1;
      if(satr_d-1>=0)
       {
          for(int j=soton_d ;j<soton_d +size_d && temp_up2==1 ;j++)
          {
                 if(D[satr_d-1][j]=='*' ||D[satr_d-1][j]=='#' )
                      temp_up2=0;
          }
        }
       else{
           temp_up2=0;
        }
                    
        if(temp_up2==1)
         {
            for(int k=soton_d ;k<soton_d +size_d; k++)
             {
                if(D[satr_d][k]=='*')
                    D[satr_d-1][k]='*';
                        
                if(D[satr_d][k]=='#')
                    D[satr_d-1][k]='#';
                                
                D[satr_d][k]='0';
             }
                place_d[0][andis_d]--;
                    
         }
                    
    }
 }
}
