for ((i = 1; i <= 9000; i++)); do
    bash macro.sh 20 "$i" 2>> err.log 1> /dev/null
    echo $i "NUMBERS TESTED"
done