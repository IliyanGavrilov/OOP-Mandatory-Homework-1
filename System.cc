#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Order.hh"
#include "System.hh"

System::System(std::vector <Order> c, int maxParts)
{
    this->collection = c;
    this->maxParts = maxParts;
    this->currParts = 0;
    this->lastOrderDeadline = 0;
}

System::System()
{
    this->maxParts = 30;
    this->currParts = 0;
    this->lastOrderDeadline = 0;
}

std::vector <Order> System::getCollection()
{
    return collection;
}

void System::setCollection(std::vector <Order> collection)
{
    this->collection = collection;
}

int System::getMaxParts()
{
    return maxParts;
}

void System::setMaxParts(int maxParts)
{
    this->maxParts = maxParts;
}

int System::getCurrParts()
{
    return currParts;
}

void System::setCurrParts(int currParts)
{
    this->currParts = currParts;
}

int System::getLastOrderDeadline()
{
    return lastOrderDeadline;
}

void System::setLastOrderDeadLine(int lastOrderDeadline)
{
    this->lastOrderDeadline = lastOrderDeadline;
}

void System::add_order(Order order)
{
    if(currParts + order.getQuantity() <= order.getDeadline() * maxParts)
    {
        collection.push_back(order);
        currParts += order.getQuantity();
        lastOrderDeadline = order.getDeadline();
    }
    else
    {
        throw 1;
    }
}

void System::print_orders()
{
    int size_c = collection.size();
    if(size_c == 0)
    {
        throw 4;
    }
    for(int i = 0;i<size_c; i++)
    {
        std::cout << "Order #" << i+1 << ":" << std::endl;
        std::cout << "Part = " << collection[i].getPart() << std::endl;
        std::cout << "Serial Number = " << collection[i].getSerialNum() << std::endl;
        std::cout << "Quantity = " << collection[i].getQuantity() << std::endl;
        std::cout << "Deadline = " << collection[i].getDeadline() << std::endl;
    }

    int finish_orders = currParts/maxParts;
    if(finish_orders <= 0)
    {
        finish_orders = 1;
    }

    std::cout << "\nAll parts count: " << currParts << std::endl;
    std::cout << "Deadline for all current orders: " << lastOrderDeadline << std::endl;
    if(lastOrderDeadline >= finish_orders)
    {
        std::cout << "Last order will finished early by " << lastOrderDeadline - finish_orders << " days" << std::endl;
    }
    else
    {
        std::cout << "We're running late by " << finish_orders - lastOrderDeadline << " days" << std::endl;
    }
}

void System::save_to_file(char* filename)
{
    int size_c = collection.size();
    std::ofstream file(filename, std::ios::app);
    if (file.is_open())
    {
        for(int i = 0;i<size_c;i++)
        {
            file << collection[i].getPart() << ", ";
            file << collection[i].getSerialNum() << ", ";
            file << collection[i].getQuantity() << ", ";
            file << collection[i].getDeadline() << std::endl;
        }

        file.close();
    }
    else
    {
        throw 2;
    }
}

void System::load_from_file(char* filename)
{
    std::ifstream file(filename);
    if(file.peek() == std::ifstream::traits_type::eof())
    {
        throw 3;
    }

    if (file.is_open())
    {
        std::string line;
        while(getline(file, line))
        {
            std::vector <std::string> v;
            std::stringstream ss(line);
            while(getline(ss, line, ','))
            {
                v.push_back(line);
            }
            std::string part = v[0];
            std::string serialNum = v[1];
            int quantity = stoi(v[2]);
            int deadline = stoi(v[3]);

            Order order = Order(part, serialNum, quantity, deadline);
            currParts += quantity;
            lastOrderDeadline = deadline;
            collection.push_back(order);
        }
        file.close();
    }
    else
    {
        throw 2;
    }
}
