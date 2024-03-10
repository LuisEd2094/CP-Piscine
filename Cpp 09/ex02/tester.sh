for ((i = 1; i <= 9000; i++)); do
    bash macro.sh 10 "$i" 2> err.log 1> out.logs
    echo $i "NUMBERS TESTED"
done