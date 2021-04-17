#include "Bookshop.h"

void menu()
{
	std::cout << "******************" << std::endl;
	std::cout << "*****BOOKSHOP*****" << std::endl;
	std::cout << "******************" << std::endl;
	std::cout << "\n\n1)Purchase Book\n2)List all books\n3)Search for book\n9)Exit\nInput: ";
}

int main()
{
	
	std::string path = "C:/Users/Desktop/list.txt";
	Bookshop bookshop = Bookshop(path);
	int choice = 0;
	int id = 0;
	char conf = ' ';
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
				std::cout << "Invalid Input! Try again: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> id;
			}
			if (bookshop.validID(id))
			{
				std::cout << "Confirm this sale? Y/N : ";
				while (conf != 'n' && conf != 'y')
				{
					std::cout << "Invalid Input! Try again: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> conf;
				}
				if (conf == 'y')
					bookshop.sellBook(id);
				else
					std::cout << "Cancelled!" << std::endl;
			}
			else
			{
				if (id != 0)
					std::cout << "Invalid Book ID!" << std::endl;
				else
					std::cout << "Cancelled!" << std::endl;
			}
			break;
		case 2:
			system("cls");
			bookshop.printAllBooks();
			break;
		case 3:
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
			bookshop.printSingleBook(id);
			break;
		case 9:
			system("pause");
			return 0;
		default:
			std::cout << "Default" << std::endl;
			break;
		}
	}
}

//still need to modify the input of a char to only allow a single char to be read.
//small modifications to output
