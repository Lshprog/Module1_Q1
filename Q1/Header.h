#pragma once
namespace stackread {
	struct Stack {
		struct Node {
			int value;
			Node* next;
			Node();
			Node(int value);
			~Node();
		};
		Node* head = nullptr;
		void push(Node*);
		int pop();
		void read_and_result();
	};
	void startprog();
}
