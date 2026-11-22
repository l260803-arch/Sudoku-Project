#include"raylib.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
void copymaker(int a[9][9], int copy[9][9]) {
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			copy[i][j] = a[i][j];
		}
	}
}
bool checker(int num, int row, int column, int a[9][9]) {
	if (a[row][column] == num)
		return true;
	return false;
}

void shuffleSudoku(int sudoku[9][9]){
	srand (time(0));
	// swap rows
	for(int i=0;i<9;i+=3){
		int r1=i+rand()%3;
		int r2=i+rand()%3;
		for(int j=0;j<9;j++){
			swap(sudoku[r1][j],sudoku[r2][j]);


		}
	}
	//swap columns
	for(int i=0;i<9;i+=3){
		int c1=i+rand()%3;
		int c2=i+rand()%3;
		for(int j=0;j<9;j++){
			swap(sudoku[j][c1],sudoku[j][c2]);
		}

	}
	//random swapping
	int n1=rand()%9+1;
	int n2=rand()%9+1;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(sudoku[i][j]==n1)
			{
				sudoku[i][j]=n2;
			}
			else if(sudoku[i][j]==n2){
				sudoku[i][j]=n1;
			}
		}
	}
	

}

bool fillcheck(int a[9][9]) {
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			if (a[i][j] == 0)
				return false;
		}
	}
	return true;
}
int main() {
	InitWindow(540, 540, "Sudoku");
	InitAudioDevice();
	Sound click = LoadSound("click.wav");
	Sound blunder = LoadSound("wrong.mp3");
	int arr[9][9] = {
		{ 7,3,5,6,1,4,8,9,2 },
		{ 8,4,2,9,7,3,5,6,1 },
		{ 9,6,1,2,8,5,3,7,4 },
		{ 2,8,6,3,4,9,1,5,7 },
		{ 4,1,3,8,5,7,9,2,6 },
		{ 5,7,9,1,2,6,4,3,8 },
		{ 1,5,7,4,9,2,6,8,3 },
		{ 6,9,4,7,3,8,2,1,5 },
		{ 3,2,8,5,6,1,7,4,9 }
	};
	srand(time(0));
	int row;
	int column;
	int empty = 50;
	int count = 0;
	bool check;
	bool screen = true;
	int copy[9][9];
	copymaker(arr, copy);
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
		if (screen == true)
		{
			//Diffuculty level window appears
			ClearBackground(BLACK);

			DrawText("SUDOKU Game", 120, 30, 50, DARKGREEN);
			DrawText("By", 250, 70, 20, DARKBLUE);
			DrawText("Hassan", 250, 90, 20, DARKBLUE);
			DrawText("Hashir", 250, 110, 20, DARKBLUE);
			DrawText("Saad", 250, 130, 20, DARKBLUE);
			DrawText("SELECT DIFFICULTY Level", 130, 170, 25, DARKBLUE);

			// Easy button
			DrawRectangle(140, 220, 300, 55, GREEN);
			DrawText("EASY Level", 210, 235, 25, WHITE);

			// Medium button
			DrawRectangle(140, 300, 300, 55, BLUE);
			DrawText("MEDIUM Level", 210, 315, 25, WHITE);

			// Hard button
			DrawRectangle(140, 380, 300, 55, RED);
			DrawText("HARD Level", 210, 395, 25, WHITE);

			// Mouse position
			int x = GetMouseX();
			int y = GetMouseY();

			// Check mouse click
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				if (x >= 140 && x <= 440 &&
					y >= 220 && y <= 275)
				{
					screen = false;
				}

				else if (x >= 140 && x <= 440 &&
					y >= 300 && y <= 355)
				{
					screen = false;
				}

				else if (x >= 140 && x <= 440 &&
					y >= 380 && y <= 435)
				{
					screen = false;
				}
			}
		}


		else
		{
			if (IsKeyPressed(KEY_ONE)) {
				bool go = checker(1, row, column, copy);
				if (go) {
					arr[row][column] = 1;
				}
				else
					PlaySound(blunder);
			}
			else if (IsKeyPressed(KEY_TWO)) {
				bool go = checker(2, row, column, copy);
				if (go) {
					arr[row][column] = 2;
				}
				else
					PlaySound(blunder);
			}
			else if (IsKeyPressed(KEY_THREE)) {
				bool go = checker(3, row, column, copy);
				if (go) {
					arr[row][column] = 3;
				}
				else
					PlaySound(blunder);
			}

			else if (IsKeyPressed(KEY_FOUR)) {
				bool go = checker(4, row, column, copy);
				if (go) {
					arr[row][column] = 4;
				}
				else
					PlaySound(blunder);
			}
			else if (IsKeyPressed(KEY_FIVE)) {
				bool go = checker(5, row, column, copy);
				if (go) {
					arr[row][column] = 5;
				}
				else
					PlaySound(blunder);
			}
			else if (IsKeyPressed(KEY_SIX)) {
				bool go = checker(6, row, column, copy);
				if (go) {
					arr[row][column] = 6;
				}
				else
					PlaySound(blunder);
			}
			else if (IsKeyPressed(KEY_SEVEN)) {
				bool go = checker(7, row, column, copy);
				if (go) {
					arr[row][column] = 7;
				}
				else
					PlaySound(blunder);
			}

			else if (IsKeyPressed(KEY_EIGHT)) {
				bool go = checker(8, row, column, copy);
				if (go) {
					arr[row][column] = 8;
				}
				else
					PlaySound(blunder);
			}

			else if (IsKeyPressed(KEY_NINE)) {
				bool go = checker(9, row, column, copy);
				if (go) {
					arr[row][column] = 9;
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
		}
		EndDrawing();
	}
	UnloadSound(click);
	UnloadSound(blunder);
	CloseAudioDevice();
	CloseWindow();
}