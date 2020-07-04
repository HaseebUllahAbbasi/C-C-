#include<iostream>
using namespace std;
int main()
{
	int twoD[4][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,11,13,14,15},{16,17,18,19,20}};
	int oneD[20];
	int count = 0;
	bool isFound;
	int colSize = sizeof(twoD[2])/sizeof(int);
	for(int i=0; i<sizeof(twoD)/(sizeof(int)*colSize); i++)
	{
		for(int j=0; j<sizeof(twoD[i])/sizeof(int); j++)
		{
			isFound = false;
			for(int k = count-1; k>=0; k--)
			{
				if(oneD[k]==twoD[i][j])
				{
					isFound = true;
					break;
				}
			}
			if(!isFound)
			{
				oneD[count++] = twoD[i][j];
			}
		}
	}
	for(int l=0; l<sizeof(oneD)/sizeof(int); l++)
	{
		cout<<oneD[l]<<" ";
	}
}
	
	
	
