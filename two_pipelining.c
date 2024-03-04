#include <stdio.h>

// Define the structure for the CPU
struct CPU {
    int instructionMemory[100];  // Instruction memory
    int registerFile[8];         // General-purpose registers
    int programCounter;          // Program counter
};

// Function to simulate the IF (Instruction Fetch) stage
int instructionFetch(struct CPU *cpu) {
    int instruction = cpu->instructionMemory[cpu->programCounter];
    cpu->programCounter++;  // Increment program counter for the next instruction
    return instruction;
}

// Function to simulate the IE (Instruction Execute) stage
void instructionExecute(struct CPU *cpu, int instruction) {
    // Simulate simple instruction execution
    // For demonstration, we'll use two basic instructions: ADD and SUB
    int opcode = (instruction >> 8) & 0xFF;  // Extract opcode from the instruction

    int operand1 = (instruction >> 4) & 0xF;  // Extract operand1 from the instruction
    int operand2 = instruction & 0xF;         // Extract operand2 from the instruction

    switch (opcode) {
        case 0:  // ADD operation
            cpu->registerFile[operand1] += cpu->registerFile[operand2];
            break;
        case 1:  // SUB operation
            cpu->registerFile[operand1] -= cpu->registerFile[operand2];
            break;
        // Add more instructions as needed
    }
}

int main() {
    // Initialize the CPU
    struct CPU cpu = {
        .instructionMemory = {0x0123, 0x1023, 0x2012},  // Example instructions (ADD, SUB, ADD)
        .registerFile = {0},
        .programCounter = 0
    };

    // Simulate two-stage pipelining
    for (int i = 0; i < 3; i++) {
        // IF stage
        int instruction = instructionFetch(&cpu);

        // IE stage
        instructionExecute(&cpu, instruction);

        // Print the register file after each instruction
        printf("Register File after instruction %d: ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%d ", cpu.registerFile[j]);
        }
        printf("\n");
    }

    return 0;
}

