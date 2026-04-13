//CS163, Program #3, chrische@pdx.edu, Chris Chen
//purpose of this program is to distribute data across a hashtable from a text file and from user input

#include <iostream>

#ifndef PRODUCT 
#define PRODUCT 

class product
{
    public:
    product();
//    product(char * item, char * description, char * category, char * type, char * price, char * quantity, char  *seller_id, char * shop_name, bool sold);
    ~product();
    int display();
    bool matches(const char * key) const;
    int copy(char item[], char description[], char category[], char type[], char price[], char quantity[], char seller_id[], char shop_name[], bool sold);
    int copy(const product & input_product);


    private:
    char * item;
    char * description;
    char * category;
    char * type;
    char * price;
    char * quantity;
    char * seller_id;
    char * shop_name;
    bool is_sold;

};

int menu(int & choice);

#endif
