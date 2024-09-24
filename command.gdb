define p_array
    set $array = $arg0
    set $rows = $arg1
    set $cols = $arg2
    set $i = 0
    while $i < $rows
        set $j = 0
        while $j < $cols
            printf "%6d", ($array)[$i][$j]
            set $j = $j + 1
        end
        printf "\n"
        set $i = $i + 1
    end
end