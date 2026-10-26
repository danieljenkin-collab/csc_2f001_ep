#include <iostream>

struct location_t{
    std::string name;
    double latitude;
    double longitude;
    location_t** n;
    size_t nb_neigh;
    
    location_t(std::string name, double latitude, double longitude);
    ~location_t();

    void set_neighbors(location_t* list[]);
};