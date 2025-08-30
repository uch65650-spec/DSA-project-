#include<iostream>
#include <vector>
#include <fstream>
#include<queue>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iomanip>  // For formatting the time
#include <ctime>    // For date and time functions
using namespace std;
class Snode {
public:
    string name;
    int terminal;
    int id;
    int preading;
    int hreading;
    int dreading;
    Snode* next;
    int totalSales;
    int cardpayment;
int cashpayment;
    Snode(string name, int terminal, int id, int preading, int hreading, int dreading) {
        this->name = name;
        this->terminal = terminal;
        this->id = id;
        this->preading = preading;
        this->hreading = hreading;
        this->dreading = dreading;
        this->totalSales = 0;
        this->cardpayment =0;
        this->cashpayment = 0;
        next = NULL;
    }
    
};

class sales {
    protected:
    Snode* head;
public:
    sales() {
        head = NULL;
    }

   void insert(string name, int terminal, int id, int preading, int hreading, int dreading, vector<Snode*>& salesQueue) {

        Snode* newNode = new Snode(name, terminal, id, preading, hreading, dreading);
        if (head == NULL) {
            head = newNode;
        } else {
            Snode* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
           
        }
         ofstream file1("salePERSOn.txt",ios::app);
        Snode* temp = head;
        while (temp != NULL) {
            file1 << "Salesperson name: " << temp->name <<endl;
            file1<< "Terminal number: " << temp->terminal << endl;
            file1 << "ID: " << temp->id << endl;
            file1 << "Petrol reading: " << temp->preading << endl;
            file1 << "High Octane reading: " << temp->hreading << endl;
            file1 << "Diesel reading: " << temp->dreading << endl;
            file1<<"total sales of "<<temp->name<<" is :"<< temp->totalSales<<endl;
              file1<<"total sales  "<<temp->name<<" by cash is :"<< temp->cashpayment<<endl;
               file1 <<"total sales "<<temp->cardpayment<<" by cash is :"<< temp->totalSales<<endl;
            
            temp = temp->next;
        file1<<"====================================="<<endl;
            
        }
        file1.close();
        
       salesQueue.push_back(newNode);
        
    }


    void display() {
        Snode* temp = head;
        while (temp != NULL) {
            cout << "Salesperson name: " << temp->name <<endl;
            cout << "Terminal number: " << temp->terminal << endl;
            cout << "ID: " << temp->id << endl;
            cout << "Petrol reading: " << temp->preading << endl;
            cout << "High Octane reading: " << temp->hreading << endl;
            cout << "Diesel reading: " << temp->dreading << endl;
            cout<<"total sales of "<<temp->name<<" is :"<< temp->totalSales<<endl;
              cout<<"total sales by cash  "<<temp->name<<" is :"<< temp->cashpayment<<endl;
                cout<<"total sales by cards "<<temp->cardpayment<<" is :"<< temp->totalSales<<endl;
            
            temp = temp->next;
        }
    }
};

class node{
    public:
    string customer;
    node*next;
    int litter;
    string type;
    int data;
    node(string customer,int litter,string type,int data)
{
    this->customer = customer;
next =NULL;
this->litter  = litter;
this->type = type;
this->data = data;
    
}};

