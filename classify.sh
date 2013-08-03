#注：
#	通过本脚本，可以在当前目录中创建名称为chapterX的目录
#并将当前目录中对应数值的文件添加到指定目录中

#! bin/bash

for((i=1;i<21;i++))
do
	mkdir chapter$i 
	echo "创建chapter"$i
	mv $i.* ./chapter$i
	echo "mv"$i".* 完成"
done
