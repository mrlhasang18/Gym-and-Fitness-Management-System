#ifndef DIET_DATABASE_H
#define DIET_DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <graphics.h>

// Function to access data from diet1 table

void access_diet1_data(const char* db_name) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *sql = "SELECT protein, carbohydrates, fats FROM diet1;";
    int rc;

    // Open the database
    rc = sqlite3_open(db_name, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    // Prepare the SQL statement
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    // Initialize graphics mode
    //int gd = DETECT, gm;
    //initgraph(&gd, &gm, NULL);
    int x1 = 620, y = 224, x2 = 838 , x3 =  1058; // Starting coordinates for text output


    // Execute the SQL statement and print the results
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        const char *protein = (const char*)sqlite3_column_text(stmt, 0);
        const char *carbohydrates = (const char*)sqlite3_column_text(stmt, 1);
        const char *fats = (const char*)sqlite3_column_text(stmt, 2);
        
        // Prepare the text to be displayed
        char output1[256];
        char output2[256];
        char output3[256];
        
        snprintf(output1, sizeof(output1), "%s", protein);
        snprintf(output2, sizeof(output2), "%s", carbohydrates);
        snprintf(output3, sizeof(output3), "%s", fats);
        
        // Output the text using outtextxy
        
        outtextxy(x1, y, output1);
        outtextxy(x2, y, output2);
        outtextxy(x3, y, output3);
        
        
        y += 49; // Move down for the next line of text
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Execution failed: %s\n", sqlite3_errmsg(db));
    }

    // Finalize the statement and close the database
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    // Wait for a key press
    // Close the graphics mode
}


void access_diet2_data(const char* db_name) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *sql = "SELECT protein, carbohydrates, fats FROM diet2;";
    int rc;

    // Open the database
    rc = sqlite3_open(db_name, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    // Prepare the SQL statement
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    // Initialize graphics mode
    //int gd = DETECT, gm;
    //initgraph(&gd, &gm, NULL);
    int x1 = 620, y = 224, x2 = 838 , x3 =  1058; // Starting coordinates for text output


    // Execute the SQL statement and print the results
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        const char *protein = (const char*)sqlite3_column_text(stmt, 0);
        const char *carbohydrates = (const char*)sqlite3_column_text(stmt, 1);
        const char *fats = (const char*)sqlite3_column_text(stmt, 2);
        
        // Prepare the text to be displayed
        char output1[256];
        char output2[256];
        char output3[256];
        
        snprintf(output1, sizeof(output1), "%s", protein);
        snprintf(output2, sizeof(output2), "%s", carbohydrates);
        snprintf(output3, sizeof(output3), "%s", fats);
        
        // Output the text using outtextxy
        
        outtextxy(x1, y, output1);
        outtextxy(x2, y, output2);
        outtextxy(x3, y, output3);
        
        
        y += 49; // Move down for the next line of text
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Execution failed: %s\n", sqlite3_errmsg(db));
    }

    // Finalize the statement and close the database
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    // Wait for a key press
    // Close the graphics mode
}

void access_diet3_data(const char* db_name) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *sql = "SELECT protein, carbohydrates, fats FROM diet3;";
    int rc;

    // Open the database
    rc = sqlite3_open(db_name, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    // Prepare the SQL statement
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    // Initialize graphics mode
    //int gd = DETECT, gm;
    //initgraph(&gd, &gm, NULL);
    int x1 = 620, y = 224, x2 = 838 , x3 =  1058; // Starting coordinates for text output


    // Execute the SQL statement and print the results
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        const char *protein = (const char*)sqlite3_column_text(stmt, 0);
        const char *carbohydrates = (const char*)sqlite3_column_text(stmt, 1);
        const char *fats = (const char*)sqlite3_column_text(stmt, 2);
        
        // Prepare the text to be displayed
        char output1[256];
        char output2[256];
        char output3[256];
        
        snprintf(output1, sizeof(output1), "%s", protein);
        snprintf(output2, sizeof(output2), "%s", carbohydrates);
        snprintf(output3, sizeof(output3), "%s", fats);
        
        // Output the text using outtextxy
        
        outtextxy(x1, y, output1);
        outtextxy(x2, y, output2);
        outtextxy(x3, y, output3);
        
        
        y += 49; // Move down for the next line of text
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Execution failed: %s\n", sqlite3_errmsg(db));
    }

    // Finalize the statement and close the database
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    // Wait for a key press
    // Close the graphics mode
}

#endif // DIET_DATABASE_H
