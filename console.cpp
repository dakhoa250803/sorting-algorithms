#include <windows.h>
#include <WinCon.h>

void setColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void setWhiteText() {
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void setLightWhiteText() {
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void setBlackText() {
	setColor(0);
}

void setYellowText() {
	setColor(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void setLightYellowText() {
	setColor(FOREGROUND_GREEN | FOREGROUND_RED);
}

void setGreenText() {
	setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void setLightGreenText() {
	setColor(FOREGROUND_GREEN);
}

void setLightRedText() {
	setColor(FOREGROUND_RED);
}

