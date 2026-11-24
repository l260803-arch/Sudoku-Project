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
	srand(time(0));
	// swap rows
	for (int i = 0;i < 9;i += 3) {
		int r1 = i + rand() % 3;
		int r2 = i + rand() % 3;
		for (int j = 0;j < 9;j++) {
			swap(sudoku[r1][j], sudoku[r2][j]);


		}
	}
	//swap columns
	for (int i = 0;i < 9;i += 3) {
		int c1 = i + rand() % 3;
		int c2 = i + rand() % 3;
		for (int i = 0;i < 9;i++) {
			swap(sudoku[i][c1], sudoku[i][c2]);
			for (int j = 0;j < 9;j++) {
				swap(sudoku[j][c1], sudoku[j][c2]);

			}

		}
		//random swapping
		int n1 = rand() % 9 + 1;
		int n2 = rand() % 9 + 1;
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				if (sudoku[i][j] == n1)
				{
					sudoku[i][j] = n2;
				}
				else if (sudoku[i][j] == n2) {
					sudoku[i][j] = n1;
				}
			}
		}

	}

}
void emptyboxes(int count, int empty, int a[][9]) {
	count = 0;
	while (count < empty) {
		int randomrow = rand() % 9;
		int randomcolumn = rand() % 9;
		if (a[randomrow][randomcolumn] != 0) {
			a[randomrow][randomcolumn] = 0;
			count++;
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
	Sound win = LoadSound("win.mp3");
	Sound haww = LoadSound("dumb.mp3");
	int loosecount = 0;
	bool loose = false;
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
	bool screen = true;
	int copy[9][9];
	bool success = false;
	int n = 0;
	copymaker(arr, copy);
	while (!(WindowShouldClose())) {
		BeginDrawing();
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			Vector2 mousePos = GetMousePosition();
			column = mousePos.x / 60;
			row = mousePos.y / 60;
			loosecount=0;
			PlaySound(click);
		}
		ClearBackground(RAYWHITE);
		if (screen == true)
		{
			
			ClearBackground(BLACK);

			DrawText("SUDOKU Game", 120, 30, 50, DARKGREEN);
			DrawText("By", 250, 80, 20, DARKBLUE);
			DrawText("Hassan", 250, 100, 20, DARKBLUE);
			DrawText("Hashir", 250, 120, 20, DARKBLUE);
			DrawText("Saad", 250, 140, 20, DARKBLUE);
			DrawText("SELECT DIFFICULTY Level", 130, 170, 25, YELLOW);

			DrawRectangle(140, 220, 300, 55, GREEN);
			DrawText("EASY Level", 210, 235, 25, WHITE);

			
			DrawRectangle(140, 300, 300, 55, BLUE);
			DrawText("MEDIUM Level", 210, 315, 25, WHITE);

			
			DrawRectangle(140, 380, 300, 55, RED);
			DrawText("HARD Level", 210, 395, 25, WHITE);

			
			int x = GetMouseX();
			int y = GetMouseY();

		
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				if (x >= 140 && x <= 440 &&
					y >= 220 && y <= 275)
				{
					copymaker(copy, arr);
					shuffleSudoku(arr);
					copymaker(arr, copy);
					emptyboxes(0, 20, arr);
					n = 5;
					screen = false;
				}

				else if (x >= 140 && x <= 440 &&
					y >= 300 && y <= 355)
				{
					copymaker(copy, arr);
					shuffleSudoku(arr);
					copymaker(arr, copy);
					emptyboxes(0, 40, arr);
					n = 4;
					screen = false;
				}

				else if (x >= 140 && x <= 440 &&
					y >= 380 && y <= 435)
				{
					copymaker(copy, arr);
					shuffleSudoku(arr);
					copymaker(arr, copy);
					emptyboxes(0, 59, arr);
					n = 3;
					screen = false;
				}
			}
		}


		else if(screen==false && success==false && loose==false)
		{
			if (IsKeyPressed(KEY_ONE)) {
				bool go = checker(1, row, column, copy);
				if (go) {
					arr[row][column] = 1;
					loosecount = 0;
				}
				else if(!go&&loosecount<n) {
					PlaySound(blunder);
					loosecount++;
				}
				bool final = fillcheck(arr);
				if (final) {
					PlaySound(win);
					success = true;
				}
				if (loosecount == n)
					PlaySound(haww);
			}
			else if (IsKeyPressed(KEY_TWO)) {
				bool go = checker(2, row, column, copy);
				if (go) {
					arr[row][column] = 2;
					loosecount = 0;
				}
				else if (!go && loosecount < n) {
					PlaySound(blunder);
					loosecount++;
				}
				bool final = fillcheck(arr);
				if (final) {
					PlaySound(win);
					success = true;
				}
				if (loosecount == n)
					PlaySound(haww);
			}
			else if (IsKeyPressed(KEY_THREE)) {
				bool go = checker(3, row, column, copy);
				if (go) {
					arr[row][column] = 3;
					loosecount = 0;
				}
				else if (!go && loosecount < n) {
					PlaySound(blunder);
					loosecount++;
				}
				bool final = fillcheck(arr);
				if (final) {
					PlaySound(win);
					success = true;
				}
				if (loosecount == n)
					PlaySound(haww);
			}

			else if (IsKeyPressed(KEY_FOUR)) {
				bool go = checker(4, row, column, copy);
				if (go) {
					arr[row][column] = 4;
					loosecount = 0;
				}
				else if (!go && loosecount < n) {
					PlaySound(blunder);
					loosecount++;
				}
				bool final = fillcheck(arr);
				if (final) {
					PlaySound(win);
					success = true;
				}
				if (loosecount == n)
					PlaySound(haww);
			}
			else if (IsKeyPressed(KEY_FIVE)) {
				bool go = checker(5, row, column, copy);
				if (go) {
					arr[row][column] = 5;
					loosecount = 0;
				}
				else if(!go&&loosecount<n) {
					PlaySound(blunder);
					loosecount++;
				}
				bool final = fillcheck(arr);
				if (final) {
					PlaySound(win);
					success = true;
				}
				if (loosecount == n)
					PlaySound(haww);
			}
			else if (IsKeyPressed(KEY_SIX)) {
				bool go = checker(6, row, column, copy);
				if (go) {
					arr[row][column] = 6;
					loosecount = 0;
				}
				else if (!go && loosecount < n) {
					PlaySound(blunder);
					loosecount++;
				}
				bool final = fillcheck(arr);
				if (final) {
					PlaySound(win);
					success = true;
				}
				if (loosecount == n)
					PlaySound(haww);
			}
			else if (IsKeyPressed(KEY_SEVEN)) {
				bool go = checker(7, row, column, copy);
				if (go) {
					arr[row][column] = 7;
					loosecount = 0;
				}
				else if (!go && loosecount < n) {
					PlaySound(blunder);
					loosecount++;
				}
				bool final = fillcheck(arr);
				if (final) {
					PlaySound(win);
					success = true;
				}
				if (loosecount == n)
					PlaySound(haww);
			}

			else if (IsKeyPressed(KEY_EIGHT)) {
				bool go = checker(8, row, column, copy);
				if (go) {
					arr[row][column] = 8;
					loosecount = 0;
				}
				else if (!go && loosecount < n) {
					PlaySound(blunder);
					loosecount++;
				}
				bool final = fillcheck(arr);
				if (final) {
					PlaySound(win);
					success = true;
				}
				if (loosecount == n)
					PlaySound(haww);
			}

			else if (IsKeyPressed(KEY_NINE)) {
				bool go = checker(9, row, column, copy);
				if (go) {
					arr[row][column] = 9;
					loosecount = 0;
				}
				else if (!go && loosecount < n) {
					PlaySound(blunder);
					loosecount++;
				}
				bool final = fillcheck(arr);
				if (final) {
					PlaySound(win);
					success = true;
				}
				if (loosecount == n)
					PlaySound(haww);
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
		else if (success == true) {
			ClearBackground(BLACK);
			DrawCircle(270, 270, 200, SKYBLUE);
			DrawText("You Won!", 140, 230, 50, WHITE);
			DrawRectangle(450, 80, 80, 40, GREEN);
			DrawText("Restart", 460, 90, 17, DARKBLUE);
			int escapex = GetMouseX();
			int escapey = GetMouseY();
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				if ((escapex >= 450 && escapex <= 530) && (escapey >= 80 && escapey <= 120)) {
					success = false;
					screen = true;
					loosecount = 0;
				}
			}
		}
		if (n == 5) {
			if (loosecount == 5) {
				loose = true;
			}
		}
		if (n == 4) {
			if (loosecount == 4) {
				loose = true;
			}
		}
		if (n == 3) {
			if (loosecount == 3) {
				loose = true;
			}
		}
		if (loose == true) {
			ClearBackground(BLACK);
			DrawCircle(270, 270, 200, SKYBLUE);
			DrawText("You Loose!", 140, 230, 50, WHITE);
			DrawRectangle(450, 80, 80, 40, GREEN);
			DrawText("Restart", 460, 90, 17, DARKBLUE);
			int escapex = GetMouseX();
			int escapey = GetMouseY();
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				if ((escapex >= 450 && escapex <= 530) && (escapey >= 80 && escapey <= 120)) {
					loose = false;
					screen = true;
					loosecount = 0;
				}
			}
		}
		EndDrawing();
	}
	UnloadSound(click);
	UnloadSound(blunder);
	UnloadSound(win);
	UnloadSound(haww);
	CloseAudioDevice();
	CloseWindow();
}
