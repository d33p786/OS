
    #include<iostream>
    #define MAX 20
    
    using namespace std;


    int main()
    {
        int Pnum, i, j;
        string Pname[MAX];
        double BT[MAX], WT[MAX], TAT[MAX], AWT=0, ATT=0;

        cout<<"Enter number of processes :";
        cin>>Pnum;


        for(i = 0; i < Pnum; i++)
        {

            cout<<"Enter Process Name :";
            cin>>Pname[i];
            cout<<"Enter Burst Time :";
            cin>>BT[i];

        }

        system("clear");
        
        cout<<"====================================================="<<endl;
        cout<<"|\tPID\t|"<<"Name\t|"<<"BT\t|"<<"WT\t|"<<"TAT\t|"<<endl;
        cout<<"====================================================="<<endl;

        WT[0] = 0;

        for(i = 1; i < Pnum; i++)
        {
        
          WT[i] = 0;
          
              for(j = 0; j < i; j++)
              {
              
              WT[i] += BT[j];
              
              }
        }

        for(i = 0; i < Pnum; i++)
        {
        
            TAT[i] = BT[i] + WT[i];
            AWT += WT[i];
            ATT += TAT[i];

            cout<<"|\t"<< i + 1 <<"\t|"<< Pname[i] <<"\t|"<< AT[i] <<"\t|"<< BT[i] <<"\t|"<< WT[i] <<"\t|"<< TAT[i] <<"\t|"<<endl;
        }
        cout<<"=====================================================";
        
        
        AWT = AWT / Pnum;
        ATT = ATT / Pnum;


        cout<<"\n\nAverage Waiting Time :"<<AWT<<endl;
        
        cout<<"Average Turn Around Time :"<<ATT<<endl;
        cout<<"===================================================="<<endl;

        return 0;
    }
