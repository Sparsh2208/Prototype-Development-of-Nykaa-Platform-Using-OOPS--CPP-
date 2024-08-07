#include <iostream>
#include <string>
#include <map>
using namespace std;

class InvalidPasswordException : public std::runtime_error {
public:
    InvalidPasswordException(const std::string& message)
        : std::runtime_error(message) {}
};

class Nykaa {
public:
    string username;
    string password;
    int id;

    Nykaa() {
        username = "";
        password = "";
        id = 0;
    }

    Nykaa(string Username, string Password, int Id) {
        username = Username;
        // Check if the password contains special characters
        for (char c : Password) {
            if (c == '/' || c == '-' || c == '+' || c == '*') {
                throw InvalidPasswordException("Invalid password: Password cannot contain '/', '-', '+', or '*'.");
            }
        }
        password = Password;
        id = Id;
    }

    virtual void login_credentials() {
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "Id: " << id << endl;
    }
};

class Makeup : public Nykaa {
public:
    string productType;
    string brand;
    string shade;
    float price;

    Makeup() {
        productType = "";
        brand = "";
        shade = "";
        price = 0.0;
    }

    void selectProductType() {
        cout << "Choose a product type: Lipstick, Blush, Mascara" << endl;
        cout << "Enter your choice: ";
        getline(cin, productType);
    }

    void selectBrand() {
        cout << "Choose a brand: Maybelline, Loreal, MAC" << endl;
        cout << "Enter your choice: ";
        getline(cin, brand);
    }

    void selectShade() {
        cout << "Choose a shade: Red, Pink, Blue" << endl;
        cout << "Enter your choice: ";
        getline(cin, shade);
    }

    void setPrice() {
        // Set the price based on the selected product type and brand
        if (productType == "Lipstick") {
            map<string, float> brandPrice = {
                {"Maybelline", 199.99},
                {"Loreal", 189.99},
                {"MAC", 179.99}
            };

            if (brandPrice.find(brand) != brandPrice.end()) {
                price = brandPrice[brand];
            } else {
                cout << "Invalid brand selected. Defaulting to Maybelline." << endl;
                brand = "Maybelline";
                price = brandPrice["Maybelline"];
            }
        } else if (productType == "Blush") {
            map<string, float> brandPrice = {
                {"Maybelline", 99.99},
                {"Loreal", 89.99},
                {"MAC", 79.99}
            };

            if (brandPrice.find(brand) != brandPrice.end()) {
                price = brandPrice[brand];
            } else {
                cout << "Invalid brand selected. Defaulting to Maybelline." << endl;
                brand = "Maybelline";
                price = brandPrice["Maybelline"];
            }
        } else if (productType == "Mascara") {
            map<string, float> brandPrice = {
                {"Maybelline", 149.99},
                {"Loreal", 139.99},
                {"MAC", 129.99}
            };

            if (brandPrice.find(brand) != brandPrice.end()) {
                price = brandPrice[brand];
            } else {
                cout << "Invalid brand selected. Defaulting to Maybelline." << endl;
                brand = "Maybelline";
                price = brandPrice["Maybelline"];
            }
        }
    }

    void display() {
        cout << endl;
        cout << "----- Your Selection -----" << endl;
        cout << "Product Type: " << productType << endl;
        cout << "Brand: " << brand << endl;
        if (productType == "Lipstick") {
            cout << "Shade: " << shade << endl;
        }
        cout << "Price: Rs " << price << endl;
    }
};

class Haircare : public Nykaa {
public:
    string brand;
    string productType;
    float price;

    Haircare() {
        brand = "";
        productType = "";
        price = 0.0;
    }

    void selectBrand() {
        cout << "Choose a brand: Moroccanoil, Loreal" << endl;
        cout << "Enter your choice: ";
        getline(cin, brand);
    }

    void selectProductType() {
        if (brand == "Moroccanoil") {
            cout << "Choose a product type: Shampoo, Conditioner" << endl;
        } else if (brand == "Loreal") {
            cout << "Choose a product type: Serum, Mask" << endl;
        }
        cout << "Enter your choice: ";
        getline(cin, productType);
    }

    void setPrice() {
        // Set the price based on the selected brand and product type
        if (brand == "Moroccanoil") {
            map<string, float> moroccanoilPrice = {
                {"Shampoo", 399.99},
                {"Conditioner", 349.99}
            };
            if (moroccanoilPrice.find(productType) != moroccanoilPrice.end()) {
                price = moroccanoilPrice[productType];
            } else {
                cout << "Invalid product type selected for Moroccanoil. Defaulting to Shampoo." << endl;
                productType = "Shampoo";
                price = moroccanoilPrice["Shampoo"];
            }
        } else if (brand == "Loreal") {
            map<string, float> lorealPrice = {
                {"Serum", 199.99},
                {"Mask", 149.99}
            };
            if (lorealPrice.find(productType) != lorealPrice.end()) {
                price = lorealPrice[productType];
            } else {
                cout << "Invalid product type selected for Loreal. Defaulting to Serum." << endl;
                productType = "Serum";
                price = lorealPrice["Serum"];
            }
        } else {
            cout << "Invalid brand selected. Price set to 0." << endl;
            price = 0.0;
        }
    }

