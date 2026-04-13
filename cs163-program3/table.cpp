#include <cstring>
using namespace std;
#include "table.h"
#include "product.h"

table::table(int size) //setting all indexes in the array to nullptr
{
    hash_table_size = size;

    hash_table = new product_node*[size];

    for(int i{0}; i < size; ++i)
    {
        hash_table[i] = nullptr;
    }


}

table::~table() //deconstructor
{
    for(int i{0}; i < hash_table_size; ++i)
    {
        product_node * current = hash_table[i];

        while(current != nullptr)
        {
            hash_table[i] = current->next;
            delete current;
            current = hash_table[i];
        }

    }

    delete[] hash_table;

}

int table::hash_function(char * key) //hash function takes in key from user and find a index for it
{
    int num = 1;

    for(unsigned int i{0}; i< strlen(key); ++i)
    {
        num = num * key[i];
    }

    return num % hash_table_size;
}

int table::insert(char * key, const product & input_product)
{
    int index = hash_function(key);

    product_node * temp = new product_node;
    temp->data.copy(input_product);
    temp->next = nullptr;


    temp->next = hash_table[index];
    hash_table[index] = temp;
    return 1;
}

int table::display_all() //display all function calling a function from the public section of product
{
    for(int i{0}; i < hash_table_size; ++i)
    {
        product_node * current = hash_table[i];

        while(current)
        {
            current->data.display();
            current = current->next;
        }
    }
    return 1;
}

int table::display_match(const char * key) //display a match calling a function from product class that has acess to the data we want to compare our key to
{
    for(int i{0}; i < hash_table_size; ++i)
    {
        product_node * current = hash_table[i];

        while(current != nullptr)
        {
            if(current->data.matches(key)) //if there is a match
            {
                current->data.display();
                return 1;
            }

            current = current->next;
        }
    }

    cout << "no match found";
    return 0;
}

bool table::retrieve(char * key, char * item_name, product & to_fill) //retirieve function takes in a category and name to find the specific nodes data and copy it into a product struct
{   //step 1: hash the key value

    int index = hash_function(key);

    //step 2: go to the table at the index of the hash key
    product_node * current = hash_table[index];

    //step 3:traverse the chain
    // step 3a: check each node to see if it matches the match

    while(current != nullptr)
    {
        if(current->data.matches(key))
        {
            to_fill.copy(current->data);

            return true;
        }
        current = current->next;
    }

    return false;

    // step 4: when you find a match copy into to_fill and return true
    //step 5: if you reach the end return false

}



















