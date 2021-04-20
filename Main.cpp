#include "Bookshop.h"
#include <iostream>

void menu()
{
	std::cout << "******************" << std::endl;
	std::cout << "*****BOOKSHOP*****" << std::endl;
	std::cout << "******************" << std::endl;
	std::cout << "\n\n1)Sell Book\n2)Rent Book\n3)Return Book\n4)List all books\n5)Search by ID\n6)Search by Author\n0)Exit\nInput: ";
}

int main()
{
	std::string path = "C:/Users/Desktop/list.txt";
	Bookshop bookshop = Bookshop(path);
	int choice = 0;
	int id = 0;
	int rID = -999;
	char conf = ' ';
	std::string aut = "";
	Book tempBook = Book();
	while (true)
	{
		menu();
		std::cin >> choice;
		while (!std::cin)
		{
			std::cout << "Invalid Input! Try again: ";
			std::cin.clear(); 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			system("cls");
			std::cout << "Do you know the ID of the book? Y/N : ";
			std::cin >> conf;
			while (conf != 'n' && conf != 'y')
			{
				std::cout << "Invalid Input! Try again: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> conf;
			}
			if (conf == 'n')
			{
				std::cout << "\n";
				bookshop.printAllBooks();
			}
			std::cout << "Enter ID of book: (0 to cancel) ";
			std::cin >> id;
			while (!std::cin)
			{
				std::cout << "\nInvalid Input! Try again: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> id;
			}
			if (bookshop.validID(id))
			{
				tempBook = bookshop.setBookRef(id);
				std::cout << "Confirm sale of '" << tempBook.getBookName() << "'? Y/N : ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				conf = std::getchar();
				while (conf != 'n' && conf != 'y')
				{
					std::cout << "\nInvalid Input! Try again: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> conf;
				}
				if (conf == 'y')
				{
					system("cls");
					bookshop.sellBook(id);
				}
				else {
					system("cls");
					std::cout << "Cancelled!" << std::endl;
				}
			}
			else
			{
				if (id != 0)
				{
					system("cls");
					std::cout << "Invalid Book ID!" << std::endl;
				}
				else
				{
					system("cls");
					std::cout << "Cancelled!" << std::endl;
				}
			}
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "Enter Renter's ID: ";
			std::cin >> rID;
			while (!std::cin)
			{
				std::cout << "\nInvalid Input! Try again: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> rID;
			}
			std::cout << "Do you know the ID of the book? Y/N : ";
			std::cin >> conf;
			while (conf != 'n' && conf != 'y')
			{
				std::cout << "Invalid Input! Try again: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> conf;
			}
			if (conf == 'n')
			{
				std::cout << "\n";
				bookshop.printAllBooks();
			}
			std::cout << "Enter ID of book: (0 to cancel) ";
			std::cin >> id;
			while (!std::cin)
			{
				std::cout << "\nInvalid Input! Try again: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> id;
			}
			if (bookshop.validID(id))
			{
				tempBook = bookshop.setBookRef(id);
				std::cout << "Confirm renting '" << tempBook.getBookName() << "' to Renter " << rID << "? Y/N : ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				conf = std::getchar();
				while (conf != 'n' && conf != 'y')
				{
					std::cout << "\nInvalid Input! Try again: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> conf;
				}
				if (conf == 'y')
				{
					system("cls");
					bookshop.rentBook(id, rID);
					std::cout << "\n";
				}
				else
				{
					system("cls");
					std::cout << "Cancelled!\n\n";
				}
			}
			else
			{
				if (id != 0)
				{
					system("cls");
					std::cout << "Invalid Book ID!\n\n";
				}
				else
				{
					system("cls");
					std::cout << "Cancelled!\n\n";
				}
			}
			break;
		}
		case 3:
			system("cls");
			std::cout << "Do you know the Renter ID? Y/N : ";
			std::cin >> conf;
			while (conf != 'n' && conf != 'y')
			{
				std::cout << "Invalid Input! Try again: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> conf;
			}
			if (conf == 'n')
			{
				std::cout << "\nEnter ID of book: (0 to cancel) ";
				std::cin >> id;
				while (!std::cin)
				{
					std::cout << "\nInvalid Input! Try again: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> id;
				}
				if (id == 0)
					std::cout << "Cancelled!" << std::endl;
				else
					bookshop.returnBook(id, -999);
			}
			else
			{
				std::cout << "\nEnter Renter ID of book: (0 to cancel)";
				std::cin >> rID;
				while (!std::cin)
				{
					std::cout << "\nInvalid Input! Try again: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> rID;
				}
				if (rID == 0)
					std::cout << "Cancelled!" << std::endl;
				else
					bookshop.returnBook(-999, rID);
			}
			break;
		case 4:
		{
			system("cls");
			bookshop.printAllBooks();
			break;
		}
		case 5:
		{
			system("cls");
			std::cout << "Enter ID to search for: ";
			std::cin >> id;
			while (!std::cin)
			{
				std::cout << "Invalid Input! Try again: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> id;
			}
			bookshop.searchByID(id);
			break;
		}
		case 6:
		{
			system("cls");
			std::cout << "Enter author to search for: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, aut);
			bookshop.searchByAuthor(aut);
			break;
		}
		case 0:
			system("pause");
			return 0;
		default:
			system("cls");
			std::cout << "Invalid Input\n\n";
			break;
		}
	}
}
