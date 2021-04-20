#pragma once

#include <string>
#include <iostream>

class Book
{

private:
	std::string bookName;
	std::string author;
	int renterID;
	int id;
	int pages;
	float price;
	bool isAvailable;

public:
	Book(std::string name, std::string author,int rID, int id, int pages, float price, bool isAvailable)
	{
		this->bookName = name;
		this->author = author;
		this->renterID = rID;
		this->id = id;
		this->pages = pages;
		this->price = price;
		this->isAvailable = isAvailable;
	}

	Book() {}

	void setName(std::string name) { this->bookName = name; }
	void setAuthor(std::string author) { this->author = author; }
	void setRenterID(int rID) { this->renterID = rID; }
	void setPrice(float price) { this->price = price; }
	void setPages(int pages) { this->pages = pages; }
	void setPrice(int id) { this->id = id; }
	void setIsAvailable(bool b) { this->isAvailable = b; }

	std::string getBookName() { return this->bookName; }
	std::string getAuthor() { return this->author; }
	int getRenterID() { return this->renterID; }
	int getID() { return this->id; }
	int getPages() { return this->pages; }
	float getPrice() { return this->price; }
	bool getIsAvailable() { return this->isAvailable; }

	void print()
	{
		std::cout << "Book Name: " << this->getBookName() << "\nAuthor: " << this->getAuthor() << "\nPage Count: " << this->getPages() << "\nBook Price: $" << this->getPrice() << "\nBook ID: " << this->getID() << "\n\n";
	}
};
