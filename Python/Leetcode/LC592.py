import re
from fractions import Fraction
ptn = re.compile(r'[+-]?\d+/\d+')


class Solution:
    def fractionAddition(self, expr: str) -> str:
        res = sum(Fraction(f) for f in ptn.findall(expr))
        return f'{res.numerator}/{res.denominator}'
