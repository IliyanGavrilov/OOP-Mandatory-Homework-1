#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Order.hh"
#include "System.hh"

using namespace std;

int main()
{
    System system = System();
    Order order = Order("Tyre", "TurboSquid 1478", 4, 3);
    Order order2 = Order("Steering Wheel", "Tesla Model Y", 1, 5);
    Order order3 = Order("Pedals", "ZH-123", 3, 7);
    Order order4 = Order("Transmission Gearbox", "Lamborghini Huracan", 1, 10);
    Order order5 = Order("Trunk", "Lamborghini Huracan", 1, 14);
    Order order6 = Order("Black Hood", "Bugatti Chiron", 1, 21);

    char filename[] = "Orders.txt";

    try
    {
        system.add_order(order);
        system.add_order(order2);
        system.add_order(order3);
        system.add_order(order4);
        system.add_order(order5);
        system.add_order(order6);
    } catch (int ex)
    {
        cout << "Error " << ex << ".Sorry, cannot fit your order in our schedule. We're overflown!" << endl;
    }

    try
    {
        system.save_to_file(filename);
        system.load_from_file(filename);
    } catch (int ex)
    {
        if(ex == 2)
        {
            cout << "Error " << ex << ".Error opening file" << endl;
        }
        else
        {
            cout << "Error " << ex << ".File is empty" << endl;
        }
    }

    try
    {
        system.print_orders();
    } catch (int ex)
    {
        cout << "Error " << ex << ".No orders found" << endl;
    }

    return 0;
}
