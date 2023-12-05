#include <bits/stdc++.h>
using namespace std;

struct personData {
    string name;
    float amountSpent;
};

bool isNamePresent(vector<personData> data, string tempName, int pos);
float totalSpendings(vector<personData>data);
void insertNew(vector<personData> &data);
void deletePerson(vector<personData> &data);
void viewData(vector<personData>data);
void modifyPerson(vector<personData>&data);
float perHeadExpediture(vector<personData> data);
void settle(vector<personData>data);

bool isNamePresent(vector<personData> data, string tempName, int pos) {
    for (int i = 0; i < pos; i++) {
        if (data[i].name == tempName) {
             return true;
        }
    }
    return false;
}
float totalSpendings(vector<personData>data){
    float moneySpent=0;
    int noOfPeople=data.size();
    for(int i=0; i<noOfPeople; i++){
        moneySpent+=data[i].amountSpent;
    }
    return moneySpent;
}
void insertNew(vector<personData> &data){
    personData temp;
    string tempName;
    do{
        cout << "Enter the Name of the person: ";
        if (cin.peek() == '\n') {
            cin.get(); 
        }
        getline(cin, tempName);
    } while(isNamePresent(data, tempName, data.size()));
    
    temp.name = tempName;
    
    cout << "Enter the Amount Spent by the person: ";
    
    while (!(cin >> temp.amountSpent)) {
        cout << "Invalid input. Please enter a valid amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    data.push_back(temp);
    cout << endl;
}
void deletePerson(vector<personData> &data) {
    string tempName;
    cout << "Enter the Name of the person to be deleted: ";
    if (cin.peek() == '\n') {
        cin.get(); 
    }
    getline(cin, tempName);
    auto pos = find_if(data.begin(), data.end(), [&](const personData person) { return person.name == tempName; });

    if (pos == data.end()) {
        cout << "No Such Person Found" << endl;
        return;
    }

    data.erase(pos);
    cout<<"Person Deleted."<<endl;
}
void viewData(vector<personData>data){
    for (int i = 0; i < data.size(); i++) {
        cout << data[i].name << " spent " << data[i].amountSpent << endl;
    }
}
void modifyPerson(vector<personData>&data){
    string tempName;
    cout << "Enter the Name of the person to be modified: ";
    if (cin.peek() == '\n') {
        cin.get(); 
    }
    getline(cin, tempName);
    for(int i=0; i<data.size(); i++){
        if(data[i].name==tempName){
            cout<<"Enter the new amount: ";
            cin>>data[i].amountSpent;
            cout<<"Person Modified"<<endl;
            return;
        }
    }
    cout<<"No Such Person Found"<<endl;
}
float perHeadExpediture(vector<personData> data){
    int noOfPeople=data.size();
    float moneySpent=totalSpendings(data);
    float perHead=moneySpent/noOfPeople;
    return perHead;
}
void settle(vector<personData>data){
    int n=data.size();
    float perHead=perHeadExpediture(data);
    vector<float>debt(n, 0.00);
    
    for (int i = 0; i < n; i++){
		debt[i] = perHead - data[i].amountSpent;
	}
	
	vector<vector<float>>solver(n, vector<float>(n));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j){
				solver[i][j] = 0;
			}
			else if (debt[i] <= 0){
				solver[i][j] = 0;
			}
			else{
				solver[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (solver[i][j] != 0){
				if (debt[j] < 0){
					solver[i][j] = min(debt[i], abs(debt[j]));
					debt[i] = debt[i] - solver[i][j];
					debt[j] = debt[j] + solver[i][j];
				}
				else{
					solver[i][j] = 0;
				}
			}
		}
	}

	cout << "To Settle the expenditure: " << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (solver[i][j] != 0){
				cout << data[i].name << " should pay ";
				printf("%0.2f", solver[i][j]);
				cout << " to " << data[j].name << ". " << endl;
			}
		}
	}
}
int main() {
    vector<personData> data;
    int choice=0;
    while(choice!=8){
        cout << "1. Add a Person" << endl;
		cout << "2. Delete a Person" << endl;
		cout << "3. Modify a Person's Spending" << endl;
		cout << "4. View Spendings" << endl;
		cout << "5. See Total Spendings." << endl;
		cout << "6. See Per Head Expenditure." << endl;
		cout << "7. Settle." << endl;
		cout << "8. Exit." << endl;
		
		cout << "Enter your choice: ";
		cin>>choice;
		
		switch(choice){
		    case 1:
		        insertNew(data);
		        break;
		    case 2:
		        deletePerson(data);
		        break;
		    case 3:
		        modifyPerson(data);
		        break;
		    case 4:
		        viewData(data);
		        break;
		    case 5:
		    {
		        auto total=totalSpendings(data);
		        printf("The Total Spendings till now is: %0.2f\n", total);
		        break;
		    }
		    case 6:
		    {
		        auto perHead=perHeadExpediture(data);
		        printf("Per head Expenditure is: %0.2f\n", perHead);
		        break;
		    }
		    case 7:
		        settle(data);
		        break;
		    case 8:
		        cout<<"Program Exited with 0 errors"<<endl;
		        break;
		}
		cout<<endl;
    }  
}
