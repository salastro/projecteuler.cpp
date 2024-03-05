#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<int>> parseFile(const string filename) {
  vector<vector<int>> result;
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    vector<int> row;
    stringstream ss(line);
    string cell;
    while (getline(ss, cell, ','))
      row.push_back(stoi(cell));
    result.push_back(row);
  }
  return result;
}

bool compareExponents(const vector<int> &a, const vector<int> &b) {
  return a[1] * log(a[0]) > b[1] * log(b[0]);
}

int main() {
  vector<vector<int>> data = parseFile("documents/0099_base_exp.txt");

  int maxIndex = 0;
  for (int i = 0; i < data.size(); i++)
    if (compareExponents(data[i], data[maxIndex]))
      maxIndex = i;

  cout << maxIndex + 1 << endl;
  return 0;
}
