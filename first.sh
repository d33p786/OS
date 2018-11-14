
i=1

while [ $i = 1 ]
do

echo '================[OPTIONS]==============='
echo '1. List the Files and Directories'
echo '2. Create a Directory'
echo '3. Create a File'
echo '4. Rename a File'
echo '5. Rename a Directory'
echo '6. Delete a File'
echo '7. Delete a Directory'
echo '8. Search a File'
echo '9. Check Present Working Directory'

read -p 'Enter Your Choice :' ch

case $ch in

1)
clear
echo 'Files and Directories :'
ls
;;

2)
clear

read -p 'Enter Name :' dname
mkdir $dname
echo 'Directory created Successfully.'
echo 'Result:'
ls -d */
;;

3)
clear
read -p 'Enter File Name :' fname
vi $fname
echo 'File created Successfully.'
echo 'Result:'
ls -d */
;;

4)
clear
echo 'Files:'
ls -f
read -p 'Enter File Name:' fname
read -p 'Enter New Name;' new
mv $fname $new
echo 'File Renamed Sucessfully.'
ls -f
;;

5)
clear
echo 'Directories :'
ls -d */
read -p 'Enter ditectory:' dname
read -p 'enetr new name:' new
mv $dname $new
echo 'Directory Renamed Successfully.'
ls -d */
;;

6)
clear
echo 'Files:'
ls -f
read -p 'Enter file name:' fname
rm $fname
echo 'File Removed.'
ls -f
;;

7)
clear
echo 'Directories :'
ls -d */
read -p 'Enter directory name:' dname
rmdir $dname
echo 'Directory Removed'
ls -d */
;;

8)
clear
ls
read -p 'Enter File name;' fname
find . -name $fname
;;

9)
echo 'Present Working Directory is :'
pwd
;;
esac

read -p 'Continue?' i
done
