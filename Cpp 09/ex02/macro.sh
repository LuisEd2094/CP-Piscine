for ((i = 1; i <= $1; i++)); do
    echo "Iteration $i:"
    ./PmergeMe $(awk -v n="$2" 'BEGIN{srand(); for(i=0;i<n;i++) print int(1 + rand()*100000)}' | tr "\n" " ")
    echo "---------------------------------------"
done