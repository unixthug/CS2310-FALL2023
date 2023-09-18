//CS2310 || Adam Jones || 9-17-23 
//Set Operations Coding Problem
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//Function declaration
void Union(vector<int>, vector<int>);
void Intersect(vector<int>, vector<int>);
void Subtract(vector<int>, vector<int>);

void Union(vector <int> a, vector <int> b) {
    vector <int> vunion;
    cout << "Union: " << endl;

    //add A for the first part of the union
    for (int i = 0; i < a.size(); i++) {
        vunion.push_back(a[i]);
    }

    //add union to vector
    int j;
    for (int i = 0; i < b.size(); i++) {
        //once the unions intersect, skip the intersect and start adding B
        for (j = 0; j < a.size(); j++) {
            if (b[i] == a[j]) {
                break;
            }
        }
        if (j == a.size()) {
        vunion.push_back(b[i]);
        }
    }
    //print union vector elements in order
    sort(vunion.begin(), vunion.end());
    for (const int& i : vunion) {
        cout << i << " ";
    }    
    cout << endl;
}
void Intersect(vector <int> a, vector <int> b) {
    cout << "Intersection: " << endl;
    //Print out matching values of A and B
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (b[i] == a[j]) {
                cout << b[i] << " ";
            }
        }
    }
    cout << endl;

}
void Subtract(vector <int> a, vector <int> b) {
    cout << "Subtraction: " << endl;
    vector <int> subtract;
    bool skip = false;
    //Add every element of A to subtract vector, skip intersection
    for (int i = 0; i < a.size(); i++) {
        skip = false;
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                skip = true;
                break;
            }
        }
        if (!skip) {
            subtract.push_back(a[i]);
        }
    }

    //sort and print every value in the vector
    sort(subtract.begin(), subtract.end());
    for (const int& i : subtract) {
        cout << i << " ";
    } 
    cout << endl;
}

int main() 
{
    //test sets
    vector <int> A = {1, 2, 3, 4, 5};
    vector <int> B = {4, 5, 6};

    //Print original sets
    cout << "Original Sets: " << endl;
    for (const int& i : A) {
        cout << i << " ";
    }
    cout << endl;
    for (const int& i : B) {
        cout << i << " ";
    }
    cout << endl;

    //run all operations
    Union(A, B);
    Intersect(A, B);
    Subtract(A, B);

    return 0;
}
