#include "product.h"

#ifndef TABLE
#define TABLE

const int MAX = 100;

struct product_node //node where we will store our data inside of
{
    product data;
    product_node * next;
};

class table
{
    public:
    table(int size = 17);
    ~table();
    int hash_function(char * key);
    int insert(char * key, const product & input_product);
    int remove();
    int display_all();
    int display_match(const char * key);
    bool retrieve(char * key, char * match, product & to_fill);
    int copy();


    private:
    product_node ** hash_table;
    int hash_table_size;
    

};

#endif
