#include <iostream>
#include "location.h"
#include <numbers>
#include <cmath>

location_t::location_t(std::string name, double latitude, double longitude) : name{name}, latitude{latitude}, longitude{longitude}, nb_neigh{0} {n = new location_t*[0];}
location_t::~location_t(){
    delete[] n;
}
void location_t::set_neighbors(location_t* list[]){
    size_t i=0;
    while(list[i]!=nullptr){
        i++;
    }
    nb_neigh=i;
    delete[] n;
    n = new location_t*[nb_neigh];
    for(size_t j=0;j<nb_neigh;j++){
        n[j]=list[j];
    }
}

double location_t::distance_to(location_t* to){
    return 6378 * (std::numbers::pi/2 - std::asin(std::sin(to->latitude) * std::sin(latitude) + std::cos(to->longitude - longitude) * std::cos(to->latitude) * std::cos(latitude)));
}
