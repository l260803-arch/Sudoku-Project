#include"raylib.h"
#include<iostream>
using namespace std;
int main() {
	InitWindow(540, 540, "Sudoku");
	int arr[9][9] = { 0 };
	int row = -1;
	int column = -1;
	while (!(WindowShouldClose())) {
		BeginDrawing();
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			Vector2 mousePos = GetMousePosition();
			column = mousePos.x / 60;
			row = mousePos.y / 60;
		}
		if ((row >= 0 && row < 9) && (column >= 0 && column < 9)) {
			if (IsKeyPressed(KEY_ONE)) {
				arr[row][column] = 1;
				column++;
			}
			if (IsKeyPressed(KEY_TWO)) {
				arr[row][column] = 2;
				column++;
			}
			if (IsKeyPressed(KEY_THREE)) {
				arr[row][column] = 3;
				column++;
			}
			if (IsKeyPressed(KEY_FOUR)) {
				arr[row][column] = 4;
				column++;
			}
			if (IsKeyPressed(KEY_FIVE)) {
				arr[row][column] = 5;
				column++;
			}
			if (IsKeyPressed(KEY_SIX)) {
				arr[row][column] = 6;
				column++;
			}
			if (IsKeyPressed(KEY_SEVEN)) {
				arr[row][column] = 7;
				column++;
			}
			if (IsKeyPressed(KEY_EIGHT)) {
				arr[row][column] = 8;
				column++;
			}
			if (IsKeyPressed(KEY_NINE)) {
				arr[row][column] = 9;
				column++;
			}
		}
		if (column == 9) {
			column = 0;
			row++;
		}
		ClearBackground(RAYWHITE);
		for (int i = 0;i < 9;i++) {
			DrawLine(i * 60, 0, i * 60, 540, BLACK);
			DrawLine(0, i * 60, 540, i * 60, BLACK);
			if (i % 3 == 0 || i == 9) {
				DrawLineEx(
					Vector2{ float(i) * 60, 0 },
					Vector2{ float(i) * 60, 540 },
					4,
					BLACK
				);
				DrawLineEx(
					Vector2{ 0, float(i) * 60 },
					Vector2{ 540, float(i) * 60 },
					4,
					BLACK
				);
			}
		}
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				if (arr[i][j] != 0) {
					DrawText(TextFormat("%d", arr[i][j]), j * 60 + 20, i * 60 + 20, 20, BLACK);
				}
			}
		}
		EndDrawing();
	}
	CloseWindow();
}
