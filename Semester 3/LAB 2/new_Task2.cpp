#include<iostream>
using namespace std;
class Book
{
	string Name_book, Name_author, Name_publisher, AssignedCMS;
	int ISSBN, Edition;
	bool isAvailable;
	public:
		Book()
		{
			isAvailable = true;
		}
		Book(string Name_bookFun,string Name_authorFun,string Name_pubFun,string, int ISSBNFun)
		{
			Name_book = Name_bookFun;
			Name_author = Name_authorFun;
			Name_publisher = Name_pubFun;
			ISSBN = ISSBNFun;
			isAvailable = true;
			Edition = 1;
		}
		Book(string Name_bookFun,string Name_authorFun,string Name_pubFun,string, int ISSBNFun, int EditionFun)
		{
			Name_book = Name_bookFun;
			Name_author = Name_authorFun;
			Name_publisher = Name_pubFun;
			ISSBN = ISSBNFun;
			isAvailable = true;
			Edition = EditionFun;
		}
		void inputDetails()
		{
			cout<<"Name: "<<endl;
			cin>>Name_book;
			cout<<"Author: "<<endl;
			cin>>Name_author;
			cout<<"Publisher: "<<endl;
			cin>>Name_publisher;
			cout<<"ISSBN: "<<endl;
			cin>>ISSBN;
			cout<<"Edition: "<<endl;
			cin>>Edition;
			
		}
		bool DispDetails(string Name_bookFun)
		{
			if(Name_bookFun==Name_book)
			{
			cout<<"Name: "<<Name_book<<endl;
			cout<<"Author: "<<Name_author<<endl;
			cout<<"Publisher: "<<Name_publisher<<endl;
			cout<<"ISSBN: "<<ISSBN<<endl;
			cout<<"Edition: "<<Edition<<endl;
			
				return true;		
			}
			else
			return false;
		}
		bool DispDetails(int ISSBNFun)
		{
			if(ISSBNFun==ISSBN )
			{
			cout<<"Name: "<<Name_book<<endl;
			cout<<"Author: "<<Name_author<<endl;
			cout<<"Publisher: "<<Name_publisher<<endl;
			cout<<"ISSBN: "<<ISSBN<<endl;
			cout<<"Edition: "<<Edition<<endl;
				return true;		
			}
			else
			return false;
		}
		
		bool DispDetails(string Name_bookFun,int ISSBNFun)
		{
			if(Name_bookFun==Name_book && ISSBNFun==ISSBN )
			{
			cout<<"Name: "<<Name_book<<endl;
			cout<<"Author: "<<Name_author<<endl;
			cout<<"Publisher: "<<Name_publisher<<endl;
			cout<<"ISSBN: "<<ISSBN<<endl;
			cout<<"Edition: "<<Edition<<endl;
				return true;		
			}
			else
			return false;
		}
		void DispDetails()
		{
			cout<<"Name: "<<Name_book<<endl;
			cout<<"Author: "<<Name_author<<endl;
			cout<<"Publisher: "<<Name_publisher<<endl;
			cout<<"ISSBN: "<<ISSBN<<endl;
			cout<<"Edition: "<<Edition<<endl;
		}
		bool AvailabilityStatus()
		{
			return isAvailable;
		}
		void issueBook(string cms)
		{
			if(!isAvailable)
			{
				cout<<"BOOK is assigned to "<<AssignedCMS<<endl;
			}
			else
			{
				AssignedCMS = cms;
				isAvailable = false;
			}
			
		
			
		}
		string get_name()
		{
			return Name_book;
		}
	
};
class Liberary
{
	
	string Librarian; 
	int maxBookNums, currBooksNum; 
	Book *booksPtr;
	public:
		Liberary(string LibrarianFun)
		{
			Librarian = LibrarianFun;
			maxBookNums = 100;
			booksPtr = new Book[maxBookNums];
			currBooksNum= 0;
		}
		Liberary(string LibrarianFun,int maxSizeFun)
		{
			Librarian = LibrarianFun;
			maxBookNums = maxSizeFun;
			booksPtr = new Book[maxBookNums];
			currBooksNum= 0;
			
		}
		void DispBookDetails()
		{
			for(int i=0; i<currBooksNum; i++)
			{
				booksPtr[i].DispDetails();
			}
		}
		void addBook()
		{
			if(currBooksNum<maxBookNums)
			{
				
			
			
				booksPtr[currBooksNum].inputDetails();
				++currBooksNum;
			}
			else
			cout<<"No Memory"<<endl;

		}
		void searchBook(string name)
		{
			for(int i=0; i<currBooksNum; i++)
			{
				if(booksPtr[i].DispDetails(name)==true)
				{
					cout<<"BOOK IS AVAILABLE"<<endl;
					break;
				}
			}
		}
		void assignBook(string cms,string name)
		{
			for(int i=0; i<currBooksNum; i++)
			{
				if(booksPtr[i].get_name()==name)
				{
					booksPtr[i].issueBook(cms);
						
				}	
			}
			
			
		}
		~Liberary()
		{
			delete []booksPtr;
		}
		
		
		
};
int main()
{
	Liberary lib("Haseeb");
	lib.addBook();
	lib.assignBook("023-18-00","oliver");
	lib.searchBook("oliver");
	
}
