/******************************************************************************
 * Problem: Food Lines
 * There are n lines of people waiting for food, and the number of people 
 * waiting in each line is known. Then, each of m new people will arrive, 
 * and they will join the shortest line (the line with the fewest number 
 * of people). Our task is to determine the number of people in each line that
 * each of the m people joins.
 * Zingaro, Daniel. Algorithmic Thinking
 *****************************************************************************/ 

#include<stdio.h>
int get_shortest_line(int * lines, int * num_of_lines);
void solve(int * lines, int * num_of_lines, int * num_of_new_people);

int main(void)
{
	int num_lines = 0, new_people = 0;
	scanf("%i %i", &num_lines, &new_people);
	
	int peoplePerLine[num_lines];
	for (int i = 0; i < num_lines; i++) {
		scanf("%i", &peoplePerLine[i]);
	}

	solve(peoplePerLine, &num_lines, &new_people);

	return 0;
}

int get_shortest_line(int * lines, int * num_of_lines)
{
	int shortest = 0;
	for (int i = 1; i < *num_of_lines; i++) {
		if (lines[shortest] > lines[i])
			shortest = i;
	}

	return shortest;
}

void solve(int * lines, int * num_of_lines, int * num_of_new_people)
{
	int shortest = 0;
	for (int i = 0; i < *num_of_new_people; i++) {
		shortest = get_shortest_line(lines, num_of_lines);
		printf("%i\n", lines[shortest]);
		lines[shortest]++;
	}

	return;
}