all: object
	./out
object:
	g++ main.cpp input.cpp quadratic_solver_func.cpp output.cpp -o out
