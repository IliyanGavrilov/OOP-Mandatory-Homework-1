#ifndef ORDER_HH
#define ORDER_HH

class Order
{
    std::string part;
    std::string serialNum;
    int quantity;
    int deadline;

    public:

    Order();

    Order(std::string part, std::string serialNum, int quantity, int deadline);

    std::string getPart();

    void setPart(std::string part);

    std::string getSerialNum();

    void setSerialNum(std::string serialNum);

    int getQuantity();

    void setQuantity(int quantity);

    int getDeadline();

    void setDeadline(int deadline);
};

#endif // ORDER_HH
