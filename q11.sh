//64050240
for file in $(find . -type f -name "*.c")
do
	trimmedName= `(echo $file | cut -d'/' -f2)`
	outName=`(echo $trimmedName | cut -d'.' -f1)`
	gcc -o $outName $trimmedName 2>/dev/null
	if [ -f $trimmedName ] 
	then 
		ans=$(./$outName)
		if [ "$ans" = "20"]
		then
			point=10
		else
			point=7
		fi
	else
		point=5
	fi 
	printf "%s %s\n" $trimmedName $point
done



