#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Order.hh"
#include "System.hh"

using namespace std;

System::System(vector <Order> c, int maxParts)
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

vector <Order> System::getCollection()
{
    return collection;
}

void System::setCollection(vector <Order> collection)
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
        cout << "Order #" << i+1 << ":" << endl;
        cout << "Part = " << collection[i].getPart() << endl;
        cout << "Serial Number = " << collection[i].getSerialNum() << endl;
        cout << "Quantity = " << collection[i].getQuantity() << endl;
        cout << "Deadline = " << collection[i].getDeadline() << endl;
    }

    int finish_orders = currParts/maxParts;
    if(finish_orders <= 0)
    {
        finish_orders = 1;
    }

    cout << "\nAll parts count: " << currParts << endl;
    cout << "Deadline for all current orders: " << lastOrderDeadline << endl;
    if(lastOrderDeadline >= finish_orders)
    {
        cout << "Last order will finished early by " << lastOrderDeadline - finish_orders << " days" << endl;
    }
    else
    {
        cout << "We're running late by " << finish_orders - lastOrderDeadline << " days" << endl;
    }
}

void System::save_to_file(char* filename)
{
    int size_c = collection.size();
    ofstream file(filename, ios::app);
    if (file.is_open())
    {
        for(int i = 0;i<size_c;i++)
        {
            file << collection[i].getPart() << ", ";
            file << collection[i].getSerialNum() << ", ";
            file << collection[i].getQuantity() << ", ";
            file << collection[i].getDeadline() << endl;
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
    ifstream file(filename);
    if(file.peek() == ifstream::traits_type::eof())
    {
        throw 3;
    }

    if (file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            vector <string> v;
            stringstream ss(line);
            while(getline(ss, line, ','))
            {
                v.push_back(line);
            }
            string part = v[0];
            string serialNum = v[1];
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
