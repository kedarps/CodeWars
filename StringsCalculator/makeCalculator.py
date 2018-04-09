# uses regular expressions to parse string with operators and applies specific operators
# for addition subtraction, in order to handle negative numbers, all operations are executed as
# additions. So for example, -1.0-4 ==> (-1.0)+(-4). This way we can gracefully handle negative numbers

import re

class Calculator(object):

    inString = ''
    DIV_MUL = r'\d+(\.\d+)?(\/|\*)\d+(\.\d+)?'
    ADD_SUB = r'(\-)?\d+(\.\d+)?(\-|\+)\d+(\.\d+)?'

    def removeSpaces(self):
        outStr = ''
        for c in self.inString:
            if c != ' ':
                outStr += c

        self.inString = outStr

    def doDivisionsMultiplications(self):
        match = re.search(self.DIV_MUL, self.inString)

        while match is not None:
            span = match.span()
            current = self.inString[span[0]:span[1]]
            div = current.find('/')
            mul = current.find('*')

            if div > 0:
                result = float(current[:div]) / float(current[div+1:])

            if mul > 0:
                result = float(current[:mul]) * float(current[mul+1:])

            newStr = self.inString[:span[0]] + str(result) + self.inString[span[1]:]

            self.inString = newStr
            match = re.search(self.DIV_MUL, self.inString)

    def doAdditionsSubtractions(self):
        match = re.search(self.ADD_SUB, self.inString)

        while match is not None:
            span = match.span()
            current = self.inString[span[0]:span[1]]
            result = 0

            expr = re.compile(r'(\-)?\d+(\.\d+)?')
            mtch = expr.finditer(current)
            result = 0

            for m in mtch:
                result += float(current[m.span()[0]:m.span()[1]])

            newStr = self.inString[:span[0]] + str(result) + self.inString[span[1]:]

            self.inString = newStr
            match = re.search(self.ADD_SUB, self.inString)

    def evaluate(self, string):
        print(string)
        self.inString = string
        self.removeSpaces()

        self.doDivisionsMultiplications()
        self.doAdditionsSubtractions()

        return float(self.inString)

allStrings = ["2 / 2 + 3 * 4 - 6",
            "2 + 3 * 4 / 3 - 6 / 3 * 3 + 8",
            "10 * 5 / 2",
            "127",
            "1.1 + 2.2 + 3.3",
            "2 + 3",
            "2 - 3 - 4",
            "1.1 * 2.2 * 3.3"]

for s in allStrings:
    print(s)
    print(Calculator().evaluate(s))
    print('================')
