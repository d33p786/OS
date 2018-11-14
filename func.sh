# Write a program to compute net sal and gross sal of an employee given code
# allegance deduction and basic pay

get()
{
read -p 'Enter code' code
read -p 'enter all' all
read -p 'enter ded' ded
read -p 'enter bp' bp
}

display()
{
echo 'the code is' $code
echo 'the all is' $all
echo 'the ded is' $ded
echo 'the bp is' $bp
}

get $code $all $ded $bp

gross=`expr $bp + $all`
net=`expr $gross - $ded`

echo 'Gross sal is' $gross
echo 'Net sal is' $net

