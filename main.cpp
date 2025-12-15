#include <iostream>
#include <sstream>
using namespace std;
class bankAccount{
    // declaration of protected data ONLY accessible through setters and getters and child classes
    protected:
    int accountNumber;
    float balance;
    public:
    // declaration of public data and methods, including setters and getters.
    string accountName;
    // functions declared inside the class then defined outside (whilst still pertaining to the class itself)
    void setAN(int a);
    int getAN();
    void setBalance(float b);
    float getBalance();
    virtual void printer() = 0;
    virtual bool updater();
    void updatePrint();
    // constructor takes in all the necessary data from the user, automatically called
    bankAccount(){
        int tempa;
        float tempb;
        // temporary variables declared within the constructor to interact with setters as perameters
        cout<<"Please input your account Number: "<<endl;
        cin>>tempa;
        setAN(tempa);
        cout<<"Please input your balance (in USD): "<<endl;
        cin>>tempb;
        setBalance(tempb);
        cout<<"What is the account holder's name? "<<endl;
        cin>>accountName;

    }
};
class savingsAccount : public bankAccount{
    public:
        const float interestRate = 0.08;
        float interestAmount(){
             return balance*interestRate;
        }
        void calcBalance(){
            setBalance(getBalance() + interestAmount());
        }
        savingsAccount(){}
        void printer() override {
            cout<<"The account number is: "<<getAN()<<endl;
            cout<<"\nThe account holder is: "<<accountName<<endl;
            cout<<"\nThe account balance is: $"<<getBalance();
        }
            bool updater() override{
                bool deposited = bankAccount::updater();
                if (deposited==true){
                    calcBalance();
                }
                return deposited;
            }
};
// setters and getters are defined here
void bankAccount::setAN(int a){
    accountNumber=a;
}
int bankAccount::getAN(){
    return accountNumber;
}
void bankAccount::setBalance(float b){
    balance=b;
}
float bankAccount::getBalance(){
    return balance;
}
// printer function prints out user data after input
void bankAccount::printer(){
    cout<<"The account number is: "<<getAN()<<endl;
    cout<<"\nThe account holder is: "<<accountName<<endl;
    cout<<"\nThe account balance is: $"<<getBalance();
}
// updater function allows users to choose what field to update
bool bankAccount::updater(){
    int tempString;
    int tempa;
    float tempb;
    cout<<"\nWhat would you like to update?\n1. account number\n2. balance\n3. account name"<<endl;
    cin>>tempString;
    if(tempString==1){
        cout<<"What is your new account number? "<<endl;
        cin>>tempa;
        setAN(tempa);
        return false;
    }
    else if(tempString==2){
        float newBalance;
        int temp2;
        cout<<"Would you like to\n1. deposit\n2. withdraw? "<<endl;
        cin>>temp2;
            if(temp2==1){
                float tempN;
                cout<<"How much would you like to deposit? "<<endl;
                cin>>tempN;
                newBalance=getBalance()+tempN;
                setBalance(newBalance);
                return true;
            }
            else if(temp2==2){
                float tempN;
                cout<<"How much would you like to withdraw? "<<endl;
                cin>>tempN;
                newBalance=getBalance()-tempN;
                while(newBalance<0){
                    cout<<"Invalid input! Please try again!"<<endl;
                    cin>>tempN;
                    newBalance=getBalance()-tempN;
                    return false;
                }
                setBalance(newBalance);
                return false;
                /*the newBalance is only accepted into the setter IF IT IS VALID (Value cannot be less than 0.01, similar to real world currency*/
            }
        }
      else if(tempString==3){
            cout<<"What would you like to change your account name to? "<<endl;
            cin>>accountName;
            // accountName variable is interacted with directly inside the class because it is public
            return false;
        }
      else{
            cout<<"Invalid input! Try again!"<<endl;
            cin>>tempString;
        }
        return false;
    }
// updatePrint function prints out updated information
void bankAccount::updatePrint(){
    cout<<"Your updated account number is: "<<getAN()<<endl;
    cout<<"Your updated account balance is: $"<<getBalance()<<endl;
    cout<<"Your updated account name is: "<<accountName<<endl;
}

int main(){
    savingsAccount obj1;
    // class object created. Functions called for the object. Constructor called automatically beforehand.
    obj1.printer();
    obj1.updater();
    obj1.updatePrint();
}
