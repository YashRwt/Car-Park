#include <iostream>
#include <string>
#include <list>
#include <algorithm>



using namespace std;
using std::cout; using std::cin;
using std::endl; using std::string;

list<list<string> > main_list; //Contains all the Entry's and Exits


void printNestedList(list<list<string> > nested_list)
{
    cout << "[ Num_Plate Day Arrival Departure ]\n"<<endl;

    // nested_list`s iterator(same type as nested_list)
    // to iterate the nested_list
    list<list<string> >::iterator nested_list_itr;

    // Print the nested_list
    for (nested_list_itr = nested_list.begin();
         nested_list_itr != nested_list.end();
         ++nested_list_itr) {

        cout << "\t  [";

        // normal_list`s iterator(same type as temp_list)
        // to iterate the normal_list
        list<string>::iterator single_list_itr;

        // pointer of each list one by one in nested list
        // as loop goes on
        list<string>& single_list_pointer = *nested_list_itr;

        for (single_list_itr = single_list_pointer.begin();
             single_list_itr != single_list_pointer.end();
             single_list_itr++) {
            cout << " " << *single_list_itr << " ";
        }
        cout << "]\n";
    }

}



int main(){

    cout<<"\n\t\tC A R  P A R K I N G"<<endl<<endl;
    int enter;

    cout<<"Press 1 for Arrival"<<endl;
    cout<<"Press 2 for Departure"<<endl;
    cout<<"Press 3 to Display Records"<<endl;
    cout<<"Press 4 to Export records"<<endl;
    cout<<"Press 5 to delete the record"<<endl;
    cout<<"Press 6 to exit"<<endl;

    cout<<"\nPlease Enter your Choice : "<<ends;
    cin>>enter;
    if(enter==1){ //For a new Entry

        cout<<"\n\t*** Details for the New Arrival ***"<<endl;

        //Declaring variables
        string day,plate,clock_in,clock_out="0000";

        cout<<"\nPls Enter the Car Number Plate :-"<<ends;
        cin>>plate;
        cout<<"\nPls Enter the Date in format of DD/MM/yy as of \n\n\t'29/02/20' as of 29 February 2020"<<endl;
        cout<<"\nPls Enter the Date :-"<<ends;
        cin>>day;
        cout<<"\nPls Enter the Time in format of 24 Hrs as of \n\n\t'2030' as of 8:30PM\n\t'600' as of 6:00AM"<<endl;
        cout<<"\nPls Enter Time Of Arrival :-"<<ends;
        cin>>clock_in;

        //Data Stored in string type inside of lists

        list<string> new_list;

        // no of lists in nested list & no of elements in list
        int n=1, m=4;
        string num;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (j==0){num=plate;}
                else if(j==1){num=day;}
                else if(j==2) {num = clock_in;}
                else if(j==3){num=clock_out;}
                new_list.push_back(num);
            }

            main_list.push_back(new_list);

            // delete all elements from single_list
            new_list.erase(new_list.begin(),
                              new_list.end());
        }

        printNestedList(main_list );

        main();

    }
    else if(enter==2){                               //For a Exit

        basic_string<char> Plate_no, Departure;
        cout<<"\n\t*** Details for the Departure ***"<<endl;
        list<string> Plate;
        cout<<"\nPls Enter the Car Number Plate :-"<<ends;
        cin>>Plate_no;
        cout<<"\nPls Enter the Time in format of 24 Hrs as of \n\n\t'2030' as of 8:30PM\n\t'600' as of 6:00AM"<<endl;
        cout<<"\nPls Enter the Departure Time :-"<<ends;
        cin>>Departure;

            //Declaring the necessary values
        Plate.push_back(Plate_no);
        list<string>::iterator Target_plate;
        int arrival_time;

        list<list<string>>::iterator nested_list_itr;
        for ( Target_plate = Plate.begin(); Target_plate != Plate.end(); ++Target_plate){

            //to iterate through the whole list
            for ( nested_list_itr = main_list.begin(); nested_list_itr != main_list.end(); ++nested_list_itr) {

                // normal_list`s iterator(same type as main_list)
                // to iterate the normal_list
                _List_iterator<string> single_list_itr;

                // as loop goes on
                list<string>& single_list_pointer = *nested_list_itr;
                int itr_no=0;

                    //Iterating through the Records
                for (single_list_itr = single_list_pointer.begin();single_list_itr != single_list_pointer.end();single_list_itr++) {

                    itr_no++;   //keeping the count
                    if (itr_no==1){int count=0;     //Getting the Plate

                        if (*single_list_itr == *Target_plate){     //Checking the desired list(same plate)

                                //Updating The Record
                            std::replace_if(single_list_pointer.begin(), single_list_pointer.end(),[](string x) {return x == "0000";}, Departure);

                                    //Getting the Arrival Time
                            for (single_list_itr = single_list_pointer.begin();single_list_itr != single_list_pointer.end();single_list_itr++){
                                ++count;
                                if(count==3){ //Getting The Arrival Time from the Target Record
                                    arrival_time= stoi(*single_list_itr);
                                }
                            }
                        }
                    }
                }
            }
        }

        //Clearing the Input List
        Plate.erase(Plate.begin(),Plate.end());

        printNestedList(main_list );

            //Calculating the hours/Amount
        float amount;int diff= ((stoi(Departure)/100)-(arrival_time/100));
        cout<<diff<<endl;

        //Amount to be Paid
        if (diff>8){amount=30.00;}
        else if(diff>7){amount=15.0;}
        else if(diff>3){amount=5.00;}
        else if(diff>1){amount=3.00;}
        else if(diff>0){amount=1.50;}
        else{amount=0.00;}


        cout<<"\n\nPayable Amount is = £ "<<amount<<ends;

        cout<<"\n\nTo Continue Pls Enter 'y' : "<<ends;
        string abcd;cin>>abcd;
        main();
    }
    else if(enter==3){ //To Show all Records

        cout<<"\n\t^^^ Displaying all Records ^^^\n"<<endl;
        printNestedList(main_list );

        cout<<"\n\nTo Continue Pls Enter 'y' : "<<ends;
        string abcd;cin>>abcd;
        main();
    }
    else if(enter==4){ //To Export all Records

        cout<<"\n---Data---"<<endl<<endl;
        cout<<"To Show all Records"<<endl;
        main();

    }
    else if(enter==5){ //Clear Records

        cout<<"\n\t*** Records cleared ***\n"<<endl<<endl;
        main_list.erase(main_list.begin(),main_list.end());
        main();
    }

    else if(enter==6){exit(0);}

}

