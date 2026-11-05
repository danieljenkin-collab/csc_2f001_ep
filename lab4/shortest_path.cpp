#include <iostream>
#include "shortest_path.h"

shortest_path_t::shortest_path_t(location_t* from, location_t* to): head{nullptr}, base{nullptr}, from{from}, to{to} {}

void shortest_path_t::compute(){
    if (head==nullptr){
        head=new node_t;
        head->next=nullptr;
        head->location=from;
        head->from=nullptr;
        head->from_origin=0.0;
        head->total=from->distance_to(to);
        head->visited=false;
        base=head;
    }
    base->visited=true;
    if(base->location==to){
        display();
    }else{
        for(int i=0;i<base->location->nb_neigh;i++){
            double from_origin=base->from_origin+base->location->distance_to(base->location->n[i]);
            double total=base->from_origin+base->location->n[i]->distance_to(to);
            node_t* temp = head;
            while(temp->location != base->location->n[i] && temp->next!=nullptr){
                temp=temp->next;
            }
            if(temp->location!=base->location->n[i]){
                temp->next=head;
                temp->location=base->location->n[i];
                temp->from=base;
                temp->from_origin=from_origin;
                temp->total=total;
                temp->visited=false;
                head=temp;
            }else if(temp->from_origin>from_origin){
                temp->from=base;
                temp->from_origin=from_origin;
                temp->total=total;
                temp->visited=true;
            }
        }
    }
    node_t* temp_base = head;
    base=nullptr;
    while(temp_base!=nullptr){
        if(temp_base->visited==false){
            if(base==nullptr){
                base=temp_base;
            }else if(temp_base->total<base->total){
                base=temp_base;
            }
        }
        temp_base=temp_base->next;
    }
    if(base==nullptr){
        display();
    }else{
        compute();
    }
}

void shortest_path_t::display(){
    if(base==nullptr){
        std::cout<<"Unable to find a path from " << from->name << " to " << to->name << "\n" << std::endl;
    }
    else{
        std::cout<<"Path from " << from->name << " to " << to->name << "\n" << std::endl;
        node_t* print_node = base;
        while(print_node!=nullptr){
            std::cout << print_node->location->name << std::endl;
            print_node=print_node->from;
        }
    }
}