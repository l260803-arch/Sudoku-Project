#include"raylib.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
int main() {
	InitWindow(540, 540, "Sudoku");
	InitAudioDevice();
	Sound click = LoadSound("click.wav");
	int easy[9][9];
	int normal[9][9];
	int hard[9][9];
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
	int empty = 35;
	int count = 0;
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
			if (IsKeyPressed(KEY_ONE))
				arr[row][column] = 1;
			else if (IsKeyPressed(KEY_TWO))
				arr[row][column] = 2;
			else if (IsKeyPressed(KEY_THREE))
				arr[row][column] = 3;
			else if (IsKeyPressed(KEY_FOUR))
				arr[row][column] = 4;
			else if (IsKeyPressed(KEY_FIVE))
				arr[row][column] = 5;
			else if (IsKeyPressed(KEY_SIX))
				arr[row][column] = 6;
			else if (IsKeyPressed(KEY_SEVEN))
				arr[row][column] = 7;
			else if (IsKeyPressed(KEY_EIGHT))
				arr[row][column] = 8;
			else if (IsKeyPressed(KEY_NINE))
				arr[row][column] = 9;

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
	CloseAudioDevice();
	CloseWindow();
}


