#include "monty.h"
buff_t buf = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *line_content;
	stack_t *stack = NULL;
	FILE *monty_file;
	unsigned int line_counter = 0;
	size_t line_size = 0;
	ssize_t read_line = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	buf.monty_file = monty_file;
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		line_content = NULL;
		read_line = getline(&line_content, &line_size, monty_file);
		buf.line_content = line_content;
		line_counter++;
		if (read_line > 0)
		{
			execute(line_content, &stack, line_counter, monty_file);
		}
		free(line_content);
	}
	free_stack(stack);
	fclose(monty_file);
	return (0);
}
