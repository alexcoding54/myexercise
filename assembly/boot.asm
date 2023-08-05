ORG 0x7C00    ; 设置代码的起始地址为0x7C00，这是x86计算机的启动扇区地址

section .text
    mov ah, 0x00    ; 设置显示模式
    mov al, 0x03    ; 使用VGA文本模式
    int 0x10        ; 调用BIOS中断，设置显示模式

    mov si, message ; 字符串的起始地址

    loop:
        mov di, si    ; 将字符串地址复制到di寄存器中
        mov ah, 0x0E  ; 设置显示属性，使用背景色为黑色
        mov al, [di]  ; 从内存中读取一个字符

        ; 计算颜色索引
        xor bx, bx    ; 使用bx寄存器存储循环计数器，初始化为0
        mov bl, al    ; 将字符存储在bl寄存器中
        and bl, 0x07  ; 使用字符的前三位作为颜色索引

        ; 切换颜色
        mov ah, 0x0B  ; 设置文本背景色
        mov bh, 0x00  ; 设置文本前景色为黑色
        mov cx, bx    ; 将颜色索引存储在cx寄存器中
        int 0x10      ; 调用BIOS中断，设置颜色

        ; 显示字符
        mov ah, 0x0E  ; 设置显示属性
        int 0x10      ; 调用BIOS中断，显示字符

        ; 延迟500ms
        mov cx, 0x1FF
        mov dx, 0x03
    delay_loop:
        dec dx
        jnz delay_loop
        dec cx
        jnz delay_loop

        ; 继续循环
        jmp loop

section .data
    message db 'uOS booting', 0  ; 待显示的字符串，以零字节结尾

times 510 - ($-$$) db 0   ; 填充剩余的空间
dw 0xAA55               ; 声明启动扇区的标志

; 程序的起始地址是0x7C00，计算机会从该地址开始执行