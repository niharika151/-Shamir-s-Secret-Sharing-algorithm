#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to decode the Y value based on its base
int decodeValue(const string& value, int base) {
    return stoi(value, nullptr, base);  // Convert string in a given base to an integer
}

// Lagrange Interpolation function to find the constant term 'c'
double lagrangeInterpolation(const vector<pair<int, int>>& points, int k) {
    double constantTerm = 0;

    for (int i = 0; i < k; i++) {
        int xi = points[i].first;
        int yi = points[i].second;

        double li = 1.0;
        for (int j = 0; j < k; j++) {
            if (i != j) {
                int xj = points[j].first;
                li *= (0.0 - xj) / (xi - xj); // Evaluating L_i(0)
            }
        }

        // Summing up the terms for the constant term
        constantTerm += yi * li;
    }

    return constantTerm;
}

int main() {
    // Example input in the format given by the problem
    map<string, map<string, string>> input = {
        {"keys", {{"n", "4"}, {"k", "3"}}},
        {"1", {{"base", "10"}, {"value", "4"}}},
        {"2", {{"base", "2"}, {"value", "111"}}},
        {"3", {{"base", "10"}, {"value", "12"}}},
        {"6", {{"base", "4"}, {"value", "213"}}}
    };

    int n = stoi(input["keys"]["n"]);  // Total number of roots
    int k = stoi(input["keys"]["k"]);  // Minimum required roots to solve the polynomial

    vector<pair<int, int>> points;

    // Decoding the points (x
