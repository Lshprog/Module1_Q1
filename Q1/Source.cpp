#include <iostream>     
#include <fstream>
#include "Header.h"

std::ifstream F;

stackread::Stack::Node::Node() {

	this->next = nullptr;
}
stackread::Stack::Node::Node(int value) {
	this->value = value;
	this->next = nullptr;
}

stackread::Stack::Node::~Node()
{
	delete next;
}

void stackread::Stack::push(Node* n)
{
	if (head == nullptr)
		head = n;
	else {
		n->next = head;
		head = n;
	}
}

int stackread::Stack::pop()
{
	Node* temp = head;
	if (head->next == nullptr)
		head = nullptr;
	else
		head = head->next;
	return temp->value;
}

void stackread::Stack::read_and_result()
{

	F.open("files\\line_to_read.txt", std::ios::in);

	char buffer;
	int i = 0;

	F.seekg(0, F.end);
	int length = F.tellg();
	F.seekg(0, F.beg);


	while (i < length) {
		F >> buffer;
		if (int(buffer) > 47 && int(buffer) < 58) {
			int temp = int(buffer) - int('0');
			stackread::Stack::Node* x = new Node(temp);
			push(x);

		}
		else if (int(buffer) == 42 || int(buffer) == 45 || int(buffer) == 43) {
			int result;
			int x, y;

			if (head != nullptr)
				x = stackread::Stack::pop();
			if (head != nullptr)
				y = stackread::Stack::pop();
			else {
				std::cout << "Incorrect line !!! ";
				F.close();
				return;
			};

			if (int(buffer) == 42)
				result = x * y;

			else if (int(buffer) == 45)
				result = y - x;

			else if (int(buffer) == 43)
				result = y + x;

			stackread::Stack::Node* z = new Node(result);
			push(z);

		}
		else {
			std::cout << "Incorrect line !!! ";
			F.close();
			return;
		}
		i++;
	}
	std::cout << "Result: " << pop();
	F.close();
	return;
}

void stackread::startprog() {

	stackread::Stack stack = stackread::Stack();
	stack.read_and_result();

}