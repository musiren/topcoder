#include <stdio.h>
#include <stdbool.h>

#define L 10

int AnswerN;

char *Map[] = {"X....L..LX",
 			   "X........X",
 			   "X.L.....RS",
 			   "X........X",
 			   "X......L.X",
 			   "X........X",
 			   "X.L....L.X",
 			   "T....L...X",
 			   "X......L.X",
 			   "X........X"};

int move_to_storage(int i, int j, char direction, int *count) {
	int first = *count;
	int second = *count + 1;

	if (i < 0 || i > L-1) {
		*count = -1;
		return false;
	}

	printf("[%d][%d] %c: %d\n", i, j, direction, *count);

	switch(direction) {
	case 'u':
		if (Map[i][j] == '.') {
			return move_to_storage(i-1, j, direction, count);
		} else if (Map[i][j] == 'L') {
			return move_to_storage(i, j+1, 'r', &first) || move_to_storage(i, j-1, 'l', &second);
		} else if (Map[i][j] == 'R') {
			return move_to_storage(i, j-1, 'l', &first) || move_to_storage(i, j+1, 'r', &second);
		} else if (Map[i][j] == 'X') {
			return false;
		} else if(Map[i][j] == 'S') {
			printf("[%d][%d] Arrive: %d\n", i, j, *count);
			AnswerN = (AnswerN > *count) && (AnswerN != -1 || *count != -1) ? AnswerN : *count;
			return true;
		}
		break;
	case 'd':
		if (Map[i][j] == '.') {
			return move_to_storage(i+1, j, direction, count);
		} else if (Map[i][j] == 'L') {
			return move_to_storage(i, j-1, 'l', &first) || move_to_storage(i, j+1, 'r', &second);
		} else if (Map[i][j] == 'R') {
			return move_to_storage(i, j+1, 'r', &first) || move_to_storage(i, j-1, 'l', &second);
		} else if (Map[i][j] == 'X') {
			return false;
		} else if(Map[i][j] == 'S') {
			printf("[%d][%d] Arrive: %d\n", i, j, *count);
			AnswerN = (AnswerN > *count) && (AnswerN != -1 || *count != -1) ? AnswerN : *count;
			return true;
		}
		break;
	case 'l':
		if (Map[i][j] == '.') {
			return move_to_storage(i, j-1, direction, count);
		} else if (Map[i][j] == 'L') {
			return move_to_storage(i+1, j, 'd', &first) || move_to_storage(i-1, j, 'u', &second);
		} else if (Map[i][j] == 'R') {
			return move_to_storage(i-1, j, 'u', &first) || move_to_storage(i+1, j, 'd', &second);
		} else if (Map[i][j] == 'X') {
			return false;
		} else if(Map[i][j] == 'S') {
			printf("[%d][%d] Arrive: %d\n", i, j, *count);
			AnswerN = (AnswerN > *count) && (AnswerN != -1 || *count != -1) ? AnswerN : *count;
			return true;
		}
		break;
	case 'r':
		if (Map[i][j] == '.') {
			return move_to_storage(i, j+1, direction, count);
		} else if (Map[i][j] == 'L') {
			return move_to_storage(i-1, j, 'u', &first) || move_to_storage(i+1, j, 'd', &second);
		} else if (Map[i][j] == 'R') {
			return move_to_storage(i+1, j, 'd', &first) || move_to_storage(i-1, j, 'u', &second);
		} else if (Map[i][j] == 'X') {
			return false;
		} else if(Map[i][j] == 'S') {
			printf("Arrive with %d changes\n", *count);
			AnswerN = (AnswerN > *count) && (AnswerN != -1 || *count != -1) ? AnswerN : *count;
			return true;
		}
		break;
	}

	return false;
}

int main(int argc, char *argv[])
{
	int i, j, count = 0;
	int terminal;
	AnswerN = -1;
	for (i = 0; i < L; i++) {
		if (Map[i][0] == 'T') {
			terminal = i;
			break;
		}
	}

	move_to_storage(terminal, 1, 'r', &count);

	printf("AnswerN: %d\n", AnswerN);
}
