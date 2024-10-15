#include <iostream>
#include <cstring>
#include <iomanip>
#define MAXSIZE 100
#define TABLE_SIZE 10

typedef struct
{
    const char key[MAXSIZE];
    int value;
} Hash_table;

Hash_table *my_table[TABLE_SIZE];

int hash_function(const char *name)
{
    int n = strnlen(name, MAXSIZE);
    int hash_value = 0;
    for (int i = 0; i < n; i++)
    {
        hash_value = (hash_value + name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

// filling the hash table
void my_hash_table()
{
    for (int i = 0; i <= TABLE_SIZE; i++)
    {
        my_table[i] = nullptr;
    }
}

// print the content of the hash table
void print_table()
{
    std::cout << "Start" << std::endl;
    for (int i = 0; i <= TABLE_SIZE; i++)
    {
        if (my_table[i] == nullptr)
        {
            std::cout << std::setw(15) << "empty slot : " << i << std::endl;
        }
        else
        {
            std::cout << std::setw(10) << my_table[i]->key << " : " << i << std::endl;
        }
    }
    std::cout << "End" << std::endl;
}

// insert data into the table
bool insert(Hash_table *table)
{
    if (table == nullptr)
    {
        return false;
    }
    int index = hash_function(table->key);
    if (my_table[index] == nullptr)
    {
        my_table[index] = table;
        return true;
    }
    return false;
}

// Check value in hashtable
Hash_table *check(char *name)
{
    int index = hash_function(name);
    if (my_table[index] != nullptr && strncmp(my_table[index]->key, name, TABLE_SIZE) == 0)
    {
        return my_table[index];
    }
    else
    {
        return nullptr;
    }
}
// print the result of check
void check_result(Hash_table *name)
{
    if (check(name))
    {
        std::cout << name << " found in the hash table" << std::endl;
    }
    else
    {
        std::cout << name << " not found" << std::endl;
    }
}

int main()
{
    my_hash_table();
    print_table();
    Hash_table table_1 = {.key = "price", .value = 300};
    Hash_table table_2 = {.key = "rate", .value = 3};
    Hash_table table_3 = {.key = "reduction", .value = -70};
    insert(&table_1);
    insert(&table_2);
    insert(&table_3);
    print_table();

    Hash_table *x = check("price");
    Hash_table *y = check("prices");
    check_result(x);
    check_result(y);
    /* std::cout << "Steve : " << hash_function("Steve") << std::endl;
    std::cout << "Keith : " << hash_function("Keith") << std::endl;
    std::cout << "Ryan : " << hash_function("Ryan") << std::endl;
    std::cout << "Scott : " << hash_function("Scott") << std::endl;
    std::cout << "Brian : " << hash_function("Brian") << std::endl; */

    return 0;
}