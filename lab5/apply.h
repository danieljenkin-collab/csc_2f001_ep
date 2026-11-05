#include <iostream>

void error(std::string str) __attribute__((noreturn));

struct list_t;

struct node_t{
    virtual node_t* eval();
    virtual node_t* apply(list_t* list);
    virtual std::string to_string();
    virtual list_t* as_list();
};

struct integer_t : node_t{
    uintptr_t value;
    integer_t(uintptr_t value) : value{value}{};

    std::string to_string();
};

struct list_t : node_t{
    node_t** elements;
    size_t nb_elements;
    size_t capacity;

    list_t();

    list_t* as_list();
    size_t size();
    node_t* at(size_t i);
    void set_at(size_t i, node_t* value);
    void append(node_t* value);
    std::string to_string();
};

struct keyword_t : node_t{
    std::string id;

    keyword_t(std::string id);

    std::string to_string();
};

struct add_t : public keyword_t{
    add_t();
};