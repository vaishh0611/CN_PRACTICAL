#include<iostream>
using namespace std;
int main()
{
	int D[7],C[11],i;
	cout<<"Enter bits message: ";
	for(i=0;i<7;i++)
	{
		cin>>D[i];
	}
	C[0]=D[0];
	C[1]=D[1];
	C[2]=D[2];
	C[4]=D[3];
	C[5]=D[4];
	C[6]=D[5];
	C[8]=D[6];
	
	C[10]=C[8]^C[6]^C[4]^C[2]^C[0];
	C[9]=C[8]^C[5]^C[4]^C[1]^C[0];
	C[7]=C[6]^C[5]^C[4];
	C[3]=C[2]^C[1]^C[0];
	
	cout<<"Message:  ";
	for(i=0;i<7;i++)
	{
		cout<<D[i];
	}
	cout<<"\ncodeword: ";
	for(i=0;i<11;i++)
	{
		cout<<C[i];
	}
	return 0;
}
