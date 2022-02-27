#include <bits/stdc++.h>

class Billing{
    struct Item{
        std::string item_name;
        int item_price;
        int quantity;
    };

    std::vector<Item> order_items;
    double bill_amount;
    void claculateBillAmount();

public:
    void addItem(std::string , double item_price, int quantity);
    void displayBill();
    void payByCash();
    void payByCreditCard();
    void payByDebitCard();
};

void Billing::addItem(std::string item_name, double item_price, int quantity){
    Item item = {item_name, item_price, quantity};
    order_items.push_back(item);
}

void Billing::claculateBillAmount(){
    bill_amount=0;

    for(auto item_iterator:order_items){
        bill_amount += item_iterator.item_price;
    }
}

void Billing::displayBill(){
    std::cout << "Items\t\tPrice\t\tQuantity\n\n";

    for(auto item_iterator:order_items){
        std::cout << item_iterator.item_name << "\t\t"
                << item_iterator.item_price << "\t\t"
                << item_iterator.quantity<< "\n\n";
    }

    this->claculateBillAmount();
    std::cout << "Total Amount\t" << bill_amount << "\n\n";
}

void Billing::payByCash(){
    std::cout << bill_amount << " paid in cash\n";
}

void Billing::payByCreditCard(){
    std::cout << bill_amount << " paid by Credit card\n";
}

void Billing::payByDebitCard(){
    std::cout << bill_amount << " paid by Debit card\n";
}

int main(){
    //declaration of an object
    Billing bill;

    //Adding order items to bill with name, amount and quantity
    bill.addItem("Bread", 50.00, 2);
    bill.addItem("Peanuts", 100.00, 1);
    bill.addItem("Honey", 50.00, 1);

    //Display bill with item list and total amount
    bill.displayBill();

    //Payment process by cash
    bill.payByCash();

    //Payment process by credit card
    bill.payByCreditCard();

    //Payment process by debit card
    bill.payByDebitCard();

    return 0;
}
