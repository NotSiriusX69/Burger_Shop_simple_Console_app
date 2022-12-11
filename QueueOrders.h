#ifndef BURGER_SHOP_QUEUEORDERS_H
#define BURGER_SHOP_QUEUEORDERS_H

#include <iostream>
#include "ClientStruct.h"
#include "BurgerStruct.h"

#define MAX_BURGERS_ORDER 15
#define MAX_QUEUE 30

struct Order {
    string ClientName;
    Burger burgers_order[MAX_BURGERS_ORDER];
    int TotalPrice = 0;
    int NbOfBurgersOrder = 0;
    int PlaceInQUEUE = 0;
};

//Queue that will contain clients orders
struct QUEUE {
    Order orders_array[MAX_QUEUE];
    int first_order;
    int last_order;
    int NbOfOrders;
};

void InitializeQUEUE(QUEUE *q) {
    q->first_order = 0;
    q->last_order = MAX_QUEUE - 1;
    q->NbOfOrders = 0;
}

bool isEmpty(QUEUE *q) {
    return (q->NbOfOrders == 0);
}

bool isFull(QUEUE *q) {
    return (q->NbOfOrders == MAX_QUEUE);
}

Order AddToQueue(QUEUE *&q, Order &order, Client client, Burgers *burgers) {

    Order Order;
    short BurgerOrder;
    Burger burger;
    bool isOrdering = true;

    order.ClientName = client.user_name;
    //Check if Client name is already in Queue
    for (int i = 0; i < q->NbOfOrders; i++) {
        if (q->orders_array[i].ClientName == order.ClientName) {
            cout << endl;
            cout << "You have already Ordered. Please wait for your order " << endl;
            cout << endl;
            isOrdering = false;
            break;
        } else
            isOrdering = true;
    }

    if (burgers->NbOfBurgers == 0) {
        cout << endl;
        cout << "No Burgers available";
        isOrdering = false;
    }

    while (isOrdering) {

        PrintBurgers(burgers);
        burger = GetBurgerByName(burgers);

        order.TotalPrice += burger.price;
        order.burgers_order[order.NbOfBurgersOrder] = burger;
        order.NbOfBurgersOrder++;

        cout << "Do you want to add more burgers?\n"
             << "1) Yes\n"
             << "2) No\n";
        cout << "Enter choice: ";
        cout << endl;

        do {
            cin >> BurgerOrder;
            cout << endl;

            if (BurgerOrder != 1 && BurgerOrder != 2) {
                cout << "Enter a valid Value: ";
                cout << endl;
            }
        } while (BurgerOrder != 1 && BurgerOrder != 2);
        if (BurgerOrder == 2) {
            cout << "Your order have been registered!" << endl;
            if (isFull(q)) {
                cout << "Queue is full, please be patient" << endl;
            }
            q->last_order = (1 + q->last_order) % MAX_QUEUE;
            q->orders_array[q->last_order] = order;
            q->NbOfOrders++;
            order.PlaceInQUEUE += q->NbOfOrders;
            return order;
        }
    }
    return order;
}

bool Dequeue(QUEUE *&q, Order order) {
    if (isEmpty(q)) {
        cout << "Queue is empty, contact staff for further info" << endl;
        return false;
    }
    if (order.PlaceInQUEUE != 1) {
        cout << endl;
        cout << "You either didn't Order or your order is still in queue!\n";
        cout << endl;
        return false;
    }
    cout << endl;
    cout << "Your Order is Done!" << endl;
    cout << endl;
    q->first_order = (1 + q->first_order) % MAX_QUEUE;
    q->NbOfOrders--;
    for (int i = 0; i < q->NbOfOrders; i++) {
        if (order.ClientName == q->orders_array[i].ClientName) {
            order.PlaceInQUEUE--;
        }
    }
    return true;
}

bool PrintQUEUE(QUEUE *q) {
    int qFirstOrder = q->first_order, qLastOrder = q->last_order;
    if (isEmpty(q)) {
        cout << endl;
        cout << "QUEUE Is Empty" << endl;
        cout << endl;
        return false;
    }

    if (qFirstOrder <= qLastOrder) {

        cout << "QUEUE\n"
             << "-----" << endl;

        for (int i = qFirstOrder; i <= qLastOrder; i++) {
            cout << "Client name: " << q->orders_array[i].ClientName << " " << endl;
            cout << "TotalPrice: " << q->orders_array[i].TotalPrice << "$ " << endl;
            cout << "Place: " << q->NbOfOrders << " " << endl;
        }
    } else {
        for (int i = qFirstOrder; i <= MAX_QUEUE - 1; i++) {
            cout << "Client name: " << q->orders_array[i].ClientName << " " << endl;
            cout << "TotalPrice: " << q->orders_array[i].TotalPrice << "$ " << endl;
            cout << "Place: " << q->NbOfOrders << " " << endl;
        }
        for (int i = 0; i <= qLastOrder; i++) {
            cout << "Client name: " << q->orders_array[i].ClientName << " " << endl;
            cout << "TotalPrice: " << q->orders_array[i].TotalPrice << "$ " << endl;
            cout << "Place: " << q->NbOfOrders << " " << endl;
        }
        return true;
    }
    return false;
}

Order getOrderThroughLogin(QUEUE *queue, Client client) {

    Order order;
    int res = 1;

    for (int i = 0; i < queue->NbOfOrders; i++) {
        res = queue->orders_array[i].ClientName.compare(client.user_name);
        if (res == 0)
            return queue->orders_array[i];
    }
    return order;

}

void DisplayOrder(Order order, QUEUE *q) {

    if (order.NbOfBurgersOrder == 0)
        cout << "You haven't Ordered yet!\n";
    else {
        cout << endl;
        cout << "|-----------Order-----------|" << endl;
        cout << "Client name:       " << order.ClientName << endl;
        cout << "Burgers names:     ";
        for (int i = 0; i < order.NbOfBurgersOrder; i++) {
            cout << order.burgers_order[i].name << " ";
        }
        cout << endl;
        cout << "Total Price:       " << order.TotalPrice << "$" << endl;
        cout << "Number of burgers: " << order.NbOfBurgersOrder << endl;
        cout << "Number of Orders:  " << q->NbOfOrders << endl;
        cout << "Place in Queue:    " << order.PlaceInQUEUE << endl;
        cout << "|-----------Order-----------|" << endl;
        cout << endl;
    }
}

#endif
