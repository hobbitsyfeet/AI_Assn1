CCC= g++

all : ai_proj
ai_proj : main.o ConvexHull.o Agent.o Environment.o Geometry.o
	$(CCC) -Wc++11- $^ -o $@ 

# $< = the corresponding .cc file
%.o : %.cc
	$(CCC) -c $<

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f ai_proj

run:
	./ai_proj
