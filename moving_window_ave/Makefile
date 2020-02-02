FLAGS += -lm

filter: filter.c
	gcc -o $@ $^ $(FLAGS)

.PHONY: clean doc plot

clean:
	rm filter

plot:
	./filter > data.csv
	gnuplot gnuplot.txt
doc:
	install manpage ${HOME}/man/man8/mov_filter.1
