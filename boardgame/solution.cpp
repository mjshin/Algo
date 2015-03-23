


//주어진 칸을 덮을 수 있는 4가지 방법
// 블록을 구성하는 3 칸의 상대적 위치 (dy, dx)
const int converType[4][3][2] { 
	{ { 0, 0}, {1, 0}, {0, 1} ), //(b)
	{ { 0, 0}, {0, 1}, {1, 1} }, //(c)
	{ { 0, 0}, {1, 0}, {1, 1} }, //(d)
	{ { 0, 0}, {1, 0}, {1, -1} ) //(e)
};

//board의 (y, x)를 type번 방법으로 덮거나 덮었던 블록을 없앤다. 
// delta = 1 이면 덮고 -1이면 덮었던 블록을 없앤다.
// 만약 블록이 제대로 덮이지 않은 경우 (게임판 밖으로 나가거나 
// 겹치거나 검은 칸을 덮을 때는 -1을 반환한다. 

bool set(vector<vector<int> >&board, int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; ++i) {
		const int ny = y + converType[type][i][0];
		const int nx = x + converType[type][i][1];

		if (ny < 0 || ny >= board.size() || nx < 0 || nx >=board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			os = false;
	}
	return ok;
}


//board의 모든 빈 칸을 덮을 수 있는 방법의 수를 반환한다. 
// board[i][j] = 1 이미 덮인 칸 혹은 검은 칸 
// board[i][j] = 0 아직 덮이지 않은 칸 

int cover(vector<vector<int>& board) {

	int y = -1;
	int x = -1;

	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size; ++j) 
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		if (y != -1) break;
	}

	//기저 사례 : 모든 칸을 채웠으면 1을 반환한다. 

   	if (y == -1) return 1;	
	int ret = 0;
	for (int type = 0; type < 4; ++type) {
		//만약 board[y][x] 형태로 덮을 수 있으면 재귀 호출을 한다. 
		if (set(board, y, x, type, 1))
			ret += cover(board);
		//덮었던 블록을 치운다. 
		set(board, y, x, type, -1);
	}

	return ret; 
}
	
	
		


