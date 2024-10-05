// COMSC-210 | Lab 18 | Vevaan Verma
using namespace std;
#include <iostream>
#include <string>

struct ReviewNode;

/* FUNCTION PROTOTYPES */
void addReviewFront(ReviewNode*& head, double rating, string review);
void addReviewBack(ReviewNode*& head, double rating, string review);
// void printReviews(ReviewNode* head);
int getValidatedChoice();

// struct ReviewNode is a node that holds a rating and a review
struct ReviewNode {

	double rating;
	string review;
	ReviewNode* next;

};

// main() is the entry point of the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	ReviewNode* head = nullptr; // create a head node and set it to nullptr
	bool addToFront;

	// prompt user for linked list addition method
	cout << "Which linked list method should we use?" << endl;
	cout << "    [1] New nodes are added at the head of the linked list" << endl;
	cout << "    [2] New nodes are added at the tail of the linked list" << endl;
	cout << "Choice: ";
	addToFront = getValidatedChoice() == 1 ? true : false; // get the choice from the user and set addToFront to true if the choice is 1, false otherwise

	return 0;

}

// addReviewFront() adds a review to the front of the linked list
// arguments: ReviewNode*& head - the head of the linked list, double rating - the rating of the review, string review - the review to add
// returns: void
void addReviewFront(ReviewNode*& head, double rating, string review) {

	ReviewNode* reviewNode = new ReviewNode; // create a new review node
	reviewNode->rating = rating; // set the rating of the review node
	reviewNode->review = review; // set the review of the review node
	reviewNode->next = head; // set the next of the review node to the current head
	head = reviewNode; // set the head to the review node

}

// addReviewBack() adds a review to the back of the linked list
// arguments: ReviewNode*& head - the head of the linked list, double rating - the rating of the review, string review - the review to add
// returns: void
void addReviewBack(ReviewNode*& head, double rating, string review) {

	ReviewNode* reviewNode = new ReviewNode; // create a new review node
	reviewNode->rating = rating; // set the rating of the review node
	reviewNode->review = review; // set the review of the review node
	reviewNode->next = nullptr; // set the next of the review node to nullptr

	if (head == nullptr) { // if the head does not exist (the linked list is empty)

		head = reviewNode; // set the head to the review node
		return; // return

	}

	ReviewNode* current = head; // create a current node and set it to the head

	while (current->next != nullptr) // while the next of the current node is not nullptr
		current = current->next; // set the current node to the next of the current node

	// now the current node is the last node in the linked list

	current->next = reviewNode; // set the next of the current node to the review node

}

// getValidatedInteger() repeatedly asks the user for input until a valid choice integer is entered (either 1 or 2) | this is a more specific int validation method specifically for the list addition method choice
// arguments: none
// returns: int - the validated integer input
int getValidatedChoice() {

	int inputInt; // variable to store the input (of type integer)

	while (!(cin >> inputInt) || !(inputInt == 1 || inputInt == 2)) { // if the input is not an integer or the input is not 1 or 2

		cout << "Invalid input. Please try again: "; // output error message
		cin.clear();
		cin.ignore(INT_MAX, '\n'); // ignore the invalid input

	}

	return inputInt;

}