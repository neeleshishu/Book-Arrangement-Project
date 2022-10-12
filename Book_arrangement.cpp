// C++ program for implementing the above
// mentioned functionalities
#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
using namespace std;
 
// Book class
class Book {
private:
    int bookid;
 
    // Max book title size 20
    char title[20];
    float price;
 
public:
    // Default Constructor
    Book()
    {
        bookid = 0;
        strcpy(title, "no title");
        price = 0;
    }
 
    // Function for taking book data
    void getBookData()
    {
        cout << "Enter bookid, title, "
             << " price: ";
        cin >> bookid;
        cin.ignore();
        cin.getline(title, 19);
        cin >> price;
    }
 
    // Function for showing book data
    void showBookData()
    {
        cout << "\n"
             << bookid
             << " " << title << " " << price;
    }
    
    int menu();
    int storeBook();
    void viewAllBooks();
    void searchBook(char*);
    void deleteBook(char*);
    void updateBook(char*);
};

int Book :: menu()
{
    char title[20];
    int choice;
    cout << "\nBook Management";
    cout << "\n1.Insert book record";
    cout << "\n2.View all book record";
    cout << "\n3.Search book record";
    cout << "\n4.Delete book record";
    cout << "\n5.Update book record";
    cout << "\n6.Exit";
    cout << "\n\nEnter your choice : ";
    cin >> choice;
  

    // while (1) {
        system("cls");
        switch (choice) {
        case 1:
            getBookData();
            storeBook();
            cout << "\nRecord inserted";
            break;
 
        case 2:
            viewAllBooks();
            break;
 
        case 3:
            cout << "\nEnter title of "
                 << "book to search : ";
            cin.ignore();
            cin.getline(title, 19);
            searchBook(title);
            break;
 
        case 4:
            cout << "\nEnter book title "
                 << "for delete record : ";
            cin.ignore();
            cin.getline(title, 19);
            deleteBook(title);
            break;
 
        case 5:
            cout << "\nEnter book title "
                 << "to update record : ";
            cin.ignore();
            cin.getline(title, 19);
            updateBook(title);
            break;
 
        case 6:
            cout << "\n Thanks for using";
            cout << "\n Press any key to exit";
            getch();
            exit(0);
 
        default:
            cout << "Invalid input";
        }
}

//}
 

void Book::updateBook(char* t)
{
    fstream file;
 
    // Open the file
    file.open("myfile3.txt",
              ios::in | ios::out | ios::ate | ios::binary);
    file.seekg(0);
    file.read((char*)this, sizeof(*this));
 
    // Read the file
    while (!file.eof()) {
        if (!strcmp(t, title)) {
            getBookData();
 
            file.seekp(file.tellp() - sizeof(*this));
            file.write((char*)this, sizeof(*this));
        }
        file.read((char*)this, sizeof(*this));
    }
 
    // Close the file
    file.close();
}
 
// Function for delete book data
void Book::deleteBook(char* t)
{
    ifstream fin;
    ofstream fout;
    fin.open("myfile3.txt",
             ios::app | ios::binary);
    if (!fin)
        cout << "\n File not found";
    else {
        fout.open("tempfile.txt",
                  ios::app | ios::binary);
        fin.read((char*)this, sizeof(*this));
 
        // Until end of file is not reached
        while (!fin.eof()) {
            if (strcmp(title, t))
                fout.write((char*)this, sizeof(*this));
            fin.read((char*)this, sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("myfile3.txt");
        rename("tempfile.txt", "myfile3.txt");
    }
}
 
// Function to search the Book
void Book::searchBook(char* t)
{
    int counter = 0;
    ifstream fin;
    fin.open("myfile3.txt",
             ios::in | ios::binary);
 
    // If file is not found
    if (!fin)
        cout << "File not found";
    else {
        fin.read((char*)this, sizeof(*this));
 
        // Until end of file is not reached
        while (!fin.eof()) {
            if (!strcmp(t, title)) {
                showBookData();
                counter++;
            }
            fin.read((char*)this, sizeof(*this));
        }
        if (counter == 0)
            cout << "No record found";
        fin.close();
    }
}
 
// Function to view all the Book
void Book::viewAllBooks()
{
    ifstream fin;
 
    
    fin.open("myfile3.txt", ios::in | ios::binary);
    if (!fin)
        cout << "File not found";
 
    else {
        fin.read((char*)this, sizeof(*this));
 
        
        while (!fin.eof()) {
            showBookData();
 
            
            fin.read((char*)this, sizeof(*this));
        }
        fin.close();
    }
}
 
// Function to implement the store of
// all the books
int Book::storeBook()
{
    if (bookid == 0 && price == 0) {
        cout << "book data not"
             << " initialized";
        return (0);
    }
    else {
        ofstream fout;
 
        fout.open("myfile3.txt", ios::app | ios::binary);
 
        
        fout.write((char*)this, sizeof(*this));
        fout.close();
        return (1);
    }
}
 


 

int main()
{
 
   
    Book b1;
    b1.menu();
    
 
   
        getch();
    }
