g++ -O2 $1;
for f in *.in; do
	echo $f
	./a.out <$f >"${f%.*}.out"
done;
