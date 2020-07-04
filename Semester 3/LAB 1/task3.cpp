/*
    3. Write a function named noDup() that takes a 2D array of size 4x5 and a 1D array of size 20. It should then copy all the elements of 2D array into 1D array but should avoid duplication. For example, let’s say we have 2D array of size 2x3 and 1D array of size 6 to keep the things simple. If 2D array have the following data in it

The contents of 1D array should be the following
15 32 18
18 55 15

15 32 18 55
*/

#include <iostream>
#include <string>
using namespace std;    
int main()
    {

        bool check;
         int temp;
               int ind=0;
        int array[][3]={{1,1,1},{1,1,18}};
        int array_d[6];
        for(int i=0; i<2; i++)
        {
            
            //int count=0;
            for(int j=0; j<3; j++)
            {
                check =  true;
                temp = array[i][j];
                
                for(int k=0; k<6; k++)
                {
                    if(temp==array_d[k])
                    {
                        check=false;
                        break;
                    }
                }
                if(check)
                {
                    array_d[ind] = temp;
                    ind++;
                }
                
            }
            
        }
        for(int i=0; i<ind; i++)
        {
            cout<<array_d[i]<<endl;
        }
    }

