#pragma once

#include <fstream>
#include <vector>
#include "Book.h"

class Bookshop {

private:
	std::vector<Book> availableBooks;
	std::vector<Book> rentedBooks;
	std::string path;

	void initializeavailableBooks(std::string path)
	{
		std::string line;
		std::string tempName;
		std::string author;
		int tempID = 0;
		int pages;
		float tempPrice = 0.0f;
		bool avail = false;
		int ctr = 0;

		std::ifstream file(path);

		if (file.is_open())
		{
			while (std::getline(file, line))
			{
				if (!line.empty())
				{
					switch (ctr)
					{
					case 0:
						tempName = line;
						ctr++;
						break;
					case 1:
						author = line;
						ctr++;
						break;
					case 2:
						tempID = std::stoi(line);
						ctr++;
						break;
					case 3:
						pages = std::stoi(line);
						ctr++;
						break;
					case 4:
						tempPrice = std::stof(line);
						ctr++;
						break;
					case 5:
						avail = (line == "true");
						availableBooks.push_back(Book(tempName, author, -1, tempID, pages, tempPrice, avail));
						tempName.clear();
						author.clear();
						pages = -999;
						tempPrice = -999;
						tempID = -999;
						ctr = 0;
						avail = false;
						break;
					}
				}
			}
		}
	}

public:
	Bookshop(std::string path) {
		this->path = path;
		initializeavailableBooks(this->path);
	};

	void setPath(std::string newPath) 
	{ 
		availableBooks.clear();
		this->path = newPath;
		initializeavailableBooks(this->path);
	}

	int getavailableBooksSize() { return availableBooks.size(); }

	void printAllBooks()
	{
		for (auto b : availableBooks)
			if(b.getIsAvailable())
				b.print();
	}

	void printSingleBook(int id)
	{
		for (Book b : availableBooks)
		{
			if (b.getID() == id && b.getIsAvailable())
				b.print();
		}
	}

	void sellBook(int id)
	{
		for (unsigned int i = 0; i < availableBooks.size(); i++)
		{
			if (availableBooks.at(i).getID() == id && availableBooks.at(i).getIsAvailable())
			{
				std::cout << "Successfully purchased " << availableBooks.at(i).getBookName() << std::endl;
				availableBooks.erase(availableBooks.begin() + i);
			}
		}
	}

	void rentBook(int id, int rID)
	{
		for (unsigned int i = 0; i < availableBooks.size(); i++)
		{
			if (availableBooks.at(i).getID() == id && availableBooks.at(i).getIsAvailable())
			{
				std::cout << "Successfully Rented Out " << availableBooks.at(i).getBookName() << " to Renter " << rID << std::endl;
				availableBooks.at(i).setRenterID(rID);
				availableBooks.at(i).setIsAvailable(false);
				rentedBooks.push_back(availableBooks.at(i));
				availableBooks.erase(availableBooks.begin() + i);
			}
		}
	}

	void returnBook(int id, int rID)
	{
		if(id!=-999)
			for(unsigned int i = 0; i < rentedBooks.size(); i++)
			{
				if (rentedBooks.at(i).getRenterID() == id) 
				{
					rentedBooks.at(i).setRenterID(rID);
					rentedBooks.at(i).setIsAvailable(true);
					std::cout << "Successfully Returned Renter " << rID << "'s Book: " << rentedBooks.at(i).getBookName() << std::endl;
					availableBooks.push_back(rentedBooks.at(i));
					rentedBooks.erase(rentedBooks.begin() + i);
				}
			}
		else if (rID != -999)
		{
			for (unsigned int i = 0; i < rentedBooks.size(); i++)
			{
				if (rentedBooks.at(i).getRenterID() == rID)
				{
					rentedBooks.at(i).setRenterID(rID);
					rentedBooks.at(i).setIsAvailable(true);
					std::cout << "Successfully Returned Renter " << rID << "'s Book: " << rentedBooks.at(i).getBookName() << std::endl;
					availableBooks.push_back(rentedBooks.at(i));
					rentedBooks.erase(rentedBooks.begin() + i);
					 
				}
			}
		}
	}

	bool validID(int id)
	{
		for (Book b : availableBooks)
		{
			if (b.getID() == id)
				return true;
		}
		for (Book b : rentedBooks)
		{
			if (b.getID() == id)
				return true;
		}

		return false;
	}

	Book setBookRef(int id)
	{
		for (Book b : availableBooks)
		{
			if (b.getID() == id && b.getIsAvailable())
				return Book(b.getBookName(), b.getAuthor(), -999, b.getID(), b.getPages(), b.getPrice(),true);
		}
		return Book();
	}

	void searchByID(int id)
	{
		for (Book b : availableBooks)
		{
			if (b.getID() == id)
				b.print();
		}
	}

	void searchByAuthor(std::string name)
	{
		std::vector<Book> rVec;
		for (unsigned int i = 0; i < availableBooks.size(); i++)
		{
			if (availableBooks.at(i).getAuthor().find(name) != 4294967295)
				rVec.push_back(availableBooks.at(i));
		}
		if (rVec.empty())
			std::cout << "Your search produced no results!\n\n";
		else
		{
			for (Book b : rVec)
				printSingleBook(b.getID());
		}
	}
};
