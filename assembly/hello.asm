section .data
    msg db "Hello", 0

section .code
    global _start

_start:
    mov ah, 09h
    mov dx, msg
    int 21h

    mov ah, 01h
    xor bx, bx
    int 21h