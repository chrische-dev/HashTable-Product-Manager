#include <fstream>
#include <iostream>
#include <cstring>
#include "table.h"
#include "product.h"
using namespace std;





int main()
{
    int choice = 0;

    char item_buffer[MAX]; //dummy arrays to get user input and send it to a function in my class
    char description_buffer[MAX]; // have to use dummy arrays because the data memebers are in a class and main does not have acess to them
    char category_buffer[MAX];
    char type_buffer[MAX];
    char price_buffer[MAX];
    char quantity_buffer[MAX];
    char seller_id_buffer[MAX];
    char shop_name_buffer[MAX];
    bool sold;
    product new_product;

    table product_table;



    ifstream file_in;
    file_in.open("product_db.txt");


    if(!file_in)
    {
        cout <<"error" <<endl; //error check text file
    }
    else
    {
        while(!file_in.eof())
        {

            file_in.get(item_buffer, MAX, '|'); 
            file_in.ignore(MAX, '|');

            file_in.get(description_buffer, MAX, '|');
            file_in.ignore(MAX, '|');

            file_in.get(category_buffer, MAX, '|');
            file_in.ignore(MAX, '|');

            file_in.get(type_buffer, MAX, '|');
            file_in.ignore(MAX, '|');

            file_in.get(price_buffer, MAX, '|');
            file_in.ignore(MAX, '|');

            file_in.get(quantity_buffer, MAX ,'|');
            file_in.ignore(MAX,'|');

            file_in.get(seller_id_buffer, MAX, '|');
            file_in.ignore(MAX, '|');

            file_in.get(shop_name_buffer, MAX, '\n');
            file_in.ignore(MAX,'\n');

            new_product.copy(item_buffer, description_buffer, category_buffer, type_buffer, price_buffer, quantity_buffer,
                    seller_id_buffer, shop_name_buffer, false); //copy data from the text file

            product_table.insert(category_buffer, new_product); //inserting data in hashtable

        }
        file_in.close();

        menu(choice);
        while(choice != 5) 
        {
            if(choice == 1) //allow user to insert data into text file
            {

                cout << "What is the name of the item:" << endl;
                cin.get(item_buffer, MAX, '\n');
                cin.ignore(MAX,'\n');

                cout << "What is the description of the item:" <<endl;
                cin.get(description_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');

                cout << "What is the category:" << endl;
                cin.get(category_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');

                cout << "What is the type:" <<endl;
                cin.get(type_buffer, MAX ,'\n');
                cin.ignore(MAX, '\n');

                cout << "What is the price:" <<endl;
                cin.get(price_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');

                cout << "What is the qauntity:" <<endl;
                cin.get(quantity_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');

                cout << "What is the seller:" << endl;
                cin.get(seller_id_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');

                cout << "What is the shops name:" <<endl;
                cin.get(shop_name_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');


                new_product.copy(item_buffer, description_buffer, category_buffer, type_buffer, price_buffer, quantity_buffer,
                        seller_id_buffer, shop_name_buffer, false);

                product_table.insert(category_buffer, new_product);
            }

            if(choice == 2)
            {
                product_table.display_all();
            }

            if(choice == 3)
            {
                cout << "What is the category you want to search for:" <<endl;
                cin.get(category_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');

                product_table.display_match(category_buffer);
            }
            if(choice == 4)
            {
                cout <<"What is the category you want to retrieve:" << endl;
                cin.get(category_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');

                cout <<"What is the items name you want to retrieve:" <<endl;
                cin.get(item_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');

                product to_fill;

                bool match = product_table.retrieve(category_buffer, item_buffer, to_fill);
                
                if(match == true)
                {
                    cout <<"retrieval successful" <<endl;
                    to_fill.display();
                }
                else
                {
                    cout << "no match found" <<endl;
                }

            }

            menu(choice);

        }



        return 0;
    }
}
