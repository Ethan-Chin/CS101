while true; do

    ./c4001 < teat.in > my.out #被测程序

    ./sample < teat.in > std.out #正确（暴力）程序

    if diff my.out std.out; then #比较两个输出文件

        printf "AC\n"  #结果相同显示AC

    elif diff -B -b my.out std.out; then

        printf "PE\n"

    else

        printf "WA\n" #结果不同显示WA，并退出

        exit 0  

    fi  

done 
