#ifndef SYSTEM_HH
#define SYSTEM_HH

class System
{
    std::vector <Order> collection;
    int maxParts;
    int currParts;
    int lastOrderDeadline;

    public:

    System(std::vector <Order> c, int maxParts);

    System();

    std::vector <Order> getCollection();

    void setCollection(std::vector <Order> collection);

    int getMaxParts();

    void setMaxParts(int maxParts);

    int getCurrParts();

    void setCurrParts(int currParts);

    int getLastOrderDeadline();

    void setLastOrderDeadLine(int lastOrderDeadline);

    void add_order(Order order);

    void print_orders();

    void save_to_file(char* filename);

    void load_from_file(char* filename);
};

#endif // SYSTEM_HH
