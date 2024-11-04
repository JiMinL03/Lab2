# main.c와 sub 디렉토리의 헤더 파일을 포함하여 빌드
main: main.c
	gcc -I./sub -o main.o main.c -L./sub -lStatic

clean:
	rm -f main.o

