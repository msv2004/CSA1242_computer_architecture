#include <stdio.h>

// Define the size of memory
#define MEMORY_SIZE 256

// Define the structure for the Computer System
struct ComputerSystem {
    int memory[MEMORY_SIZE];
    int cpuRegister;
};

// Function to write data to memory
void writeToMemory(struct ComputerSystem *system, int address, int data) {
    if (address >= 0 && address < MEMORY_SIZE) {
        system->memory[address] = data;
        printf("Data %d written to memory address %d\n", data, address);
    } else {
        printf("Invalid memory address\n");
    }
}

// Function to read data from memory
int readFromMemory(struct ComputerSystem *system, int address) {
    if (address >= 0 && address < MEMORY_SIZE) {
        int data = system->memory[address];
        printf("Data %d read from memory address %d\n", data, address);
        return data;
    } else {
        printf("Invalid memory address\n");
        return -1; // Return -1 for invalid memory access
    }
}

int main() {
    // Initialize the computer system
    struct ComputerSystem system;

    // Example: Write data to memory
    writeToMemory(&system, 10, 42);

    // Example: Read data from memory
    int readData = readFromMemory(&system, 10);

    // Example: Access CPU register
    system.cpuRegister = 5;
    printf("Value in CPU register: %d\n", system.cpuRegister);

    return 0;
}

