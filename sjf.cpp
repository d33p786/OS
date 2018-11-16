




#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


typedef struct proccess
{
	int at,bt,ct,ta,wt,btt;
	string pro_id;
}Schedule;

bool compare(Schedule a,Schedule b)
{
	return a.at<b.at;
}
bool compare2(Schedule a,Schedule b)
{
	return a.bt<b.bt;

}

int main()
{
	
 Schedule pro[10];
	int n,i,j,pcom;
	double tat=0,twt=0;

	cout<<"Enter the number of Process::";
	cin>>n;
  

	for(i=0;i<n;i++)
	{
	
	    cout<<"Enter Process Name :";
         cin>>pro[i].pro_id;
            
            cout<<"Enter Arrival Time :";
         cin>>pro[i].at;
            
            cout<<"Enter Burst Time :";
       cin>>pro[i].bt;
	
		
		
		
		pro[i].btt=pro[i].bt;
	}

	sort(pro,pro+n,compare);


	i=0;
	pcom=0;
	while(pcom<n)
	{
		for(j=0;j<n;j++)
		{
			if(pro[j].at>i)
			break;
		}

		sort(pro,pro+j,compare2);

		if(j>0)
		{

			for(j=0;j<n;j++)
			{
				if(pro[j].bt!=0)
				break;
			}
			if(pro[j].at>i)

			{
				i=pro[j].at;

			}
			pro[j].ct=i+1;
			pro[j].bt--;
		}
		i++;
		pcom=0;
		for(j=0;j<n;j++)
		{
			if(pro[j].bt==0)
			pcom++;
		}
	}

/*
        cout<<"========================================================="<<endl;
        cout<<"|\tPID\t|"<<"AT\t|"<<"BT\t|"<<"TAT\t|"<<"WT\t|"<<endl;
        cout<<"========================================================="<<endl;*/
        cout<<"========================================================="<<endl;
	cout<<"ProID\tAtime\tBtime\tCtime\tTtime\tWtime\n";
	cout<<"========================================================="<<endl;

	for(i=0;i<n;i++)
	{
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].btt;
		tat=tat+pro[i].ta;
		twt=twt+pro[i].wt;

		cout<<pro[i].pro_id<<"\t"<<pro[i].at<<"\t"<<pro[i].btt<<"\t"<<pro[i].ct<<"\t"<<pro[i].ta<<"\t"<<pro[i].wt;
		cout<<endl;
	}
	cout<<"=====================================================";
        
        twt = twt / n;
        tat = tat / n;


        cout<<"\n\nAverage Waiting Time :"<<twt<<endl;
        
        cout<<"Average Turn Around Time :"<<tat<<endl;
        cout<<"===================================================="<<endl;

	
	
	
	
	return 0;
}
