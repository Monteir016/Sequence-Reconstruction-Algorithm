#include <iostream> 
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int setSize; // Ex: setSize = 3 --> 1, 2, 3 
int sequenceSize; // Ex: sequenceSize = 4 --> 2 1 3 2
int result;

struct Entry{
    int value;
    int split;
    int leftValue;
    int rightValue;

    Entry(int v, int s, int lv, int rv)
        : value(v), split(s), leftValue(lv), rightValue(rv) {}
};

vector<int> sequence;
vector<vector<int> > matrix;
vector<vector<vector<Entry>>> result_matrix;



int getResult(int a, int b) {
    return matrix[a - 1][b - 1];
}

string reconstructingExpression(int start, int end, Entry newEntry) {

    if (start == end) {
        return to_string(sequence[start]);
    }


    Entry leftSequence(0,0,0,0);
    Entry rightSequence(0,0,0,0);


    for (size_t i = 0; i < result_matrix[start][newEntry.split].size(); i++) {

        if (result_matrix[start][newEntry.split][i].value == newEntry.leftValue) {
            
            leftSequence = result_matrix[start][newEntry.split][i];
            break;
        }
    }


    for (size_t j = 0; j < result_matrix[newEntry.split + 1][end].size(); j++) {

        if (result_matrix[newEntry.split + 1][end][j].value == newEntry.rightValue) {
            
            rightSequence = result_matrix[newEntry.split + 1][end][j];
            break;
        }
    }


    
    string leftExpr = reconstructingExpression(start, newEntry.split, leftSequence);
    string rightExpr = reconstructingExpression(newEntry.split + 1, end, rightSequence);

    end = newEntry.split + 1;
    
    return "(" + leftExpr + " " + rightExpr + ")";

}


void printSolution(int check) {
    if (check == 1) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
}


int createTable() {

    if (sequenceSize == 1) {
        if (sequence[0] == result) {
            cout << "1" << endl;
            cout << sequence[0] << endl;
            return 0;
        } else {
            cout << "0" << endl;
            return 0;
        }
    }

    result_matrix.resize(sequenceSize, vector<vector<Entry>>(sequenceSize)); // Resizing the matrix to sequenceSize**2

    for (int d = 0; d < sequenceSize; d++) {
        for (int k = 0; k < sequenceSize - d; k++) {
            int differentValues = 0;
            
            unordered_set<int> uniqueResults;

            if (d == 0) {
                result_matrix[k][k].push_back({sequence[k], 0, 0, 0});
            } else if (d == 1) {

                int calculatedValue = getResult(sequence[k], sequence[k+1]);
                
                result_matrix[k][k + d].push_back(
                    {calculatedValue, k, sequence[k], sequence[k + 1]});
                
                if (calculatedValue == result && sequenceSize == 2) {
                    printSolution(1);
                    cout << "(" << sequence[k] << " " << sequence[k + 1] << ")" << endl;
                    return 0;
                }

            } else {
            
                for (int i = k + d - 1; i >= k; i--) {

                    size_t sizeElement1 = result_matrix[k][i].size(); // Left
                    size_t sizeElement2 = result_matrix[i + 1][k + d].size(); // Right
                    
                    for (size_t iterator1 = 0; iterator1 < sizeElement1; iterator1++) {
                        for (size_t iterator2 = 0; iterator2 < sizeElement2; iterator2++) {
                            
                            int uniqueResult = getResult(
                                result_matrix[k][i][iterator1].value,
                                result_matrix[i + 1][k + d][iterator2].value);

                            
                            if (uniqueResults.find(uniqueResult) == uniqueResults.end()) {
                                
                                uniqueResults.insert(uniqueResult);
                                
                                Entry newEntry(uniqueResult, i, 
                                            result_matrix[k][i][iterator1].value, 
                                            result_matrix[i + 1][k + d][iterator2].value);
                                result_matrix[k][k + d].push_back(newEntry);
                                differentValues++;

                                if (d == sequenceSize - 1 && k == sequenceSize - d - 1 && uniqueResult == result) {

                                    printSolution(1);
                                    cout << reconstructingExpression(0, sequenceSize - 1, newEntry) << endl;
                                    return 0;
                                }

                                if (differentValues == setSize) {
                                    break;
                                }

                            }
                        }
                        if (differentValues == setSize) {
                            break;
                        }
                    }
                    if (differentValues == setSize) {
                        break;
                    }
                }
            }
        }
    }

    printSolution(0);
    return 0;
}

void readInput() {

    cin >> setSize;

    cin >> sequenceSize;

    matrix.resize(setSize, vector<int>(setSize));
    sequence.resize(sequenceSize);

    for (int line= 0; line < setSize; line++) {
        for (int row = 0; row< setSize; row++) {
            cin >> matrix[line][row];
        }
    }

    for (int i = 0; i < sequenceSize; i++) {
        cin >> sequence[i];
    }

    cin >> result;
}

int main() {

    readInput();
    createTable();
    return 0;

}