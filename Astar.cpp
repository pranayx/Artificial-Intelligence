#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findPosition(vector<vector<int>> initial_state) {
    pair<int, int> p;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(initial_state[i][j] == -1){
                p = make_pair(i, j);
                return p;
            }
        }
    }
}

int cal_heuristic(vector<vector<int>> arr, vector<vector<int>> final_state) {
    int heuristic = 0;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(arr[i][j] != final_state[i][j]) {
                heuristic++;
            }
        }
    }

    return heuristic;
}

void shift_up(vector<vector<int>> initial_state, vector<vector<int>> &up, int pos_row, int pos_col) {
    up = initial_state;
    swap(up[pos_row][pos_col],up[pos_row-1][pos_col]);
}

void shift_down(vector<vector<int>> initial_state, vector<vector<int>> &down, int pos_row, int pos_col) {
    down = initial_state;
    swap(down[pos_row][pos_col],down[pos_row+1][pos_col]);
}

void shift_left(vector<vector<int>> initial_state, vector<vector<int>> &left, int row, int col) {
    left = initial_state;
    swap(left[row][col-1],left[row][col]);
}

void shift_right(vector<vector<int>> initial_state, vector<vector<int>> &right, int row, int col) {
    right = initial_state;
    swap(right[row][col+1],right[row][col]);
}

void puzzle(vector<vector<int>> initial_state, vector<vector<int>> final_state) {
    if(initial_state == final_state) {
        return;
    }

    pair<int, int> p = findPosition(initial_state);
    int pos_row = p.first;
    int pos_col = p.second;

    vector<vector<int>> up;
    vector<vector<int>> down;
    vector<vector<int>> left;
    vector<vector<int>> right;

    int u_heuristic = 999999, d_heuristic = 999999, l_heuristic = 999999, r_heuristic = 999999;

    if(pos_row > 0) {
        shift_up(initial_state, up, pos_row, pos_col);
        u_heuristic = cal_heuristic(up, final_state);
    }
    if(pos_row < 2){
        shift_down(initial_state, down, pos_row, pos_col);
        d_heuristic = cal_heuristic(down, final_state);
    }
    if(pos_col > 0) {
        shift_left(initial_state, left, pos_row, pos_col);
        l_heuristic = cal_heuristic(left, final_state);
    } 
    if(pos_col < 2) {
        shift_right(initial_state, right, pos_row, pos_col);
        r_heuristic = cal_heuristic(right, final_state);
    }

    vector<int> heuristic = {u_heuristic, d_heuristic, l_heuristic, r_heuristic};
    int m_heuristic = 999999;
    int m_heuristic_idx;
    
    for(int i = 0; i < heuristic.size(); i++) {
        if(heuristic[i] < m_heuristic) {
            m_heuristic = heuristic[i];
            m_heuristic_idx = i;
        }
    }

    if(m_heuristic_idx == 0) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout<<up[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        puzzle(up, final_state);
        cout<<endl;
    } else if(m_heuristic_idx == 1) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout<<down[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        puzzle(down, final_state);
        cout<<endl;
    } else if(m_heuristic_idx == 2) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout<<left[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        puzzle(left, final_state);
        cout<<endl;
    } else if(m_heuristic_idx == 3) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout<<right[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        puzzle(right, final_state);
        cout<<endl;
    }
}

int main() {
    vector<vector<int>> initial_state = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, -1}
    };

    vector<vector<int>> final_state = {
        {1, -1, 3},
        {4, 2, 5},
        {7, 8, 6}
    };

    puzzle(initial_state, final_state);

    return 0;
}