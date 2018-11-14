i=1
while [ $i = 1 ]
do

echo '1:Add'
echo '2:Sub'
echo '3:Mul'
echo '4:Div'
echo '5:Mod'
read sw
case $sw in
1)

read -p '1st value:' a
read -p '2nd value:' b
c=$(expr "$a" + "$b")
echo "Ans is" $c
;;
2)
read -p '1st value:' a
read -p '2nd value:' b
c=$(expr "$a" - "$b")
echo "Ans is" $c
;;
3)
read -p '1st value:' a
read -p '2nd value:' b
c=$(expr "$a" \* "$b")
echo "Ans is" $c
;;
4)
read -p '1st value:' a
read -p '2nd value:' b
c=$(expr "$a" / "$b")
echo "Ans is" $c
;;
5)
read -p '1st value:' a
read -p '2nd value:' b
c=$(expr "$a" % "$b")
echo "Ans is" $c
;;

esac

read -p 'Continue?' i
done

