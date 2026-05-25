# 021 Macro Vocabulary Demo

This example demonstrates the first conservative `nugget-fwlib` macro layer.

It uses:

```gcb
#include "../../common/rb_macros.inc"
```

The purpose is to show how named constants can make a GCBASIC program read more like an instrument story.

Instead of raw numeric flags:

```gcb
Running = 0
If Running = 1 Then
```

this example uses symbolic intent:

```gcb
Running = RB_FALSE
If Running = RB_TRUE Then
```

Instead of scattered protocol strings, it uses GSA word macros:

```gcb
HSerPrint RB_GSA_WORD_STATUS
HSerPrint RB_GSA_STATUS_READY
```

## Important design rule

The macro layer does not hide the proven chip facts. The register-level setup remains in the architecture and GPIO include files.

Macros name intent. They do not replace understanding.
