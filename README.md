leetcode practice code.

my idea
    1.provide infra func lib with clang for leetcode practice.
    2.keep my solution for leetcode.

usage of lc_file_ex.sh
    submit: bash lc_file_ex.sh file commit
    this command can extract lib in your source file, then source file with lib can commit to leetcode.
    rollback: bash lc_file_ex.sh file rollback
    this command can rollback the extracted lib in your source file, then ut can be ran.

usage of command.gdb
    provide some usable gdb command for debug.