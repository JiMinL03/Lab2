# 정적 라이브러리 만들기
OBJECTS = add.o sub.o mul.o div.o
MAKE: libStatic.a

libStatic.a: $(OBJECTS)
	ar rcs $@ $(OBJECTS)

add.o: add.c
	gcc -c $<  # -c 플래그를 추가하여 객체 파일 생성

sub.o: sub.c
	gcc -c $<  # -c 플래그를 추가하여 객체 파일 생성

mul.o: mul.c
	gcc -c $<  # -c 플래그를 추가하여 객체 파일 생성

div.o: div.c
	gcc -c $<  # -c 플래그를 추가하여 객체 파일 생성

clean:
	rm -f *.o libStatic.a

