/*
Task 2: This task is about relationship between a book and library. A book usually have the following details
    i. Name of book
    ii. Name of author
    iii. Name of publisher
    iv. ISSBN number
    v. Edition
A library on the other hand have several books. We might have different libraries for different disciplines such as Mathematics, English literature, Computer Science, Electrical etc. Every library have a collection of the books. Now let’s discuss this problem using the concepts that we learnt so far.
You are required to create two classes named Book and Library. Class named book must have the following members and methods
Book Class:
Private:
String Name_book, Name_author, Name_publisher, AssignedCMS; int ISSBN, Edition; bool isAvailable;
Public:
    i. A default constructor with no parameters. It should assign true to isAvailable. 
    ii. A constructor that takes four parameters named Name_bookFun, Name_authorFun, Name_pubFun and ISSBNFun and assign them to the four private members. Absence of Edition number shows that this is the first edition of the book. It should also initialize isAvalable by true.
    iii. A constructor that takes five parameters named Name_bookFun, Name_authorFun, Name_pubFun, ISSBNFun and EditionFun and assign them to the five private members. It should also initialize isAvalable by true.
    iv. A function named inputDetails that stores the values into the private members of the class.
    v. Member function named DispDetails that takes a string named Name_bookFun and display details of book if name is matched with the book name. It should also return true if the book is found and vice versa.
    vi. An overloaded function named DispDetails that takes an integer named ISSBNFun as input and perform the similar operation. It should also return true if the book is found and vice versa.
    vii. Another overloaded function named DispDetails that takes no arguments and display the details of the book. 
    viii. A function named AvailabilityStatus that returns the value of isAvailable.
    ix. A function named issueBook that takes cms id of a student as input, store it in AssignedCMS, assign false to isAvailable. It should return an error message that “Book is already issued to a student with CMS id ______” if book is already assigned to someone else.

Library Class:
Private:
String Librarian; int maxBookNums, currBooksNum; Book *booksPtr;
Public:
    i. A constructor that takes a string named LibrarianFun as input, assigns it to Librarian. It should assign a default value of 100 to the variable named maxBookNums and create a dynamic array of size maxBookNums using booksPtr. It should also assign a value of 0 to currBooksNum.
    ii. A constructor that takes a string named LibrarianFun and an integer named maxSizeFun as inputs, assigns them to Librarian and maxBookNums. It should then create a dynamic array of size maxBookNums using booksPtr. It should also assign a value of 0 to currBooksNum.
    iii. Member function named DispBookDetails that display the details of all books in the library by calling DispDetails function with no arguments.
    iv. A function named addBook that takes all the details required for a book and add that book to the dynamic array of objects. It should also increment currBooksNum as a book is added. Make sure that currBooksNum doesn’t exceed the maximum size.
    v. A function named searchBook that takes name of the book as input and display whether book is available or not.
    vi. A function named assignBook that takes cms id and book name as input and assign that book to the person with cms id if book is available. An error message should be displayed in case if book isn’t included in Library or is already assigned to someone else.
    vii. A destructor that destroy the dynamic array.


*/
#include<iostream>
using namespace std;
class book
{
	string Name_book, Name_author, Name_publisher, CMS;
	int ISSBN, Edition;
	bool isAvailable;
public :
	book()
	{
		isAvailable = true;
	}
	book(string Name_bookFun,string Name_authorFun,string Name_pubFun,int ISSBNFun)
	{
		Name_book=Name_bookFun;
		Name_author=Name_authorFun;
		Name_publisher=Name_pubFun;
		ISSBN=ISSBNFun;
		Edition = 1;
		isAvailable= true;
	
	}
	book(string Name_bookFun,string Name_authorFun,string Name_pubFun,int ISSBNFun,int EditionFun)
	{
		Name_book=Name_bookFun;
		Name_author=Name_authorFun;
		Name_publisher=Name_pubFun;
		ISSBN=ISSBNFun;
		Edition = EditionFun;
		isAvailable= true;
	
	}
	void inputDetails()
	{
		cout<<"Enter book name = ";
		cin>>Name_book;
		cout<<"Enter Author = ";
		cin>>Name_author;
		cout<<"Enter publisher = ";
		cin>>Name_publisher;
		cout<<"Enter ISSBN = ";
		cin>>ISSBN;
		cout<<"Enter Edition = ";
		cin>>Edition;
	}
	bool DispDetails(string Name_bookFun  )
	{
		if(Name_bookFun==Name_book)
		{
			DispDetails();
			return true;
		}
		else
			return false;
	}
	bool DispDetails(int ISSBNFun )
	{
		if(ISSBNFun==ISSBN)
		{
			DispDetails();
			return true; 
		}
		else
			return false;
	}
	void DispDetails()
	{
		cout<<"Book Name = "<<Name_book<<endl;
		cout<<"Author Name = "<<Name_author<<endl;
		cout<<"Publisher  = "<<Name_publisher<<endl;
		cout<<"ISSBN Number = "<<ISSBN<<endl;
		cout<<"Book Edition = "<<Edition<<endl;
	}
	bool AvailabilityStatus()
	{
		return isAvailable;
	}
	void issueBook(string cms)
	{
	
		if(!isAvailable)
		{
			cout<<"Book is already issued to a student with CMS id "<<CMS<<endl;
		}
		else
		{
			CMS=cms;
			cout<<"Book is issued Successfully!.."<<endl;
			isAvailable = false;      
		}
	}
};
class library
{
	string Librarian;
	int maxBookNums, currBooksNum;
	book *booksptr;
public :
	library(string LibrarianFun)
	{
		maxBookNums=100;
		currBooksNum=0;
		Librarian=LibrarianFun;
		booksptr= new book[maxBookNums];
	}
	library(string LibrarianFun,int maxSizeFun)
	{
		Librarian=LibrarianFun; 
		maxBookNums=maxSizeFun;
		booksptr = new book[maxBookNums];
		currBooksNum=0;
	}
	void DispBookDetails()
	{
		for(int i=0 ; i<currBooksNum;i++)
		{
			booksptr[i].DispDetails();
		}
	}
	void addBook()
	{
		if(currBooksNum<maxBookNums)
		{
			booksptr[currBooksNum].inputDetails();
			currBooksNum++;
		}
		else
		cout<<"Unable to add, Max size is reached "<<endl;
	}
	void searchBook(string book_name)
	{
		bool flag=true;
		for(int i=0 ; i<currBooksNum ; i++)
		{
			if(booksptr[i].DispDetails(book_name))
			{
				cout<<"Book is in the Library "<<endl;
				flag=false;
				break;
			}
		}
		if(flag)
		cout<<"Book is not in the library "<<endl;
	}
	void assignBook(string cms,string name)
	{
		bool flag=true;
		for(int i=0 ; i<currBooksNum; i++)
		{
			if(booksptr[i].DispDetails(name))
			{
				flag=false;
				booksptr[i].issueBook(cms);
				break;
				
			}
			
		}
		if(flag)
		cout<<"Book is not in the Library!.."<<endl;
	}
	~library()
	{
		delete []booksptr;
	}
};
main()
{
	library obj("none",2);
	obj.addBook();
	obj.addBook();
	obj.addBook();
	cout<<endl;
//	obj.searchBook("Cal");
//	obj.assignBook("023-18-00","Cal");
//	obj.assignBook("023-18-01","Kal");
//	obj.assignBook("023-18-01","Cal");
}
