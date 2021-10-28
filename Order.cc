#include <iostream>
#include <string>
#include "Order.hh"

Order::Order()
{
    Order("", "", -1, -1);
}
Order::Order(std::string part, std::string serialNum, int quantity, int deadline)
{
    this->part = part;
    this->serialNum = serialNum;
    this->quantity = quantity;
    this->deadline = deadline;
}

std::string Order::getPart()
{
    return part;
}

void Order::setPart(std::string part)
{
    this->part = part;
}

std::string Order::getSerialNum()
{
    return serialNum;
}

void Order::setSerialNum(std::string serialNum)
{
    this->serialNum = serialNum;
}

int Order::getQuantity()
{
    return quantity;
}

void Order::setQuantity(int quantity)
{
    this->quantity = quantity;
}

int Order::getDeadline()
{
    return deadline;
}

void Order::setDeadline(int deadline)
{
    this->deadline = deadline;
}
