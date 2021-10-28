#include <iostream>
#include <string>
#include "Order.hh"

using namespace std;

Order::Order()
{
    Order("", "", -1, -1);
}
Order::Order(string part, string serialNum, int quantity, int deadline)
{
    this->part = part;
    this->serialNum = serialNum;
    this->quantity = quantity;
    this->deadline = deadline;
}

string Order::getPart()
{
    return part;
}

void Order::setPart(string part)
{
    this->part = part;
}

string Order::getSerialNum()
{
    return serialNum;
}

void Order::setSerialNum(string serialNum)
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
