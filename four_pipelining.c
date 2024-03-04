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

// Function to simulate the ID (Instruction Decode) stage
void instructionDecode(struct CPU *cpu, int instruction, int *opcode, int *operand1, int *operand2) {
    *opcode = (instruction >> 8) & 0xFF;  // Extract opcode from the instruction
    *operand1 = (instruction >> 4) & 0xF;  // Extract operand1 from the instruction
    *operand2 = instruction & 0xF;         // Extract operand2 from the instruction
}

// Function to simulate the EX (Execute) stage
int execute(struct CPU *cpu, int opcode, int operand1, int operand2) {
    // Simulate simple instruction execution
    // For demonstration, we'll use two basic instructions: ADD and SUB
    switch (opcode) {
        case 0:  // ADD operation
            return cpu->registerFile[operand1] + cpu->registerFile[operand2];
        case 1:  // SUB operation
            return cpu->registerFile[operand1] - cpu->registerFile[operand2];
        // Add more instructions as needed
        default:
            return 0;  // Default case for unknown opcode
    }
}

// Function to simulate the WB (Write Back) stage
void writeBack(struct CPU *cpu, int result, int operand1) {
    // Simulate writing back the result to the register file
    cpu->registerFile[operand1] = result;
}

int main() {
    // Initialize the CPU
    struct CPU cpu = {
        .instructionMemory = {0x0123, 0x1023, 0x2012},  // Example instructions (ADD, SUB, ADD)
        .registerFile = {0},
        .programCounter = 0
    };

    // Simulate four-stage pipelining
    for (int i = 0; i < 3; i++) {
        // IF stage
        int instruction = instructionFetch(&cpu);

        // ID stage
        int opcode, operand1, operand2;
        instructionDecode(&cpu, instruction, &opcode, &operand1, &operand2);

        // EX stage
        int result = execute(&cpu, opcode, operand1, operand2);

        // WB stage
        writeBack(&cpu, result, operand1);

        // Print the register file after each instruction
        printf("Register File after instruction %d: ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%d ", cpu.registerFile[j]);
        }
        printf("\n");
    }

    return 0;
}

