// COMSC-210 | Lab 18 | Vevaan Verma
using namespace std;
#include <iostream>
#include <string>

struct ReviewNode;

/* FUNCTION PROTOTYPES */
ReviewNode* getUserReview();
void addReviewFront(ReviewNode*& head, ReviewNode*&);
void addReviewBack(ReviewNode*& head, ReviewNode*&);
void outputReviews(ReviewNode* head);
int getValidatedChoice();
double getValidatedRating(string prompt);
char getValidatedChar(string prompt);

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
	cout << "    Choice: ";
	addToFront = getValidatedChoice() == 1 ? true : false; // get the choice from the user and set addToFront to true if the choice is 1, false otherwise

	char userChoice; // variable to store the user's choice

	do {

		ReviewNode* reviewNode = getUserReview(); // get a review from the user

		if (addToFront) addReviewFront(head, reviewNode); // add the review to the front of the linked list
		else addReviewBack(head, reviewNode); // add the review to the back of the linked list

		userChoice = getValidatedChar("Add another review? (y / n): "); // prompt user to add another review

	} while (userChoice == 'y'); // repeat until the user does not want to add another review

	return 0;

}

// getUserReview() gets a review from the user and returns a pointer to a review node with the rating and review
// arguments: none
// returns: ReviewNode* - a pointer to a review node with the rating and review
ReviewNode* getUserReview() {

	string review; // variable to store the review

	double rating = getValidatedRating("Enter a rating (0 - 5): "); // get the validated rating from the user

	cin.ignore(); // ignore input buffer (to prevent getline from reading the new line character)
	cout << "Enter a review: "; // prompt user for review
	getline(cin, review); // get the review from the user

	return new ReviewNode{ rating, review, nullptr }; // return a new review node with the rating and review

}

// addReviewFront() adds a review to the front of the linked list
// arguments: ReviewNode*& head - the head of the linked list, ReviewNode*& nodeToAdd - the review node to add to the front of the linked list
// returns: void
void addReviewFront(ReviewNode*& head, ReviewNode*& nodeToAdd) {

	nodeToAdd->next = head; // set the next of the review node to the current head
	head = nodeToAdd; // set the head to the review node

}

// addReviewBack() adds a review to the back of the linked list
// arguments: ReviewNode*& head - the head of the linked list, ReviewNode*& nodeToAdd - the review node to add to the back of the linked list
// returns: void
void addReviewBack(ReviewNode*& head, ReviewNode*& nodeToAdd) {

	nodeToAdd->next = nullptr; // set the next of the review node to nullptr

	if (head == nullptr) { // if the head does not exist (the linked list is empty)

		head = nodeToAdd; // set the head to the review node
		return; // return

	}

	ReviewNode* current = head; // create a current node and set it to the head

	while (current->next != nullptr) // while the next of the current node is not nullptr
		current = current->next; // set the current node to the next of the current node

	// now the current node is the last node in the linked list

	current->next = nodeToAdd; // set the next of the current node to the review node

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

// getValidatedRating() repeatedly asks the user for input until a valid rating is entered (between 0.0 and 5.0) | this is a more specific double validation method specifically for the rating
// arguments: prompt (string) - the prompt to display to the user when asking for input
// returns: double - the validated double input
double getValidatedRating(string prompt) {

	double inputDbl; // variable to store the input (of type double)
	cout << prompt;

	while (!(cin >> inputDbl) || inputDbl < 0.0 || inputDbl > 5.0) { // if the input is not a double or the input is not between 0.0 and 5.0

		cout << "Invalid input. Please try again: "; // output error message
		cin.clear();
		cin.ignore(INT_MAX, '\n'); // ignore the invalid input

	}

	return inputDbl;

}

// getValidatedChar() repeatedly asks the user for input until a valid char is entered
// arguments: prompt (string) - the prompt to display to the user when asking for input
// returns: char - the validated char input
char getValidatedChar(string prompt) {

	char inputChar; // variable to store the input (of type char)
	cout << prompt;

	while (!(cin >> inputChar) || (inputChar != 'y' && inputChar != 'n')) { // if the input is not a char or the input is not 'y' or 'n'

		cout << "Invalid input. Please try again: "; // output error message
		cin.clear();
		cin.ignore(INT_MAX, '\n'); // ignore the invalid input

	}

	cin.ignore(INT_MAX, '\n'); // ignore the rest of the input (so it doesn't get read in the next input)
	return inputChar;

}