#include <sqlite3.h>
#include <iostream>

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("mydatabase.db", &db);

    if (rc == SQLITE_OK) {
        std::cout << "Connected to database successfully!" << std::endl;

        // ... your SQLite operations here ...

        sqlite3_close(db);
    } else {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    return 0;
}
