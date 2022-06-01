.586
.model flat, stdcall
option casemap:none

include \masm32\include\windows.inc
include \masm32\include\user32.inc
includelib \masm32\lib\user32.lib
include \masm32\include\kernel32.inc
includelib \masm32\lib\kernel32.lib
include \masm32\include\gdi32.inc
includelib \masm32\lib\gdi32.lib
include \masm32\include\masm32.inc
includelib \masm32\lib\masm32.lib

WinMain proto :HINSTANCE,:HINSTANCE,:LPSTR,:DWORD

.data
    windowClass db "Window class", 0
    buttonClass db "button", 0
    editClass db "edit", 0

    windowTitle db "Sample Text", 0
    buttonText db "Add", 0
    inputAGhost db "First number", 0
    inputBGhost db "Second number", 0
    resultGhost db "Result", 0

.data?
    hInstance   HINSTANCE ?
    hWndButton  HWND ?
    hWndInputA  HWND ?
    hWndInputB  HWND ?
    hWndResult  HWND ?
    inputABuff  db 256 dup (?)
    inputBBuff  db 256 dup (?)
    resultBuff  db 16 dup (?)

.const
    idButton equ 1
    idInputA equ 2
    idInputB equ 3
    idResult equ 4
.code
;********************** ENTRY POINT ************************;
start:
    invoke  GetModuleHandle, NULL
    mov     hInstance, eax
    invoke  WinMain, eax, NULL, NULL, SW_SHOWDEFAULT
    invoke  ExitProcess, eax

;********************** WINAPI ENTRY ***********************;
WinMain proc hInst:HINSTANCE,hPrevInst:HINSTANCE,sCmdLine:LPSTR,nCmdShow:DWORD
    ; Process initialization
    local   wcex:WNDCLASSEX
    local   hWnd:HWND
    local   message:MSG

    mov     wcex.cbSize, SIZEOF WNDCLASSEX
    mov     wcex.style, CS_HREDRAW or CS_VREDRAW
    mov     wcex.lpfnWndProc, offset WndProc
    mov     wcex.cbClsExtra, NULL
    mov     wcex.cbWndExtra, NULL
    push    hInst
    pop     wcex.hInstance
    invoke  LoadIcon, NULL, IDI_APPLICATION
    mov     wcex.hIcon, eax
    mov     wcex.hIconSm, eax
    invoke  LoadCursor, NULL, IDC_ARROW
    mov     wcex.hCursor, eax
    mov     wcex.hbrBackground,COLOR_BTNFACE+1
    mov     wcex.lpszMenuName, NULL
    mov     wcex.lpszClassName, offset windowClass

    invoke  RegisterClassEx, addr wcex
    test    eax, eax
    jz      fail

    ; Main window
    invoke  CreateWindowEx, NULL, \
            addr windowClass, addr windowTitle, \
            WS_OVERLAPPEDWINDOW, \
            CW_USEDEFAULT, CW_USEDEFAULT, \
            500, 120, \
            NULL, NULL, hInst, NULL

    mov     hWnd, eax
    test    eax, eax
    jz      fail

    invoke  ShowWindow, hWnd, nCmdShow
    invoke  UpdateWindow, hWnd

    ; Message loop
    messageLoop:
        invoke  GetMessage, addr message, NULL, 0, 0
        cmp     eax, 0
        jl      fail
        je      processEnd

        invoke  TranslateMessage, addr message
        invoke  DispatchMessage, addr message
        jmp     messageLoop

    processEnd:
        xor     eax, eax
        ret
    fail:
        invoke GetLastError
        ret
WinMain endp

WndProc proc hWnd:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM
    .IF uMsg==WM_CREATE
;********************** GUI CREATION ***********************;
        invoke  CreateWindowEx, WS_EX_CLIENTEDGE, \
                addr editClass, addr inputAGhost, \
                WS_CHILD or WS_VISIBLE or WS_BORDER or ES_LEFT or ES_AUTOHSCROLL, \
                10, 10, 200, 30, hWnd, idInputA, hInstance, NULL
        mov hWndInputA, eax
        invoke  CreateWindowEx, WS_EX_CLIENTEDGE, \
                addr editClass, addr inputBGhost, \
                WS_CHILD or WS_VISIBLE or WS_BORDER or ES_LEFT or ES_AUTOHSCROLL, \
                10, 40, 200, 30, hWnd, idInputB, hInstance, NULL
        mov hWndInputB, eax

        invoke  CreateWindowEx, NULL, \
                addr buttonClass, addr buttonText, \
                WS_VISIBLE or WS_CHILD or BS_DEFPUSHBUTTON, \
                210, 25, 60, 30, hWnd, idButton, hInstance, NULL
        mov     hWndButton, eax
        invoke  SetFocus, hWndButton

        invoke  CreateWindowEx, WS_EX_CLIENTEDGE, \
                addr editClass, addr resultGhost, \
                WS_CHILD or WS_VISIBLE or WS_BORDER or ES_LEFT or ES_AUTOHSCROLL or ES_READONLY, \
                270, 25, 200, 30, hWnd, idResult, hInstance, NULL
        mov hWndResult, eax

    .ELSEIF uMsg==WM_COMMAND
;********************** GUI PROCESS ************************;
        mov eax, wParam
        .IF ax == idButton
            shr eax, 10h
            .IF ax == BN_CLICKED
                invoke GetWindowText, hWndInputA, addr inputABuff, 256
                invoke atodw, addr inputABuff
                push eax

                invoke GetWindowText, hWndInputB, addr inputBBuff, 256
                invoke atodw, addr inputBBuff
                pop ebx

                add eax, ebx
                invoke dwtoa, eax, addr resultBuff
                invoke SetWindowText, hWndResult, addr resultBuff
            .ENDIF
        .ENDIF

    .ELSEIF uMsg==WM_DESTROY
        invoke PostQuitMessage, 0

    .ELSE
        invoke DefWindowProc, hWnd, uMsg, wParam, lParam
        ret

    .ENDIF

    xor eax, eax
    ret
WndProc endp

end start