    void display() {
        cout << endl;
        cout << "----- Your Selection -----" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Product Type: " << productType << endl;
        cout << "Price: Rs " << price << endl;
    }
};

class Fragrance : public Nykaa {
public:
    string category;
    string fragrancenote;
    string brandname;
    float price;

    Fragrance() {
        category = "";
        fragrancenote = "";
        brandname = "";
        price = 0.0;
    }

    void selectCategory() {
        cout << "Choose a category: Men, Women, Unisex" << endl;
        cout << "Enter your choice: ";
        getline(cin, category);
    }

    void selectFragranceNote() {
        cout << "Choose a fragrance note: Aqua, Floral, Fruity, Woody, Spice" << endl;
        cout << "Enter your choice: ";
        getline(cin, fragrancenote);
    }

    void setBrand() {
        // Set the brand and price based on the selected category and fragrance note
        if (category == "Men") {
            if (fragrancenote == "Aqua") {
                brandname = "Dior";
                price = 1200.0;
            } else if (fragrancenote == "Floral") {
                brandname = "Calvin Klein";
                price = 900.0;
            } else if (fragrancenote == "Fruity") {
                brandname = "Gucci";
                price = 1100.0;
            } else if (fragrancenote == "Woody") {
                brandname = "Versace";
                price = 1000.0;
            } else if (fragrancenote == "Spice") {
                brandname = "Giorgio Armani";
                price = 950.0;
            } else {
                cout << "Invalid fragrance note selected. Brand set to none." << endl;
                brandname = "None";
                price = 0.0;
            }
        } else if (category == "Women") {
            if (fragrancenote == "Aqua") {
                brandname = "Chanel";
                price = 1500.0;
            } else if (fragrancenote == "Floral") {
                brandname = "Burberry";
                price = 1300.0;
            } else if (fragrancenote == "Fruity") {
                brandname = "Dolce & Gabbana";
                price = 1400.0;
            } else if (fragrancenote == "Woody") {
                brandname = "Tom Ford";
                price = 1800.0;
            } else if (fragrancenote == "Spice") {
                brandname = "Yves Saint Laurent";
                price = 1600.0;
            } else {
                cout << "Invalid fragrance note selected. Brand set to none." << endl;
                brandname = "None";
                price = 0.0;
            }
        } else if (category == "Unisex") {
            if (fragrancenote == "Aqua") {
                brandname = "Prada";
                price = 1350.0;
            } else if (fragrancenote == "Floral") {
                brandname = "Jo Malone";
                price = 1250.0;
            } else if (fragrancenote == "Fruity") {
                brandname = "Marc Jacobs";
                price = 1150.0;
            } else if (fragrancenote == "Woody") {
                brandname = "Armani Exchange";
                price = 950.0;
            } else if (fragrancenote == "Spice") {
                brandname = "Hugo Boss";
                price = 1050.0;
            } else {
                cout << "Invalid fragrance note selected. Brand set to none." << endl;
                brandname = "None";
                price = 0.0;
            }
        } else {
            cout << "Invalid category selected. Brand set to none." << endl;
            brandname = "None";
            price = 0.0;
        }
    }

    void display() {
        cout << endl;
        cout << "----- Your Selection -----" << endl;
        cout << "Category: " << category << endl;
        cout << "Fragrance note: " << fragrancenote << endl;
        cout << "Brand: " << brandname << endl;
        cout << "Price: Rs " << price << endl;
    }
};

class Skincare : public Nykaa {
public:
    string skintype;
    string brandname;
    float price;
    string producttype;

    Skincare() {
        skintype = "";
        brandname = "";
        producttype = "";
    }

    void selectSkinType() {
        cout << "Choose your skin type: Dry, Oily, Normal, Combination" << endl;
        cout << "Enter your choice: ";
        getline(cin, skintype);
    }

    void selectBrand() {
        cout << "Choose a brand: Loreal, Olay, Neutrogena, Cetaphil, Clinique" << endl;
        cout << "Enter your choice: ";
        getline(cin, brandname);
    }

    void selectProductType() {
        cout << "Choose a product type: Moisturizer, Toner" << endl;
        cout << "Enter your choice: ";
        getline(cin, producttype);
    }

    void display() {
        cout << endl;
        cout << "----- Your Selection -----" << endl;
        cout << "Skin Type: " << skintype << endl;
        cout << "Brand: " << brandname << endl;
        cout << "Product Type: " << producttype << endl;

        // Display the price based on the selected brand and product type
        map<string, map<string, float>> skincarePrices = {
            { "Loreal", {{"Moisturizer", 800.0}, {"Toner", 500.0}}},
            { "Olay", {{"Moisturizer", 700.0}, {"Toner", 450.0}}},
            { "Neutrogena", {{"Moisturizer", 600.0}, {"Toner", 400.0}}},
            { "Cetaphil", {{"Moisturizer", 750.0}, {"Toner", 550.0}}},
            { "Clinique", {{"Moisturizer", 900.0}, {"Toner", 600.0}}},
            { "None", {{"Moisturizer", 0.0}, {"Toner", 0.0}}} // No price for invalid selections
        };

        cout << "Price: Rs " << skincarePrices[brandname][producttype] << endl;
    }
};

