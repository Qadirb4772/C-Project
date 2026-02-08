#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct Schedule{
    string Day;
    string subject[5];
    string time[5];};
    int Days=7;
    Schedule Week[7];
    int attendance[7];
    int DayCount=0;
    //function for changing string time to minutes
int ToMinutes(string s){
    int hours = stoi(s.substr(0,2));
    int minutes = stoi(s.substr(3, 2));
    int totalMinutes = hours * 60 + minutes;
    return totalMinutes;
    }
    
//function for changing the integer minutes to hours string
string ToHours(int minutes){
	string hours = (minutes/60 < 10 ? "0" : "") + to_string(minutes/60);
	string mins = (minutes % 60 < 10 ? "0" : "") + to_string(minutes % 60);
	string FreeTime = hours + ":" + mins;
return FreeTime;
}
    //important functions prototypes
void AddSchedule(Schedule arr[], int n);
void ViewSchedule(Schedule arr[], int n);
void SearchSubject();
void AddNotes(string Arr1[], string Arr2[], int num);
void ViewNotes();
void AddOtherNotes(string Arr1[], string Arr2[], int num);
void DeleteNotes();
void FreeTime();
int main(){
    int num;
    do{
        cout<<setw(20)<<"   =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n"<<"\n      Welcome to Campus Smart Schedular (CSS)\n\n"<<"   =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n";
        cout<<setw(20)<<"1. Add Weekly Schedule\n2. View Schedule By Day\n3. Find Free Time\n4. Search Subject\n5. Note Options\n0. Exit\n";
        cout<<"\n"; 
        cout<<setw(25)<<"Enter Your Choice=";
        cin>>num;
        if(num==1){
            AddSchedule(Week, Days);}
        else if(num == 2){
            ViewSchedule(Week, Days);}
            
            else if(num == 3){
          FreeTime();}
        else if(num == 4){
            SearchSubject();
			}
        
        else if(num == 5){
   	        	
        int choice;
        	do{
        		cout<<" 1. View Notes\n 2. Add Notes\n 3. Delete Notes\n 0. Back to Main Menu\n"
        		<<"\tEnter your Choice = ";
        		cin >> choice;
        		
        		switch (choice){
        			case 1: 
					ViewNotes();
					break;
					
					case 2:{
						int num;
				cout<<"Enter the number of Subjects you want to add Notes for = ";
				cin >> num;
        	string Subject[num]; string Notes[num];
						AddNotes(Subject, Notes, num);
						break;
					}
					case 3:
						DeleteNotes();
						break;
						
					case 0:
						break;	
					default:
						cout<<"Invalid Choice!! Try Again\n";
					break;
					 
				}
			}while(choice != 0);
            }
        }while(num!=0);
        cout<<"\n\n_\nTHANK YOU FOR USING OUR APP!! SEE YOU SOON!!\n_\n";
return 0;
}
  //All Functions definitions are here 
  
//function for adding the schedule
void AddSchedule(Schedule arr[], int n){
	//Opening File
	ofstream WriteFile("CSSinput.txt",ios::app);
	
    if(!WriteFile)
    cout<<"Error opening file CSSinput\n";

        //Opening Files
        ofstream days("Days.txt", ios::app);
		ofstream subs("Subjects.txt", ios::app);
		ofstream timing("Timings.txt", ios::app);
		
		if(!subs)
		cout<<"Error Opening file Subjects.txt\n";
		if(!timing)
		cout<<"Error Opening file Timings.txt\n";  
		if(!days)
		cout<<"Error Opening file Subjects.txt\n";
    
    while(DayCount <7){
        cout<<"Enter The Day "<<DayCount+1<<": ";
        cin>>arr[DayCount].Day;
        days << arr[DayCount].Day<<endl;
        WriteFile<<arr[DayCount].Day<<endl;
        cout<<"YOU CAN ONLY ADD 5 SUBJECTS FOR EACH DAY!!: \n";

        for(int j=0; j<5; j++){
            cout<<"Enter The Subject "<<j+1<<" : ";
            cin.ignore();
            getline(cin,arr[DayCount].subject[j]);
            
            subs<<arr[DayCount].subject[j]<<endl;
            WriteFile<<setw(20)<<arr[DayCount].subject[j];
            
            cout<<"Enter The Time for "<<arr[DayCount].subject[j]<<"(e.g., 09:00-10:00): ";
            cin>>arr[DayCount].time[j];
            WriteFile<<setw(20)<<arr[DayCount].time[j]<<endl;
			timing<<arr[DayCount].time[j]<<endl;
			}
        cout<<endl<<endl;
        DayCount++;}
        //Closing Files
        subs.close();
        timing.close();
        WriteFile.close();
    }