class customer{
 node*head;
 public:
 customer(){
     head = NULL;
 }
 void insert(string n,int litter , string type,int data){
     node*name = new node(n,litter,type,data);
     if(head == NULL){
         head = name;
     }
     else{
         node*temp =head;
        while(temp->next != NULL){
             temp = temp->next;
             
             
         }
         temp->next = name;
         ofstream file2("customer.txt",ios::app);
     node*t = head;
     while(t!=NULL){
         file2<<"customer name : "<<temp->customer<<"  ";
         file2<<"litters : "<<temp->litter<<"  ";
         file2<<"type: "<<temp->type<<"  ";
         file2<<"data : "<<temp->data;
         file2<<endl;
         t = t->next;
         file2<<endl;
     file2<<"==========================="<<endl;
     file2.close();
         
     }
     }
 }
 void display(){
     node*temp = head;
     while(temp!=NULL){
         cout<<temp->customer<<"  ";
         cout<<temp->litter<<"  ";
         cout<<temp->type<<"  ";
         cout<<temp->data;
         cout<<endl;
         temp= temp->next;
     }
 }
 
};
class price {
    
public:
 static int dprice;
  static float cardpayments;
  static float cashpayments; 
    static int pprice;
    static int hprice;
    static int pstoke;
    static int hstoke;
    static int dstoke;
    static int total;
    void changep(int add){
	pstoke = add;
	 ofstream file2("details.txt",ios::app);
	 file2<<"stoke add new petrol inventry is "<<pstoke<<endl;
// 	 file2.close();
	}
	 void changed(int add){
	dstoke = add;
	 ofstream file2("details.txt",ios::app);
	 file2<<"stoke add new diesel inventry is "<<dstoke<<endl;
	 file2.close();
	}
	 void changeh(int add){
	hstoke = add;
    ofstream file2("details.txt",ios::app);
	 file2<<"stoke add new high octane inventry is "<<hstoke<<endl;
	 file2.close();
	}
void minusp(int litter){
		pstoke-=litter;
	}
	void minusd(int litter){
		dstoke-=litter;
	}
	void minush(int litter){
	    hstoke-=litter;
	}
	void updatep(int price){
		
		pprice = price;
		ofstream file2("details.txt",ios::app);
		file2<<"petrol price changed"<<endl;
		file2<<"new price : "<<pprice<<endl;
		file2.close();
	
	}
	void updated(int price){
	
		dprice = price;
		ofstream file2("details.txt",ios::app);
		file2<<"diesel  price changed"<<endl;
		file2<<"new price : "<<dprice<<endl;
		file2.close();
		
	}
		void updateh(int price){
		
		hprice = price;
		ofstream file2("details.txt",ios::app);
		file2<<"high octane price changed"<<endl;
		file2<<"new price : "<<hprice<<endl;
		file2.close();
		
		
	}
	void updatess(int bill,string type){
	    if(type == "card"){
	        cardpayments+=bill;
	    }
	    else if(type == "cash"){
	        cashpayments +=bill;
	    }
	}
	void stotal(){
	    cout<<"total sales till now : "<<total<<endl;
	    cout<< "card payments : " <<cardpayments<< endl;
	     cout<< "cash payments : " <<cashpayments<<endl; 
	}
};
 int price::dprice = 299;
 int price::pprice = 256;
 int price::hprice = 310;
 int price::pstoke = 200;
 int price::hstoke = 200;
 int price::dstoke = 200;
 int price::total = 0;
 float price::cardpayments = 0;
 float price::cashpayments = 0;
 class billing : public price{
   string selected;
   public : 
   
     void forrecipt(int ter, string person, string t, float data, string cus) {
   auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    tm localTime;

    // Use localtime_r if on POSIX (Linux/Unix). Use localtime_s on Windows.
    #ifdef _WIN32
        localtime_s(&localTime, &now); // Windows-safe version
    #else
        localtime_r(&now, &localTime); // POSIX-safe version
    #endif

    //
    cout << "\n\t\tWait, printing receipt..." << endl;
    cout << "\t\tPrinting";
    

    for (int i = 0; i < 10; i++) {
        this_thread::sleep_for(chrono::seconds(1)); 
        cout << "."; // Print dots for the simulation
        cout.flush(); // Make sure they appear immediately
    }

    // Format date and time
    stringstream dateTimeStream;
    dateTimeStream << put_time(&localTime, "%A, %B %d, %Y %I:%M:%S %p");

    // Print a decorative receipt
    cout << "\n\n============================= RECEIPT =============================\n";
    cout << "Transaction Date: " << dateTimeStream.str() << endl;
    cout << "=====================================================================" << endl;
    cout << "Terminal:           " << ter << endl;
    cout << "Salesperson:        " << person << endl;
    cout << "Fuel Type:          " << t << endl;
    cout << "Customer:           " << cus << endl;
    cout << "=====================================================================" << endl;
    cout << "Total Bill:        RS" << fixed << setprecision(2) << data << endl;
    cout << "=====================================================================\n";
    
    ofstream file3("recipt.txt",ios::app);
     // Print a decorative receipt
    file3<< "\n\n============================= RECEIPT =============================\n";
file3 << "Transaction Date: " << dateTimeStream.str() << endl;
    file3<< "=====================================================================" << endl;
    file3 << "Terminal:           " << ter << endl;
    file3 << "Salesperson:        " << person << endl;
    file3 << "Fuel Type:          " << t << endl;
    file3 << "Customer:           " << cus << endl;
    file3<< "=====================================================================" << endl;
    file3<< "Total Bill:        RS" << fixed << setprecision(2) << data << endl;
    file3 << "=====================================================================\n";
    file3.close();
}
     
   void card(int litter,int bill,string type){
        cout<<"\tplz pay this amount : "<<bill<<endl;
       cout<<"\t you selected card payemnt "<<endl;
       string accNo;
       string date;
       string year;
       int cvc;
       cout<<"total bill : " << bill<<endl;
       cout<<"plz enter the account number : ";
       cin>>accNo;
       cout<<"plz enter expire date : ";
       cin>>date;
       cout<<"plz enter expire  year : ";
       cin>>year;
       cout<<"\tpayment process start "<<endl;
        cout << "processing";
    for (int i = 0; i < 10; i++) {
        this_thread::sleep_for(chrono::seconds(1));  // Wait for 1 second
        cout << ".";
        cout.flush();
    }
    cout<<endl;
    cout<<"\tpayment recived ....!"<<endl;
       updatess( bill,"card");
      
   }
   void cash(int litter,int bill,string type){
       cout<<"you selected cash \n";
       int cash;
       cout<<"\tplz pay this amount : "<<bill<<endl;
       do{
           cout<<"plz enter the cash : ";
       cin>>cash;
           if(cash>=bill){
               cout<<"✅ Payment accepted. Returning change: Rs. :"<<cash-bill<<endl;
               break;
           }else if(cash<bill){
           double remaining = bill - cash;
            cout << "⚠ Insufficient cash. Rs. " << remaining << " still due.\n";}
            else if(cash<=0){
                 cout << "❌ Invalid amount. Please enter a positive value.\n";
            }
       }while(true);
       updatess( bill,"cash");
       
       
   }
   void payment(int litters,int bill,string type){
  string choice;
   do{cout<<"plz select payment method : \n1:card \n2;cash\nselect : ";
   cin>>choice;
   if(choice == "card" || choice == "1" ){
      selected  = "card;";
      card(litters,bill,type);
       break;
   }else if(choice == "cash" || choice == "2"){
       cash(litters,bill,type);
       selected  = "cash;";
       break;
   }
   else{
       cout<<"invalid entry plz try again !!"<<endl;
   }
   }while(true); 
   }
void paymentelectric(int bill, string type, int battery, int curr) {
    string choice;
    string selected;

    do {
        cout << "Please select payment method:\n1: Card\n2: Cash\nSelect: ";
        cin >> choice;

        if (choice == "card" || choice == "1") {
            selected = "card";
            cout << "\tPlease pay this amount: " << bill << endl;
            cout << "\tYou selected card payment\n";

            string accNo, date, year;
            int cvc;

            cout << "Total bill: " << bill << endl;
            cout << "Please enter the account number: ";
            cin >> accNo;
            cout << "Please enter expiry date: ";
            cin >> date;
            cout << "Please enter expiry year: ";
            cin >> year;

            cout << "\tPayment processing started\n";
            cout << "Processing";
            for (int i = 0; i < 10; i++) {
                this_thread::sleep_for(chrono::seconds(1));
                cout << ".";
                cout.flush();
            }
            cout << endl;
            cout << "\tPayment received....!\n";

            updatess(bill, "card");
            break;
        }
        else if (choice == "cash" || choice == "2") {
            selected = "cash";
            cout << "You selected cash\n";
            int cash;
            cout << "\tPlease pay this amount: " << bill << endl;

            do {
                cout << "Please enter the cash: ";
                cin >> cash;

                if (cash >= bill) {
                    cout << "✅ Payment accepted. Returning change: Rs. " << (cash - bill) << endl;
                    break;
                }
                else if (cash < bill) {
                    double remaining = bill - cash;
                    cout << "⚠ Insufficient cash. Rs. " << remaining << " still due.\n";
                }
                else if (cash <= 0) {
                    cout << "❌ Invalid amount. Please enter a positive value.\n";
                }

            } while (true);

            updatess(bill, "cash");
            break;
        }
        else {
            cout << "Invalid entry, please try again!\n";
        }

    } while (true);
}


   
   	string select(){
       return selected;
   }
   };
 class types: virtual public billing {
    public:
    float petrol(int litters){
    if(pstoke >=litters)	{
    		cout<<"you enter : "<<litters<<" litters"<<endl;
    cout<<"price of petrol is  "<<pprice<<endl;
    cout<<"total bill is  : "<<pprice*litters<<endl;
    payment(litters,pprice*litters,"petrol");
 minusp(litters);
 total+=pprice*litters;
    return pprice*litters;
		}
   else{
   	cout<<" petrol stock is not available ..."<<endl;
   	return -1;
   }
}
float diesel(int litters){
    cout<<"you enter : "<<litters<<" litters"<<endl;
    cout<<"price of diesel is  "<<dprice<<endl;
    cout<<"total bill is  : "<<dprice*litters<<endl;
       payment(litters,dprice*litters,"diesel");
     minusd(litters);
     
      total+=dprice*litters;
    return dprice*litters;
}
float highOctane(int litters){
    cout<<"you enter : "<<litters<<" litters"<<endl;
    cout<<"price of highoctane is  "<<hprice<<endl;
    cout<<"total bill is  : "<<hprice*litters<<endl;
      payment(litters,hprice*litters,"highOctane");
     minush(litters);
      total+=hprice*litters;
    return hprice*litters;}
    
 };
 class electric : virtual public billing{
     int rate;
   public :
   electric(){
       rate =10;
   }
   int eDisplay(){
       int batteryLife;
        int curr;
    
        cout<<"we charger"<<rate<<"rupees par percent % "<<endl;
        cout<<"plz enter battery life : ";
        cin>>batteryLife;
        cout<<"plz enter current charged percentage : ";
        cin>>curr;
        if(batteryLife < curr){
            cout<<"sorry you battery life is less then current we donot charge "<<endl;
			return -1;
        }
        
    int total = batteryLife-curr;
    cout<<"according to your life you may charge till  "<<total<<" percent "<<endl;
string choice;
cout<<"do you want to recharge it : ";
cin>>choice;
if(choice == "yes" || choice == "1"){
    cout<<"\t\tcharging starts"<<endl;
     cout << "charging";
    for (int i = 0; i < 20; i++) {
        this_thread::sleep_for(chrono::seconds(1));  // Wait for 1 second
        cout << ".";
        cout.flush();
    }
    cout<<endl;
    cout<<"charging complete"<<endl;
    cout<<"your total bill is : "<<rate*total<<endl;
    paymentelectric(rate*total,"electric",batteryLife,curr);
    return rate*total;
}
else if(choice == "NO" || choice == "2"){
    cout<<"back to main manu"<<endl;
    
}
else{
    cout<<"invalid entry"<<endl;
}
    }
    void changerate(){
        cout<<"electric price : "<<rate<<endl;
        string choice;
        cout<<"do you want to change the price of percentage charging :";
        cin>>choice;
        if(choice == "yes" || choice == "1"){
  cout<<"plz enter new rate :";
  cin>>rate;
}
else if(choice == "NO" || choice == "2"){
    cout<<"back to main manu"<<endl;
    
}
else{
    cout<<"invalid entry"<<endl;
}
    }
 };
 
 class salePersons : public sales,virtual public billing{
     public: 
    int terminals;
     vector<Snode*> salesQueue; 
     salePersons(){
         terminals =2;
     }
     void persons(){
         cout<<"current working terminals are : "<<terminals<<endl;
         string cheak;
         cout<<"plz enter do you want to add more terminal yes(1)or no(2) :";
         cin>>cheak;
         if(cheak == "1"|| cheak == "yes"){
             cout<<"how many terminals you want to get in working :  ";
             cin>>terminals;
         }
         else if(cheak == "1"|| cheak == "yes"){
             cout<<"no chnage "<<endl;
             
         }
         else{
             cout<<"invalid entry !"<<endl;
         }
         
     }
     void def(){
    string name;
    int terminalNo;
    int reading;
    int id;
    int preading;
    int hreading;
    int dreading;
    for(int i =1;i<=terminals;i++){
       
        cout<<"saleperson enter name: ";
        cin.ignore();
        getline(cin,name);
        terminalNo =i;
        cout<<"terminal number aloted is : "<<terminalNo<<endl;
        cout<<"plz enter id : ";
        cin>>id;
        cout<<"plz enter petrol meter reading : ";
        cin>>preading;
        cout<<"plz enter high octane reading : ";
        cin>>hreading;
        cout<<"plz enter the diesel reading  : ";
        cin>>dreading;
        insert(name,terminalNo,id,preading,hreading,dreading, salesQueue);
    } }
      
    void  dis(){
          display();
      }
    void searchByName( string searchName) {
    Snode* temp = head;
    bool found = false;
    while (temp != NULL) {
        if (temp->name == searchName) {
            cout << "Salesperson Found!" << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Terminal: " << temp->terminal << endl;
            cout << "ID: " << temp->id << endl;
            cout << "Petrol reading: " << temp->preading << endl;
            cout << "High Octane reading: " << temp->hreading << endl;
            cout << "Diesel reading: " << temp->dreading << endl;
            found = true;
        }
        temp = temp->next;
        if (found) {
      break;
    }
    }
    if (!found) {
        cout << "Salesperson with name '" << searchName << "' not found." << endl;
    }
}
 Snode* getNextSalesperson() {
        static int current = 0;
        if (salesQueue.empty()) 
        {
            return NULL;
            
        }
        Snode* assigned = salesQueue[current];
        current = (current + 1) % salesQueue.size(); 
        return assigned;
    }
   void updateReading(Snode* salesperson, string fuelType, int liters) {
    int amount = 0;
    if (fuelType == "petrol") {
    salesperson->preading += liters;
    amount = pprice * liters;
} else if (fuelType == "diesel") {
    salesperson->dreading += liters;
    amount = dprice * liters;
} else if (fuelType == "highoctane") {
    salesperson->hreading += liters;
    amount = hprice * liters;
}
if(select()=="card"){
    salesperson->cardpayment +=amount;
    
}
else if (select()=="cash"){
     salesperson->cashpayment +=amount;
}
salesperson->totalSales += amount;
}
   
     
 };
 
 class manager :public salePersons, public customer,public electric {
    string choice;
    public:

    void admin(){
         cout<<"\t\tmanager access\t"<<endl;
     do{
         cout << "\n--- Manager Main Menu ---\n";
            cout << "1. Change Fuel Prices\n";
            cout << "2. Manage Fuel Stock\n";
            cout << "3. Manage Salespersons\n";
            cout << "4. View Customer Data\n";
            cout << "5. Electric Car Charging\n";
            cout << "6. View Total Sales\n";
            cout<<  "7.for see data in files\n";
            cout << "0. Exit Admin Panel\n";
     cout<<"what are you looking for :";
     cin>>choice;
     if(choice =="chnage price "|| choice == "1"){
         cout<<"you selected to change price "<<endl;
        string pchange;
        do{
        cout<<"you want to cheak price (1)\nor change the price of petrol(2),\nhighoctane(3),\ndiesel(4) or exit(0) form this : ";
        cin>>pchange;
        
            if(pchange == "petrol"|| pchange == "2"){
                int change;
                cout<<"current price is : "<<pprice<<endl;
                cout<<"plz change the petrol  price :";
                cin>>change;
               updatep(change);
               
            }
            else if(pchange == "highoctane"|| pchange == "3"){
                 int change;
                cout<<"current price is : "<<hprice<<endl;
                cout<<"plz change the high octane  price :";
                cin>>change;
               updateh(change);
            }
            else if(pchange == "diesel"|| pchange == "4"){
                int change;
                cout<<"current price is : "<<dprice<<endl;
                cout<<"plz change the diesel price :";
                cin>>change;
               updated(change);
            }
            else if(pchange == "exit" || pchange == "0" ){
                cout<<"exit form price change manu "<<endl;
                break;
            }
            else if(pchange == "cheak"||pchange == "1"){
                cout<<"petrol proce :"<<pprice<<endl;
                cout<<"diesel price : "<<dprice<<endl;
                cout<<"high octane price "<<hprice<<endl;
            }
            else{
                cout<<"invalid entry plz try again"<<endl;
            }
            
        }while(true);
        
     }
     else if(choice == "file" ||choice == "7" ){
         string ch;
         do{cout<<"you want to cheak\n1.saleperson file\n2.customer file\n3.recipt file\n4,updates file\n 0.exit";
         cin>>ch;
if (ch == "saleperson" || ch == "1") {
            ifstream file1("salePERSOn.txt");
            if (!file1) {
                cout << "Error opening file" << endl;
            } else {
                string line;
                while (getline(file1, line)) {
                    cout << line << endl;
                }
            }
        } else if (ch == "customer" || ch == "2") {
            ifstream file2("customer.txt");
            if (!file2) {
                cout << "Error opening file" << endl;
            } else {
                string line;
                while (getline(file2, line)) {
                    cout << line << endl;
                }
            }
        } else if (ch == "recipt" || ch == "3") {
            ifstream file3("recipt.txt");
            if (!file3) {
                cout << "Error opening file" << endl;
            } else {
                string line;
                while (getline(file3, line)) {
                    cout << line << endl;
                }
            }
        } else if (ch == "updates" || ch == "4") {
            ifstream file4("updates.txt");
            if (!file4) {
                cout << "Error opening file" << endl;
            } else {
                string line;
                while (getline(file4, line)) {
                    cout << line << endl;
                }
            }
        } else if (ch == "0") {
            break; // 
        } else {
            cout << "Invalid option. Please try again.\n";
        }

         }while(true);
     }
     else if (choice == "stoke" ||choice == "2" ){
         cout<<"\tyou selected stokes"<<endl;
         string pchange;
         do{
         cout<<"are you looking for cheak(1) stock\n, update petrol(2)\n,update highoctane(3)\n, diesel(4)\n or exit(0)\n the manu :";
         cin>>pchange;
         if(pchange == "cheak"|| pchange == "1"){
             cout<<"petrol stock avaible is : "<<pstoke<<endl;
             cout<<"high octane stock avaiable is : "<<hstoke<<endl;
             cout<<"diesel stock available is : "<<dstoke<<endl;
         }
         else if(pchange == "petrol"|| pchange == "2"){
             int change;
             cout<<"current petrol  stock avaiable is : "<<pstoke<<endl;
             cout<<"update change is : ";
             cin>>change;
             changep(change);
         }
         else if(pchange == "highoctane"|| pchange == "3"){
             int change;
               cout<<"current high octane stock avaiable is : "<<hstoke<<endl;
             cout<<"update change is : ";
             cin>>change;
             changeh(change);
         }
         else if(pchange == "diesel"|| pchange == "4"){
             int change;
              cout<<"current high octane stock avaiable is : "<<dstoke<<endl;
             cout<<"update change is : ";
             cin>>change;
             changed(change);
         }
         else if(pchange == "exit"|| pchange == "0"){
             cout<<"out from stock manu "<<endl;
             break;
         }
         else{
             cout<<"invalid entry plz try again "<<endl;
         }
         }while(true);
         }
     else if(choice == "exit"|| choice == "0"){
         cout<<"exit from admin access"<<endl;
         break;
     } 
     else if(choice  == "sale person "|| choice  == "3"){
         cout<<"you enter in sale person data "<<endl;
       
         do{
              string change;
         cout<<"do you want to increase or decrease terminals(1)\ncurrent working sale persons(2) \n search saleperson by name(3)  \nexit(0) ";
         cin>>change;
             if(change =="change terminal "|| change == "1"){
                 persons();
             }
             else if(change == "current"|| change == "2"){
                 dis();
             }
             else if(change  == "exit"|| change =="0" ){
                 cout<<"exit from sale person manu ";
                 break;
             }
             else if(change == "by name"|| change == "3"){
             string searchName;
             cout<<"plz enter the name which you want to find ";
             cin.ignore();
             getline(cin,searchName);
                 searchByName(searchName);
             }
             
         }while(true);
         
     }
     else if(choice == "customer" || choice == "4"){
         cout<<"customer data till now "<<endl;
         customer::display();
     }
     else if(choice =="electric" || choice == "5" ){
         cout<<"electric car"<<endl;
         changerate();
     }else if(choice =="total" || choice == "6" )
     {
         stotal();
     }
     else{
                cout<<"invalid entry plz try again"<<endl;
            }
         
         
     }while(true);
 }};
