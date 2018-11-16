
    #include<iostream>
    #include <cstring>
    #define MAX 20
    
    using namespace std;


	struct process
	{
		string name;
		double BT, WT, PRT, TAT;
	};
	
	
		void sort(process prc[], int Pnum)
	{
        
        process temp;
        
	    for(int i=0;i<Pnum;i++)
	    {

	        for(int j= i+1;j<Pnum;j++)
	        {
	        
	            if(prc[j].PRT< prc[i].PRT)
	            {
	            
	            temp = prc[i];
	            prc[i] = prc[j]; 
	            prc[j] = temp;
	            
	            }     
	        }  
	    }
	}
	
    int main()
    {
        int Pnum, i, j;
       double AWT=0, ATT=0;

        cout<<"Enter number of processes :";
        cin>>Pnum;

		process prc[Pnum];
		

        for(i = 0; i < Pnum; i++)
        {

         
            cout<<"Enter Process Name :";
            cin>>prc[i].name;
            /*
            cout<<"Enter Arrival Time :";
            cin>>prc[i].AT;
            */
            cout<<"Enter Burst Time :";
            cin>>prc[i].BT;
            
            cout<<"Enter priority:";
            cin>>prc[i].PRT;

        }
   sort(prc,Pnum);
   for(i=0;i<Pnum;i++)
        {
        
        cout<<prc[i].name<<prc[i].PRT<<prc[i].BT<<endl;
        
        }
	
        system("clear");
        
        cout<<"====================================================="<<endl;
        cout<<"|\tPID\t|"<<"Name\t|"<<"PRT\t|"<<"BT\t|"<<"WT\t|"<<"TAT\t|"<<endl;
        cout<<"====================================================="<<endl;

        prc[0].WT = 0;

        for(i = 1; i < Pnum; i++)
        {
        
          prc[i].WT = 0;
          
              for(j = 0; j < i; j++)
              {
              
              prc[i].WT += prc[j].BT;
              
              }
        }

        for(i = 0; i < Pnum; i++)
        {
        
            prc[i].TAT = prc[i].BT + prc[i].WT;
            AWT += prc[i].WT;
            ATT += prc[i].TAT;

            cout<<"|\t"<< i + 1 <<"\t|"<< prc[i].name <<"\t|"<<prc[i].PRT<<"\t|"<< prc[i].BT <<"\t|"<< prc[i].WT <<"\t|"<<prc[i].TAT <<"\t|"<<endl;
        }
        cout<<"=====================================================";
        
        
        AWT = AWT / Pnum;
        ATT = ATT / Pnum;


        cout<<"\n\nAverage Waiting Time :"<<AWT<<endl;
        
        cout<<"Average Turn Around Time :"<<ATT<<endl;
        cout<<"===================================================="<<endl;

        return 0;
    }
