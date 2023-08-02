#include <iostream>
#include <fstream> 
#include <cstring>
using namespace std;
//verify logged in or not

bool IsloggedIn()
{
    string username, password, un, pw; 

    cout << "Enter username :";
    cin >> username;

    cout << "Enter password :";
    cin >> password;

    //for reading file that you have account or not

    ifstream read("data\\" + username + ".txt"); //here data.txt where our data will save for us 
    //the file name is written in double cout in file handling
    getline(read, un); //for reading the user name is that user valid
    getline(read, pw); //reading the password correct or not

    if (un == username && pw == password)
    {
        return true;   //that the user is valid and can log in
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;

    cout << "1 : Register \n2 :Login\nYour choice :";
    cin >> choice;
    if (choice == 1)
    {
        string username, password;

        cout << "select a username :";
        cin >> username;
        cout << "select a password :";
        cin >> password;


        ofstream file;
        //open file help of open function
        file.open("data\\" + username + ".txt");

        //rewrite in the file
        file<<username<<endl<<password; //the data is registered into our file
        file.close();
    main();//to start again
    
    }

//if user have already account and want to log in then
    else if(choice==2)
    {
        //create a variable status and assign into islogged in function 
        //and it proceed it from there
       bool status =IsloggedIn();

       if(!status) //if login goes wrong user name and password is incorrect
       {
          cout<<"Invalid user name password :"<<endl;
          system("PAUSE");//This is a Windows-specific command, which tells the OS to run the pause
          return 0;
       }
       else 
       {
           cout<<"Successfully Logged in"<<endl;
           system("pause");
           return 1;
       }
    }
}
