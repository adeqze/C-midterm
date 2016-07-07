#include<iostream>
using namespace std;
int mystery(int n);
int main()
{
	cout<<mystery(3)<<endl;
	
	return 0;
}

int mystery(int n)
{
	if(n<=1)
	return 1;
	else
	return (mystery(n -1) + n);
}
