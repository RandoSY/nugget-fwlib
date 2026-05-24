''' General beginner GPIO helpers.
Sub RB_GPIO_RC0_Output()
    Dir PORTC.0 Out
    ANSELC.0 = 0
    LATC.0 = 0
End Sub
Sub RB_GPIO_RC1_Output()
    Dir PORTC.1 Out
    ANSELC.1 = 0
    LATC.1 = 0
End Sub
Sub RB_GPIO_RA0_InputDigital()
    Dir PORTA.0 In
    ANSELA.0 = 0
End Sub
Sub RB_GPIO_RC0_Set()
    LATC.0 = 1
End Sub
Sub RB_GPIO_RC0_Clear()
    LATC.0 = 0
End Sub
Sub RB_GPIO_RC0_Toggle()
    LATC.0 = !LATC.0
End Sub
