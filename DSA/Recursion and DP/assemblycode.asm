section .data
    arr db 3, 1, 4, 2  ; Array elements
    n equ $ - arr      ; Number of elements in the array
    tsum dq 0          ; Total sum initialized to 0
    mini dq 0x7FFFFFFFFFFFFFFF  ; Initialize mini to the maximum possible value

section .text
    global _start

_start:
    ; Calculate total sum of array elements
    mov rcx, n          ; Loop counter
    mov rsi, arr        ; Pointer to array
    mov rax, 0          ; Initialize sum to 0
sum_loop:
    movzx rbx, byte [rsi]   ; Load next array element into rbx
    add rax, rbx            ; Add current element to sum
    inc rsi                 ; Move to next element
    loop sum_loop           ; Continue until all elements are processed
    mov tsum, rax           ; Store total sum

    ; Find minimum absolute difference
    xor rcx, rcx            ; Initialize loop counter to 0
    mov rsi, 0              ; Initialize sum to 0
    mov rdi, tsum           ; Total sum
    call solve              ; Call recursive function

    ; Print result (mini)
    mov rdi, mini
    mov rax, 1              ; syscall number for sys_write (stdout)
    mov rsi, rdi            ; pointer to message
    mov rdx, 20             ; length of message
    syscall

    ; Exit program
    mov rax, 60             ; syscall number for sys_exit
    xor rdi, rdi            ; Exit code 0
    syscall

solve:
    ; Recursive function to find minimum absolute difference
    ; Parameters:
    ;   rdi - current element
    ;   rsi - sum of current subset
    ;   rcx - current index
    ;   rdx - total sum
    ;   r8  - address of mini
    ;   r9  - number of elements (n)
    ; Returns:
    ;   mini - minimum absolute difference

    ; Base case: If we reached the end of the array
    cmp rcx, n          ; Check if index is equal to n
    je end_solve        ; If so, return

    ; Include current element in the sum
    movzx rbx, byte [arr + rcx]  ; Load current array element
    add rsi, rbx                  ; Add current element to sum

    ; Calculate absolute difference
    mov rax, rsi          ; Load sum into rax
    sub rax, rdx          ; Subtract total sum
    cmp rax, 0            ; Compare with 0
    jge skip_update_mini  ; If greater than or equal to 0, skip update_mini

    neg rax               ; Negate to get absolute value
    cmp rax, [r8]         ; Compare with mini
    jae skip_update_mini  ; If greater than or equal to mini, skip update_mini
    mov [r8], rax         ; Update mini

skip_update_mini:
    ; Recursively call solve with the next index
    inc rcx               ; Increment index
    call solve            ; Recursive call

    ; Exclude current element from the sum and continue
    sub rsi, rbx          ; Subtract current element from sum
    jmp solve             ; Continue solving

end_solve:
    ret
