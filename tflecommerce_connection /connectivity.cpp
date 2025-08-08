#include <iostream>
#include <mysql.h>
#include <cstdlib>  
#include <stdexcept>

// Object Oriented Programming (OOP) approach to manage topics in a MySQL database

class DBManager {
    // Access specifiers
private:
    // Data members
    MYSQL *conn;  // MySQL connection object

public:
    // Constructors and destructors
    DBManager() {
        // Initialize MySQL connection
        conn = mysql_init(NULL);
        if (conn == NULL) {
            std::cerr << "mysql_init() failed\n";
            exit(EXIT_FAILURE);
        }

        if (mysql_real_connect(conn, "localhost", "root", "P@ssw0rd", "tflecommerce", 0, NULL, 0) == NULL) {
            std::cerr << "mysql_real_connect() failed\n";
            mysql_close(conn);
            exit(EXIT_FAILURE);
        }
    }

    ~DBManager() {
        mysql_close(conn);
    }

    void displayData() {
        MYSQL_RES *res;
        MYSQL_ROW row;

        // Execute SQL query to select all products
        if (mysql_query(conn, "SELECT * FROM products")) {
            std::cerr << "SELECT * FROM products failed. Error: " << mysql_error(conn) << "\n";
            return;
        }

        // Store the result set
        res = mysql_store_result(conn);
        if (res == NULL) {
            std::cerr << "mysql_store_result() failed. Error: " << mysql_error(conn) << "\n";
            return;
        }

        // Fetch and display each row
        while ((row = mysql_fetch_row(res)) != NULL) {
            std::cout << "id: " << row[0] << " name: " << row[1]
                      << " description: " << row[2] << " price:" << row[3]
                      << " stock: " << row[4] << " category_id: " << row[5] << "\n";
        }

        // Clean up
        mysql_free_result(res);
    }

    void displayData(int id) {
        MYSQL_RES *res;
        MYSQL_ROW row;

        char query[128];
        snprintf(query, sizeof(query), "SELECT * FROM products WHERE id = %d", id);

        if (mysql_query(conn, query)) {
            std::cerr << "SELECT failed. Error: " << mysql_error(conn) << "\n";
            return;
        }

        res = mysql_store_result(conn);
        if (res == NULL) {
            std::cerr << "mysql_store_result() failed. Error: " << mysql_error(conn) << "\n";
            return;
        }

        if ((row = mysql_fetch_row(res)) != NULL) {
            std::cout << "id: " << row[0] << " name: " << row[1]
                      << " description: " << row[2] << " price: " << row[3]
                      << " stock: " << row[4] << " category_id: " << row[5] << "\n";
        } else {
            std::cout << "No product found with that ID.\n";
        }

        mysql_free_result(res);
    }

    bool insertData(int id, const std::string& name, const std::string& description, double price, int stock, int category_id) {
        char query[512];

        snprintf(query, sizeof(query),
                 "INSERT INTO products(id, name, description, price, stock, category_id) VALUES (%d, '%s', '%s', %f, %d, %d)",
                 id, name.c_str(), description.c_str(), price, stock, category_id);

        if (mysql_query(conn, query)) {
            std::cerr << "INSERT failed. Error: " << mysql_error(conn) << "\n";
            return false;
        }

        return true;
    }

    bool updateData(int id, const std::string& name, const std::string& description, double price, int stock, int category_id) {
        char query[256];

        snprintf(query, sizeof(query),
                 "UPDATE products SET name = '%s', description = '%s', price = '%f', stock = '%d', category_id = '%d' WHERE id = %d",
                 name.c_str(), description.c_str(), price, stock, category_id, id);

        if (mysql_query(conn, query)) {
            std::cerr << "UPDATE products failed. Error: " << mysql_error(conn) << "\n";
            return false;
        }

        if (mysql_affected_rows(conn) == 0) {
            std::cout << "ID not found. No data updated.\n";
            return false;
        }

        return true;
    }

    bool deleteData(int id) {
        char query[256];

        snprintf(query, sizeof(query), "DELETE FROM products WHERE id = %d", id);

        if (mysql_query(conn, query)) {
            std::cerr << "DELETE FROM products failed. Error: " << mysql_error(conn) << "\n";
            return false;
        }

        if (mysql_affected_rows(conn) == 0) {
            std::cout << "ID not found. No data deleted.\n";
            return false;
        }

        return true;
    }
};


int main() {
    // Create an instance of DBManager
    DBManager *ptrDbManager = NULL;
    ptrDbManager = new DBManager();
    int choice;

     do{
    // Display menu options
    std::cout << "Menu:\n";
    std::cout << "1. Display all products\n";
    std::cout << "2. Display a specific products\n";
    std::cout << "3. Insert a new products\n";
    std::cout << "4. Update a products\n";
    std::cout << "5. Delete a product\n";
    std::cout << "6. Exit\n";
    
    
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    // Handle user input and call appropriate methods on dbManager
    
    switch (choice) {
        case 1:
            ptrDbManager->displayData();
            break;

        case 2: {
            int id;
            std::cout << "Enter product ID to display: ";
            std::cin >> id;
            ptrDbManager->displayData(id);           
            std::cin.ignore();

            break;
        }

        case 3: {
            std::string name, description;
            double price;
            int id, stock, category_id;
            std::cout << "\nEnter id: ";
            std::cin >> id ;
            std::cin.ignore();
            std::cout << "\nEnter name: ";
            std::getline(std::cin,name);
            std::cout << "\nEnter description: " ;
            std::getline(std::cin,description);
            std::cout << "\nEnter price: " ;
            std::cin >> price;
            std::cout << "\nEnter stock: " ;
            std::cin >> stock;
            std::cout << "\nEnter category_id: " ;
            std::cin >> category_id;

            if (ptrDbManager->insertData(id, name, description, price, stock, category_id)) {
                std::cout << "data inserted successfully.\n";
            } else {
                std::cout << "Failed to insert data.\n";
            }
            break;
        }

        case 4: {
            std::string name, description;
            double price;
            int id, stock, category_id;
            std::cout << "Enter id: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Enter name: ";
            std::getline(std::cin,name);
            std::cout << "Enter description: ";
            std::getline(std::cin,description);
            std::cout << "Enter price: ";
            std::cin >> price;
            std::cout << "Enter stock: ";
            std::cin >> stock;
            std::cout << "Enter category_id: ";
            std::cin >> category_id;

            if (ptrDbManager->updateData(id, name, description, price, stock, category_id)) {
                std::cout << "Topic updated successfully.\n";
            } else {
                std::cout << "Failed to update topic.\n";
            }
            break;
        }

        case 5: {
            int id;
            std::cout << "Enter product ID to delete: ";
            std::cin >> id;
            if (ptrDbManager->deleteData(id)) {
                std::cout << "Product deleted successfully.\n";
            } else {
                std::cout << "Failed to delete product.\n";
            }
            break;
        }

        case 6:
            return 0;  // Exit the program

        default:
            std::cout << "Invalid choice. Please try again.\n";
    }
}
while(choice!=6);
return 0;
    

}

// g++ connectivity.cpp -o conn.exe `mysql_config --cflags --libs`
// 0./conn.exe
