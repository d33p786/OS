main=`pwd`
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
echo
ls --group-directories-first
;;

2)
clear
echo 'Directories :'
tree -d
echo
read -p 'Choose Directory:' dir
cd $dir
read -p 'Enter Name :' dname
mkdir $dname
echo
echo 'Directory created Successfully.'
cd $main
echo
echo 'Result:'
tree -d
;;

3)
clear
echo 'Directories :'
tree -d
read -p 'Choose Directory:' dir
read -p 'Enter File Name :' fname
cd $dir | gedit $fname
echo
echo 'File created Successfully.'
echo
echo 'Result:'
ls | grep "$fname"  
cd $main
;;

4)
clear
echo 'Files:'
tree
read -p 'Choose Directory:' dir
cd $dir
read -p 'Enter File Name:' fname
read -p 'Enter New Name;' new
mv $fname $new
echo
echo 'File Renamed Sucessfully.'
ls |  grep "$new" 
cd $main
;;

5)
clear
echo 'Directories :'
tree -d
read -p 'Choose Directory:' dir
cd $dir
read -p 'Enter Directory :' dname
read -p 'Enetr New Name:' new
mv $dname $new
echo 'Directory Renamed Successfully.'
cd $main
tree -d
;;

6)
clear
echo 'Files:'
tree
read -p 'Choose Directory:' dir
cd $dir
read -p 'Enter File Name:' fname
rm $fname
echo
echo 'File Removed Sucessfully.'
ls -f
cd $main
;;

7)
clear
echo 'Directories :'
tree -d
read -p 'Choose Directory:' dir
cd $dir
read -p 'Enter directory name:' dname
rm -rf $dname
echo
echo 'Directory Removed Successfully.'
cd $main
tree -d
;;

8)
clear
ls
echo
read -p 'Enter File name;' fname
find $main -name $fname
;;

9)
clear
echo 'Present Working Directory is :'
pwd
;;
esac

echo
read -p 'Do you want to Continue?' i
done
