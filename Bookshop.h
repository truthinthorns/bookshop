#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Book.h"

class Bookshop {

private:
	std::vector<Book> bookVec;
	std::string path;

	void initializeBookVec(std::string path)
	{
		std::string line;
		std::string tempName;
		float tempPrice = 0.0f;
		int tempID = 0;
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
						tempPrice = std::stof(line);
						ctr++;
						break;
					case 2:
						tempID = std::stoi(line);
						bookVec.push_back(Book(tempName, tempPrice, tempID));
						tempName.clear();
						tempPrice = -999;
						tempID = -999;
						ctr = 0;
						break;
					}
				}
			}
		}
	}

public:
	Bookshop(std::string path) {
		this->path = path;
		initializeBookVec(this->path);
	};

	void setPath(std::string newPath) 
	{ 
		bookVec.clear();
		this->path = newPath;
		initializeBookVec(this->path);
	}

	int getBookVecSize() { return bookVec.size(); }

	void printAllBooks()
	{
		for (auto b : bookVec)
			std::cout << "Book Name: " << b.getBookName() << "\nBook Price: $" << b.getPrice() << "\nBook ID: " << b.getID() << std::endl << std::endl;
	}

	void printSingleBook(int id)
	{
		for (Book b : bookVec)
		{
			if (b.getID() == id)
				std::cout << "Book Name: " << b.getBookName() << "\nBook Price: $" << b.getPrice() << "\nBook ID: " << b.getID() << std::endl << std::endl;
		}
	}

	void sellBook(int id)
	{
		for (int i = 0; i < bookVec.size(); i++)
		{
			if (bookVec.at(i).getID() == id)
			{
				std::cout << "Successfully purchased " << bookVec.at(i).getBookName() << std::endl;
				bookVec.erase(bookVec.begin() + i);
			}
		}
	}

	bool validID(int id)
	{
		for (Book b : bookVec)
		{
			if (b.getID() == id)
				return true;
		}
		return false;
	}
};