#include <iostream>
using namespace std;

/*int factorial(int *n)
{
	int fact = 1;
	
	
	for(int i = 1; i<=*n; i++){
		fact = fact * i;
	} 
	return fact;
}


int main(int argc, char** argv) {
	
	
	
	int num;
	cout<<"enter a num:";
	cin>>num;
	
	if(num==0)
	{
		cout<<"the fact of 0 is 1";
		return 0;
	}
	
	int result =factorial(&num);
	cout<<"the factorial of"<<num<<"is"<<result<<endl;
	
	return 0;
}*/


int main(){
	
	float resp = 200.0, rcapp = 150.0, rlatt = 100.0;
	float* esp=&resp;
	float* capp= &rcapp;
	float* latt=&rlatt;
	float qesp,qcapp,qlatt;
	
	float* pqesp = &qesp;
	float* pqcapp = &qcapp;
	float* pqlatt = &qlatt;
	float bill;
	float* ptrbill = &bill;
	
	cout<<"1.esp=200\n2.cappu = 150\n3.latte=100\n";
	cout<<"please order number of espresso:";
	cin>>qesp;
	cout<<"please order number of cappucino:";
	cin>>qcapp;
	cout<<"please order number of latte:";
	cin>>qlatt;
	
	*(ptrbill) = (*(esp) * *(pqesp)) + (*(capp) * *(pqesp)) + (*(latt) * *(pqlatt));
	cout<<"\n"<<bill;
	
	return 0;
}

