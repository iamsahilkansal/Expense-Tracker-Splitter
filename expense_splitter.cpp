#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

void AddMoney(string *name, float n, float *amount){
    string temp_name;
    bool flag=false;
    while(flag!=true){
        cout << "Please enter the name of the person: ";
	    cin >> temp_name;
	    for (int i = 0; i < n; i++){
	        if (temp_name == name[i]){
	            cout << "Enter the amount: ";
			    cin >> amount[i];
			    cout<<"Amount Successfully Added"<<endl;
	            flag =true;
		    }
	    }
	    if(!flag){
	        cout<<"Please Enter a Valid Name."<<endl;
	    }
    }
}

void See(string *name, int n, float *amount){
	for (int i = 0; i < n; i++){
		cout << name[i] << "paid: " ;
		printf("%0.2f\n", amount[i]);
	}
}

float TotalSpendings(int n, float* amount){
    float total_spendings=0.00;
    for(int i=0;i<n;i++){
        total_spendings=total_spendings+amount[i];
    }
    return total_spendings;
}

float PerHead(int n, float total_spendings){
    float per_head=0.00;
    per_head=total_spendings/n;
    return per_head;
}

void Settle(int n,float per_head,float* amount,string* name){
    float debt[n];
    for(int i=0;i<n;i++){
        debt[i]=0.00;
    }
    for(int i=0;i<n;i++){
        debt[i]=per_head-amount[i];
    }
    float matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                matrix[i][j]=0;
            }
            else if(debt[i]<=0){
                matrix[i][j]=0;
            }
            else{
                matrix[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]!=0){
                if(debt[j]<0){
                    matrix[i][j]=min(debt[i],abs(debt[j]));
                    debt[i] = debt[i] - matrix[i][j];
                    debt[j] = debt[j] + matrix[i][j];
                }
                else{
                    matrix[i][j]=0;
                }
            }
        }
    }
    cout<<"To Settle the expenditure: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]!=0){
                cout<<name[i]<<" should pay ";
                printf("%0.2f",matrix[i][j]);
                cout<<" to "<<name[j]<<". "<<endl;
            }
        }
    }
}

int main(){
    int n;
    bool flag=false;
    while(flag!=true){
        cout << "Enter the no of people: ";
	    cin >> n;
	    if(n<=10){
	        flag=true;
	    }
	    else{
	        cout<<"Please Enter people less than 10."<<endl;
	    }
	    cout<<endl;
    }
	string name[n];
	float amount[n], total_spendings=0.00, per_head=0.00;
	for (int i = 0; i < n; i++){
		amount[i] = 0.00;
	}

	int choice = 0;
	for (int i = 0; i < n; i++){
		cout << "Enter the name of person " << i + 1 << ": ";
		cin >> name[i];
	}
	cout<<endl;

	while (choice != 6){
		cout << "1. Add Money." << endl;
		cout << "2. See Total Spendings by each member." << endl;
		cout << "3. See Total Spendings." << endl;
		cout << "4. See Per Head Expenditure." << endl;
		cout << "5. Settle." << endl;
		cout << "6. Exit." << endl;

		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice){
			case 1:
				AddMoney(name, n, amount);
				cout<<endl;
				break;
				
			case 2:
				See(name, n, amount);
				cout<<endl;
				break;

			case 3:
			    TotalSpendings(n, amount);
			    total_spendings= TotalSpendings(n, amount);
			    if(total_spendings>0){
			        cout<<"Total Spendings are: ";
			        printf("%0.2f\n",total_spendings);
			    }
			    else{
			        cout<<"No Spendings till now, please make some entries."<<endl;
			    }
			    cout<<endl;
				break;

			case 4:
				per_head=PerHead(n, total_spendings);
				if(per_head>0){
				    cout<<"Per Head Expenditure is: ";
				    printf("%0.2f\n",per_head);
				}
				else{
				    cout<<"No Spendings till now, please make some entries."<<endl;
				}
				cout<<endl;
				break;

			case 5:
				Settle(n,per_head,amount,name);
				cout<<endl;
				choice=6;
				break;

			case 6:
				cout << "Program Exited with zero errors";
				cout<<endl;
				break;
		}
	}
}