
echo "Enter 1st number:"
read n1
echo "Enter 2nd number:"
read n2
echo "Enter 3rd number:"
read n3

if [ $n1 -gt $n2 -a $n1 -gt $n3 ]
then
echo $n1 is greater.
elif [ $n2 -gt $n1 -a $n2 -gt $n3 ]
then
echo $n2 is greater.
elif [ $n3 -gt $n1 -a $n3 -gt $n2 ]
then 
echo $n3 is greater.
else
echo all are equal.
fi
