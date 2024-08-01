#ifndef SQLITE_CONNECTIVITY_H
#define SQLITE_CONNECTIVITY_H

#include <sqlite3.h>
#include <iostream>
#include "DRAWPAGES.h"

bool check_sqlite_connectivity(const char* db_path) {
    sqlite3* db;
    int rc = sqlite3_open(db_path, &db);

    if (rc != SQLITE_OK) {
        //fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        drawConnectivityFalse();
        
        sqlite3_close(db);
        return false;
    }

    drawConnectivityTrue();
    sqlite3_close(db);
    return true;
}

#endif // SQLITE_CONNECTIVITY_H
