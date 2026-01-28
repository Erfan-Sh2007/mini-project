#include <iostream>
#include <ctime>
#include <cstdlib>



void input_ship(char ary[10][10],int size_ship,int place[2][4])
{
   
   int random_satr;
   int random_soton;

    srand(time(0));
    random_satr = rand() % (10)+1;
    srand(time(0));
    random_soton = rand() % (10-size_ship+2)+1;
    int temp=1; 
   while(temp==1)
   {
         srand(time(0));
         random_satr = rand() % (10)+1;
         random_soton = rand() % (10-size_ship+1)+1;
        temp=0;
        for(int i=random_soton-2;i<=random_soton+size_ship && i<=9;i++)
        {
            if(ary[random_satr-1][i]==42 || ary[random_satr-2][i]==42 || ary[random_satr][i]==42)
            {
                temp=1;
            }
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