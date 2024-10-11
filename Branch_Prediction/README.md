# Branch Prediction

## Overview

The Branch Prediction module implements various branch prediction algorithms in C++. These algorithms include:
- Always Taken Predictor
- Always Not Taken Predictor
- Single-Bit Predictor
- Two-Bit Predictor

Each predictor is implemented in a separate C++ file.

## Contents

- `Tests/`: Folder containing test cases for the Branch Prediction module.
- `2_bit_predictor.cpp`: C++ file implementing the Two-Bit predictor.
- `Always_nottaken.cpp`: C++ file implementing the Always Not Taken predictor.
- `Always_taken.cpp`: C++ file implementing the Always Taken predictor.
- `single_bit_predictor.cpp`: C++ file implementing the Single-Bit predictor.

## Usage

To run the Branch Prediction module:

1. Prepare the input trace file in the following format:
    - Each line should represent a branch instruction.
    - Format: `core <core_number>: PC (<Machine Code>) branch_instruction rs1, rs2, offset_value (pc + [0-9]+)`
    - Example: `core 0: 0x80000288 (0x00629063) bne t0, t1, pc + 0`
    - Save the input trace file as `input.txt`.

2. Compile the desired branch prediction algorithm:
    - For Always Taken predictor:
        ```
        g++ Always_taken.cpp -o always_taken
        ```
    - For Always Not Taken predictor:
        ```
        g++ Always_nottaken.cpp -o always_nottaken
        ```
    - For Single-Bit predictor:
        ```
        g++ single_bit_predictor.cpp -o single_bit
        ```
    - For Two-Bit predictor:
        ```
        g++ 2_bit_predictor.cpp -o two_bit
        ```

3. Run the compiled executable with the input file:
    - For Always Taken:
        ```
        ./always_taken input.txt
        ```
    - For Always Not Taken:
        ```
        ./always_nottaken input.txt
        ```
    - For Single-Bit predictor:
        ```
        ./single_bit input.txt
        ```
    - For Two-Bit predictor:
        ```
        ./two_bit input.txt
        ```

4. Ensure that the following output files are generated:
    - `output.txt`: Branch Target Buffer details.

## Note

- Only conditional branches are considered for prediction as non-conditional branches are always taken.
- The accuracy of each predictor is provided in the output files.

## Additional Information

For more detailed instructions and examples, refer to the specific README files in the test directories.
