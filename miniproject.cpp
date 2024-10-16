// Library management system
#include<bits/stdc++.h>
using namespace std;
class LibraryStructure{
    public:
    string book_name,author_name;
    int issue_date[3],return_date[3];
    int prompt(){
        int query;
        cout<<"\n\n*******************************************************\nLibrary Management System\n*******************************************************\n\nChoose an operation from the given list:-\n1.Add a book\n2.Display data of all the books\n3.Display data of a particular book\n4.Issue a book\n5.Feed return date\n6.Calculate fine(if any)\n7.Exit\n\nEnter your choice: ";
        cin>>query;
        return query;
    }
    int display(vector<LibraryStructure>&db,int index){
        cout<<"\nBook name: "<<db[index].book_name<<endl;
        cout<<"\nAuthor name: "<<db[index].author_name<<endl;
        cout<<"\nIssue date: "<<db[index].issue_date[0]<<" "<<db[index].issue_date[1]<<" "<<db[index].issue_date[2]<<endl;
        cout<<"\nReturn date: "<<db[index].return_date[0]<<" "<<db[index].return_date[1]<<" "<<db[index].return_date[2]<<endl;
    }
    LibraryStructure data_input(){
        LibraryStructure input;
        cout<<"Enter book name: ";
        cin.ignore();
        getline(cin,input.book_name);
        cout<<"Enter author name: ";
        getline(cin,input.author_name);
        cout<<"Enter issue date in 'dd mm yyyy' format(0 0 0 if none): ";
        cin>>input.issue_date[0]>>input.issue_date[1]>>input.issue_date[2];
        cout<<"Enter return date(0 0 0 if none): ";
        cin>>input.return_date[0]>>input.return_date[1]>>input.return_date[2];
        return input;
    }
};
class LibraryOperations:public LibraryStructure{
    public:
    void session(int query,vector<LibraryStructure>&db,int *exit){
        int index;
        cout<<"\nEnter 0-based index(if required for any operation, else -1): ";
        cin>>index;
        int fine=0;
        switch (query){
            if(index<db.size()&&index>-1){
                case 2:
                //the "delete book" functionality was inoperational because the books are stored as elements of a vector with datatype <LibraryStructure>. so when i used this line
                // db.erase(db.begin()+index), it used to delete the first letter from the book name instead of all the data of that particular book
                for(int i=0;i<db.size();i++){
                    cout<<"-------------------------------------------\n";
                    display(db,i);
                    cout<<"-------------------------------------------\n";
                }
                return;
                case 3:
                cout<<"\nEnter issue date(0 0 0 if none): ";
                cin>>db[index].issue_date[0]>>db[index].issue_date[1]>>db[index].issue_date[2];
                return;
                case 4:
                cout<<"\nEnter return date(0 0 0 if none): ";
                cin>>db[index].return_date[0]>>db[index].return_date[1]>>db[index].return_date[2];
                return;
                case 5:
                if(db[index].return_date[0]>db[index].issue_date[0]&&db[index].return_date[1]>db[index].issue_date[1]) {
                    fine=5*(db[index].return_date[0]-db[index].issue_date[0])+150*(db[index].return_date[1]-db[index].issue_date[1]-1);
                }
                else if(db[index].return_date[1]>db[index].issue_date[1]+1){
                    fine=5*(30+db[index].return_date[0]-db[index].issue_date[0])+150*(db[index].return_date[1]-db[index].issue_date[1]-2);
                }                
                cout<<"The fine is Rs."<<fine<<endl;
                return;
                case 6:
                display(db,index);
                return;
            }
            else{
                case 1:
                db.emplace_back(data_input());
                return;
                case 7:
                cout<<"\nProgram exitted\n";
                *exit=7;
                return;
            }
            default: cout<<"INVALID INPUT!!!\n";
        }
    }
};
int main(){
    vector<LibraryStructure>database;
    LibraryOperations obj;
    int termination=0;
    do{
        int query=obj.prompt();
        obj.session(query,database,&termination);
    }while (termination<7);
}