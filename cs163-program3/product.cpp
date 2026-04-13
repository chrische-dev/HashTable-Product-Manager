#include <iostream>
#include <cstring>

#include "product.h"
using namespace std;

product::product() //product constructor
{
    item = nullptr;
    description = nullptr;
    category = nullptr;
    type = nullptr;
    price = nullptr;
    quantity = nullptr;
    seller_id = nullptr;
    shop_name = nullptr;
    is_sold = false;
}


/*
   product::product(char * item_buffer, char * description_buffer, char * category_buffer, char * type_buffer, char * price_buffer, char * quantity_buffer, char * seller_id_buffer, char * shop_name_buffer, bool sold)
   {
   item = new char[strlen(item_buffer) + 1];
   strcpy(item, item_buffer);

   description = new char[strlen(description_buffer)+1];
   strcpy(description, description_buffer);

   category = new char[strlen(category_buffer)+1];
   strcpy(category, category_buffer);

   type = new char[strlen(type_buffer)+1];
   strcpy(type, type_buffer);

   price = new char[strlen(price_buffer)+1];
   strcpy(price, price_buffer);

   quantity = new char[strlen(quantity_buffer)+1];
   strcpy(quantity, quantity_buffer);

   seller_id = new char[strlen(seller_id_buffer)+1];
   strcpy(seller_id, seller_id_buffer);

   shop_name = new char[strlen(shop_name_buffer)+1];
   strcpy(shop_name, shop_name_buffer);

   }
 */

product::~product() //product deconstructor
{

    if (item) delete [] item;
    if (description) delete [] description;
    if (category) delete [] category;
    if(type) delete [] type;
    if(price) price = 0;
    if (quantity) quantity = 0;
    if(seller_id) seller_id = 0;
    if(shop_name) delete [] shop_name;
    if(is_sold) is_sold = false;
}

int product::copy(char item_buffer[], char description_buffer[], char category_buffer[], char type_buffer[], char price_buffer[], char quantity_buffer[], char seller_id_buffer[], char shop_name_buffer[], bool sold) //copy function so that we can get the data from main and copy it into our private 
{
    // Delete any data members of Product (item, description, etc.) if they are present.
    if (item) delete [] item;
    if (description) delete [] description;
    if (category) delete [] category;
    if(type) delete [] type;
    if(price) price = 0;
    if (quantity) quantity = 0;
    if(seller_id) seller_id = 0;
    if(shop_name) delete [] shop_name;
    if(is_sold) is_sold = false;
    // do the rest.


    item = new char[strlen(item_buffer)+1];
    strcpy(item,item_buffer);

    description = new char[strlen(description_buffer)+1];
    strcpy(description, description_buffer);

    category = new char[strlen(category_buffer)+1];
    strcpy(category, category_buffer);

    type = new char[strlen(type_buffer)+1];
    strcpy(type, type_buffer);

    price = new char[strlen(price_buffer)+1];
    strcpy(price, price_buffer);

    quantity = new char[strlen(quantity_buffer)+1];
    strcpy(quantity,quantity_buffer);

    seller_id = new char[strlen(seller_id_buffer)+1];
    strcpy(seller_id, seller_id_buffer);

    shop_name = new char[strlen(shop_name_buffer)+1];
    strcpy(shop_name, shop_name_buffer);

    is_sold = sold;


    return 1;   
}
int product::copy(const product & input_product) //another copy function both do the same thing
{
    copy(input_product.item, input_product.description, input_product.category, input_product.type, input_product.price,
            input_product.quantity, input_product.seller_id, input_product.shop_name, input_product.is_sold);

    return 1;
}


int product::display() //display function in my product class so it can access its data members inside of the class
{                       // then table can call this function because its public
    cout << item <<endl;
    cout << description << endl;
    cout << category << endl;
    cout << type << endl;
    cout << price <<endl;
    cout << quantity <<endl;
    cout << seller_id << endl;
    cout << shop_name << endl;
    cout << is_sold << endl;
    return 1;

}

int menu(int & choice)
{
    cout << endl << "Menu" <<endl;
    cout << "1. insert new product" <<endl;
    cout << "2. display all" << endl;
    cout << "3. find a match" << endl;
    cout << "4. retrieve" <<endl;
    cout << "5. quit" <<endl;
    cout << "enter a number 1-5:";
    cin >> choice;
    cin.ignore(100, '\n');

    return 1;
}

bool product::matches(const char * key) const //match function in my product so it has access to the category in private and table can call the fuction
{

    if(strcmp(category, key)== 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}





