#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    
    string s;
    string sor[4]={"right","left","down","up"};
   
        srand(time(0));
        s=sor[rand()%4];

    if(s=="right")
       cout << s;
    
       
}