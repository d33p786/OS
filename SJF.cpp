
    #include<iostream>
 
    using namespace std;
	
	struct process
	{
		string name;
		double status;
		double AT, BT, WT, TAT;
	};
	
	void sort(process prc[], int Pnum)
	{
        
        process temp;
        
	    for(int i=0;i<Pnum;i++)
	    {

	        for(int j= i+1;j<Pnum;j++)
	        {
	        
	            if(prc[j].AT < prc[i].AT)
	            {
	            
	            temp = prc[i];
	            prc[i] = prc[j]; 
	            prc[j] = temp;
	            
	            }     
	        }  
	    }
	}
	
	int compare(process prc[], int Pnum)
	{
	    int pos;
	    for (int i=0;i<Pnum;i++)
	    {
	        for (int j=i+1;j<Pnum;j++)
	        {
	        
	            if(prc[j].BT < prc[i].BT)
	            pos =j;
	        }
	        
	    }
return pos;	
	}
	
    int main()
    {
        
        int Pnum, i, j;
      
        cout<<"Enter number of processes :";
        cin>>Pnum;

		process prc[Pnum];
		double  AWT=0, ATT=0;

        for(i = 0; i < Pnum; i++)
        {

            cout<<"Enter Process Name :";
            cin>>prc[i].name;
            
            cout<<"Enter Arrival Time :";
            cin>>prc[i].AT;
            
            cout<<"Enter Burst Time :";
            cin>>prc[i].BT;

        }

        system("clear");
        
        sort(prc,Pnum);
        /*
        for(i=0;i<Pnum;i++)
        {
        
        cout<<prc[i].name<<prc[i].AT<<prc[i].BT<<endl;
        
        }*/
        
        
       int pos;

        for(i = 0; i < Pnum; i++)
        {
        
        pos = compare(prc,Pnum);
        
          prc[pos].WT = 0;
          prc[i].BT= prc[i].BT - prc[pos].AT;
          prc[i].WT = prc[i].WT +prc[pos].BT;
              for(j = 0; j < i; j++)
              {
              
              WT[i] += prc[j].BT;
              
              }
        }
        
        
        cout<<"========================================================="<<endl;
        cout<<"|\tPID\t|"<<"Name\t|"<<"AT\t|"<<"BT\t|"<<"WT\t|"<<"TAT\t|"<<endl;
        cout<<"========================================================="<<endl;


        for(i = 0; i < Pnum; i++)
        {
        
            TAT[i] = prc[i].BT + WT[i];
            AWT += WT[i];
            ATT += TAT[i];

            cout<<"|\t"<< i + 1 <<"\t|"<< prc[i].name <<"\t|"<< prc[i].BT <<"\t|"<< WT[i] <<"\t|"<< TAT[i] <<"\t|"<<endl;
        }
        cout<<"=====================================================";
        
        
        AWT = AWT / Pnum;
        ATT = ATT / Pnum;


        cout<<"\n\nAverage Waiting Time :"<<AWT<<endl;
        
        cout<<"Average Turn Around Time :"<<ATT<<endl;
        cout<<"===================================================="<<endl;

        return 0;
    }
