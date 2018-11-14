read -p 'Enter number :' n
a=0
b=1
i=0
echo $a
echo $b
while [ $i -lt $n ]
do
r=$(expr "$a" + "$b")
echo $r
a=$b
b=$r
i=$(expr "$i" + 1)
done
