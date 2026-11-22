#include"raylib.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
void reappear(int a[9][9]) {
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
bool checkBox(int a[9][9],int row, int num, int column){
	int startRow=(row/3)*3;
	int startColumn=(column/3)*3;
	for(int i=startRow;i<startRow+3;i++){
		for(int j=startColumn;j<startColumn+3;j++){
			if (i != row || j != column) {
				if (a[i][j] == num)
					return false;
			}
		}
	}
	return true;
}

bool rowcheck(int a[9][9], int num, int row, int column) {
	for (int c = 0;c < 9;c++) {
		if (c != column) {
			if (a[row][c] == num)
				return false;
		}
	}
	return true;
}
bool columncheck(int a[9][9], int num, int row, int column) {
	for (int r = 0;r < 9;r++) {
		if (r != row) {
			if (a[r][column] == num)
				return false;
		}
	}
	return true;
}
bool dead(int a[9][9]) {
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			if (a[i][j] == 0) {
				bool go = false;
				for (int k = 1;k <= 9;k++) {
					bool check1 = rowcheck(a, k, i, j);
					bool check2 = columncheck(a, k, i, j);
					bool check3 = checkBox(a, i, k, j);
					if (check1 && check2 && check3) {
						go = true;
						break;
					}
				}
				if (go == false)
					return true;
			}
		}
	}
	return false;
}
int main() {
	InitWindow(540, 540, "Sudoku");
	InitAudioDevice();
	Sound click = LoadSound("click.wav");
	Sound blunder = LoadSound("wrong.mp3");
	int arr[9][9]= {
		{7,3,5,6,1,4,8,9,2},
		{8,4,2,9,7,3,5,6,1},
		{9,6,1,2,8,5,3,7,4},
		{2,8,6,3,4,9,1,5,7},
		{4,1,3,8,5,7,9,2,6},
		{5,7,9,1,2,6,4,3,8},
		{1,5,7,4,9,2,6,8,3},
		{6,9,4,7,3,8,2,1,5},
		{3,2,8,5,6,1,7,4,9}
	};
	srand(time(0));
	int row = -1;
	int column = -1;
	int empty = 50;
	int count = 0;
	bool check;
	while (count < empty) {
		int randomrow = rand() % 9;
		int randomcolumn = rand() % 9;
		if (arr[randomrow][randomcolumn] != 0) {
			arr[randomrow][randomcolumn] = 0;
			count++;
		}
	}
	while (!(WindowShouldClose())) {
		BeginDrawing();
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			Vector2 mousePos = GetMousePosition();
			column = mousePos.x / 60;
			row = mousePos.y / 60;
			PlaySound(click);
		}
		ClearBackground(RAYWHITE);
		    if (IsKeyPressed(KEY_ONE)) {
				bool check1 = rowcheck(arr, 1, row, column);
				bool check2 = columncheck(arr, 1, row, column);
				bool check3 = checkBox(arr, row, 1, column);
				if (check1 && check2 && check3) {
					arr[row][column] = 1;
					bool final = dead(arr);
					if (final == true) {
						reappear(arr);
						PlaySound(blunder);
					}
				}
				else
					PlaySound(blunder);
		    }
			else if (IsKeyPressed(KEY_TWO)) {
				bool check1 = rowcheck(arr, 2, row, column);
				bool check2 = columncheck(arr, 2, row, column);
				bool check3 = checkBox(arr, row, 2, column);
				if (check1 && check2 && check3) {
					arr[row][column] = 2;
					bool final = dead(arr);
					if (final == true) {
						reappear(arr);
						PlaySound(blunder);
					}
				}
				else
					PlaySound(blunder);
			}
			else if (IsKeyPressed(KEY_THREE)) {
				bool check1 = rowcheck(arr, 3, row, column);
				bool check2 = columncheck(arr, 3, row, column);
				bool check3 = checkBox(arr, row, 3, column);
				if (check1 && check2 && check3) {
					arr[row][column] = 3;
					bool final = dead(arr);
					if (final == true) {
						reappear(arr);
						PlaySound(blunder);
					}
				}
				else
					PlaySound(blunder);
			}
				
			else if (IsKeyPressed(KEY_FOUR)) {
				bool check1 = rowcheck(arr, 4, row, column);
				bool check2 = columncheck(arr, 4, row, column);
				bool check3 = checkBox(arr, row, 4, column);
				if (check1 && check2 && check3) {
					arr[row][column] = 4;
					bool final = dead(arr);
					if (final == true) {
						reappear(arr);
						PlaySound(blunder);
					}
				}
				else
					PlaySound(blunder);
			}
			else if (IsKeyPressed(KEY_FIVE)) {
				bool check1 = rowcheck(arr, 5, row, column);
				bool check2 = columncheck(arr, 5, row, column);
				bool check3 = checkBox(arr, row, 5, column);
				if (check1 && check2 && check3) {
					arr[row][column] = 5;
					bool final = dead(arr);
					if (final == true) {
						reappear(arr);
						PlaySound(blunder);
					}
				}
				else
					PlaySound(blunder);
			}	
			else if (IsKeyPressed(KEY_SIX)) {
				bool check1 = rowcheck(arr, 6, row, column);
				bool check2 = columncheck(arr, 6, row, column);
				bool check3 = checkBox(arr, row, 6, column);
				if (check1 && check2 && check3) {
					arr[row][column] = 6;
					bool final = dead(arr);
					if (final == true) {
						reappear(arr);
						PlaySound(blunder);
					}
				}
				else
					PlaySound(blunder);
			}	
			else if (IsKeyPressed(KEY_SEVEN)) {
				bool check1 = rowcheck(arr, 7, row, column);
				bool check2 = columncheck(arr, 7, row, column);
				bool check3 = checkBox(arr, row, 7, column);
				if (check1 && check2 && check3) {
					arr[row][column] = 7;
					bool final = dead(arr);
					if (final == true) {
						reappear(arr);
						PlaySound(blunder);
					}
				}
				else
					PlaySound(blunder);
			}
			
			else if (IsKeyPressed(KEY_EIGHT)) {
				bool check1 = rowcheck(arr, 8, row, column);
				bool check2 = columncheck(arr, 8, row, column);
				bool check3 = checkBox(arr, row, 8, column);
				if (check1 && check2 && check3) {
					arr[row][column] = 8;
					bool final = dead(arr);
					if (final == true) {
						reappear(arr);
						PlaySound(blunder);
					}
				}
				else
					PlaySound(blunder);
			}
				
			else if (IsKeyPressed(KEY_NINE)) {
				bool check1 = rowcheck(arr, 9, row, column);
				bool check2 = columncheck(arr, 9, row, column);
				bool check3 = checkBox(arr, row, 9, column);
				if (check1 && check2 && check3) {
					arr[row][column] = 9;
					bool final = dead(arr);
					if (final == true) {
						reappear(arr);
						PlaySound(blunder);
					}
				}
				else
					PlaySound(blunder);
			}
				

		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				if (arr[i][j] != 0) {
					DrawText(TextFormat("%d", arr[i][j]), j * 60 + 20, i * 60 + 20, 20, BLUE);
				}
			}
		}
		int startX = 0;
		int startY = 0;
		int cellSize = 60;
		for (int i = 0;i <= 9;i++) {
			float thickness;
			if (i % 3 == 0)
				thickness = 2;
			else
				thickness = 1;
			if (thickness == 2) {
				DrawLineEx(
					Vector2{ (float)startX,(float)(startY + i * cellSize) },
					Vector2{ (float)(startX + 9 * cellSize),
						(float)(startY + i * cellSize) },
					thickness,
					DARKGREEN
				);
				DrawLineEx(
					Vector2{ (float)(startX + i * cellSize),(float)startY },
					Vector2{ (float)(startX + i * cellSize),
						(float)(startY + 9 * cellSize) },
					thickness,
					DARKGREEN
				);
			}
			else {
				DrawLineEx(
					Vector2{ (float)startX,(float)(startY + i * cellSize) },
					Vector2{ (float)(startX + 9 * cellSize),
						(float)(startY + i * cellSize) },
					thickness,
					LIGHTGRAY
				);
				DrawLineEx(
					Vector2{ (float)(startX + i * cellSize),(float)startY },
					Vector2{ (float)(startX + i * cellSize),
						(float)(startY + 9 * cellSize) },
					thickness,
					LIGHTGRAY
				);
			}
		}
			EndDrawing();
	}
	UnloadSound(click);
	UnloadSound(blunder);
	CloseAudioDevice();
	CloseWindow();
}



