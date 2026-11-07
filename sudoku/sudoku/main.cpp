#include"raylib.h"
#include<iostream>
using namespace std;
int main() {
	InitWindow(540, 540, "Sudoku");
	InitAudioDevice();
	Sound click = LoadSound("click.wav");
	int arr[9][9] = { 0 };
	int row = -1;
	int column = -1;
	int i = 0, j = 0;
	int number;
	while (!(WindowShouldClose())) {
		BeginDrawing();
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			Vector2 mousePos = GetMousePosition();
			column = mousePos.x / 60;
			row = mousePos.y / 60;
			PlaySound(click);
		}
		ClearBackground(RAYWHITE);

		if (i <= 8) {
			if (IsKeyPressed(KEY_ONE))
				number = 1;
			else if (IsKeyPressed(KEY_TWO))
				number = 2;
			else if (IsKeyPressed(KEY_THREE))
				number = 3;
			else if (IsKeyPressed(KEY_FOUR))
				number = 4;
			else if (IsKeyPressed(KEY_FIVE))
				number = 5;
			else if (IsKeyPressed(KEY_SIX))
				number = 6;
			else if (IsKeyPressed(KEY_SEVEN))
				number = 7;
			else if (IsKeyPressed(KEY_EIGHT))
				number = 8;
			else if (IsKeyPressed(KEY_NINE))
				number = 9;
			else
				number = 0;
			if (number != 0) {
				arr[i][j] = number;
				
				if (j < 8) 
					j++;

				else {
					j = 0;
					i++;
				}
			}
		}

		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				if (arr[i][j] != 0) {
					DrawText(TextFormat("%d", arr[i][j]), j * 60 + 20, i * 60 + 20, 20, BLACK);
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


