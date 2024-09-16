#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to decode the Y value based on its base
long long decodeValue(const string& value, int base) {
    return stoll(value, nullptr, base);  // Convert string in the given base to long long
}

// Lagrange Interpolation function to find the constant term 'c'
long long lagrangeInterpolation(const vector<pair<int, long long>>& points, int k) {
    long long constantTerm = 0;

    for (int i = 0; i < k; i++) {
        int xi = points[i].first;
        long long yi = points[i].second;

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
        {"keys", {{"n", "9"}, {"k", "6"}}},
        {"1", {{"base", "10"}, {"value", "28735619723837"}}},
        {"2", {{"base", "16"}, {"value", "1A228867F0CA"}}},
        {"3", {{"base", "12"}, {"value", "32811A4AA0B7B"}}},
        {"4", {{"base", "11"}, {"value", "917978721331A"}}},
        {"5", {{"base", "16"}, {"value", "1A22886782E1"}}},
        {"6", {{"base", "10"}, {"value", "28735619654702"}}},
        {"7", {{"base", "14"}, {"value", "71AB5070CC4B"}}},
        {"8", {{"base", "9"}, {"value", "122662581541670"}}},
        {"9", {{"base", "8"}, {"value", "642121030037605"}}}
    };

    int n = stoi(input["keys"]["n"]);
    int k = stoi(input["keys"]["k"]);

    vector<pair<int, long long>> points;

    // Decoding the points (x, y)
    for (auto& item : input) {
        if (item.first != "keys") {
            int x = stoi(item.first);  // x is the key
            int base = stoi(item.second["base"]);
            string value = item.second["value"];
            long long y = decodeValue(value, base);  // Decode y based on base
            points.push_back({x, y});
        }
    }

    // Sort the points by x for consistency (optional, not required)
    sort(points.begin(), points.end());

    // Use Lagrange interpolation to find the constant term (c)
    long long constantTerm = lagrangeInterpolation(points, k);

    // Output the result
    cout << "The constant term (c) is: " << constantTerm << endl;

    return 0;
}
