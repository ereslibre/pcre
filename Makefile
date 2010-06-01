all: pcre

pcre: main.cpp
	g++ -o $@ `pkg-config --cflags --libs libpcre` main.cpp

clean:
	rm pcre
