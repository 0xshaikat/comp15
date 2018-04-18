// Shaikat Islam
// COMP15
// Phase II
// 18-04-2018

#include <iostream>
#include <string>
#include <cstring>
#include "LinkedHashNode.h"
#include "HashMap.h"
using namespace std;

const int DEFAULT_SIZE = 128;

//default constructor
HashMap::HashMap()
{
    threshold = .75;
    max = 96;
    table_size = DEFAULT_SIZE;
    size = 0;
    table = new LinkedHashNode*[table_size];
    for (int i = 0; i < table_size; i++)
    {
        table[i] = NULL;
    }
}// end constructor

//destructor
HashMap::~HashMap()
{
    for (int i = 0; i < table_size; i++)
    {
        if(table[i] != NULL)
        {
            LinkedHashNode *prev = NULL;
            LinkedHashNode *curr = table[i];
            while(curr != NULL)
            {
                prev = curr;
                curr = curr->get_next();
                delete prev;
            }// end while
        }// end if
    }// end for
    delete []table;
}// end destructor

void HashMap::set_threshold(float t)
{
    this->threshold = t;
    max = (int)(table_size * threshold);
}// end set_threshold

string HashMap::get(string key)
{
    //hash function
    char * c = new char [key.length()+1];
    strcpy (c, key.c_str());
    int key_length = key.length();
    int i, sum;
    for (sum = 0, i = 0; i < key_length; i++)
    {
        sum += c[i];
    }
    int hash_v = sum % table_size;
    if(table[hash_v] == NULL)
    {
        return "";
    }// end if
    else
    {
        LinkedHashNode *curr = table[hash_v];
        while (curr != NULL && curr->get_key() != key)
        {
            curr = curr->get_next();
        }// end while
        if (curr == NULL)
        {
            return "";
        }// end if
        else
        {
            return curr->get_value();
        }// end else
    }// end else

}// end get

void HashMap::insert(string key, string value)
{
    //hash function
    char * c = new char [key.length()+1];
    strcpy (c, key.c_str());
    int key_length = key.length();
    int i, sum;
    for (sum = 0, i = 0; i < key_length; i++)
    {
        sum += c[i];
    }
    int hash_v = sum % table_size;
    if (table[hash_v] == NULL) {
        table[hash_v] = new LinkedHashNode(key, value);
        size++;
    }// end if
    else
    {
        LinkedHashNode *curr = table[hash_v];
        while (curr->get_next() != NULL)
        {
            curr = curr->get_next();
        }// end while
        if (curr->get_key() == key)
        {
            curr->set_value(value);
        }// end if
        else
        {
            curr->set_next(new LinkedHashNode(key, value));
            size++;
        }// end else
    }// end else
    if (size >= max)
    {
        resize();
    }// end if
}// end insert

void HashMap::remove(string key)
{
    //hash function
    char * c = new char [key.length()+1];
    strcpy (c, key.c_str());
    int key_length = key.length();
    int i, sum;
    for (sum = 0, i = 0; i < key_length; i++)
    {
        sum += c[i];
    }
    int hash_v = sum % table_size;

    if (table[hash_v] != NULL)
    {
        LinkedHashNode *prev = NULL;
        LinkedHashNode *curr = table[hash_v];
        while (curr->get_next() != NULL && curr->get_key() != key)
        {
            prev = curr;
            curr = curr->get_next();
        }// end while
        if (curr->get_key() == key)
        {
            if (prev == NULL)
            {
                LinkedHashNode *next_node = curr->get_next();
                delete curr;
                table[hash_v] = next_node;
            }// end if
            else
            {
                LinkedHashNode *next = curr->get_next();
                delete curr;
                prev->set_next(next);
            }// end else
            size--;
        }// end if
    }// end else
}// end remove

void HashMap::resize()
{
    int old_size= table_size;
    table_size *= 2;
    max = (int) (table_size * threshold);
    LinkedHashNode **old = table;
    table = new LinkedHashNode*[table_size];
    for (int i = 0; i < table_size; i++)
    {
        table[i] = NULL;
    }// end for

    size = 0;

    for (int h = 0; h < old_size; h++)
    {
        if (old[h] != NULL)
        {
            LinkedHashNode *old_one;
            LinkedHashNode *curr = old[h];
            while (curr != NULL)
            {
                insert(curr->get_key(), curr->get_value());
                old_one = curr;
                curr = curr->get_next();
                delete old_one;
            }// end while
        }// end if
    }//end for
    delete[] old;
}// end resize

int HashMap::get_size()
{
    return size;
}// end get_size
