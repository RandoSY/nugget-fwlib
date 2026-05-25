''' ================================================================
''' rb_7seg.inc
''' Addressable seven-segment character primitive.
'''
''' Purpose:
'''   Provide the CLI with a clean primitive:
'''
'''       display index + character code -> visible character
'''
''' Current status:
'''   This file defines the character vocabulary and command-facing
'''   API. The exact REDBOARD seven-segment digit enable pins and
'''   segment pins must be verified before hardware output is enabled.
'''
''' Design rule:
'''   Do not pretend the pin map is known. Keep the API stable and
'''   make the hardware map explicit when confirmed.
''' ================================================================

#define RB_7SEG_DIGIT_COUNT 3

' Segment bit order used by the character table:
' bit0 = A
' bit1 = B
' bit2 = C
' bit3 = D
' bit4 = E
' bit5 = F
' bit6 = G
' bit7 = DP


Function RB_7Seg_CharToPattern(In RB_Ch As Byte) As Byte

    ' Default: blank / unsupported.
    RB_7Seg_CharToPattern = 0

    ' ASCII numeric digits.
    If RB_Ch = 48 Then
        RB_7Seg_CharToPattern = 63      ' 0: A B C D E F
    ElseIf RB_Ch = 49 Then
        RB_7Seg_CharToPattern = 6       ' 1: B C
    ElseIf RB_Ch = 50 Then
        RB_7Seg_CharToPattern = 91      ' 2: A B D E G
    ElseIf RB_Ch = 51 Then
        RB_7Seg_CharToPattern = 79      ' 3: A B C D G
    ElseIf RB_Ch = 52 Then
        RB_7Seg_CharToPattern = 102     ' 4: B C F G
    ElseIf RB_Ch = 53 Then
        RB_7Seg_CharToPattern = 109     ' 5: A C D F G
    ElseIf RB_Ch = 54 Then
        RB_7Seg_CharToPattern = 125     ' 6: A C D E F G
    ElseIf RB_Ch = 55 Then
        RB_7Seg_CharToPattern = 7       ' 7: A B C
    ElseIf RB_Ch = 56 Then
        RB_7Seg_CharToPattern = 127     ' 8: A B C D E F G
    ElseIf RB_Ch = 57 Then
        RB_7Seg_CharToPattern = 111     ' 9: A B C D F G

    ' Useful hex-ish letters and display-safe symbols.
    ElseIf RB_Ch = 65 Then
        RB_7Seg_CharToPattern = 119     ' A
    ElseIf RB_Ch = 97 Then
        RB_7Seg_CharToPattern = 119     ' a -> A style
    ElseIf RB_Ch = 66 Then
        RB_7Seg_CharToPattern = 124     ' b style
    ElseIf RB_Ch = 98 Then
        RB_7Seg_CharToPattern = 124
    ElseIf RB_Ch = 67 Then
        RB_7Seg_CharToPattern = 57      ' C
    ElseIf RB_Ch = 99 Then
        RB_7Seg_CharToPattern = 88      ' c style
    ElseIf RB_Ch = 68 Then
        RB_7Seg_CharToPattern = 94      ' d style
    ElseIf RB_Ch = 100 Then
        RB_7Seg_CharToPattern = 94
    ElseIf RB_Ch = 69 Then
        RB_7Seg_CharToPattern = 121     ' E
    ElseIf RB_Ch = 101 Then
        RB_7Seg_CharToPattern = 121
    ElseIf RB_Ch = 70 Then
        RB_7Seg_CharToPattern = 113     ' F
    ElseIf RB_Ch = 102 Then
        RB_7Seg_CharToPattern = 113
    ElseIf RB_Ch = 72 Then
        RB_7Seg_CharToPattern = 118     ' H
    ElseIf RB_Ch = 104 Then
        RB_7Seg_CharToPattern = 116     ' h
    ElseIf RB_Ch = 76 Then
        RB_7Seg_CharToPattern = 56      ' L
    ElseIf RB_Ch = 108 Then
        RB_7Seg_CharToPattern = 56
    ElseIf RB_Ch = 80 Then
        RB_7Seg_CharToPattern = 115     ' P
    ElseIf RB_Ch = 112 Then
        RB_7Seg_CharToPattern = 115
    ElseIf RB_Ch = 85 Then
        RB_7Seg_CharToPattern = 62      ' U
    ElseIf RB_Ch = 117 Then
        RB_7Seg_CharToPattern = 28      ' u
    ElseIf RB_Ch = 45 Then
        RB_7Seg_CharToPattern = 64      ' minus sign
    ElseIf RB_Ch = 95 Then
        RB_7Seg_CharToPattern = 8       ' underscore
    ElseIf RB_Ch = 32 Then
        RB_7Seg_CharToPattern = 0       ' blank
    End If

End Function


Sub RB_7Seg_Init
    ' Placeholder. Add segment and digit pin directions here once
    ' the exact REDBOARD seven-segment map is verified.
End Sub


Function RB_7Seg_IsDigitValid(In RB_Digit As Byte) As Bit
    If RB_Digit < RB_7SEG_DIGIT_COUNT Then
        RB_7Seg_IsDigitValid = RB_TRUE
    Else
        RB_7Seg_IsDigitValid = RB_FALSE
    End If
End Function


Function RB_7Seg_WritePattern(In RB_Digit As Byte, In RB_Pattern As Byte) As Bit
    ' Placeholder implementation.
    ' Returns RB_FALSE because hardware pin map is not enabled yet.
    ' Future version should:
    '   1. disable all digit selects
    '   2. drive segment pins A..G/DP from RB_Pattern
    '   3. enable selected digit
    RB_7Seg_WritePattern = RB_FALSE
End Function


Function RB_7Seg_WriteChar(In RB_Digit As Byte, In RB_Ch As Byte) As Bit
    Dim RB_Pattern As Byte

    RB_Pattern = RB_7Seg_CharToPattern(RB_Ch)
    RB_7Seg_WriteChar = RB_7Seg_WritePattern(RB_Digit, RB_Pattern)
End Function


Sub RB_7Seg_PrintCharInfo(In RB_Digit As Byte, In RB_Ch As Byte)
    Dim RB_Pattern As Byte

    RB_Pattern = RB_7Seg_CharToPattern(RB_Ch)

    HSerPrint "7SEG DIGIT "
    HSerPrint RB_Digit
    HSerPrint " CHAR ASCII "
    HSerPrint RB_Ch
    HSerPrint " PATTERN "
    HSerPrint RB_Pattern
    HSerPrintCRLF
End Sub


Sub RB_7Seg_PrintMap
    HSerPrint "7SEG MAP"
    HSerPrintCRLF
    HSerPrint "DIGITS 0..2 RESERVED"
    HSerPrintCRLF
    HSerPrint "SEGMENTS A,B,C,D,E,F,G,DP PIN MAP PENDING"
    HSerPrintCRLF
End Sub
