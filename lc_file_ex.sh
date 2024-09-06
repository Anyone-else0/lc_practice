#!/bin/bash

if [[ $# -ne 2 ]]; then
    echo "param error"
    exit 1
fi

target_file=$1
op_code=$2

if [[ ${op_code} == "commit" ]] then
    # 注释头文件并添加对应的源文件和头文件到当前文件中
    include_ele=`cat ${target_file} | grep -n "#include \"" | grep -v "//" | head -n1`
    while [[ -n ${include_ele} ]]
    do
        echo "handle: ${include_ele}"
        include_line=`echo "${include_ele}" | awk -F':' '{print $1}'`
        include_code=`echo "${include_ele}" | awk -F':' '{print $2}'`
        include_str=`echo "${include_ele}" | awk -F'[".]' '{print $2}'`
        include_head="${include_str}.h"
        include_src="${include_str}.c"
        if [[ ${target_file} == ${include_src} ]]; then
            echo "file error"
            exit 1
        fi
        sed -i "${include_line}s/^/\/\/ lc_comment_ori:&/g" ${target_file}
        sed -i "${include_line}a\/\/ lc_comment_target_end:${include_head}" ${target_file}
        sed -i "${include_line} r ${include_src}" ${target_file}
        sed -i "${include_line} r ${include_head}" ${target_file}
        sed -i "${include_line}a\/\/ lc_comment_target_begin:${include_head}" ${target_file}
        sed -i "/^${include_code}$/d" ${target_file}
        include_ele=`cat ${target_file} | grep -n "#include \"" | grep -v "//" | head -n1`
    done
elif [[ ${op_code} == "rollback" ]]; then
    # 删除添加的文件内容并还原头文件包含
    begin_line=`cat ${target_file} | grep -n lc_comment_target_begin | awk -F':' '{print $1}' | head -n1`
    end_line=`cat ${target_file} | grep -n lc_comment_target_end | awk -F':' '{print $1}' | head -n1`
    while [[ -n ${begin_line} ]]
    do
        sed -i "${begin_line},${end_line}d" ${target_file}
        del_ele=`cat ${target_file} | grep -n "// lc_comment_ori:" | head -n1`
        del_line=`echo "${del_ele}" | awk -F':' '{print $1}'`
        ori_str=`echo "${del_ele}" | awk -F':' '{print $3}'`
        sed -i "${del_line}s/.*/${ori_str}/g" ${target_file}
        begin_line=`cat ${target_file} | grep -n lc_comment_target_begin | awk -F':' '{print $1}' | head -n1`
        end_line=`cat ${target_file} | grep -n lc_comment_target_end | awk -F':' '{print $1}' | head -n1`
    done
else
    echo "op code error"
    exit 1
fi