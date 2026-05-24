''' Tiny fixed-size line buffer for GSA text.
#define RB_LINE_MAX 32
Dim RB_Line As String * RB_LINE_MAX
Dim RB_LineReady As Bit
Dim RB_LineCount As Byte
Dim RB_LineTooLong As Bit
Sub RB_LineBuf_Init()
    RB_Line = ""
    RB_LineReady = 0
    RB_LineCount = 0
    RB_LineTooLong = 0
End Sub
Sub RB_LineBuf_Clear()
    RB_Line = ""
    RB_LineReady = 0
    RB_LineCount = 0
    RB_LineTooLong = 0
End Sub
Sub RB_LineBuf_AddChar(In RB_Ch As Byte)
    If RB_Ch = 13 Then
        RB_LineReady = 1
        Exit Sub
    End If
    If RB_Ch = 10 Then
        RB_LineReady = 1
        Exit Sub
    End If
    If RB_LineCount < RB_LINE_MAX Then
        RB_Line = RB_Line + Chr(RB_Ch)
        RB_LineCount = RB_LineCount + 1
    Else
        RB_LineTooLong = 1
        RB_LineReady = 1
    End If
End Sub
