#include<iostream>
using namespace std;
void encode(int a,int b, int enc[]);
void decode(int a,int b, double enc[]);
int main()
{
	
	string text;
	cout<<"please enter the message "<<endl;
	getline(cin,text);
	int number = 0;
	if(text.length()%2==1)
	{
		number+=text.length()+1;
	}
	else
		number+=text.length();
	int message[number];

	for (int i = 0; i < text.length(); ++i)
	{
		if((int)text[i]>=65&&(int)text[i]<=90)
		{
			message[i] = (int)text[i]-64;    
	//		cout<<(int)text[i]-64<<" ";	
		}
		else if((int)text[i]>=97&&(int)text[i]<=122)
		{
	//		cout<<(int)text[i]-96<<" ";	
			message[i] = (int)text[i]-96;
		}
		else
		{
			message[i] = 0;
			//cout<<0<<" ";
		}
	}
	cout<<endl;
	cout<<"please enter the matrix a b c d"<<endl;
	int enc[4]; 
	for(int i=0; i<4; i++)
	{
		cin>>enc[i];
	}
	for(int i=0; i<4; i++)
	{
	//	cout<<enc[i]<<" ";
	//	if(i%2==1)
	//		cout<<endl;
	}
	cout<<endl;
	for (int i = 0; i < text.length(); ++i)
	{
		//cout<<message[i]<<" ";
	//	if(i%2==0)
	//		cout<<"\t"; 
	}

	int decoded[text.length()];
	//cout<<"message passed "<<endl;
	for(int i=0; i<text.length(); i++)
	{

		if(i%2==0)
		encode(message[i],message[i+1],enc);  

	}
	int det = enc[0]*enc[3]-enc[2]*enc[1];
	double array_inv[4];
	array_inv[0] = enc[3]*(1.0/det);
	array_inv[3] = enc[0]*(1.0/det);
	array_inv[1] = -enc[1]*(1.0/det);
	array_inv[2] = -enc[2]*(1.0/det);
	for(int i=0; i<4; i++)
	{
	//	cout<<array_inv[i]<<" ";
	//	if(i%2==1)
	//		cout<<endl;
	}

	//decode(48,74,array_inv);
	return 0;
}
void encode(int a,int b, int enc[])
{
	//cout<<endl;
	cout<<"[ ";
	cout<<a*enc[0]+b*enc[2]<<" ";
	cout<<a*enc[1]+b*enc[3]<<" ";
	cout<<"] ";
	cout<<"\t";
}
void decode(int a,int b, double enc[])
{

	cout<<endl;
	cout<<a*enc[0]+b*enc[2]<<" ";
	cout<<a*enc[1]+b*enc[3]<<" ";
	cout<<endl;
}

