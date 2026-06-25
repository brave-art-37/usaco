#include <bits/stdc++.h>
using namespace std;

const int MAX_COLS = 10;
// Movement directions (up, down, left, right)
const vector<pair<int, int>> MOVES = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

vector<pair<int, int>> find_region(const vector<string> &grid, int row, int col) {
	const int n = grid.size();          // Shorthand for the number of rows
	const char color = grid[row][col];  // Color of the starting cell

	queue<pair<int, int>> q;
	q.push({row, col});  // Start BFS from the given cell (row, col)

	vector<pair<int, int>> cells;  // Stores coordinates of connected cells
	vector<vector<bool>> visited(n, vector<bool>(MAX_COLS, false));
	while (!q.empty()) {
		const auto [row, col] = q.front();  // Current cell (row, col)
		q.pop();

		// Skip if the cell has already been visited
		if (visited[row][col]) { continue; }

		visited[row][col] = true;
		cells.push_back({row, col});  // Add the cell to the connected region

		for (auto [dx, dy] : MOVES) {
			int next_row = row + dx;
			int next_col = col + dy;

			// Check if the neighboring cell is within bounds
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < MAX_COLS) {
				// If the neighbor (next_row, next_col) has the same color
				if (grid[next_row][next_col] == color) {
					// Add the neighbor (next_row, next_col) to the queue
					q.push({next_row, next_col});
				}
			}
		}
	}

	return cells;
}

vector<vector<pair<int, int>>> find_removable_regions(const vector<string> &grid,
                                                      int k) {
	const int n = grid.size();
	vector<vector<pair<int, int>>> removable_regions;
	vector<vector<bool>> visited(n, vector<bool>(MAX_COLS, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MAX_COLS; j++) {
			// Skip already visited cells or empty cells ('0')
			if (grid[i][j] == '0' || visited[i][j]) { continue; }

			char color = grid[i][j];
			const auto cells = find_region(grid, i, j);

			// Mark all cells in the region as visited
			for (auto [r, c] : cells) { visited[r][c] = true; }

			// If the region size meets the threshold, add it to the removable regions
			if (cells.size() >= k) { removable_regions.push_back(cells); }
		}
	}

	return removable_regions;
}

void apply_gravity(vector<string> &grid) {
	const int n = grid.size();
	for (int j = 0; j < MAX_COLS; j++) {
		int empty_row = n - 1;  // Start from the bottom of the column

		// Move non-empty cells to the lowest available position in the column
		for (int i = n - 1; i >= 0; i--) {
			if (grid[i][j] != '0') {
				swap(grid[empty_row][j], grid[i][j]);
				empty_row--;
			}
		}
	}
}

int main() {
	//ifstream fin("mooyomooyo.in");
	int n, k;
	cin >> n >> k;

	vector<string> grid(n);
	for (int i = 0; i < n; i++) { cin >> grid[i]; }

	while (true) {
		// Find all removable regions (regions of size >= k)
		auto removable_regions = find_removable_regions(grid, k);

		if (removable_regions.empty()) { break; }

		// Remove all identified regions by setting their cells to '0'
		for (const auto &region : removable_regions) {
			for (const auto &[row, col] : region) { grid[row][col] = '0'; }
		}

		// Apply gravity to the grid
		apply_gravity(grid);
	}

	//ofstream fout("mooyomooyo.out");
	for (const auto &row : grid) { cout << row << "\n"; }
}
