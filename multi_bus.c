#include <stdio.h>

// Define the memory size
#define MEMORY_SIZE 1024

// Define the structure for the CPU
struct CPU {
    int instructionBus;
    int dataBus;
    int registers[8];  // Assuming 8 general-purpose registers
};

// Define the structure for Memory
struct Memory {
    int data[MEMORY_SIZE];
};

// Function to write data to memory
void writeToMemory(struct Memory *memory, int address, int data) {
    if (address >= 0 && address < MEMORY_SIZE) {
        memory->data[address] = data;
        printf("Data %d written to memory address %d\n", data, address);
    } else {
        printf("Invalid memory address\n");
    }
}

// Function to read data from memory
int readFromMemory(struct Memory *memory, int address) {
    if (address >= 0 && address < MEMORY_SIZE) {
        int data = memory->data[address];
        printf("Data %d read from memory address %d\n", data, address);
        return data;
    } else {
        printf("Invalid memory address\n");
        return -1; // Return -1 for invalid memory access
    }
}

int main() {
    // Initialize the CPU, Memory, and Buses
    struct CPU cpu = {0, 0, {0}};
    struct Memory memory;

    // Example: Write data to memory using the data bus
    cpu.dataBus = 42;
    writeToMemory(&memory, 100, cpu.dataBus);

    // Example: Read data from memory using the data bus
    cpu.dataBus = readFromMemory(&memory, 100);

    // Example: Transfer data from the instruction bus to a register
    cpu.instructionBus = 5;
    cpu.registers[0] = cpu.instructionBus;
    printf("Value in CPU register 0: %d\n", cpu.registers[0]);

    return 0;
}

