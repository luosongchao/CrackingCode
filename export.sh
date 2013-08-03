#注：
#	通过这个脚本，可以将当前文件夹中所有目录为chapterX
#文件中，所有子文件，移动到其上一层目录中
#!bin/bash

for dir in `find -type d -name "chapter*"` 
do
	name=`echo "$dir" | awk -F/ '{ print $2}'`  #获取文件夹中所有目录的名称
	cd ~/桌面/CFile/craking-code/$name
	cp * ~/桌面/CFile/craking-code/
	echo "移动"$PWD"中所有文件，完成"
	cd   ~/桌面/CFile/craking-code/
done

