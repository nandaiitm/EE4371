# include<iostream>
# include<fstream>
# include<cstdlib>
# include<conio.h>
using namespace std;
int main()
{
    char option;
    string line;
    fstream f_handle;
    f_handle.open("users.txt");
    if(!f_handle)
    {
        cout << "File could not be opened \n";
        exit(-1);
    }
    while(1)
    {
        system("cls");
        cout << "\t\t\t\t\t****STUDENT DATABASE MANGEMENT SOFTWARE****\n\n";
        cout << "\tSELECT ANY ONE OF THE FOLLOWING OPTIONS:\n";
        cout << "\t\t1.Add student record\n";
        cout << "\t\t2.List all the student records\n";
        cout << "\t\t3.Modify a selected record\n";
        cout << "\t\t4.Delete a selected record\n";
        cout << "\t\t5.Exit software\n\n";
        cout << "\t\tEnter your option : ";
        option=getche();
        switch(option)
        {
            case '1':

                break;

            case '2':
                f_handle.seekg(0,ios::beg);
                while(f_handle)
                {
                    getline(f_handle,line);
                    cout << line << endl;
                }
                break;
                
            case '3':

                break;
                
            case '4':

                break;
                
            case '5':
                cout << "\n\n\t\t\t\t***SOFTWARE HAS BEEN SUCCESSFULLY TERMINATED***\n";
                f_handle.close();
                exit(0);
                break;

            default:
                system("cls");
                cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND 5 ON THE HOME SCREEN\n";
                cout << "Press any key to get redirected to the home screen: ";
                getch();
                continue;
        }
        system("pause");
       exit(0); 
    }
    return 0;
}