//function for viewing schedule
void ViewSchedule(Schedule arr[], int n){
	ifstream inFile("CSSinput.txt");
	if(!inFile){
		cout<<"File Not Found\n";
	}
	else{
		string line;
		while(getline(inFile, line)){
			cout<<line<<"\n";
		}
	inFile.close();
	}
}
//function for searching subject
void SearchSubject(){
    string target;
    cout<<"Enter The Subject You want to Search=";
    cin.ignore();
    getline(cin, target);
    for(int i=0; i<target.length(); i++){
        if(i == 0){
            target[i] = toupper(target[i]);}  
        else {
            target[i] = tolower(target[i]);}
        		}
        
    string sub, day, time;
    ifstream Subjects("Subjects.txt"); ifstream Days("Days.txt"); ifstream timing("Timings.txt");
    if(!Subjects || !Days || !timing)
    cout<<"Error Opening one of the files\n";
   
	string* SubjectArray = new string[35];
	string* TimeArray = new string[35];
	string DaysArray[7];
	for(int i = 0; i < 35 && getline(Subjects, sub);  i++){
		SubjectArray[i] = sub;
	}
	
	for(int i = 0; i < 35 && getline(timing, time); i++){
	TimeArray[i] = time;
}
	for(int i = 0; i < 7 && getline(Days, day); i++){
		DaysArray[i] = day;
	}
	Subjects.close();
	timing.close();
	Days.close();	
	
    int index = -1;

    	for(int j = 0; j < 35; j++){
    		if(SubjectArray[j] == target){
    			cout<<"The Time of "<<target<<" on "<<DaysArray[j/5]<<" is "<<TimeArray[j]<<endl;
    			index = 1;
			}
		}
	
	if(index == -1)
	cout<<target<<" not found in your schedule!!!\n";
    }
//function for finding free time
void FreeTime(){
	string time;
	string day;
	ifstream timing("Timings.txt");
	ifstream Days("Days.txt");
	if(!timing)
	cout<<"Error File Opening\n";
	if(!Days)
    cout<<"Error Opening File\n";
    
    
	string* TimeArray = new string[35];
	string DaysArray[7];
	for(int i = 0; i < 35 && getline(timing, time); i++){
		TimeArray[i] = time;
	}
	
	for(int i = 0; i < 7 && getline(Days, day); i++){
		DaysArray[i] = day;
	}
	cout<<"\n=~=~=~=~FREE TIME SLOTS=~=~=~=~\n";
	for(int i = 0; i < 34; i++){
		
		string substring1 = TimeArray[i].substr(TimeArray[i].find("-")+1);
		string substring2 = TimeArray[i+1].substr(0, TimeArray[i+1].find("-"));
		int end = ToMinutes(substring1);
		int start = ToMinutes(substring2);
		string starting = ToHours(start); 
		string Ending = ToHours(end);
		
		if(start > end){
		int index = i/5;
		string day = DaysArray[index];
			cout<<day<<": ("<<Ending<<" to "<<starting<<")"<<endl;
		}
}  
}

//function for Adding Notes
void AddNotes(string Arr1[], string Arr2[], int num){
	if(num == 0) return;
	else{
	ofstream Out("Notes.txt");
	ofstream writeSubjects("Subject.txt");
	ofstream writeNotes("Note.txt");
	if(!Out || !writeSubjects || !writeNotes){
		cout<<"Error Opening One of the files\n";
	}
	for(int i = 0; i < num; i++){
		if(i==0)cin.ignore();
		cout<<"Enter The Subject "<<i+1<<" = ";
		getline(cin, Arr1[i]);
		writeSubjects<<Arr1[i]<<endl;
		cout<<"Enter The Note For "<<Arr1[i]<<" = ";
		getline(cin, Arr2[i]);
		writeNotes<<Arr2[i]<<endl;
		Out<<Arr1[i]<<" | "<<Arr2[i]<<"\n";
	}
	writeSubjects.close();
	writeNotes.close();
	Out.close();
}
}

//function for Viewing notes
void ViewNotes(){
	string Notes, sub;
	ifstream viewNote("Note.txt");
	ifstream viewSubject("Subject.txt");
	if(!viewNote || !viewSubject)
	cout<<"Error Opening File!!\n";
	
	while(getline(viewNote, Notes) && getline(viewSubject, sub)){
		cout<<sub<<" -> "<<Notes<<"\n";
	}
	viewNote.close();
	viewSubject.close();
}

//function for deleting notes
void DeleteNotes() {
	int num; 
	cout<<"How Many Notes have you previously added?=";
	cin >> num;
    string subject;
    cout << "Enter the Subject whose note you want to delete: ";
    fflush(stdin);
    getline(cin, subject);
    
	string* SubjectsForNotes = new string[num];
	string* AllNotes = new string[num];
	ifstream ReadSubjects("Subject.txt");
	ifstream ReadNotes("Note.txt");
	string Sub, note;
	
	
	for(int count = 0; count < num && getline(ReadSubjects, Sub) &&getline(ReadNotes, note); count++){
		SubjectsForNotes[count] = Sub;
		AllNotes[count] = note;
	}
	
	for(int i = 0; i < num; i++){
		if(SubjectsForNotes[i] == subject){
			AllNotes[i] = " ";
			SubjectsForNotes[i] = " ";
			cout<<"Notes Deleted Successfully\n";
			break;
		}
	}
	ofstream writeToSubjects("Subject.txt");
	ofstream writeToNote("Note.txt");
   
        for(int i = 0; i < num; i++){
            writeToSubjects<<SubjectsForNotes[i]<<endl;
            writeToNote<<AllNotes[i]<<endl;
        }
    writeToSubjects.close();
    writeToNote.close();
}