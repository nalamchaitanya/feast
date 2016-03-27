for t in {5..20..1}
do
	echo Running ${t}...
	./encrypt ${t}.txt ${t}.enc >> time.enc
	./decrypt ${t}.enc ${t}.dec
	diff ${t}.enc ${t}.dec
done