class manu : public types , public manager  {
public:
string choice;
void mainManu(){
    int litters;
    string name;
    def();
    system("cls"); 
    
    cout<<"\t-------------------\t"<<endl;
    cout<<"||";
    cout<<"\tWelcome to pso pump\t";
    cout<<"||"<<endl;
      cout<<"\t-------------------\t"<<endl;
    
do{
    
    cout<<"customer enter your name please : ";
    cin.ignore();
    getline(cin,name);
    cout << "\n====== Fuel Station Menu ======\n";
    cout << "1. Petrol\n";
    cout << "2. Diesel\n";
    cout << "3. High Octane\n";
    cout << "5. Electric Vehicle Charging\n";
    cout << "0. Exit\n";
   
    cout << "================================\n";

    cout<<"what are you looking for : ";
    cin>>choice;
    if(choice == "1"|| choice  == "petrol"){
    
      Snode* assignedSalesperson = getNextSalesperson(); 
    if (assignedSalesperson) {
        cout << "You will be served by salesperson: " << assignedSalesperson->name
             << " at Terminal: " << assignedSalesperson->terminal << endl;
    } else {
        cout << "No salesperson available!" << endl;
        break;
}
        cout<<"you selected petrol "<<endl;
        cout<<"plz enter how much ltters required : ";
        cin>>litters;
      float data1 =  petrol(litters);
    int tr = assignedSalesperson->terminal;
      string na = assignedSalesperson->name;
      if (data1 == -1){
      	cout<<"sorry stoke is not avaiable "<<endl;
      	
	  }
      else{
      	
	  
      this->billing::forrecipt(tr,na,"petrol",data1,name);
      
     customer::insert(name,litters,"petrol",data1);

      updateReading(assignedSalesperson, "petrol", litters);}
    }
    else if (choice == "2"|| choice  == "diesel"){
          Snode* assignedSalesperson = getNextSalesperson(); 
         if (assignedSalesperson) {
        cout << "You will be served by salesperson: " << assignedSalesperson->name
             << " at Terminal: " << assignedSalesperson->terminal << endl;
    } else {
        cout << "No salesperson available!" << endl;
        break;
        
}
           cout<<"you selected diesel "<<endl;
        cout<<"plz enter how much ltters required : ";
        cin>>litters;
      float data1 =  diesel(litters);
       int tr = assignedSalesperson->terminal;
      string na = assignedSalesperson->name;
      if(data1==-1){
      	cout<<"sorry stocke is not avaiable "<<endl;
	  }else{
	
	  
    this->billing::forrecipt(tr,na,"diesel",data1,name);
      
      customer::insert(name,litters,"diesel",data1);
      
       updateReading(assignedSalesperson, "diesel", litters);}
    }
    else if (choice == "3"|| choice  == "highoctane"){
         Snode* assignedSalesperson = getNextSalesperson(); 
         if (assignedSalesperson) {
        cout << "You will be served by salesperson: " << assignedSalesperson->name
             << " at Terminal: " << assignedSalesperson->terminal << endl;
    } else {
        cout << "No salesperson available!" << endl;
        break;
        
        
}
          cout<<"you selected highoctane "<<endl;
        cout<<"plz enter how much ltters required : ";
        cin>>litters;
      float data1 =  highOctane(litters);
      int tr = assignedSalesperson->terminal;
      string na = assignedSalesperson->name;
      if(data1 == -1){
      	cout<<"sorry stoke is not avaiable "<<endl;
	  }else{
	  
      this->billing::forrecipt(tr,na,"highoctane",data1,name);
      
      customer::insert(name,litters,"highoctane",data1);
      
       updateReading(assignedSalesperson,"highoctane", litters);}
    }
    else if(choice == "exit"|| choice == "0"){
        cout<<"thanks system is closed "<<endl;
        break;
    }
    else if(choice == "admin111"){
        admin();
    }
    else if(choice == "electric" || choice == "5"){
       
               Snode* assignedSalesperson = getNextSalesperson(); 
         if (assignedSalesperson) {
        cout << "You will be served by salesperson: " << assignedSalesperson->name
             << " at Terminal: " << assignedSalesperson->terminal << endl;
    } else {
        cout << "No salesperson available!" << endl;
        break;
        
}
         cout<<"\telctric car "<<endl;
        int data1 =  eDisplay();
        if(data1 == -1){
      	cout<<"sorry not avaiable "<<endl;
	  break;
            
        }
	    int tr = assignedSalesperson->terminal;
      string na = assignedSalesperson->name;
      this->billing::forrecipt(tr,na,"electric",data1,name);
      customer::insert(name,10,"electric",data1);
      
      
    }
    else if(choice == "exit"|| choice == "0"){
        cout<<"thanks system is closed "<<endl;
        break;
    }
        else{
        cout<<"invalid entry try again"<<endl;
    }
      
    }while(true);
}
};
int main(){


manu obj2;
obj2.mainManu();
// obj1.display();
return 0;
}