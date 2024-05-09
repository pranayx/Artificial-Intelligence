#include <iostream>
#include <string>
#include <map>
#include <algorithm> // for std::transform

using namespace std;

// Define a Product struct to hold product information
struct Product {
    string name;
    float price;
    string description;
    string features;
    bool available;
    string warranty;
};

// Function to display product information
void displayProductInfo( Product& product) {
    cout << "Description: " << product.description << endl;
    cout << "Features: " << product.features << endl;
    cout << "Availability: " << (product.available ? "Available" : "Out of stock") << endl;
    cout << "Warranty: " << product.warranty << endl;
}

// Function to convert a string to lowercase
string toLowercase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    // Create a map to store products
    map<string, Product> products;

    // Populate some sample products
    products["laptop"] = {"Laptop", 999.99, "High-performance laptop with SSD and 16GB RAM", "SSD, 16GB RAM, High-performance", true, "1-year warranty"};
    products["smartphone"] = {"Smartphone", 599.99, "Latest smartphone with dual camera and OLED display", "Dual camera, OLED display", true, "1-year warranty"};
    products["headphones"] = {"Headphones", 149.99, "Wireless noise-canceling headphones with long battery life", "Wireless, Noise-canceling, Long battery life", false, "1-year warranty"};

    // Initialize variables for user input and context
    string userInput;
    string currentProduct;

    cout << "Welcome to the Electronics Shop! How can I assist you today?" << endl;

    // Main interaction loop
    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        // Convert user input to lowercase
        string userInputLower = toLowercase(userInput);

        // Check if the user wants to quit
        if (userInputLower == "quit") {
            cout << "Goodbye! Have a great day." << endl;
            break;
        }

        // Check if the user greeted the bot
        if (userInputLower.find("hi") != string::npos || userInputLower.find("hello") != string::npos) {
            cout << "Bot: Hi there! How can I assist you today?" << endl;
            continue;
        }

        // Check if the user mentioned a product
        for ( auto pair : products) {
            if (userInput.find(pair.first) != string::npos) {
                currentProduct = pair.first;
                displayProductInfo(pair.second);
                break;
            }
        }

        if(userInput.find("products")!=string::npos){
            for(auto pair: products){
                cout<<pair.first<<endl;
            }
        }


        // Check if the user asked for price
        if (userInput.find("price") != string::npos) {
            if (!currentProduct.empty()) {
                cout << "The price of " << products[currentProduct].name << " is $" << products[currentProduct].price << endl;
            } else {
                cout << "Please specify a product first." << endl;
            }
        }

        // Check if the user asked for features
        if (userInput.find("features") != string::npos) {
            if (!currentProduct.empty()) {
                cout << "The features of " << products[currentProduct].name << " are: " << products[currentProduct].features << endl;
            } else {
                cout << "Please specify a product first." << endl;
            }
        }

        // Check if the user asked for availability
        if (userInput.find("availability") != string::npos) {
            if (!currentProduct.empty()) {
                cout << "The availability of " << products[currentProduct].name << " is: " << (products[currentProduct].available ? "Available" : "Out of stock") << endl;
            } else {
                cout << "Please specify a product first." << endl;
            }
        }

        // Check if the user asked for warranty information
        if (userInput.find("warranty") != string::npos) {
            if (!currentProduct.empty()) {
                cout << "The warranty of " << products[currentProduct].name << " is: " << products[currentProduct].warranty << endl;
            } else {
                cout << "Please specify a product first." << endl;
            }
        }

        // If no specific action was triggered, reply with a generic message
       // else if (currentProduct.empty() && userInput.find("price") == string::npos && userInput.find("features") == string::npos && userInput.find("availability") == string::npos && userInput.find("warranty") == string::npos) {
           // cout << "I can't reply to that, please be more specific." << endl;
        //}
    }

    return 0;
}
