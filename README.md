leetcode practice code

1.provide infra func lib.
2.keep my solution for leetcode.

submit:
    bash lc_file_ex.sh file commit
ut:
    bash lc_file_ex.sh file rollback

gdb print array:
set $array = info.ppMark
set $rows = 5
set $cols = 5
set $i = 0
while $i < $rows
    set $j = 0
    while $j < $cols
        printf "%3d", ($array)[$i][$j]
        set $j = $j + 1
    end
    printf "\n"
    set $i = $i + 1
end

