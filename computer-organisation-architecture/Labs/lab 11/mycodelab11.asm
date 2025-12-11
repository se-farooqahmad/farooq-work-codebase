ORG 0x100
mov SI,0
mov ah,00
mov al,03h
int 10h 

MOV AH, 06h    ; Scroll up function
XOR AL, AL     ; Clear entire screen
XOR CX, CX     ; Upper left corner CH=row, CL=column
MOV DX, 184FH  ; lower right corner DH=row, DL=column 
MOV BH, 11110000b ;background color = white and foreground color = black
INT 10H

mov ah,02
mov bh,0
mov dh,12
mov dl,40
int 10h  
mov dl,'C'
mov ah,02h
int 21h 
mov ah,07h
int 21h
cmp al,'L'
je left
again1: 
mov dl,[R+SI]
cmp dl,0
je terminate 
inc SI
mov ah,02h
int 21h 
jmp again1


left: 
mov ah,02
mov bh,0
mov dh,12
mov dl,35
int 10h 

again2: 
mov dl,[L+SI]
cmp dl,0
je terminate 
inc SI
mov ah,02h
int 21h 
jmp again2
terminate:

MOV AX,0x4C00
INT 21H
L:db "Left",0
R:db "Right",0