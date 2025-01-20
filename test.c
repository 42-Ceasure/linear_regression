#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isValidInteger(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;  // Not a valid integer
        }
        str++;
    }
    return 1;  // Valid integer
}

int parseLine(char *line, int *mileAge, int *price) {
    char *token;
    token = strtok(line, ",");
    if (token == NULL || !isValidInteger(token)) {
        printf("Invalid mileage value: %s\n", token);
        return 0;
    }
    *mileAge = atoi(token);
    
    token = strtok(NULL, ",");
    if (token == NULL || !isValidInteger(token)) {
        printf("Invalid price value: %s\n", token);
        return 0;
    }
    *price = atoi(token);
    
    return 1;
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int mileAge, price;
        // Skip empty lines or invalid lines
        if (line[0] == '\n' || !parseLine(line, &mileAge, &price)) {
            continue;  // Skip invalid lines
        }
        printf("Mileage: %d, Price: %d\n", mileAge, price);
    }

    fclose(file);
    return 0;
}
