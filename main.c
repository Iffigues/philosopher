#include "./include/philosopher.h"

int main(int argc, char **argv) {
	t_opt *opt;

	opt = NULL;
	opt = make_opt(argc, argv);
	if (opt == NULL) {
		write(1, "bad option", 10);
		return (1);
	}
	start(opt);;
	return (0);
}
