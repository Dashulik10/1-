#include <iostream>
#include <string>
#include "Comment.h"
using namespace std;

// Comment
Comment::Comment() : description_of_comment(""), rating(0) {}
Comment::Comment(string desc, int r)
    : description_of_comment(desc), rating(r) {}

bool Comment::isPositive() const 
{
    return rating >= 5;
}