class Retailstore : public Nykaa {
public:
    string cityname;
    string nearestStore;

    Retailstore() {
        cityname = "";
        nearestStore = "";
    }

    void selectCity() {
        cout << "Choose a city: Delhi, Mumbai, Bangalore, Chennai, Kolkata" << endl;
        cout << "Enter your choice: ";
        getline(cin, cityname);
    }

    void display() {
        cout << endl;
        cout << "----- Your Selection -----" << endl;
        cout << "City: " << cityname << endl;

        // Display the nearest Nykaa store based on the selected city
        map<string, string> cityToStore = {
            { "Delhi", "Nykaa Store - Connaught Place" },
            { "Mumbai", "Nykaa Store - Bandra" },
            { "Bangalore", "Nykaa Store - Indiranagar" },
            { "Chennai", "Nykaa Store - T. Nagar" },
            { "Kolkata", "Nykaa Store - South City Mall" },
            { "None", "Nykaa store not found in the selected city" }, // For invalid selections
             { "Hubli", "Nykaa store not found in the selected city" },
             { "Dharwad", "Nykaa store not found in the selected city" }
        };

        nearestStore = cityToStore[cityname];
        cout << "Nearest Nykaa store: " << nearestStore << endl;
    }
};

template <typename T>
void displayWelcomeMessage(const T& message) {
    cout << message << std::endl;
}

int main() {
    try {
        Nykaa nykaa;
        string welcomeMessage = "Welcome to Nykaa!";
        displayWelcomeMessage(welcomeMessage);
        cout << "Enter your username: ";
        getline(cin, nykaa.username);
        cout << "Enter your password: ";
        getline(cin, nykaa.password);
        // Check if the password contains special characters
        for (char c : nykaa.password) {
            if (c == '/' || c == '-' || c == '+' || c == '*') {
                throw InvalidPasswordException("Invalid password: Password cannot contain '/', '-', '+', or '*'.");
            }
        }
        cout << "Enter your id: ";
        cin >> nykaa.id;
        cin.ignore(); // Ignore the newline character left by cin

        float totalPrice = 0.0; // Variable to store the total price of all selected items
        // Apply discount based on user type
        string userType;
        cout << endl;
        cout << "Are you a First User or a Regular User? (Type 'First' or 'Regular'): ";
        getline(cin, userType);

        while (true) {
            cout << endl;
            cout << "Choose a section: Makeup, Haircare, Fragrance, Skincare, Retailstore" << endl;
            cout << "Enter your choice (type 'exit' to stop): ";
            string sectionChoice;
            getline(cin, sectionChoice);

            if (sectionChoice == "exit") {
                break; // Exit the loop if the user chooses to stop
            } else if (sectionChoice == "Makeup") {
                Makeup makeup;
                makeup.selectProductType();
                makeup.selectBrand();
                if (makeup.productType == "Lipstick") {
                    makeup.selectShade();
                }
                makeup.setPrice();
                makeup.display();
                totalPrice += makeup.price;
            } else if (sectionChoice == "Haircare") {
                Haircare haircare;
                haircare.selectBrand();
                haircare.selectProductType();
                haircare.setPrice();
                haircare.display();
                totalPrice += haircare.price;
            } else if (sectionChoice == "Fragrance") {
                Fragrance fragrance;
                fragrance.selectCategory();
                fragrance.selectFragranceNote();
                fragrance.setBrand();
                fragrance.display();
                totalPrice += fragrance.price;
            } else if (sectionChoice == "Skincare") {
                Skincare skincare;
                skincare.selectSkinType();
                skincare.selectBrand();
                skincare.selectProductType();
                skincare.display();
                totalPrice += skincare.price;
            } else if (sectionChoice == "Retailstore") {
                Retailstore retailstore;
                retailstore.selectCity();
                retailstore.display();
            } else {
                cout << "Invalid section choice. Please try again." << endl;
            }
        }

        float discountPercentage = (userType == "First") ? 0.1 : 0.05;
        float discountedPrice = totalPrice - (totalPrice * discountPercentage);

        cout << "Total Price: Rs " << totalPrice << endl;
        cout << "Discounted Price: Rs " << discountedPrice << endl;

        cout << endl;
        cout << "Thank you for using Nykaa! Happy shopping!" << endl;
    } catch (const InvalidPasswordException& e) {
        cout << "Error occurred: " << e.what() << endl;
        return 1; // Exit the program with an error code
    } catch (const exception& e) {
        cout << "Error occurred: " << e.what() << endl;
    }

    return 0;
}
