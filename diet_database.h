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

void access_Fitness1_data(const char* db_name, int c) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *sql = "SELECT count1, count2, count3, count5, coutn6 FROM fitness1;";
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
    int x = 92, y = 190; // Starting coordinates for text output


    // Execute the SQL statement and print the results
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        const char *count1 = (const char*)sqlite3_column_text(stmt, 0);
        const char *count2 = (const char*)sqlite3_column_text(stmt, 1);
        const char *count3 = (const char*)sqlite3_column_text(stmt, 2);
        const char *count5 = (const char*)sqlite3_column_text(stmt, 3);
        const char *count6 = (const char*)sqlite3_column_text(stmt, 4);
        
        // Prepare the text to be displayed
        char output1[256];
        char output2[256];
        char output3[256];
        char output5[256];
        char output6[256];
        
        
        snprintf(output1, sizeof(output1), "%s", count1);
        snprintf(output2, sizeof(output2), "%s", count2);
        snprintf(output3, sizeof(output3), "%s", count3);
        snprintf(output5, sizeof(output5), "%s", count5);
        snprintf(output6, sizeof(output6), "%s", count6);
        
        // Output the text using outtextxy
        switch(c)
        { 
        case 1:outtextxy(x, y, output1);
        	   break;
        
        case 2:outtextxy(x, y, output2);
               break;
        
        case 3: outtextxy(x, y, output3);
               break;
        
        case 4: outtextxy(x, y, output5);
               break;
        
        case 5: outtextxy(x, y, output6);
               break;
		}
		
       // outtextxy(x1, y, output1);
       // outtextxy(x2, y, output2);
       // outtextxy(x3, y, output3);
        
        
        y += 30; // Move down for the next line of text
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


void access_Fitness2_data(const char* db_name, int c) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *sql = "SELECT count1, count2, count3, count4, count5, count6 FROM fitness2;";
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
    int x = 92, y = 190; // Starting coordinates for text output


    // Execute the SQL statement and print the results
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        const char *count1 = (const char*)sqlite3_column_text(stmt, 0);
        const char *count2 = (const char*)sqlite3_column_text(stmt, 1);
        const char *count3 = (const char*)sqlite3_column_text(stmt, 2);
        const char *count4 = (const char*)sqlite3_column_text(stmt, 3);
        const char *count5 = (const char*)sqlite3_column_text(stmt, 4);
        const char *count6 = (const char*)sqlite3_column_text(stmt, 5);
        
        // Prepare the text to be displayed
        char output1[256];
        char output2[256];
        char output3[256];
        char output4[256];
        char output5[256];
        char output6[256];
        
        
        snprintf(output1, sizeof(output1), "%s", count1);
        snprintf(output2, sizeof(output2), "%s", count2);
        snprintf(output3, sizeof(output3), "%s", count3);
        snprintf(output4, sizeof(output4), "%s", count4);
        snprintf(output5, sizeof(output5), "%s", count5);
        snprintf(output6, sizeof(output6), "%s", count6);
        
        // Output the text using outtextxy
        switch(c)
        { 
        case 1:outtextxy(x, y, output1);
        	   break;
        
        case 2:outtextxy(x, y, output2);
               break;
        
        case 3: outtextxy(x, y, output3);
               break;
        
        case 4: outtextxy(x, y, output4);
               break;
        
        case 5: outtextxy(x, y, output5);
               break;
               
        case 6: outtextxy(x, y, output6);
               break;
		}
		
       // outtextxy(x1, y, output1);
       // outtextxy(x2, y, output2);
       // outtextxy(x3, y, output3);
        
        
        y += 30; // Move down for the next line of text
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


void access_Fitness3_data(const char* db_name, int c) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *sql = "SELECT count1, count2, count3, count4, count5, count6 FROM fitness3;";
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
    int x = 92, y = 190; // Starting coordinates for text output


    // Execute the SQL statement and print the results
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        const char *count1 = (const char*)sqlite3_column_text(stmt, 0);
        const char *count2 = (const char*)sqlite3_column_text(stmt, 1);
        const char *count3 = (const char*)sqlite3_column_text(stmt, 2);
        const char *count4 = (const char*)sqlite3_column_text(stmt, 3);
        const char *count5 = (const char*)sqlite3_column_text(stmt, 4);
        const char *count6 = (const char*)sqlite3_column_text(stmt, 5);
        
        // Prepare the text to be displayed
        char output1[256];
        char output2[256];
        char output3[256];
        char output4[256];
        char output5[256];
        char output6[256];
        
        
        snprintf(output1, sizeof(output1), "%s", count1);
        snprintf(output2, sizeof(output2), "%s", count2);
        snprintf(output3, sizeof(output3), "%s", count3);
        snprintf(output4, sizeof(output4), "%s", count4);
        snprintf(output5, sizeof(output5), "%s", count5);
        snprintf(output6, sizeof(output6), "%s", count6);
        
        // Output the text using outtextxy
        switch(c)
        { 
        case 1:outtextxy(x, y, output1);
        	   break;
        
        case 2:outtextxy(x, y, output2);
               break;
        
        case 3: outtextxy(x, y, output3);
               break;
        
        case 4: outtextxy(x, y, output4);
               break;
        
        case 5: outtextxy(x, y, output5);
               break;
               
        case 6: outtextxy(x, y, output6);
               break;
		}
		
       // outtextxy(x1, y, output1);
       // outtextxy(x2, y, output2);
       // outtextxy(x3, y, output3);
        
        
        y += 30; // Move down for the next line of text
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
