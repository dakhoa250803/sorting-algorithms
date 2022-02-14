#include <conio.h>
#include <iostream>
#include "keyboard.h"

KeyCode getKeyPressed() {
	return (KeyCode)_getch();
}
