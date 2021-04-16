#pragma once

#include <string>

class Book
{

private:
	std::string bookName;
	float price;
	int id;

public:
	Book(std::string name, float price, int id)
	{
		this->bookName = name;
		this->price = price;
		this->id = id;
	}

	void setName(std::string name) { this->bookName = name; }
	void setPrice(float price) { this->price = price; }
	void setPrice(int id) { this->id = id; }

	std::string getBookName() { return this->bookName; }
	float getPrice() { return this->price; }
	int getID() { return this->id; }
};