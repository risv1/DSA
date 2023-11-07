#include <iostream>
#include <stack>

using namespace std;

struct Move {
    int n;
    char source, auxiliary, destination;

    Move(int discs, char src, char aux, char dest) : n(discs), source(src), auxiliary(aux), destination(dest) {}
};

void towerOfHanoi(int numDiscs) {
    stack<Move> moves;
    moves.push(Move(numDiscs, 'A', 'B', 'C'));

    while (!moves.empty()) {
        Move currentMove = moves.top();
        moves.pop();

        if (currentMove.n == 1) {
            cout << "Move disc 1 from " << currentMove.source << " to " << currentMove.destination << endl;
        } else {
            moves.push(Move(currentMove.n - 1, currentMove.auxiliary, currentMove.source, currentMove.destination));
            moves.push(Move(1, currentMove.source, currentMove.auxiliary, currentMove.destination));
            moves.push(Move(currentMove.n - 1, currentMove.source, currentMove.destination, currentMove.auxiliary));
        }
    }
}

int main() {
    int numDiscs;
    cout << "Enter the number of discs: ";
    cin >> numDiscs;

    towerOfHanoi(numDiscs);

    return 0;
}
