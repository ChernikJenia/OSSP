@echo off
echo -- строка параметров: %1 %2 %3 %4
echo -- параметр 1: %1
echo -- параметр 2: %2
echo -- параметр 3: %3
set /a a = %1 + %2
echo -- %1 + %2 = %a%

set /a b = %1 * %2
echo -- %1 * %2 = %b%

set /a c = %3 / %2
echo -- %3 / %2 = %c%

set /a d = %1 - %2
echo -- %1 - %2 = %d%

set /a e = (%2 - %1) * (%1 - %2)
echo -- (%2 - %1) * (%1 - %2) = %d%