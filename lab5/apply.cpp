#include <iostream>
#include "apply.h"

void error(std::string str) {
  std::cout << "Error: " << str << std::endl;
  exit(1);
}

//node_t:
node_t* node_t::eval() {return this;}

node_t* node_t::apply(list_t* list) {error("Node is an integer or list");}

std::string node_t::to_string(){return "???";} //std::cout just prints in the console, to return a string you must use return

list_t* node_t::as_list(){error("Node is not necessarily a list");}

uintptr_t node_t::int_value(){error("Node is not an integer");}

//integer_t:
std::string integer_t::to_string(){return std::to_string(value);}
uintptr_t integer_t::int_value(){return value;}


//list_t:
list_t::list_t(): elements{nullptr}, nb_elements{0}, capacity{0}{}

list_t* list_t::as_list(){return this;}

size_t list_t::size(){return nb_elements;}

node_t* list_t::at(size_t i){if(i<nb_elements){return elements[i];}else{error("index geq size of list");}}

void list_t::set_at(size_t i, node_t* value){if(i<nb_elements){elements[i]=value;}else{error("index geq size of list");}}

void list_t::append(node_t* value){
  if (nb_elements==capacity){
    if(capacity==0){capacity+=1;}
    else{capacity*=2;}
    node_t** n =new node_t*[capacity];
    for(size_t i=0;i<nb_elements;i++){
      n[i]=elements[i];
    }
    n[nb_elements]=value; //we dont free memory (using delete) in this lab
    elements=n;
  }else{
    elements[nb_elements]=value;
  }
  nb_elements++;
}

std::string list_t::to_string(){
  std::string s="(";
  for(size_t i=0; i<nb_elements; i++){
    if(i==0){s += elements[0]->to_string();}
    else{s+=(' ' + elements[i]->to_string());}
  }
  s+=')';
  return s;
}

node_t* list_t::eval(){
  if(nb_elements==0){error("empty list");}
  return at(0)->eval()->apply(this);
}

//keyword_t

keyword_t::keyword_t(std::string id) : id{id} {}

std::string keyword_t::to_string(){return ("<" + id + ">");}

//add_t

add_t::add_t() : keyword_t("+"){}
node_t* add_t::apply(list_t* list){
  integer_t* i = new integer_t(0);
  for(size_t n=1;n<list->nb_elements; n++){
    i->value+=list->at(n)->eval()->int_value();
  }
  return i;
}