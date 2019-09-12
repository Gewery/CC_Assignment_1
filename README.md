# Turbo Pascal Lexical analyzer

## Tokens:

Token name | Description | Attached attribute
---|---|---
**identifier**|letter followed by letters and numbers|pointer to corresponding record
**number**|constant numbers as 1, 2, 1.4524...|lexem
**literal**|double quoted strings as "Hello world!'|lexem without ''
**+**, **-**, **<**, **>**, __*__, **==**, and so on |one token for each __operator__ named the same as it's lexem|pointer to corresponding record
**,**, **;**, **(**, **)**, __..__, **.**, and so on |one token for each __delimiter__ named the same as it's lexem|pointer to corresponding record
**if**, **else**, **absolute**, **program**, __begin__, **end**, and so on |one token for each __keyword__ named the same as it's lexem|pointer to corresponding record

<br>

## Attributes of Tokens

#### Token itself is a __class__ that has the following attributes:

* lexem
* type (as keyword, delimiter, operator, ...)
* number of line with it's first appearance (for identifiers only)
