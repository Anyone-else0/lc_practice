define p_help
    printf "usage of command\n\n"
    printf "1.打印二维数组\n"
    printf "    p_list arrayAddr rowSize colSize\n"
    printf "1.打印双向链表\n"
    printf "    p_list listHeadAddr entryType entryNodeName\n"
end

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

define p_list
    set $list = $arg0
    set $tmpNode = $list->pNext
    while $tmpNode != $list
        printf "node addr:"
        p $tmpNode
        printf "next:"
        p $tmpNode->pNext
        printf "prev:"
        p $tmpNode->pPrev
        set $offset = &((($arg1 *)0)->$arg2)
        set $tmpEntry = ($arg1 *)((char *)$tmpNode - (char *)$offset)
        printf "entry addr:"
        p $tmpEntry
        p *($tmpEntry)
        set $tmpNode = $tmpNode->pNext
    end
end