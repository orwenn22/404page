CXX = g++
raylib = raylib/src


executable: ./src/*.cpp ./src/States/*.cpp ./src/Breakout/*.cpp
	${CXX} ./src/*.cpp ./src/States/*.cpp ./src/Breakout/*.cpp -o executable -L${raylib} -I${raylib} -lraylib -ldl -lpthread


# require EMSDK to be in the PATH
# TODO: make the changes requiered to remove ASYNCIFY
404.html: ./src/*.cpp ./src/States/*.cpp ./src/Breakout/*.cpp ./src/Matrix/*.cpp
	emcc ./src/*.cpp ./src/States/*.cpp ./src/Breakout/*.cpp ./src/Matrix/*.cpp ./raylib/src/libraylib.a \
		-o 404.html \
		-I${raylib} -s USE_GLFW=3 -s ASYNCIFY \
		--preload-file res/404mac.png \
		--shell-file shell.html