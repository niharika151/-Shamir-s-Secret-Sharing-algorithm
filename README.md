# -Shamir-s-Secret-Sharing-algorithm
c++ code for genertating  Shamir's Secret Sharing algorithm


**CASE 1:

CODE:**
https://github.com/niharika151/-Shamir-s-Secret-Sharing-algorithm/blob/main/Shamir's_Secret_case1.cpp


**1. Problem Context:**
The code solves a problem using Lagrange Interpolation to reconstruct a polynomial from given points (x, y) and find the constant term c.
The input data contains values encoded in various numerical bases, which need to be converted to base-10 integers before applying interpolation.


**2. Decoding Function:**
decodeValue:
Converts the string representation of the y values from their respective numerical bases (e.g., base-2, base-10) to base-10 integers.
Uses the function stoi (string-to-integer conversion) with the specified base.
This allows handling of numbers in various bases like binary (base 2), decimal (base 10), and others.

**3. Main Function Workflow:**
Step 1: Input Parsing

The input is stored in a nested map (map<string, map<string, string>>), containing values in different bases.
Extracts n (total number of points) and k (minimum required points for interpolation) from the "keys" section.
Step 2: Decoding Points

Iterates over the map to decode each point (x, y) where:
x is the index of the point (from the map key).
y is the encoded value, converted using decodeValue based on its respective base.
Stores each decoded pair (x, y) in a vector for interpolation.
Step 3: Lagrange Interpolation

Calls the lagrangeInterpolation function using the decoded points.
Finds the constant term c by evaluating the polynomial at x = 0.
Step 4: Output

The constant term c is printed as the final result, which represents the hidden secret in the polynomial.


**4. Lagrange Interpolation Key Points:**
Purpose: Used to reconstruct a polynomial of degree k-1 based on k points.
Efficiency: Interpolation operates in O(k²) time complexity due to the double loop structure.
Output: The constant term c is computed by evaluating the polynomial at x = 0.


**5. Additional Features:**
Base Conversion: The code supports decoding y values from various numerical bases.
Polynomial Rebuilding: Uses an efficient method for polynomial reconstruction using Lagrange's interpolation formula.
Error Handling: The code handles potential variations in the input base and properly decodes it to perform computations.

**6:INPUT PROVIDED TEST CASE:**
{
    "keys": {
        "n": 4,
        "k": 3
    },
    "1": {
        "base": "10",
        "value": "4"
    },
    "2": {
        "base": "2",
        "value": "111"
    },
    "3": {
        "base": "10",
        "value": "12"
    },
    "6": {
        "base": "4",
        "value": "213"
    }
}


**7.OUTPUT IMAGE:**
![image](https://github.com/user-attachments/assets/e7d7b141-54cc-4175-a130-3b2ca7dba979)



**2.****CASE2:**

**CODE:**
https://github.com/niharika151/-Shamir-s-Secret-Sharing-algorithm/blob/main/Shamir's_Secret_case2.cpp


**1. Problem Context**
The problem involves reconstructing a polynomial from given (x, y) points using Lagrange Interpolation to find the constant term c, which is the secret in a Shamir's Secret Sharing context.
The input consists of points encoded in various number bases, requiring conversion before interpolation.


**2. Input Data Format**
The input is a structured JSON-like map:
n: Total number of points provided.
k: The minimum number of points required to reconstruct the polynomial.
Each point is encoded as (x, y), where:
x: The key (index of the point).
y: The value encoded in a specific numerical base (e.g., base 10, base 16).


**3. Decoding Function**
decodeValue: This function converts the string representation of y values from their respective bases to base-10 using stoll (string-to-long-long conversion).
Input: Encoded y value (string) and its base (integer).
Output: The base-10 integer value of y.
This handles conversions from bases such as binary, hexadecimal, octal, and custom bases like 12 and 14.

**5. Main Workflow**
Step 1: The input data is stored in a map<string, map<string, string>> structure, where each point contains a base and value.
Step 2: Extract n (total points) and k (minimum required points) from the JSON.
Step 3: Iterate over the points, decode the y values using decodeValue, and store each (x, y) pair.
Step 4: Optionally, the points are sorted by x values to maintain consistency, though this is not necessary for interpolation.
Step 5: Call lagrangeInterpolation to compute the constant term using the first k points.

**6. Key Features**
Base Conversion: Handles decoding from different numerical bases.
Lagrange Interpolation: Efficiently reconstructs the polynomial using the given points.
Large Number Handling: Uses long long for dealing with large values of y (important for cryptographic applications).


**7. Code Efficiency**
Time Complexity: Lagrange interpolation has a complexity of O(k²) due to the nested loops required for computing the basis polynomials.
The code works efficiently for a moderate number of points k, which is typical in secret sharing schemes.

**8.INPUT TEST CASE PROVIDED:**
{
    "keys": {
        "n": 9,
        "k": 6
    },
    "1": {
        "base": "10",
        "value": "28735619723837"
    },
    "2": {
        "base": "16",
        "value": "1A228867F0CA"
    },
    "3": {
        "base": "12",
        "value": "32811A4AA0B7B"
    },
    "4": {
        "base": "11",
        "value": "917978721331A"
    },
    "5": {
        "base": "16",
        "value": "1A22886782E1"
    },
    "6": {
        "base": "10",
        "value": "28735619654702"
    },
    "7": {
        "base": "14",
        "value": "71AB5070CC4B"
    },
    "8": {
        "base": "9",
        "value": "122662581541670"
    },
    "9": {
        "base": "8",
        "value": "642121030037605"
    }
}


**9.OUTPUT IMAGE:**
![image](https://github.com/user-attachments/assets/3b8b1a07-df59-46c5-8db0-9c8abd02b2ab)


