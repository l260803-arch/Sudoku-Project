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
		ClearBackground(RAYWHITE);
		for (int i = 0;i < 9;i++) 
			DrawLine(i * 60, 0, i * 60, 540, BLACK);
			DrawLine(0, i * 60, 540, i * 60, BLACK);
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





