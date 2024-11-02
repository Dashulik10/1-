#ifndef COMMENT_H
#define COMMENT_H
#include <iostream>
#include <string>
using namespace std;

class Comment 
{
public:
	string description_of_comment;
	int rating;

	Comment();
	Comment(string description_of_comment, int rating);


	bool isPositive() const;
};
#endif