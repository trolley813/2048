#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

const int FIELD_SIZE = 4;
int field[FIELD_SIZE][FIELD_SIZE];
int score;

enum Direction {
	NORTH,
	EAST,
	SOUTH,
	WEST
};

void init_field() {
	int i, j;
	i = rand() % FIELD_SIZE;
	j = rand() % FIELD_SIZE;
	field[i][j] = 4;
	i = rand() % FIELD_SIZE;
	j = rand() % FIELD_SIZE;
	field[i][j] = 2;
	i = rand() % FIELD_SIZE;
	j = rand() % FIELD_SIZE;
	field[i][j] = 2;
}

void print_field() {
	cout << endl;
	for (int i = 0; i < FIELD_SIZE; i++) {
		for (int j = 0; j < FIELD_SIZE; j++) {
			cout << field[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << "Score: " << score << endl;
}

Direction read_direction() {
input:
	char c = _getch();
	switch (c)
	{
	case 'w':
		return NORTH;
	case 's':
		return SOUTH;
	case 'a':
		return WEST;
	case 'd':
		return EAST;
	default:
		goto input;
	}
}

bool has_free_cells() {
	for (int i = 0; i < FIELD_SIZE; i++) {
		for (int j = 0; j < FIELD_SIZE; j++) {
			if (field[i][j] == 0) {
				return true;
			}
		}
	}
	return false;
}

void shift(Direction direction) {
	switch (direction)
	{
	case NORTH:
		for (int j = 0; j < FIELD_SIZE; j++) {
			for (int i = 0; i < FIELD_SIZE - 1; i++) {
				if (field[i][j] == field[i + 1][j]) {
					field[i][j] *= 2;
					field[i + 1][j] = 0;
					score += field[i][j];
				}
				bool shift = false;
				do {
					for (int i = 0; i < FIELD_SIZE - 1; i++) {
						shift = false;
						if (field[i][j] == 0 && field[i + 1][j] != 0) {
							field[i][j] = field[i + 1][j];
							field[i + 1][j] = 0;
							shift = true;
						}
					}
				} while (shift);
			}
		}
		break;
	case EAST:
		break;
	case SOUTH:
		break;
	case WEST:
		break;
	default:
		break;
	}
}

void add_new_element() {
	int i, j;
	do {
		i = rand() % FIELD_SIZE;
		j = rand() % FIELD_SIZE;
	} while (field[i][j]);
	field[i][j] = (rand() % 4) ? 2 : 4;
}

int main() {
	srand(time(0));
	init_field();
	print_field();
	while (has_free_cells()) {
		Direction dir = read_direction();
		shift(dir);
		add_new_element();
		print_field();
	}
}