

read -p 'Enter number' n

i=1
f=1
while [ $i -le $n ]
do

f=`expr $f \* $i`
i=`expr $i + 1`

done

echo 'Fact is' $f
