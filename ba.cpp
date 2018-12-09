#include<iostream>
#include<vector>
using namespace std;
int alloc[50][50];
int maxi[50][50];
int need[50][50];
int avail[50];

int check_safety(int j,int nr)
{
	for(int i=0;i<nr;i++)
	{
		if(need[j][i]>avail[i])
		return 0;
	}
	return 1;
}


int check(bool a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==false)
		return 0;
	}
	return 1;
}

void display(int matrix[][50],int i)
{
	for(int j=0;j<3;j++){
	
	cout<<matrix[i][j]<<" ";}
	cout<<"\t\t";
}
int main()
{
	int np=100;
	int nr=100;
	
	cout<<"\nEnter the no of processes : ";
	cin>>np;
	cout<<"\nEnter the no of resources : ";
	cin>>nr;
	
	
	cout<<"\nEnter the allocation data : \n";
	for(int i=0;i<np;i++)
	for(int j=0;j<nr;j++)
	cin>>alloc[i][j];
	
	cout<<"\nEnter the requirement data : \n";
	for(int i=0;i<np;i++)
	for(int j=0;j<nr;j++)
	cin>>maxi[i][j];
	
	for(int i=0;i<np;i++)
	for(int j=0;j<nr;j++)
	need[i][j]=maxi[i][j]-alloc[i][j];
	
	cout<<"\nEnter the availability matrix : \n";
	for(int i=0;i<nr;i++)
	cin>>avail[i];
	
	cout<<"\nProcess\tAllocation\tMax\tNeed\n";
	for(int i=0;i<np;i++){
	cout<<" P"<<i<<"\t";
	display(alloc,i);
	display(maxi,i);
	display(need,i);
	cout<<endl;
}
	int flg;
	bool completed[np];
	vector<int>sq;
	cout<<"\nWORK:\n";
	for(int i=0;i<nr;i++)
	cout<<" "<<avail[i]<< " ";
	while(1)
	{
		for(int i=0;i<np;i++)
		{
			if(!completed[i] && check_safety(i,nr))
			{
				cout<<"+";
				for(int j=0;j<nr;j++){
				cout<<alloc[i][j]<<"  ";
				}
				cout<<endl;
				cout<<"__________"<<endl;
				for(int j=0;j<nr;j++){
				avail[j]+=alloc[i][j];
				cout<<" "<<avail[j]<< " ";
				}
				sq.push_back(i);
				completed[i]=true;
			}
			cout<<endl;	
		}
		flg=check(completed,np);
		if(flg==1){break;}	
	}
	
	cout<<"\nThe final availability matrix \n";
	for(int i=0;i<nr;i++)
	cout<<avail[i]<<"  ";
	
	cout<<"\n --------- Result ------------- \n";
	if(flg==1){
	
	for(int k=0;k<sq.size();k++){
	cout<<"P"<<sq[k]<<" ";}
	cout<<"\nThere is no deadlock";}
	else
	cout<<"Sorry there is a possibility of deadlock";
	
return 0;
}

